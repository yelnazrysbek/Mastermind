#include "add_functions.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int my_strcmp(char* first, char* second) {

       while(*first) {
        if (*first != *second) {
            break;
        }
        first++; second++;
    }

    int f = (int)*first;
    int s = (int)*second;

    return f-s;
}

char* my_strcpy(char* destination, char* source) {
    char* index = destination;

    while(*source) {
        *index = *source;
        index++;
        source++;
    }

    *index = '\0';
    return destination;
}

char* my_rand() {
    char* num = (char*)malloc(sizeof(char)*4+1);

    srand (time(NULL));
    int i = 0;
    for(; i<4; i++) {
        int number = rand() % 8;
        if (i > 0) {
            while (num[i-1] == number + '0') {
                number = rand() % 8;
            }
        }
        num[i] = number + '0';
    }
    
    num[i] = '\0';

    return num;
}

// 1 - input contains non-digits, 2 - contains 8 or 9,  0 - correct
int is_correctinput(char* source) {

    for (int i = 0; i<4; i++) {
        if (!(source[i] >= '0' && source[i] <= '9')) {
            return 1;
        }
        
        if (source[i]== '8' || source[i] == '9') {
            return 2;
        }

    }
    return 0;
} 

int my_atoi(char* source) {
    char* p = source;
  
    int i = 0;
    int j = 0; 

    for (; *p != '\0'; p++) {
        i = *p - 48;
        j = j*10+i;
    }
  
    return j;
}

char* input() {
    char* buffer = malloc(101);
    buffer[100] = '\0';
    read(0, buffer, 100);
    return buffer;
}
