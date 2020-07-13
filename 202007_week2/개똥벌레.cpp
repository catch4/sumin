// BOJ # 3020 개똥벌레
// 석순과 종유석에 대한 각각의 배열을 만들고 길이를 받음.
// 각 배열을 정렬 -> lower bound를 이용해서 부숴질 석순 or 종유순의 개수 구하기

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, h, bottom[100000], top[100000];

int main() {
    scanf("%d %d", &n, &h);
    int len = n / 2;
    for (int i = 0; i < len; i++)
        scanf("%d %d", &bottom[i], &top[i]);

    sort(bottom, bottom + len);
    sort(top, top + len);

    int min_num = 2099999999, min_cnt = 0;
    for (int level = 1; level <= h; level++) {
        int bottom_break = (len) - (lower_bound(bottom, bottom + len, level) - bottom);
        int top_break = (len) - (lower_bound(top, top + len, h - level + 1) - top);
        int breaks = bottom_break + top_break;
        if (breaks < min_num) {
            min_cnt = 1;
            min_num = breaks;
        } else if (breaks == min_num)
            min_cnt++;
    }
    printf("%d %d", min_num, min_cnt);
}