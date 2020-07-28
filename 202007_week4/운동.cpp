// boj # 1956 운동
// 플로이드 와샬 알고리즘.
#include <algorithm>
#include <iostream>
using namespace std;

#define INF 99999999
int V, E, route[400][400];

int main() {
    cin >> V >> E;
    int from, to, d, answer = INF;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) route[i][j] = INF;

    for (int i = 0; i < E; i++) {
        cin >> from >> to >> d;
        from--, to--;
        route[from][to] = d;
    }

    for (int pivot = 0; pivot < V; pivot++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                route[i][j] = min(route[i][j], route[i][pivot] + route[pivot][j]);

    for (int i = 0; i < V; i++)
        answer = min(answer, route[i][i]);

    cout << ((answer >= INF) ? (-1) : answer);
}