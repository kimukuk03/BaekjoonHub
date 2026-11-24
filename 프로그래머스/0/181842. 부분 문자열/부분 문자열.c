#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) {
    int answer = 0;
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
        
    for(int j = 0; j <= str2_len - str1_len; j++)
    {
        int count = 20;

        for(int i = 0; i < str1_len; i++)//str1 하나하나 비교
        {
            if(str1[i] == str2[j + i])// 하나하나 비교 했을떄 하나라도 안맞으면 0출력
            {
                count++;
            }
        }
        if (count == str1_len + 20)
        {
        answer = 1;
        break;
        }
    }
    return answer;
}