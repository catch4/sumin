// boj # 2151 거울설치
// bfs로 순차적으로 풀되, queue대신 priority_queue를 사용해서 거울 개수가 적은 것 부터 우선적으로 계산.
#include <iostream>
#include <queue>
using namespace std;

struct node {
    // d: direction
    int d, x, y, cnt;
    bool operator<(const node &t) const {
        return cnt > t.cnt;
    }
};

int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string arr[50];
node init, target;

void bfs() {
    priority_queue<node> q;
    for (int i = 0; i < 4; i++) q.push({i, init.x, init.y, 0});

    while (!q.empty()) {
        int d = q.top().d, x = q.top().x, y = q.top().y, cnt = q.top().cnt;
        q.pop();
        if (x == target.x && y == target.y) {
            printf("%d\n", cnt);
            return;
        }
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[nx][ny] == '*') continue;

        // 거울이 없는 경우
        q.push({d, nx, ny, cnt});

        // 거울이 있는 경우
        if (arr[nx][ny] == '!') {
            q.push({(d + 1) % 4, nx, ny, cnt + 1});
            q.push({(d + 3) % 4, nx, ny, cnt + 1});
        }
    }
}

int main() {
    cin >> n;
    int doorCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < n; j++)
            if (arr[i][j] == '#') {
                if (doorCnt == 0)
                    init = {0, i, j, 0}, doorCnt++;
                else
                    target = {0, i, j, 0};
            }
    }
    bfs();
}