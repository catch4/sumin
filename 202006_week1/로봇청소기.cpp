#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, d;
};

int n, m;
int map[51][51];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool visit[51][51];

int canMove(int nx, int ny) {
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1)
        return false;
    return true;
}

int bfs(node init) {
    int cnt = 0;
    queue<node> q;
    q.push(init);
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, d = q.front().d;
        if (!visit[x][y]) {
            visit[x][y] = true;
            cnt += 1;
        }
        q.pop();
        bool cleanup = false;
        for (int i = 0; i < 4; i++) {
            d = d - 1 >= 0 ? d - 1 : 3;
            int nx = x + dx[d], ny = y + dy[d];
            if (canMove(nx, ny) && !visit[nx][ny]) {
                q.push({nx, ny, d});
                cleanup = true;
                break;
            }
        }
        if (!cleanup) {
            int nx = x - dx[d], ny = y - dy[d];
            if (canMove(nx, ny)) {
                q.push({nx, ny, d});
                continue;
            }
            break;
        }
    }
    return cnt;
}

int main() {
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);

    cout << bfs({r, c, d});
}