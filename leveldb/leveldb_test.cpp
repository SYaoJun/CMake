#include <assert.h>
#include <string.h>
#include <iostream>
#include "leveldb/db.h"

int main()
{
    leveldb::DB *db;
    leveldb::Options options;

    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
    assert(status.ok());

    std::string k1 = "name";

    std::string v1 = "jim";

    status = db->Put(leveldb::WriteOptions(), k1, v1);
    assert(status.ok());
    std::cout << status.ok() << std::endl;
    delete db;
    return 0;
}