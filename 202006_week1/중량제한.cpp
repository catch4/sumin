#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, weight;
};

int n, m;
map<int, vector<node>> islands;
bool visit[20001];

bool bfs(int limit, int start, int end) {
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == end)
            return true;

        for (auto elem : islands[x])
            if (!visit[elem.x] && elem.weight >= limit) {
                visit[elem.x] = true;
                q.push(elem.x);
            }
    }
    return false;
}

int main() {
    int start, end, mini = 0, maxi = 1000000000;
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        islands[a].push_back({b, c});
        islands[b].push_back({a, c});
    }
    cin >> start >> end;

    int mid = 0;
    while (mini <= maxi) {
        mid = (mini + maxi) / 2;
        memset(visit, false, sizeof(visit));
        if (bfs(mid, start, end))
            mini = mid + 1;
        else
            maxi = mid - 1;
    }

    cout << maxi;
}