// BOJ #17244 아맞다우산
// 해당 층을 방문했는지를 비트마스크를 사용해서 확인했다.
// 익혀두면 다른 문제 풀때 도움이 많이 될 것 같음.
// 마지막에 탈출조건을 잘못설정해서 런타임에러가 계속 났다 ㅠㅠ

#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, b;
};
int visit[50][50][35], place[50][50], cnt = 0;
string arr[50];
queue<node> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs() {
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, b = q.front().b;

        q.pop();
        if ((arr[x][y] == 'E')) {
            if ((b == (1 << cnt) - 1)) {
                cout << visit[x][y][b] - 1;
                return;
            } else
                continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (arr[nx][ny] == '#') continue;
            if (visit[nx][ny][b]) continue;
            if (arr[nx][ny] == 'X' && !(b & (1 << place[nx][ny]))) {
                int nb = b + (1 << place[nx][ny]);
                q.push({nx, ny, nb});
                visit[nx][ny][nb] = visit[x][y][b] + 1;
            } else {
                q.push({nx, ny, b});
                visit[nx][ny][b] = visit[x][y][b] + 1;
            }
        }
    }
    return;
}

int main() {
    int M, N;
    cin >> N >> M;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'S') {
                q.push({i, j, 0});
                visit[i][j][0] = 1;
            } else if (arr[i][j] == 'X') {
                place[i][j] = cnt;
                cnt++;
            }
        }
    }
    bfs();
}