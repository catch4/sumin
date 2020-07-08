// boj # 17822 원판 돌리기 (solved)
// 전형적인 시뮬레이션 문제! 어렵지는 않았지만 런타임 에러를 찾는 데 애먹었다.
// 런타임 에러 이유: int 함수 선언해놓고 리턴하지 않음
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
using namespace std;

int N, M, T;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
deque<int> board[51];
bool candidate[51][51];

void rotate(int x, int d, int k) {
    int tmp;
    for (int i = x; i <= N; i += x) {
        if (d == 0)  // 시계방향 회전
            for (int j = 0; j < k; j++) {
                tmp = board[i].back();
                board[i].pop_back();
                board[i].push_front(tmp);
            }
        else  // 반시계방향 회전
            for (int j = 0; j < k; j++) {
                tmp = board[i].front();
                board[i].pop_front();
                board[i].push_back(tmp);
            }
    }
}

bool checkAdjacent() {
    bool hasAdjacent = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 1 || nx > N) continue;
                // 링의 첫 번째 숫자랑 M번째 숫자가 맞닿는 경우
                if (ny < 0) ny = M - 1;
                if (ny == M) ny = 0;
                // 숫자가 같다면 지울 후보에 적어주기.
                if (!candidate[nx][ny] && board[i][j] == board[nx][ny]) {
                    candidate[nx][ny] = true;
                    candidate[i][j] = true;
                    hasAdjacent = true;
                }
            }
        }
    }
    return hasAdjacent;
}

void removeAdjacent() {
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            if (candidate[i][j])
                board[i][j] = 0;
}

void adjustNum() {
    int sum = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                sum += board[i][j];
                cnt += 1;
            }
        }
    }
    if (cnt == 0) return;
    double avg = (double)sum / (double)cnt;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                if ((double)board[i][j] > avg)
                    board[i][j] -= 1;
                else if ((double)board[i][j] < avg)
                    board[i][j] += 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp, x, d, k, answer = 0;
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++) {
            cin >> tmp;
            board[i].push_back(tmp);
        }
    while (T--) {
        cin >> x >> d >> k;
        memset(candidate, false, sizeof(candidate));
        rotate(x, d, k);
        if (checkAdjacent())
            removeAdjacent();
        else
            adjustNum();
    }
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            answer += board[i][j];

    cout << answer;
}