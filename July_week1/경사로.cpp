// BOJ #14890 경사로
// 중간에 continue안넣어줘서 디버깅하는데 애먹음

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, l, arr[100][100];

bool check(vector<int> v) {
    vector<int> installed(n, 0);
    // 오른쪽으로 가면서 내려가는 경사로 설치
    for (int i = 1; i < n;) {
        if (v[i - 1] == v[i] || v[i - 1] < v[i]) {
            i++;
            continue;
        }
        if (v[i - 1] - v[i] == 1) {
            // 경사로 놓을 수 있는 지 확인
            for (int j = 0; j < l; j++) {
                if (i + j == n || v[i] != v[i + j]) return false;
                installed[i + j] = true;
            }
            i += l;
            continue;
        }
        return false;
    }

    // v를 뒤집고 다시 가면서 내려가는 경사로 설치
    reverse(v.begin(), v.end());
    for (int i = 1; i < n;) {
        if (v[i - 1] == v[i] || v[i - 1] < v[i]) {
            i++;
            continue;
        }
        if (v[i - 1] - v[i] == 1) {
            // 경사로 놓을 수 있는 지 확인
            for (int j = 0; j < l; j++) {
                if (i + j == n || v[i] != v[i + j]) return false;
                if (installed[n - (i + j) - 1]) return false;
                installed[n - (i + j) - 1] = true;
            }
            i += l;
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    cin >> n >> l;
    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        vector<int> tmp1, tmp2;
        for (int j = 0; j < n; j++) {
            // 가로라인
            tmp1.push_back(arr[i][j]);
            // 세로라인
            tmp2.push_back(arr[j][i]);
        }
        answer += check(tmp1);
        answer += check(tmp2);
    }
    cout << answer;
}