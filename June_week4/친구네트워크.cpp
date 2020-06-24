// BOJ # 4195 친구 네트워크
// union find의 대표적인 문제.
// 예전에 Python으로 풀었을 때는 시간초과 문제가 없었는데 c++이 더 빡센거 같다 ㅠㅠ
// c++에선 map이 확실히 느린듯..!! (map을 많이 써야되는 경우에는 python으로 풀어보기!!)
// => 결국 map 대신 string들을 각각 임의의 숫자로 변경 후 배열을 이용해서 풀었다.
// 그리고 endl은 절대 쓰지 말기 😭 (시간 초과 주범이었음..)
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int parent[200010], cnt[200010];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x, cnt[x] += cnt[y];
    return cnt[x];
}

int main() {
    int T, F;
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> F;
        map<string, int> m;
        int ct = 1;
        for (int i = 1; i <= 2 * F; i++) parent[i] = i, cnt[i] = 1;
        for (int i = 0; i < F; i++) {
            string f1, f2;
            cin >> f1 >> f2;
            if (m.count(f1) == 0) m[f1] = ct++;
            if (m.count(f2) == 0) m[f2] = ct++;
            cout << uni(m[f1], m[f2]) << '\n';
        }
    }
}