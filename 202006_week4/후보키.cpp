// 프로그래머스 # 42890 후보키
// 엄청 오래걸렸다 ㅠㅠ
// 조금 더 깨끗한 코드로 만드려다가 결국에는 생각한 것을 그대로 코딩하니 금방 끝났다
// visit함수를 이용하는 대신 string을 이용함! ("110100" <- 이런식으로)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<vector<string>> relations;
vector<string> keys;

bool contain(string a, string b) {
    string res = "";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i])
            res += a[i];
        else
            res += '0';
    }
    if ((a == res || b == res) && res != "0000") return true;
    return false;
}

void checkUnique(string res) {
    set<string> s;
    for (int i = 0; i < relations.size(); i++) {
        string tmp = "";
        for (int j = 0; j < relations[0].size(); j++)
            if (res[j] == '1') tmp += ('/' + relations[i][j]);
        s.insert(tmp);
    }
    if (s.size() == relations.size()) {
        for (auto key : keys)
            if (contain(key, res)) return;
        keys.push_back(res);
    }
}

void select(string cur) {
    if (cur.length() == relations[0].size()) {
        checkUnique(cur);
        return;
    }

    select(cur + '0');
    select(cur + '1');
}

int solution(vector<vector<string>> relation) {
    relations = relation;
    select("");

    return keys.size();
}

int main() {
    cout << solution({{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}});
}