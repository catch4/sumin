// programmers # 64062 징검다리 건너기 solve
// 이분탐색을 이용했음
// 문제는 제대로 풀었지만, k만큼 비어도 건널수있다고 잘못이해해서 애먹음 ㅠ^ㅠ
// 입출력 예제로 나온 건 모두 꼼꼼하게 읽기!!!
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0, mid;
    int mini = *min_element(stones.begin(), stones.end());
    int maxi = *max_element(stones.begin(), stones.end());
    while (mini <= maxi) {
        mid = (mini + maxi) / 2;

        // mid 명이 건넌다고 했을 때, 가장 긴 연속된 빈 징검다리 개수 구하기
        int maxLen = 0, cnt = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= mid)
                cnt++;
            else {
                maxLen = max(cnt, maxLen);
                cnt = 0;
            }
        }
        maxLen = max(cnt, maxLen);
        if (maxLen >= k)
            maxi = mid - 1;
        else
            mini = mid + 1;
    }
    return maxi;
}

int main() {
    cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 6);
}