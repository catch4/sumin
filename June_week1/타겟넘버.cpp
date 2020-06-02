#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> numbers, int target, vector<int> signs) {
    if (signs.size() == numbers.size()) {
        int answer = 0;
        for (int i = 0; i < signs.size(); i++)
            answer += signs[i] * numbers[i];
        return answer == target ? 1 : 0;
    }
    signs.push_back(1);
    int plus = dfs(numbers, target, signs);
    signs.pop_back();
    signs.push_back(-1);
    int minus = dfs(numbers, target, signs);
    return plus + minus;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, {});
}

int main() {
    cout << solution({1, 1, 1, 1, 1}, 3);
}