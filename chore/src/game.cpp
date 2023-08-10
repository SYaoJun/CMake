//
// Created by 姚军 on 2023/8/10.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>

#define N  1024
#define M 128
int step = 0;
int limit = 35;
char candidate_words[N][M];
char enterword[M];
char targetword[M];

void get_array() {


}
int is_exist_in_array(){

}
void show_hint(){

}
int main() {
    strcpy(enterword, "bugs");
    strcpy(targetword, "xrgs");
    get_array();
    while(true) {
        scanf("%s", enterword);
        if(strcmp(enterword, "?") == 0) {
            show_hint();
        }
        if(strcmp(enterword, targetword) == 0) {
            fprintf(stdout, "Well done - you solved the ladder in %d steps.", step);
            break;
        }
        get_array();
        if(is_exist_in_array()) {
            step++;
            fprintf(stderr, "Enter word %d (or ? for help):", step);
        }
        if(step > limit) {
            fprintf(stderr, "Enter word %d (or ? for help):", step);
        }
    }
    return 0;
}