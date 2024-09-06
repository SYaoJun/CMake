#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/ipc/api.h>
#include <iostream>
#include <unordered_map>

// 简单的键值存储引擎接口
class KVStore {
public:
    // 存储键值对
    void put(const std::string& key, int64_t value) {
        keys_.push_back(key);
        values_.push_back(value);
    }

    // 将数据构建为 Arrow Table
    std::shared_ptr<arrow::Table> buildArrowTable() {
        arrow::StringBuilder key_builder;
        arrow::Int64Builder value_builder;

        for (const auto& key : keys_) {
            key_builder.Append(key);
        }

        for (const auto& value : values_) {
            value_builder.Append(value);
        }

        std::shared_ptr<arrow::Array> keys;
        std::shared_ptr<arrow::Array> values;

        key_builder.Finish(&keys);
        value_builder.Finish(&values);

        auto schema = arrow::schema({
            arrow::field("key", arrow::utf8()),
            arrow::field("value", arrow::int64())
        });

        return arrow::Table::Make(schema, {keys, values});
    }

    // 简单的查询示例
    void queryTable(const std::shared_ptr<arrow::Table>& table, const std::string& key_to_find) {
        auto key_array = std::static_pointer_cast<arrow::StringArray>(table->column(0)->chunk(0));
        auto value_array = std::static_pointer_cast<arrow::Int64Array>(table->column(1)->chunk(0));

        for (int64_t i = 0; i < key_array->length(); ++i) {
            if (key_array->GetString(i) == key_to_find) {
                std::cout << "Found key: " << key_to_find << " with value: " << value_array->Value(i) << std::endl;
            }
        }
    }

private:
    std::vector<std::string> keys_;
    std::vector<int64_t> values_;
};

int main() {
    KVStore store;
    store.put("key1", 100);
    store.put("key2", 200);
    store.put("key3", 300);

    // 构建 Arrow Table
    auto table = store.buildArrowTable();

    // 查询
    store.queryTable(table, "key2");

    return 0;
}
