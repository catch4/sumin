#include <iostream>
#include <queue>
#include <string>

using namespace std;

string answer = "0";
string numList = "0123456789ABCDEF";
int maxLen = 0;

string getString(char x) {
    string s(1, x);

    return s;
}

void bfs(int n) {
    queue<string> q;
    for (int i = 1; i < n; i++)
        q.push(getString(numList[i]));

    while (!q.empty()) {
        string f = q.front();
        q.pop();
        answer += f;
        if (answer.length() >= maxLen) {
            return;
        }
        for (int i = 0; i < n; i++)
            q.push(f + numList[i]);
    }
}

string solution(int n, int t, int m, int p) {
    // 0은 처음에는 빼주고 시작. (0으로 시작하는 숫자는 없기 때문. ex 01, 001 ...) => 마지막에 맨 앞에 추가
    maxLen = m * t;
    bfs(n);

    string result = "";
    for (int i = 0; i < t; i++) {
        int turn = (p - 1) + m * i;
        result += answer[turn];
    }
    return result;
}

int main() {
    cout << solution(16, 16, 2, 2);
}