// boj # 6593 상범빌딩
// bfs로 풀면 됨. (출력형식때문에 애먹음 ㅠㅠ)
// 0. building 배열에 입력정보를 넣으면서 시작지점을 init에 담고, 목적지를 target변수에 저장.
// 1. 동,서,남,북,상,하 로 가는 경우를 고려
// 2. 1에서 다음과 같은 경우는 제외하고 나머지는 queue에 넣어줌.
//    - 빌딩을 벗어나는 경우
//    - 이미 해당 자리를 방문한 경우
//    - 해당 위치에 벽(#)이 있는 경우
// 3. 계속 queue에 넣으면서 목적지(target)에 도착하면 bfs종료.
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int z, x, y;
};

// building[층][x][y]
char building[30][30][30];
int visit[30][30][30];
int dx[6] = {0, 0, 1, -1, 0, 0}, dy[6] = {0, 0, 0, 0, 1, -1}, dz[6] = {1, -1, 0, 0, 0, 0};
int L, R, C;
node target;
queue<node> q;

void bfs() {
  while (!q.empty()) {
    int z = q.front().z, x = q.front().x, y = q.front().y;
    int cnt = visit[z][x][y];
    q.pop();
    if (x == target.x && y == target.y && z == target.z) {
      printf("Escaped in %d minute(s).\n", cnt - 1);
      return;
    }
    for (int i = 0; i < 6; i++) {
      int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
      if (visit[nz][nx][ny] || (building[nz][nx][ny] == '#')) continue;
      q.push({nz, nx, ny});
      visit[nz][nx][ny] = cnt + 1;
    }
  }
  printf("Trapped!\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;

  while (true) {
    memset(visit, 0, sizeof(visit));
    queue<node> empty;
    swap(q, empty);

    cin >> L >> R >> C;
    if (!(L || R || C)) return 0;
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < R; j++) {
        cin >> line;
        for (int k = 0; k < C; k++) {
          building[i][j][k] = line[k];
          if (building[i][j][k] == 'S') {
            q.push({i, j, k});
            visit[i][j][k] = 1;
          } else if (building[i][j][k] == 'E')
            target = {i, j, k};
        }
      }
    }

    bfs();
  }
}