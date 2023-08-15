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

void buf_test(char **buf)

{
    char u[10] = "yaojun";
    strcpy(buf[0], u);
    printf("buf[0] = %s\n", buf[0]);
}
int main()
{
    const int LINE = 480000;
    const int WORD_LEN = 10;
    char **buf = (char **)malloc(LINE * sizeof(char *));
    for (int i = 0; i < LINE; i++)
    {
        buf[i] = (char *)malloc(WORD_LEN * sizeof(char));
    }

    buf_test(buf);

    for (int i = 0; i < LINE; i++)
    {
        free(buf[i]);
    }

    free(buf);
    return 0;
}