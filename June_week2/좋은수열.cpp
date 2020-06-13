#include <stdlib.h>

#include <iostream>
using namespace std;

int n;
string answer = "";

bool check(string num) {
    int l = num.length();
    for (int len = 2; len <= l; len++) {
        for (int i = len; i <= l - len; i++) {
            string before = num.substr(i - len, len);
            if (num.substr(i, len) == before)
                return false;
        }
    }
    return true;
}

void dfs(string num, int before) {
    if (answer != "") return;
    if (num.length() == n) {
        answer = num;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        string ns = num + to_string(i);
        if (before != i && check(ns))
            dfs(ns, i);
    }
}

int main() {
    cin >> n;
    dfs("", 0);
    cout << answer;
}