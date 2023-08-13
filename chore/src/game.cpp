#include <cstddef>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <string>
#include <fcntl.h>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <unordered_set>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char buf[1024];
    while (1) {
        char *ret = gets(buf);
        if (ret == NULL) {
            break;
        }
        printf("str = %s\n", buf);
    }
    return 0;
}