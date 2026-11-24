#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    
    char answer1[11], answer2[11];
    sprintf(answer1, "%d%d", a, b);
    sprintf(answer2, "%d%d", b, a);
    int str1 = atoi(answer1);
    int str2 = atoi(answer2);
    
    if(str1 >= str2)
    {
        answer = str1;
    }
    else
    {
        answer = str2;
    }
    return answer;
}