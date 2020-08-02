// boj 1507 궁금한 민호
// 불가능한 경우를 고려하지 못했음.
// 1. 한 도시에서 다른 도시로 갈수 있는 경우를 cityDistance에 담았다.
//    (단, a->b, b->a 중 하나만  담음)
// 2. cityDistance를 시간 가장 짧은 순으로 정렬. 시간이 가장 짧은 것부터 하나씩 길을 만들어감.
// 3. a->b로 이동할 수 있는 가장 짧은 길(curDist)을 찾는다.
//    아래 세 가지 경우의 수가 생김
//    1) curDist가 직통 길보다 길다. => 그럼 a->b사이에 길을 놔줘야함.
//    2) curDist가 직통 길과 길이가 같다. => 길을 안 놔줘도 됨.
//    3) curDist가 직통 길보다 작다. => 불가능한 경우이므로 -1리턴하고 끝냄.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 9999999
struct city {
  int city1, city2, dist;
  bool operator<(const city &t) const {
    return dist > t.dist;
  }
};
int N, cities[20][20], route[20][20], visit[20][20];
vector<city> cityDistance;

bool cmp(city a, city b) {
  return a.dist < b.dist;
}

int bfs(int from, int to) {
  priority_queue<city> q;
  memset(visit, 0, sizeof(visit));
  for (int i = 0; i < N; i++) {
    int dist = route[from][i];
    if (dist == INF) continue;
    q.push({from, i, dist});
    visit[from][i] = true, visit[i][from] = true;
  }

  while (!q.empty()) {
    int city1 = q.top().city1, city2 = q.top().city2, dist = q.top().dist;
    q.pop();
    if (city2 == to) return dist;

    for (int i = 0; i < N; i++) {
      if (route[city2][i] == INF) continue;
      if (visit[city2][i]) continue;
      q.push({city2, i, dist + route[city2][i]});
      visit[city2][i] = true, visit[i][city2] = true;
    }
  }
  return INF;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &cities[i][j]);
      route[i][j] = INF;
      if (i < j) cityDistance.push_back({i, j, cities[i][j]});  //1.
    }

  sort(cityDistance.begin(), cityDistance.end(), cmp);  //2.

  for (auto elem : cityDistance) {
    int city1 = elem.city1, city2 = elem.city2, dist = elem.dist;
    int curDist = bfs(city1, city2);  // 3.
    if (dist < curDist) route[city1][city2] = dist, route[city2][city1] = dist;
    if (dist > curDist) {
      printf("-1\n");
      return 0;
    };
  }

  int answer = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) answer += (route[i][j] == INF ? 0 : route[i][j]);
  printf("%d", answer);
}