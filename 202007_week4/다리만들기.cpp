// boj # 2146 다리만들기
// 1. 같은 나라끼리 같은 숫자를 가지도록 설정 (makeCountry)
// 2. 땅이 있는 곳에서 다리 만들기 시도하며 가장 짧은 다리를 구함.
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define INF 9999999
struct node {
    int x, y;
};
int N, arr[101][101], visit[101][101], answer = INF;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void makeCountry(int init_x, int init_y, int num) {
    queue<node> q;
    q.push({init_x, init_y});
    arr[init_x][init_y] = num;

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (arr[nx][ny] != 1) continue;
            q.push({nx, ny});
            arr[nx][ny] = num;
        }
    }
}

int makeBridge(int init_x, int init_y) {
    queue<node> q;
    q.push({init_x, init_y});
    visit[init_x][init_y] = 1;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        if (arr[x][y] != arr[init_x][init_y] && arr[x][y] != 0) return visit[x][y] - 2;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny]) continue;
            if (arr[nx][ny] == arr[init_x][init_y]) continue;
            q.push({nx, ny});
            visit[nx][ny] = visit[x][y] + 1;
        }
    }
    return INF;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int countryNum = 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                makeCountry(i, j, countryNum);
                countryNum++;
            }
        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) continue;
            memset(visit, 0, sizeof(visit));
            answer = min(answer, makeBridge(i, j));
        }
    }

    cout << answer;
}