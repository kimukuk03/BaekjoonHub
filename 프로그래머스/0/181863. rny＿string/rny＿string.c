#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rny_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.  
    int rny_string_len = strlen(rny_string);
    int rny_string_origin_len = rny_string_len;
    
    for(int i = 0; i < rny_string_len; i++)
    {
        if(rny_string[i] == 'm')
        {
            rny_string_len += 1;
        }
    }
    char* answer = (char*)malloc((rny_string_len+1)*sizeof(char));
    
    int j = 0;
    
    for(int i = 0; i < rny_string_origin_len; i++)
    {
        if(rny_string[i] == 'm')
        {
            answer[j] = 'r';
            answer[j + 1] = 'n';
            j+=2;
        }
        else
        {
            answer[j] = rny_string[i];
            j++;
        }
    }
    answer[rny_string_len] = '\0';
    
    
    return answer;
}