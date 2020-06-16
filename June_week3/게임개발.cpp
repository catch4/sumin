// boj # 1516 게임개발
// 위상 정렬 개념을 공부하고 푼 문제
// 계속 런타임에러가 발생했는데, 혹시나하고 auto를 지우니까 문제가 해결됐다

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, tmp, time[501], inDegree[501], result[501];
vector<int> arr[501];
queue<int> q;

void topologySort() {
    // pair<숫자, 누적 시간>
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (q.empty()) return;  // 순환 생김
        int x = q.front();
        q.pop();
        for (int j = 0; j < arr[x].size(); j++) {
            int elem = arr[x][j];
            inDegree[elem]--;
            result[elem] = max(result[x] + time[elem], result[elem]);
            if (inDegree[elem] == 0)
                q.push(elem);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        int j = 0;
        for (;; j++) {
            cin >> tmp;
            if (tmp == -1) break;
            arr[tmp].push_back(i);
        }
        inDegree[i] = j;
    }
    topologySort();
    for (int i = 1; i <= n; i++)
        cout << result[i] << endl;
}