
find_library(LEVELDB_LIBRARY_
    leveldb 
    /Users/yaojun/MyInstall/leveldb_install/lib)

find_path(LEVELDB_INCLUDES_ 
    leveldb/db.h 
    /Users/yaojun/MyInstall/leveldb_install/include)

if (LEVELDB_INCLUDES_ AND LEVELDB_LIBRARY_)
    set(LEVELDB_FOUND_ TRUE)
endif (LEVELDB_INCLUDES_ AND LEVELDB_LIBRARY_)