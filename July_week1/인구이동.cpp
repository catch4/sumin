// BOJ #16234 인구이동
// bfs를 이용해서 품

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y;
};

// arr[x][y][door]
// door은 각각 인구수(0),위(1),오른쪽(2),아래(3),왼쪽(4) 값을 가지며 1은 열려있는 경우 0은 닫힌 경우
int n, l, r, arr[50][50][5];
int visit[50][50];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void openDoor() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int diff;
            // 옆에 나라 확인
            if (j + 1 != n) {
                diff = abs(arr[i][j][0] - arr[i][j + 1][0]);
                if (diff >= l && diff <= r) {
                    arr[i][j][2] = 1;
                    arr[i][j + 1][4] = 1;
                }
            }
            // 아래 나라 확인
            if (i + 1 != n) {
                diff = abs(arr[i][j][0] - arr[i + 1][j][0]);
                if (diff >= l && diff <= r) {
                    arr[i][j][3] = 1;
                    arr[i + 1][j][1] = 1;
                }
            }
        }
    }
}

void closeDoor() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 1; k < 5; k++)
                arr[i][j][k] = 0;
}

bool move() {
    int moveCnt = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) continue;
            // bfs(이동하기)
            queue<node> q;
            vector<node> unioned;
            q.push({i, j});
            visit[i][j] = 1;
            while (!q.empty()) {
                int x = q.front().x, y = q.front().y;
                unioned.push_back({x, y});
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (arr[x][y][i + 1] == 0 || visit[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
            if (unioned.size() == 1) continue;
            moveCnt++;
            // 한 union의 합 구하기
            int acc = 0;
            for (auto elem : unioned) acc += arr[elem.x][elem.y][0];
            // 인구 균일하게 만들기
            int nextPopulations = acc / unioned.size();
            for (auto elem : unioned) arr[elem.x][elem.y][0] = nextPopulations;
        }
    }
    // 인구이동이 일어나지 않으면 false, 일어나면 true
    return moveCnt == 0 ? false : true;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j][0];

    int answer = 0;
    while (true) {
        closeDoor();
        openDoor();
        bool moved = move();
        if (!moved) break;
        answer++;
    }
    cout << answer;
}