
#include <vector>

//최대공약수 구하기
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

//최소공배수 구하기
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

//signals는 2차원 벡터
int solution(std::vector<std::vector<int>> signals)
{
    int n = signals.size(); // 신호등 개수

    //각 신호등의 전체 주기를 저장
    std::vector<int> blinker(n);

    int answer = -1;
    int green;
    int yellow;
    int red;

    //모든 신호등 주기의 최소공배수
    int limit = 1;

    //각 신호등의 전체 주기 계산
    for (int i = 0; i < n; i++)
    {
        green = signals[i][0];   // 초록불 시간
        yellow = signals[i][1];  // 노란불 시간
        red = signals[i][2];     // 빨간불 시간

        // 신호등의 전체 주기
        blinker[i] = green + yellow + red;

        // 전체 신호등의 주기가 다시 반복되는 시간 계산
        limit = lcm(limit, blinker[i]);
    }

    //1초부터 모든 신호등이 노란불인지 확인
    for (int t = 1; t <= limit; t++)
    {
        bool allYellow = true;

        for (int i = 0; i < n; i++)
        {
            green = signals[i][0];
            yellow = signals[i][1];

            //현재 신호등 주기에서 몇 번째 위치인지 계산
            int time = (t - 1) % blinker[i];

            //초록불 또는 빨간불인 경우
            if (time < green || time >= green + yellow)
            {
                allYellow = false;
                break;
            }
        }
        //모든 신호등이 동시에 노란불이면
        if (allYellow)
        {
            answer = t;
            break;
        }
    }
    return answer;
}
