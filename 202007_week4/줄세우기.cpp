// boj # 2252 줄세우기
// 위상정렬로 품.
// topology(자기를 가리키고 있는 노드의 개수)가 0인 것을 queue에 넣으면서 진행.
#include <iostream>
#include <queue>
using namespace std;

int N, M, topology[32001];
vector<int> students[32001];
queue<int> q;

int main() {
    cin >> N >> M;
    int first, second;
    for (int i = 0; i < M; i++) {
        cin >> first >> second;
        students[first].push_back(second);
        topology[second] += 1;
    }

    for (int i = 1; i <= N; i++) {
        if (topology[i] == 0) q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for (auto elem : students[x]) {
            topology[elem]--;
            if (topology[elem] == 0) q.push(elem);
        }
    }
}