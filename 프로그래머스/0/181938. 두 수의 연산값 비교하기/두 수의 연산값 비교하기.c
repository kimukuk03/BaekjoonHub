#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    int count = 0;          //자릿수
    int c = b;
    int d = a;
    
    while(c > 0)
    {
        c = c / 10;
        count++;
    }
    for(int i = 1; i <= count; i++)
    {
        a = a * 10;
    }
    
    int cal_1 = a + b;
    int cal_2 = 2 * d * b;
    
    if(cal_1 >= cal_2)
    {
        answer = cal_1;
    }
    else if(cal_1 < cal_2)
    {
        answer = cal_2;
    }
    
    
    return answer;
}