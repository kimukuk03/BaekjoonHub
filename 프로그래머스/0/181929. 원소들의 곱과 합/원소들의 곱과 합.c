#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int mul = 1;
    int add = 0;
    int square = 0;
    
    for(int i = 0; i < num_list_len; i++)
    {
        mul = mul * num_list[i];
    }
    for(int i = 0; i < num_list_len; i++)
    {
        add += num_list[i];
    }
    square = add * add;
    if(mul > square)
    {
        answer = 0;
    }
    else if(mul < square)
    {
        answer = 1;
    }
    
    return answer;
}