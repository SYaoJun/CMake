#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>

#define DEFAULT_LIMIT 15
#define DEFAULT_LENGTH 4
#define DEFAULT_DICTFILE "/usr/share/dict/words"

void print_usage() {
    fprintf(stderr, "Usage: uqwordladder [--from fromWord] [--target endWord] [--limit stepLimit]\n"
                    "[--length length] [--dictfile filename]\n");
    exit(16);
}

int is_valid_word(const char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *fromWord = NULL;
    char *endWord = NULL;
    char *dictfile = strdup(DEFAULT_DICTFILE);
    int stepLimit = DEFAULT_LIMIT;
    int length = DEFAULT_LENGTH;

    static struct option long_options[] = {
        {"from", required_argument, 0, 'f'},
        {"target", required_argument, 0, 't'},
        {"length", required_argument, 0, 'L'},
        {"limit", required_argument, 0, 'l'},
        {"dictfile", required_argument, 0, 'd'},
        {0, 0, 0, 0}
    };



    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'f':
                fromWord = strdup(optarg);
                break;
            case 't':
                endWord = strdup(optarg);
                break;
            case 'l':
                stepLimit = atoi(optarg);
                break;
            case 'L':
                length = atoi(optarg);
                break;
            case 'd':
                free(dictfile);
                dictfile = strdup(optarg);
                break;
            default:
                print_usage();
        }
    }

    printf("fromWord = %s\n", fromWord);
    printf("endWorld = %s\n", endWord);
    printf("steplimit = %d\n", stepLimit);
    printf("length = %d\n", length);


    // Checking word lengths for consistency
    if ((fromWord && strlen(fromWord) != length) || (endWord && strlen(endWord) != length)) {
        fprintf(stderr, "uqwordladder: Word lengths should be consistent\n");
        exit(15);
    }

    // Check if the length is between 2 and 9 (inclusive)
    if (length < 2 || length > 9) {
        fprintf(stderr, "uqwordladder: Word length should be from 2 to 9 (inclusive)\n");
        exit(6);
    }

    // Check for words containing only letters
    if ((fromWord && !is_valid_word(fromWord)) || (endWord && !is_valid_word(endWord))) {
        fprintf(stderr, "uqwordladder: Words should contain only letters\n");
        exit(10);
    }

    // Check if start and end words are different
    if (fromWord && endWord && strcmp(fromWord, endWord) == 0) {
        fprintf(stderr, "uqwordladder: Start and end words must be different\n");
        exit(2);
    }

    // Check stepLimit for validity
    if (stepLimit < length || stepLimit > 55) {
        fprintf(stderr, "uqwordladder: Step limit must be word length to 55 (inclusive)\n");
        exit(1);
    }

    // Check dictionary file existence
    FILE *file = fopen(dictfile, "r");
    if (!file) {
        fprintf(stderr, "uqwordladder: File named \"%s\" cannot be opened\n", dictfile);
        exit(3);
    }
    fclose(file);

    // TODO: Your main implementation code goes here

    free(fromWord);
    free(endWord);
    free(dictfile);

    return EXIT_SUCCESS;
}
