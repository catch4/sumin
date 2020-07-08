// BOJ # 2110 공유기 설치
// 전형적인 이분탐색 문제
// 공유기 설치 가능한 거리를 이분탐색으로 찾아감.
// 하나의 거리를 가정했다면, 그 때 설치 가능한 개수가 몇개인지 판단하고 C와 비교해서 다음 작업 수행.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, C, tmp, mini = 1, maxi = 1000000000, mid;
    vector<int> v;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> tmp, v.push_back(tmp);

    sort(v.begin(), v.end());
    while (mini <= maxi) {
        mid = (mini + maxi) / 2;
        int nextPossible = -1, cnt = 0;
        for (int i = 0; i < N; i++)
            if (nextPossible <= v[i])
                nextPossible = v[i] + mid, cnt++;

        if (cnt >= C)
            mini = mid + 1;
        else
            maxi = mid - 1;
    }
    cout << maxi << endl;
}