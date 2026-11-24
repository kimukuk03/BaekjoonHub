#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int answer = 0;
    int myString_len = strlen(myString);
    int pat_len = strlen(pat);
    
    if(pat_len > myString_len)//pat이 myString보다 길이가 길떄
    {
        return answer;
    }
    else
    {
        for(int j = 0; j <= myString_len - pat_len; j++)
        {
            answer = 1;
            
            for(int i = 0; i < pat_len; i++)
            {
                if(tolower(myString[i + j]) != tolower(pat[i]))
                {
                    answer = 0;
                    break;
                }
            }
            if (answer == 1)
            {
                return answer;
            }
        }
    }
    
    return answer;
}