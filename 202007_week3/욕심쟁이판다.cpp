// boj # 1937 욕심쟁이 판다
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, forest[500][500], memo[500][500];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (memo[x][y]) return memo[x][y];

    memo[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (forest[nx][ny] <= forest[x][y]) continue;

        memo[x][y] = max(memo[x][y], dfs(nx, ny) + 1);
    }

    return memo[x][y];
}

void solution() {
    int answer = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) answer = max(answer, dfs(i, j));

    printf("%d\n", answer);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &forest[i][j]);

    solution();
}