#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

#define DEFAULT_LIMIT 15
#define DEFAULT_LENGTH 4
#define DEFAULT_DICTFILE "/usr/share/dict/words"
#define DEFAULT_SIZE 256
#define DEFAULT_BUFFERSIZE 6000000

char array[DEFAULT_SIZE][DEFAULT_SIZE];
char buf[DEFAULT_BUFFERSIZE];

int index_ = 0;
int is_exist_dictionary_file = 0;

void print_usage() {
    fprintf(stderr,
            "Usage: uqwordladder [--from fromWord] [--target endWord] [--limit stepLimit]\n"
            "[--length length] [--dictfile filename]\n");
    exit(16);
}


//judge that if the word is all composed with letter
/*int isalpha(char c)
{
        //if the position is a letter, then it returns true
	if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
	{
		return 1;
	}
	return 0;
}*/
//function for checking if the enterword is in all possible arrays
int is_exist_in_array(char *enterword) {
    for (int i = 0; i < index_; i++) {
        if (strcmp(enterword, array[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// function for checking for words containing only letters
int is_valid_word(const char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i]))
            return 0;
    }
    return 1;
}
char* to_upper_case(char* word) {
    int n = strlen(word);
    for(int i = 0; i < n; i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}

//function for check if rhe length of the word is in the range
/*void stepLimit_Checking()
{
    int length,limit;
    if(limit < length || limit > 55)
    {
	printf("uqwordladder: Step limit must be word length to 55 (inclusive)");
	exit(1);
    }
}*/
int Dictionary_File_Name_Checking(char *filename) {
    // open write read
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "uqwordladder: File named \"%s\" cannot be opened\n",
                filename);
        exit(3);
    }
//    int n;
//    int count = 0;
    fread(buf, 1, DEFAULT_BUFFERSIZE, file);
//	printf("read bytes: %d\n", n);
//	count += n;
//    printf("count = %d\n", count);
    fclose(file);
    return 0;
}

//get and list all the possible words that just change one word of the front
void get_candidate_word(char *enterword) {

    memset(array, 0, sizeof(array));
    index_ = 0;
    char s_copy[DEFAULT_SIZE];
    int n = strlen(enterword);
//    printf("enterword = %s\n", enterword);
    //traversal the letter sequences
    for (int i = 0; i < n; i++) {
        //enumerate a-z
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != enterword[i]) {
                char before_letter = enterword[i];
                enterword[i] = c;
//                printf("s_copy = %s\n", enterword);
                memcpy(array[index_], enterword, n);
                enterword[i] = before_letter;
                ++index_;

            }
        }
    }

}

void print_condidate_words() {

    int n = 3;
    for(int i = 0; i < n; i++) {
        fprintf(stdout, "%s\n", to_upper_case(array[i]));
    }
    fprintf(stdout, "...\n");
    for(int i = 0; i < n; i++) {
        fprintf(stdout, "%s\n", to_upper_case(array[index_- (n-i)]));
    }
}
//void get_value(int argc, char** argv)
//{
//    for(int i = 1; i < argc; i++)
//    {
//	if(strcmp(argv[i], "--target") == 0)
//	{
//	    strcpy(target, argv[i+1]);
//	    i += 2;
//	    continue;
//	}
//	else if(strcmp(argv[i], "--from") == 0)
//	{
//	    strcpy(from, argv[i+1]);
//	    i += 2;
//	    continue;
//	}
//	else if(strcmp(argv[i], "--limit") == 0)
//	{
//	    limit = atoi(argv[i+1]);
//	    i += 2;
//	    continue;
//	}
//	else if(strcmp(argv[i], "--length") == 0)
//	{
//	    length = atoi(argv[i+1]);
//	    i += 2;
//	    continue;
//	}
//	else if(strcmp(argv[i], "--dictfile") == 0)
//	{
//	    is_exist_dictionary_file = 1;
//	    strcpy(filename,argv[i+1]);
//	    i += 2;
//	    continue;
//	}
//    }
//}





