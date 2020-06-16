// boj #14888 연산자 끼워넣기
// dfs를 이용했음.
#include <algorithm>
#include <iostream>
using namespace std;

int N, A[12], sign[4], mini = 2000000000, maxi = -2000000000;

void dfs(int level, int cal) {
    if (level == N - 1) {
        mini = min(mini, cal), maxi = max(maxi, cal);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (sign[i] > 0) {
            sign[i]--;
            if (i == 0) dfs(level + 1, cal + A[level + 1]);
            if (i == 1) dfs(level + 1, cal - A[level + 1]);
            if (i == 2) dfs(level + 1, cal * A[level + 1]);
            if (i == 3) dfs(level + 1, cal / A[level + 1]);
            sign[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> sign[i];
    dfs(0, A[0]);
    printf("%d\n%d\n", maxi, mini);
}