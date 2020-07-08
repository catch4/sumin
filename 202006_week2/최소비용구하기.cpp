#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
    int x, cost;
};

int n, m, s, e;
bool visit[1001];
int memo[1001];
map<int, vector<node>> bus;

bool cmp(node a, node b) {
    return a.cost < b.cost;
}

void dfs(int num, int cost) {
    if (num == e)
        return;

    for (auto& elem : bus[num]) {
        int nextCost = cost + elem.cost;
        if (!visit[elem.x] && nextCost < memo[elem.x]) {
            visit[elem.x] = true;
            memo[elem.x] = nextCost;
            dfs(elem.x, nextCost);
            visit[elem.x] = false;
        }
    }
}

int main() {
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        bus[a].push_back({b, c});
    }
    scanf("%d %d", &s, &e);
    for (int i = 0; i < 1001; i++) {
        visit[i] = false;
        memo[i] = 2000000000;
    }
    for (auto it = bus.begin(); it != bus.end(); it++)
        sort(bus[it->first].begin(), bus[it->first].end(), cmp);

    dfs(s, 0);
    printf("%d", memo[e]);
}