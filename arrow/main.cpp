#include <cstdint>
#include <iostream>
#include <vector>

#include "arrow/api.h"

using arrow::Int32Builder;
using arrow::Int64Builder;
using arrow::DoubleBuilder;
using arrow::StringBuilder;

struct row_data {
    int32_t col1;
    int64_t col2;
    double col3;
    std::string col4;
};//行结构

#define EXIT_ON_FAILURE(expr)                      \
  do {                                             \
    arrow::Status status_ = (expr);                \
    if (!status_.ok()) {                           \
      std::cerr << status_.message() << std::endl; \
      return EXIT_FAILURE;                         \
    }                                              \
  } while (0);

arrow::Status CreateTable(const std::vector<struct row_data>& rows,std::shared_ptr<arrow::Table>* table) {

    //使用arrow::jemalloc::MemoryPool::default_pool()构建器更有效，因为这可以适当增加底层内存区域的大小.
    arrow::MemoryPool* pool = arrow::default_memory_pool();

    Int32Builder col1_builder(pool);
    Int64Builder col2_builder(pool);
    DoubleBuilder col3_builder(pool);
    StringBuilder col4_builder(pool);

    //现在我们可以循环我们现有的数据，并将其插入到构建器中。这里的' Append '调用可能会失败(例如，我们无法分配足够的额外内存)。因此我们需要检查它们的返回值。
    for (const row_data& row : rows) {
        ARROW_RETURN_NOT_OK(col1_builder.Append(row.col1));
        ARROW_RETURN_NOT_OK(col2_builder.Append(row.col2));
        ARROW_RETURN_NOT_OK(col3_builder.Append(row.col3));
        ARROW_RETURN_NOT_OK(col4_builder.Append(row.col4));
    }

    //添加空值,末尾值的元素为空
    ARROW_RETURN_NOT_OK(col1_builder.AppendNull());
    ARROW_RETURN_NOT_OK(col2_builder.AppendNull());
    ARROW_RETURN_NOT_OK(col3_builder.AppendNull());
    ARROW_RETURN_NOT_OK(col4_builder.AppendNull());

    std::shared_ptr<arrow::Array> col1_array;
    ARROW_RETURN_NOT_OK(col1_builder.Finish(&col1_array));
    std::shared_ptr<arrow::Array> col2_array;
    ARROW_RETURN_NOT_OK(col2_builder.Finish(&col2_array));
    std::shared_ptr<arrow::Array> col3_array;
    ARROW_RETURN_NOT_OK(col3_builder.Finish(&col3_array));
    std::shared_ptr<arrow::Array> col4_array;
    ARROW_RETURN_NOT_OK(col4_builder.Finish(&col4_array));

    std::vector<std::shared_ptr<arrow::Field>> schema_vector = {
            arrow::field("col1", arrow::int32()), arrow::field("col2", arrow::int64()), arrow::field("col3", arrow::float64()),
            arrow::field("col4", arrow::utf8())};

    auto schema = std::make_shared<arrow::Schema>(schema_vector);

    //最终的' table '变量是我们可以传递给其他可以使用Apache Arrow内存结构的函数的变量。这个对象拥有所有引用数据的所有权，
    //因此一旦我们离开构建表及其底层数组的函数的作用域，就不必关心未定义的引用。
    *table = arrow::Table::Make(schema, {col1_array, col2_array, col3_array,col4_array});

    return arrow::Status::OK();
}
arrow::Status TableToVector(const std::shared_ptr<arrow::Table>& table,
                                    std::vector<struct row_data>* rows) {
    //检查表结构是否一致
    std::vector<std::shared_ptr<arrow::Field>> schema_vector = {
            arrow::field("col1", arrow::int32()), arrow::field("col2", arrow::int64()), arrow::field("col3", arrow::float64()),
            arrow::field("col4", arrow::utf8())};
    auto expected_schema = std::make_shared<arrow::Schema>(schema_vector);

    if (!expected_schema->Equals(*table->schema())) {
        // The table doesn't have the expected schema thus we cannot directly
        // convert it to our target representation.
        return arrow::Status::Invalid("Schemas are not matching!");
    }

    //获取对应列数据指针
    auto col1s =
            std::static_pointer_cast<arrow::Int32Array>(table->column(0)->chunk(0));
    auto col2s =
            std::static_pointer_cast<arrow::Int64Array>(table->column(1)->chunk(0));
    auto col3s =
            std::static_pointer_cast<arrow::DoubleArray>(table->column(2)->chunk(0));
    auto col4s =
            std::static_pointer_cast<arrow::StringArray>(table->column(3)->chunk(0));

    for (int64_t i = 0; i < table->num_rows(); i++) {
        if(col1s->IsNull(i)){
            assert(i==3);//第四行为null
        }else{
            int32_t col1 = col1s->Value(i);
            int64_t col2 = col2s->Value(i);
            double col3 = col3s->Value(i);
            std::string col4 = col4s->GetString(i);
            rows->push_back({col1, col2, col3,col4});
        }
    }

    return arrow::Status::OK();
}
int main(int argc, char** argv) {
    //行数组
    std::vector<row_data> rows = {
            {1, 11,1.0, "John"}, {2, 22,2.0, "Tom"}, {3,33, 3.0,"Susan"}};

    std::shared_ptr<arrow::Table> table;
    EXIT_ON_FAILURE(CreateTable(rows, &table));

    std::vector<row_data> expected_rows;
    EXIT_ON_FAILURE(TableToVector(table, &expected_rows));
    std::cout<<expected_rows.size()<<std::endl;
    assert(rows.size() == expected_rows.size());

    return EXIT_SUCCESS;
}