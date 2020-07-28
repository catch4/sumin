#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define STRAIGHT 100
#define CORNER 500
using namespace std;

struct node {
  //direction - 0(수평) 1(수직)
  int x, y, cost, direction;
  //   bool operator<(const node &t) const {
  //     return cost > t.cost;
  //   }
};

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool visit[25][25];
int N, answer;

void bfs(vector<vector<int>> &board) {
  queue<node> pq;
  for (int i = 0; i < 4; i++) {
    pq.push({0, 0, STRAIGHT, i});
  }
  while (!pq.empty()) {
    int x = pq.front().x, y = pq.front().y, cost = pq.front().cost, direction = pq.front().direction;
    pq.pop();
    if (x == N - 1 && y == N - 1) {
      answer = min(cost, answer);
      printf("%d\n", cost);

      return;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      int ncost = cost + ((i % 2 == direction % 2) ? STRAIGHT : CORNER + STRAIGHT);
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (board[nx][ny] == 1) continue;
      if (visit[nx][ny]) continue;
      if (ncost >= answer) continue;

      pq.push({nx, ny, ncost, i});
    }
  }
}

int solution(vector<vector<int>> board) {
  answer = 999999999;
  N = board.size();
  memset(visit, false, sizeof(visit));
  bfs(board);
  return answer - 100;
}

int main() {
  cout << solution(
      {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}});
}