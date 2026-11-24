#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) 
{
    int answer = 0;
    if (n % 2 == 0)
    {
        for(int i = 1; 2*i <= n; i++)
        {
            answer += 4*i *i;
        }
    }
    else if (n % 2 != 0)
    {
        for(int i = 1; 2*i-1 <= n; i++)
        {
            answer += (2*i - 1);
        }
    }
    
    return answer;
}