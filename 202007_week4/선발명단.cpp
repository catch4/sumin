// boj 3980 선발명단
// dfs로 품
#include <cstring>
#include <iostream>
using namespace std;

int t, m[11][11], visit[11], answer = 0;

void dfs(int level, int sum) {
    if (level == 11) {
        answer = sum > answer ? sum : answer;
        return;
    }
    for (int i = 0; i < 11; i++) {
        if (!visit[i] && m[i][level] > 0) {
            visit[i] = true;
            dfs(level + 1, sum + m[i][level]);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(visit, 0, sizeof(visit));
        memset(m, 0, sizeof(m));
        answer = 0;
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                scanf("%d", &m[i][j]);

        dfs(0, 0);
        cout << answer << endl;
    }
}