#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// arr[i]에는 A,B,C가 순서대로 들어감
long long arr[20001][3];
int n;

// 해당 숫자까지의 누적 합 계산
long long acc(long long mid) {
    long long accVal = 0;
    for (int i = 0; i < n; i++)
        if (mid >= arr[i][0])
            accVal += (min(arr[i][2], mid) - arr[i][0]) / arr[i][1] + 1;
    return accVal;
}

int main() {
    long long inf = 9999999999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[i][0], &arr[i][2], &arr[i][1]);

    long long min = 1, max = inf;
    while (min <= max) {
        long long mid = (min + max) / 2;
        long long accVal = acc(mid);
        if (accVal % 2)
            max = mid - 1;
        else
            min = mid + 1;
    }
    if (max == inf) {
        cout << "NOTHING" << endl;
        return 0;
    }
    cout << min << ' ' << acc(min) - acc(min - 1) << endl;
}