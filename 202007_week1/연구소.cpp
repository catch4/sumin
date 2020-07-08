// BOJ # 14502 연구소
// dfs를 이용해서 벽을 세우고, bfs를 이용해서 안전 영역 구함.

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y;
};
int N, M, arr[8][8], safeArea, answer = 0;
bool visit[8][8];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<node> virusInit;

void getSafeArea() {
    queue<node> q;
    int virusArea = 0;
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < virusInit.size(); i++) q.push(virusInit[i]);
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        virusArea++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (arr[nx][ny] != 0 || visit[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    int leftArea = safeArea - virusArea;
    answer = answer > leftArea ? answer : leftArea;
}

void makeWall(int cnt, int depth, int x, int y) {
    if (cnt == 3) {
        getSafeArea();
        return;
    }

    for (int i = x; i < N; i++, y = 0) {
        for (int j = y; j < M; j++) {
            if (arr[i][j] != 0) continue;
            arr[i][j] = 1;
            makeWall(cnt + 1, depth + 1, i, j + 1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    safeArea = -3;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virusInit.push_back({i, j});
                safeArea++;
            }
            if (arr[i][j] == 0) safeArea++;
        }

    makeWall(0, 0, 0, 0);
    cout << answer;
}