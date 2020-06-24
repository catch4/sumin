// BOJ #2178 미로탐색
// 아주 전형적인 bfs 문제.
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, cnt;
};
int N, M, visit[100][100];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string arr[100];

int bfs() {
    queue<node> q;
    q.push({0, 0, 1});
    visit[0][0] = true;

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        q.pop();
        if (x == N - 1 && y == M - 1) return cnt;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!visit[nx][ny] && arr[nx][ny] == '1') {
                q.push({nx, ny, cnt + 1});
                visit[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << bfs() << endl;
}