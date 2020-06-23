// BOJ #16637 괄호 추가하기
// 처음에는 DP로 최댓값들만 arr에 저장하면서 풀었다.
// 1+2*3-4 이렇게 있으면 arr[0]은 0번째 까지 최댓값(1), arr[2]은 2번째 인덱스(숫자 2)까지 최댓값(3)
// arr[4]는 최댓값 구할때, max(arr[2]*arr[4], arr[0]*(2*3)) 이런식으로 구함! max(괄호 x, 괄호o) 이렇게 구함.
// 문제는 계속 최댓값만 추적하고 있어서 -20*-9가 최댓값인 180이 되는데,
// 애초에 -20이 최댓값이 아니라 arr에 다른값이 저장되는 문제 가 있었음.
// 결국 set으로 만들어서 나오는 모든 결과값 부르트 포스로 다 확인함 ^-^;
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int N;
set<long long> arr[20];
string equation;

long long calc(long long num1, long long num2, char sign) {
    if (sign == '+') return num1 + num2;
    if (sign == '-') return num1 - num2;
    if (sign == '*') return num1 * num2;
}

int main() {
    cin >> N >> equation;
    if (N == 1) {
        cout << equation;
        return 0;
    }
    arr[0].insert(equation[0] - '0');
    arr[2].insert(calc(equation[0] - '0', equation[2] - '0', equation[1]));
    if (N == 3) {
        cout << *arr[2].begin();
        return 0;
    }

    for (int i = 4; i < N; i += 2) {
        long long bracketSum = calc(equation[i - 2] - '0', equation[i] - '0', equation[i - 1]);
        for (auto elem = arr[i - 4].begin(); elem != arr[i - 4].end(); elem++)
            arr[i].insert(calc(*elem, bracketSum, equation[i - 3]));

        for (auto elem = arr[i - 2].begin(); elem != arr[i - 2].end(); elem++)
            arr[i].insert(calc(*elem, equation[i] - '0', equation[i - 1]));
    }
    cout << *arr[N - 1].rbegin();
}