void check_argument_validation(char *fromWord, char *endWord,
                               int length, int limit) {

//    printf("length = %d\n", length);
    // Checking word lengths for consistency
    if ((fromWord && strlen(fromWord) != length) ||
        (endWord && strlen(endWord) != length)) {
        fprintf(stderr, "uqwordladder: Word lengths should be consistent\n");
        exit(15);
    }

    // Check if the length is between 2 and 9 (inclusive)
    if (length < 2 || length > 9) {
        fprintf(stderr,
                "uqwordladder: Word length should be from 2 to 9 (inclusive)\n");
        exit(6);
    }

    // Check for words containing only letters
    if ((fromWord && !is_valid_word(fromWord)) ||
        (endWord && !is_valid_word(endWord))) {
        fprintf(stderr, "uqwordladder: Words should contain only letters\n");
        exit(10);
    }

    // Check if start and end words are different
    if (fromWord && endWord && strcmp(fromWord, endWord) == 0) {
        fprintf(stderr,
                "uqwordladder: Start and end words must be different\n");
        exit(2);
    }

    // Check stepLimit for validity
    if (limit < length || limit > 55) {
        fprintf(stderr,
                "uqwordladder: Step limit must be word length to 55 (inclusive)\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    char *fromWord = NULL;
    char *endWord = NULL;
    char *dictfile = strdup(DEFAULT_DICTFILE);
    int stepLimit = DEFAULT_LIMIT;
    int length = DEFAULT_LENGTH;

    static struct option long_options[] = {
            {"from",     required_argument, 0, 'f'},
            {"target",   required_argument, 0, 't'},
            {"length",   required_argument, 0, 'L'},
            {"limit",    required_argument, 0, 'l'},
            {"dictfile", required_argument, 0, 'd'},
            {0, 0,                          0, 0}
    };


    int opt;
    int option_index = 0;

    while ((opt = getopt_long(argc, argv, "", long_options, &option_index)) !=
           -1) {
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



//    get_value(argc,argv);//parse argument
    check_argument_validation(fromWord, endWord, length,
                              stepLimit);//check argument validation


    if (!is_exist_dictionary_file) {
        strcpy(dictfile, DEFAULT_DICTFILE);
    }

    Dictionary_File_Name_Checking(dictfile);//read data from dictionary
    char enterword[DEFAULT_SIZE];
    char lastword[DEFAULT_SIZE];
    memcpy(lastword, fromWord, length);
    printf("a lastword = %s", lastword);
    fprintf(stdout,
            "Welcome to UQWordLadder!Your goal is to turn '%s' into '%s' in at most %d steps\n",
            to_upper_case(fromWord), to_upper_case(endWord), stepLimit);

    int step = 0;
    while (1) {
        fprintf(stdout, "Enter word %d (or ? for help):\n", step+1);
        int ret = scanf("%s", enterword);
        if (ret == EOF) {
            fprintf(stdout, "Game over.\n");
            break;
        }
        if (step > stepLimit) {
            fprintf(stdout, "Game over - no more steps remaining.\n");
            exit(11);
        }

        if (strcmp(enterword, "?") == 0) {
            printf("b lastword = %s", lastword);
            get_candidate_word(lastword);
            fprintf(stdout, "Suggestions:-----------\n");
            print_condidate_words();
            fprintf(stdout, "-----End of Suggestions\n");
            continue;
        }
        get_candidate_word(enterword);
        if (!is_valid_word(enterword)) {
            fprintf(stderr, "Word must contain only letters - try again.\n");
            continue;
        }
        if (strcmp(enterword, endWord) == 0) {
            fprintf(stdout, "Well done - you solved the ladder in %d steps.\n",
                    step);
            break;
        }

        if (is_exist_in_array(enterword)) {
            step++;
            strcpy(lastword, enterword);
            continue;
        }

    }
    return 0;
}





