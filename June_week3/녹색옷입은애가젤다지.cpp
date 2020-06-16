// boj # 4485
// 지난주에도 비슷한 문제가 있어서 똑같이 dfs로 풀었는데 시간 초과가 발생했다.
// 다익스트라의 개념을 찾아보니
// 내가 푸는 방식과 똑같은데 다만 길이(비용)가 짧은 것들을 먼저 방문한다는 특징이 있었다.
// 그래서 bfs로 바꿔주고 priority queue를 사용하니 문제가 해결됐다.
// 결론: 다익스트라로 품!

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> p;
int n, arr[125][125], memo[125][125];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs() {
    memo[0][0] = arr[0][0];
    priority_queue<p> pq;
    pq.push({-arr[0][0], {0, 0}});
    while (!pq.empty()) {
        int x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (memo[nx][ny] <= memo[x][y] + arr[nx][ny]) continue;
            memo[nx][ny] = memo[x][y] + arr[nx][ny];
            pq.push({-arr[nx][ny], {nx, ny}});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int t = 1;; t++) {
        cin >> n;
        if (n == 0) return 0;

        memset(memo, 999999, sizeof(memo));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        bfs();
        cout << "Problem " << t << ": " << memo[n - 1][n - 1] << endl;
    }
}