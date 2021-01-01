#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAXLINE 100
#define MAXROLL 21

char Line[MAXLINE];
int  Rolls[MAXROLL];

int get_int(char *line) {
    int n;
    fgets(line, MAXLINE, stdin);
    sscanf(line, "%d", &n);
    return n;
}

int get_ints(char *line, int *ints) {
    fgets(line, MAXLINE, stdin);
    char *strToken = strtok(line, " " );
    int n = 0;
    while(strToken != NULL) {
        sscanf(strToken, "%d", ints); 
        n++;
        ints++;
        strToken = strtok(NULL, " ");
    }
    return n;
}
#define START int h=0
#define ADVANCE_FRAME h++
#define IS_NEW_FRAME (h % 2 == 0)
#define FRAME_NB (h / 2)
int score(int *rolls, int n) {
    START;
    int result = 0;
    for(int i = 0; i < n && FRAME_NB < 10; i++) {
        result += rolls[i];
        if (IS_NEW_FRAME && rolls[i] == 10) {
            result += rolls[i+1] + rolls[i+2];
            ADVANCE_FRAME;
        }
        else if (!IS_NEW_FRAME &&  rolls[i-1] + rolls[i] == 10) 
            result += rolls[i+1];
        ADVANCE_FRAME;
    }
    return result;
}
int main() {
    int max_case = get_int(Line);
    for(int i=0; i<max_case; i++) {
        for(int i=0; i<MAXROLL; i++)
                Rolls[i] = 0;
        int max_roll = get_int(Line);
        assert(max_roll <= MAXROLL);
        get_ints(Line, Rolls);
        printf("%d\n", score(Rolls, max_roll));
    }
    return 0;
}
