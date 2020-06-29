// 프로그래머스 # 1835 단체사진 찍기
// 사진찍는 인원이 8명뿐이어서 부르트포스로 계산했다.
// 전역변수 초기화 다시 안해줘서 좀 애먹었음 ㅠㅠ!

#include <iostream>
#include <vector>
using namespace std;

vector<string> conditions = {};
int answer = 0;

void check(string word) {
    for (auto condition : conditions) {
        int f1 = word.find(condition[0]);
        int f2 = word.find(condition[2]);

        char sign = condition[3];
        int dist = abs(f1 - f2) - 1, num = (condition[4] - '0');
        if ((sign == '=') && (dist == num)) continue;
        if ((sign == '>') && (dist > num)) continue;
        if ((sign == '<') && (dist < num)) continue;
        return;
    }
    answer++;
}

void dfs(string left, string word) {
    if (left == "") check(word);

    for (int i = 0; i < left.size(); i++)
        dfs(left.substr(0, i) + left.substr(i + 1), word + left[i]);
}

int solution(int n, vector<string> data) {
    answer = 0;
    conditions = data;
    dfs("ACFJMNRT", "");
    return answer;
}