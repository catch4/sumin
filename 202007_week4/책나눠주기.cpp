// boj # 9576 책나눠주기
// to로 오름차순 정렬 -> from으로 오름차순 정렬

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int from, to;
};
int T, N, M, a, b, visit[1001], answer;
vector<node> students;

bool cmp(node a, node b) {
    if (a.to == b.to)
        return a.from < b.from;

    return a.to < b.to;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        answer = 0;
        students.clear();
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            students.push_back({a, b});
        }
        sort(students.begin(), students.end(), cmp);

        for (int i = 0; i < M; i++) {
            int from = students[i].from, to = students[i].to;
            for (int j = from; j <= to; j++) {
                if (!visit[j]) {
                    visit[j] = true;
                    answer++;
                    break;
                }
            }
        }
        cout << answer << "\n";
    }
}