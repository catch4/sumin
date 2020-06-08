#include <stdlib.h>

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<set<int>> v;

int getContinuousNum(int n, int repeat) {
    string res = "";
    for (int i = 0; i < repeat; i++) res += (n + '0');
    return atoi(res.c_str());
}

int solution(int N, int number) {
    int answer = -1;
    for (int i = 1; i <= 8; i++)
        v.push_back({getContinuousNum(N, i)});

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (const auto& num1 : v[j]) {
                for (const auto& num2 : v[i - j - 1]) {
                    v[i].insert(num1 + num2);
                    v[i].insert(num1 - num2);
                    v[i].insert(num1 * num2);
                    if (num2 != 0) v[i].insert(num1 / num2);
                }
            }
        }
        if (v[i].find(number) != v[i].end()) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

int main() {
    cout << solution(2, 11);
}