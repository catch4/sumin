// pro #12913 땅따먹기
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land) {
    int dp[100000][4], answer = 0;
    int pick[4][3] = {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}};

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 4; i++) dp[0][i] = land[0][i];
    for (int i = 1; i < land.size(); i++)
        for (int j = 0; j < 4; j++)
            dp[i][j] = land[i][j] + max({dp[i - 1][pick[j][0]], dp[i - 1][pick[j][1]], dp[i - 1][pick[j][2]]});

    for (int i = 0; i < 4; i++)
        answer = max(answer, dp[land.size() - 1][i]);

    return answer;
}

int main() {
    cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}});
}