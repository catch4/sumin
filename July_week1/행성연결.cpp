// BOJ # 16398 행성연결
// 거리가 짧은 순으로 정렬 후, union find로 부모가 같지 않다면 플로우 설치
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int x, y, cost;
};
int n, tmp, parents[1000];
vector<node> cost;

bool cmp(node a, node b) {
    return a.cost < b.cost;
}

int find(int x) {
    if (x == parents[x]) return x;
    int p = find(parents[x]);
    parents[x] = p;
    return p;
}

void unions(int x, int y) {
    x = find(x);
    y = find(y);
    parents[y] = x;
}

int main() {
    long long answer = 0;
    int lineCnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (i < j) cost.push_back({i, j, tmp});
        }
    }
    for (int i = 0; i < n; i++) parents[i] = i;
    sort(cost.begin(), cost.end(), cmp);
    for (auto elem : cost) {
        if (lineCnt == n - 1) break;
        if (find(elem.x) == find(elem.y)) continue;
        unions(elem.x, elem.y);
        answer += elem.cost;
        lineCnt++;
    }
    cout << answer;
}