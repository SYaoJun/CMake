#include <iostream>
#include <cassert>
#include "leveldb/db.h"
#include "leveldb/write_batch.h"
int main()
{
    // Open a database.
    leveldb::DB* db;
    leveldb::Options opts;
    opts.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(opts, "testdb", &db);
    assert(status.ok());

    // Write data.
    status = db->Put(leveldb::WriteOptions(), "name", "yaojun");
    assert(status.ok());

    // Read data.
    std::string val;
    status = db->Get(leveldb::ReadOptions(), "name", &val);
    assert(status.ok());
    std::cout << val << std::endl;
   }
