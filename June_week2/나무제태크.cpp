#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int N, M, K;
// A는 겨울에 추가할 수 있는 비료의 양, soil은 현재 비료의 양
int A[11][11], soil[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
deque<int> tree[11][11];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    // 비료 입력받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            soil[i][j] = 5;
        }
    // 심은 나무 정보
    int x, y, age;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &age);
        tree[x - 1][y - 1].push_back(age);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sort(tree[i][j].begin(), tree[i][j].end(), cmp);

    for (int year = 0; year < K; year++) {
        // 봄
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bool spring = true;
                for (int k = tree[i][j].size() - 1; k >= 0; k--) {
                    if (soil[i][j] >= tree[i][j][k] && spring) {
                        //봄
                        // 충분히 양분이 있음
                        soil[i][j] -= tree[i][j][k];
                        tree[i][j][k] += 1;
                    } else {
                        spring = false;
                        //여름
                        // 양분 부족함 => dead 에 추가하고 tree리스트에서 삭제
                        soil[i][j] += tree[i][j][k] / 2;
                        tree[i][j].erase(tree[i][j].begin() + k);
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //가을
                for (int k = 0; k < tree[i][j].size(); k++) {
                    if (tree[i][j][k] % 5 != 0) continue;
                    for (int _ = 0; _ < 8; _++) {
                        int nx = i + dx[_], ny = j + dy[_];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        tree[nx][ny].push_back(1);
                    }
                }
                //겨울
                soil[i][j] += A[i][j];
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            answer += tree[i][j].size();
    cout << answer;
}