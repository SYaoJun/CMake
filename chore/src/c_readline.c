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