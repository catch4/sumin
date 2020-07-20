// BOJ #16236 아기상어
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int d, x, y;
    bool operator<(const node &t) const {
        if (d == t.d) {
            if (x == t.x)
                return y > t.y;
            else
                return x > t.x;
        }
        return d > t.d;
    }
};

int n, arr[20][20], time, fishSize = 2;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
bool visit[20][20];

node findNextFish(node init) {
    priority_queue<node> q;
    memset(visit, false, sizeof(visit));
    q.push({0, init.x, init.y});
    visit[init.x][init.y] = true;
    while (!q.empty()) {
        int d = q.top().d, x = q.top().x, y = q.top().y;
        q.pop();
        if (arr[x][y] < fishSize && arr[x][y] != 0) {
            time += d;
            arr[x][y] = 0;
            return {0, x, y};
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] > fishSize) continue;
            if (visit[nx][ny]) continue;
            q.push({d + 1, nx, ny});
            visit[nx][ny] = true;
        }
    }
    return {0, -1, -1};
}

void solution(node init) {
    node currentFish = init;
    while (true) {
        for (int i = 0; i < fishSize; i++) {
            node nextFish = findNextFish(currentFish);
            if (nextFish.x == -1 && nextFish.y == -1) return;
            currentFish = nextFish;
        }
        fishSize++;
    }
}

int main() {
    cin >> n;
    node init;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) arr[i][j] = 0, init = {0, i, j};
        }
    }
    solution(init);
    cout << time << endl;
}