// boj # 7453 합이 0인 네 정수 (unsolved)
// 시간초과와 메모리 초과 발생.
// 처음에는 a,b열 c,d열을 짝지어 미리 계산해두는 방식으로 했는데 그러면 메모리 초과
// 결국 c,d열만 미리 계산해두고 a,b는 실시간으로 계산하며 확인하는 방식으로 해결
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
int arr[4001][4], n;
long long answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v.push_back((long long)(arr[i][2] + arr[j][3]));
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            long long tmp = arr[i][0] + arr[j][1];
            long long lower = lower_bound(v.begin(), v.end(), -tmp) - v.begin();
            long long upper = upper_bound(v.begin(), v.end(), -tmp) - v.begin();
            if (v[lower] == -tmp)
                answer += upper - lower;
        }

    cout << answer << endl;
}