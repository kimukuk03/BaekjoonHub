#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int height = (n + w - 1) / w;

    vector<vector<int>> boxes(height, vector<int>(w, 0));

    int row, col;

    for (int i = 1; i <= n; i++) {
        int r = (i - 1) / w;
        int c = (i - 1) % w;

        if (r % 2 == 1) {
            c = w - 1 - c;
        }

        boxes[r][c] = i;

        if (i == num) {
            row = r;
            col = c;
        }
    }

    for (int r = row; r < height; r++) {
        if (boxes[r][col] != 0) {
            answer++;
        }
    }

    return answer;
}