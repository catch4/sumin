// boj 1# 2014 소수의 곱
// pq를 이용해서 계속 가장 작은 수들을 소수 리스트(arr)와 곱해주며 값을 넣어감.
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

int K, N, arr[100];
ll maxVal = 0;
map<int, int> visit;

int main() {
    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> arr[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(1);

    for (int i = 0; i < N; i++) {
        ll num = pq.top();
        pq.pop();
        for (int i = 0; i < K; i++) {
            ll nextNum = num * arr[i];
            if (pq.size() > N && nextNum > maxVal) continue;

            if (!visit.count(nextNum)) {
                maxVal = max(maxVal, nextNum);
                visit[nextNum] = true;
                pq.push(nextNum);
            }
        }
    }
    cout << pq.top() << "\n";
}