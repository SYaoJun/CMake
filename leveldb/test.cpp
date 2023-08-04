#include <assert.h>
#include <string.h>
#include <iostream>
#include "leveldb/db.h"

int main()
{
    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    std::string k1 = "name";
    std::string v1 = "jim";

    status = db->Put(leveldb::WriteOptions(), k1, v1);
    assert(status.ok());

    status = db->Get(leveldb::ReadOptions(), k1, &v1);
    assert(status.ok());
    std::cout << "k1:" << k1 << "; v1:" << v1 << std::endl;

    std::string k2 = "age";
    std::string v2 = "20";

    status = db->Put(leveldb::WriteOptions(), k2, v2);
    assert(status.ok());
    status = db->Get(leveldb::ReadOptions(), k2, &v2);
    assert(status.ok());
    std::cout << "k2:" << k2 << "; v2:" << v2 << std::endl;

    status = db->Delete(leveldb::WriteOptions(), k2);
    assert(status.ok());
    std::cout << "Delete k2.." << std::endl;
    status = db->Get(leveldb::ReadOptions(), k2, &v2);
    if (!status.ok())
        std::cerr << "k2:" << k2 << "; " << status.ToString() << std::endl;
    else
        std::cout << "k2:" << k2 << "; v2:" << v2 << std::endl;

    delete db;
    return 0;
}