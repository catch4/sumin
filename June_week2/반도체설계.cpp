/*
1->4, 2->2, 3->6, 4->3,..이런식으로 이어지는 포트들이 있을 때,
오른쪽의 포트를 기준으로 "오름차순 정렬"하도록 하고, "가장 긴 증가하는 수열"을 찾는 문제로 변경해서 생각함.
*/
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node {
    int from, to;
};

int n, tmp, answer = 0;
vector<node> ports;
vector<int> v = {-100000000};

bool cmp(node a, node b) {
    return a.to < b.to;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ports.push_back({i, tmp});
    }
    sort(ports.begin(), ports.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (v.back() < ports[i].from) {
            v.push_back(ports[i].from);
            answer++;
            continue;
        }
        auto it = lower_bound(v.begin(), v.end(), ports[i].from);
        *it = ports[i].from;
    }
    printf("%d", answer);
}