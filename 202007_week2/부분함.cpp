// BOJ # 1806 부분합
// 부분합이 S 인걸 구하는줄알고 조금 헤맴 ㅠㅠ
// 누적합을 미리 acc배열에 저장해둠. (합을 바로바로 구하기 위해서)
// 이분탐색을 이용해서 가장 짧은 길이를 구함.

#include <algorithm>
#include <iostream>
using namespace std;

int n, s, acc[100000];

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> acc[i];
        if (i > 0) acc[i] += acc[i - 1];
    }
    if (s > acc[n - 1]) printf("0\n"), exit(0);

    int mini = 1, maxi = n, mid;
    while (mini <= maxi) {
        mid = (mini + maxi) / 2;
        bool biggerThanS = false;
        for (int i = mid - 1; i < n; i++) {
            int sum = acc[i] - ((i - mid) < 0 ? 0 : acc[i - mid]);
            if (sum >= s) biggerThanS = true;
        }
        if (biggerThanS)
            maxi = mid - 1;
        else
            mini = mid + 1;
    }
    printf("%d\n", mini);
}