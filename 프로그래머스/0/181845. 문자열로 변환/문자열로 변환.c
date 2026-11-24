#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    char str[10000];
    sprintf(str, "%d", n);
    int str_len = strlen(str);
    
    char* answer = (char*)malloc((str_len + 1)*sizeof(char));
    
    for(int i = 0; i < str_len; i++)
    {
        answer[i] = str[i];
    }
    answer[str_len] = '\0';
    
    
    return answer;
}