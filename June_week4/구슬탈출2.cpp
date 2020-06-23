// BOJ # 13460 구슬탈출 2
// 이전에 풀어본 적이 있어서 어렵지 않게 풀었음.
// bfs를 이용하고 움직이는 주체가 두개다보니 visit배열을 4차원으로 만드는게 포인트인듯!

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int rx, ry, bx, by;
};

int N, M;
char arr[11][11];
bool visit[11][11][11][11];  //rx,ry,bx,by
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<node, int>> q;

pair<node, pair<int, int>> move(int direction, node cur) {
    int rx = cur.rx, ry = cur.ry, bx = cur.bx, by = cur.by;
    int i, j;
    // 빨간 구슬 움직이기
    for (i = 0;; i++) {
        int nrx = rx + dx[direction], nry = ry + dy[direction];
        if (arr[nrx][nry] == '#') break;
        rx = nrx, ry = nry;
        if (arr[nrx][nry] == 'O') break;
    }
    // 파란 구슬 움직이기
    // 빨간 구슬 움직이기
    for (j = 0;; j++) {
        int nbx = bx + dx[direction], nby = by + dy[direction];
        if (arr[nbx][nby] == '#') break;
        bx = nbx, by = nby;
        if (arr[nbx][nby] == 'O') break;
    }
    return {{rx, ry, bx, by}, {i, j}};
}

int bfs() {
    while (!q.empty()) {
        node curPosition = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > 10) return -1;
        if (arr[curPosition.bx][curPosition.by] == 'O') continue;
        if (arr[curPosition.rx][curPosition.ry] == 'O') return cnt;
        for (int i = 0; i < 4; i++) {
            pair<node, pair<int, int>> res = move(i, curPosition);
            node nextPos = res.first;
            int rcnt = res.second.first, bcnt = res.second.second;
            int nrx = nextPos.rx, nry = nextPos.ry, nbx = nextPos.bx, nby = nextPos.by;
            if (nrx == nbx && nry == nby) {
                // 둘다 구멍에 들어온 경우 답이 안되므로 패스
                if (arr[nrx][nry] == 'O')
                    continue;
                else {
                    // 짧게 움직인 애가 더 앞에 있어야 함.
                    if (rcnt < bcnt)
                        nbx -= dx[i], nby -= dy[i];
                    else
                        nrx -= dx[i], nry -= dy[i];
                }
            }
            if (!visit[nrx][nry][nbx][nby]) {
                q.push({{nrx, nry, nbx, nby}, cnt + 1});
                visit[nrx][nry][nbx][nby] = true;
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    string line;
    pair<int, int> red, blue;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            arr[i][j] = line[j];
            if (arr[i][j] == 'R')
                red = {i, j};
            else if (arr[i][j] == 'B')
                blue = {i, j};
        }
    }
    q.push({{red.first, red.second, blue.first, blue.second}, 0});
    visit[red.first][red.second][blue.first][blue.second] = true;
    cout << bfs();
}