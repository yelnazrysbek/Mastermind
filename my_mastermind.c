#include "add_functions.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct GameDt {
    char code[5];
    int attempts;
} gameDt;

gameDt* handle_input(int argc, char* argv[]) {

    int i = 0;
    char strCode[5];
    int isCode = 0;
    int rounds = 10;

    for (; i<argc; i++) {
        if (my_strcmp(argv[i], "-c") == 0) {
            my_strcpy(strCode, argv[i+1]);
            isCode = 1; 
        } 

        if (my_strcmp(argv[i], "-t") == 0) {
            rounds = my_atoi(argv[i+1]);
        }
    }

    if (isCode == 0) {
        char* randCode = my_rand();
        my_strcpy(strCode, randCode);
        free(randCode);
    }

    gameDt* gmd = (gameDt*)malloc(sizeof(gameDt));
    my_strcpy(gmd->code, strCode);
    gmd->attempts = rounds;

    return gmd;  
}

int wellplaced_pieces(char* code, char* input) {
    int num = 0; 
    while (*code) {
        if (*code == *input) {
            num++;
        }
        code++;
        input++;
    }
    return num;
}

int misplaced_pieces(char* code, char* input) {
    
    int i, j;
    int misplaced = 0;

    for (i = 0; i<4; i++) {
        for (j = 0; j<4; j++) {
            if (code[i] == input[j] && i!=j) {
                misplaced++;
            }
        }
    }

    return misplaced; 
}

int check_code(char* orig_code, char* user_code) {
    int wellplaced = wellplaced_pieces(orig_code, user_code);
    int misplaced = misplaced_pieces(orig_code, user_code);

    printf("Well placed pieces: %d\n", wellplaced);
    printf("Misplaced pieces: %d\n", misplaced);

    if (wellplaced == 4) {
        return 0;
    } else {
        return 1;
    }
}

char* cut(char* input) {
    char* new = (char*)malloc(sizeof(char)*4+1);
    new[4] = '\0';

    for (int i = 0; i<4; i++) {
        new[i] = input[i];
    }

    return new;
}

int process_round(char* orig_code, int round) {
    printf("Round %d\n", round);
    char* user_input = input();
    char* user_code = cut(user_input);
    int res_code = -1; 

    if (is_correctinput(user_code) == 1) {
        printf("Error: Input contains non-digits\n");
    } else if (is_correctinput(user_code) == 2) {
        printf("Error: Input contains 8 and/or 9\n");
    } else {
        res_code = check_code(orig_code, user_code);
    }

    free(user_code);
    free(user_input);

    return res_code;
}

void play(gameDt* gm_dt) {
    int current = 0;

    printf("Will you find the secret code?\n----\n");

    while(current < gm_dt->attempts) {
        int res_code = process_round(gm_dt->code, current);
        printf("----\n");
        current++;

        if (res_code == 0) {
            printf("!!!Congrats!!!\n");
            break;
        }
    }
    printf("End of game\n");
}

int main(int argc, char* argv[]) {
    gameDt* gmd = handle_input(argc, argv);
    play(gmd);
    free(gmd);
	return 0;
}