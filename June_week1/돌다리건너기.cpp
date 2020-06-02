#include <cstring>
#include <iostream>
using namespace std;

string target;
string roads[2];
int memo[2][101][21];
int targetLen, roadsLen;

/*
line: 0->devil road/ 1->angel road
idx: current index in road
level: index for target (ex level==0 means 'R' in RGS)
*/
int dfs(int line, int idx, int level) {
    if (level == targetLen) return 1;
    if (idx >= roadsLen) return 0;
    int &count = memo[line][idx][level];
    if (count != -1) return count;
    count = 0;
    for (int i = idx; i < roadsLen; i++)
        if (roads[line][i] == target[level])
            count += dfs(line == 0 ? 1 : 0, i + 1, level + 1);
    return count;
}

int main() {
    cin >> target;
    cin >> roads[0];
    cin >> roads[1];
    targetLen = target.length();
    roadsLen = roads[0].length();

    memset(memo, -1, sizeof(memo));
    printf("%d", dfs(0, 0, 0) + dfs(1, 0, 0));
}