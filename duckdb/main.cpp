#include "duckdb.hpp"

using namespace duckdb;

int main() {
    DuckDB db(nullptr);

    Connection con(db);

    con.Query("CREATE TABLE tb(id INTEGER, name text)");
    auto res = con.Query("INSERT INTO tb VALUES (101, 'hello world')");
    res->Print();
    auto result = con.Query("SELECT * FROM tb");
    result->Print();
}