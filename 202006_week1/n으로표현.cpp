// PRO # 42895 n으로 표현
// 아이디어를 생각하는게 어려웠지, 구현은 어렵지 않았다.
// 비슷한 유형의 문제가 나오면 떠올려서 풀면 좋을 듯

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<int> arr[9];

int makeNum(int N, int iter) {
    int res = 0;
    for (int i = 0; i < iter; i++) {
        res += N;
        N *= 10;
    }
    return res;
}

int solution(int N, int number) {
    if (N == number) return 1;
    for (int i = 1; i <= 8; i++) {
        arr[i].insert(makeNum(N, i));
        for (int j = 1; j <= i / 2; j++) {
            int a = j, b = i - j;
            for (auto it1 = arr[a].begin(); it1 != arr[a].end(); ++it1) {
                for (auto it2 = arr[b].begin(); it2 != arr[b].end(); ++it2) {
                    int num1 = *it1, num2 = *it2;
                    arr[i].insert(num1 + num2);
                    arr[i].insert(num1 - num2);
                    arr[i].insert(num2 - num1);
                    arr[i].insert(num1 * num2);
                    if (num2 != 0) arr[i].insert(num1 / num2);
                    if (num1 != 0) arr[i].insert(num2 / num1);
                }
            }
        }
        for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
            if (*it == number) return i;
        }
    }
    return -1;
}

int main() {
    cout << solution(2, 11);
}