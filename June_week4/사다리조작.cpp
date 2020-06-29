// BOJ 15684 사다리 조작
// 처음에 다리를 놓아서 조건이 만족했는지 확인하는 부분을 bfs로 푸려고했다.
// 다리를 놓는 부분은 dfs로 풀었는데 잘못풀고있었다. for문에서 y=0으로 초기화해주는 부분을 처음 알게되어서 이걸 적용했다면 제대로 풀었을것같기도 하다 😂

#include <cstdio>
#include <iostream>
using namespace std;

int N, M, H, arr[30][10], ans = 4;

bool ladder() {
    for (int i = 0; i < N; i++) {
        int k = i;
        for (int j = 0; j < H; j++) {
            if (arr[j][k])
                k += 1;
            else if (k > 0 && arr[j][k - 1])
                k -= 1;
        }
        if (i != k) return false;
    }
    return true;
}

void solve(int cnt, int x, int y) {
    if (ans <= cnt) return;
    if (ladder()) {
        if (ans > cnt) ans = cnt;
        return;
    }
    if (cnt == 3) return;
    for (int i = x; i < H; i++, y = 0) {
        for (int j = y; j < N - 1; j++) {
            if (arr[i][j])
                j++;
            else {
                arr[i][j] = 1;
                // 바로 옆에는 다리를 놓으면 안됨.
                solve(cnt + 1, i, j + 2);
                arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M >> H;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
    }
    solve(0, 0, 0);
    cout << ((ans < 4) ? ans : -1);
}