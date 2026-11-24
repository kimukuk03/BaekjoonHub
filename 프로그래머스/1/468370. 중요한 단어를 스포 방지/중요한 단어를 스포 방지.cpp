#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    int n = message.size();

    // 각 문자의 스포 방지 여부
    vector<bool> spoiler(n, false);

    // 스포 방지 구간 표시
    for (const auto& range : spoiler_ranges) {
        for (int i = range[0]; i <= range[1]; i++) {
            spoiler[i] = true;
        }
    }

    // 일반 단어 저장
    unordered_set<string> normalWords;

    // 스포 방지 단어 저장
    vector<string> spoilerWords;

    int i = 0;

    while (i < n) {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        string word = "";
        bool isSpoiler = false;

        // 공백이 나올 때까지 단어 추출
        while (i < n && message[i] != ' ') {
            word += message[i];

            if (spoiler[i]) {
                isSpoiler = true;
            }

            i++;
        }

        // 단어 분류
        if (isSpoiler) {
            spoilerWords.push_back(word);
        }
        else {
            normalWords.insert(word);
        }
    }

    // 공개된 스포 방지 단어 저장
    unordered_set<string> revealedWords;

    for (const string& word : spoilerWords) {
        // 일반 단어에도 없고 이전에 공개된 적도 없는 경우
        if (normalWords.count(word) == 0 &&
            revealedWords.count(word) == 0) {
            answer++;
        }

        revealedWords.insert(word);
    }

    return answer;
}