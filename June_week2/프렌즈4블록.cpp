#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int M, N;
vector<string> b;

struct node {
    int x, y;
};

int check4blocks(int x, int y) {
    vector<node> blocks = {{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}};
    for (int i = 1; i < 4; i++) {
        int _x = blocks[i].x, _y = blocks[i].y;
        if (_x < 0 || _x >= N || _y < 0 || _y >= M) return 0;
        if (b[x][y] != b[_x][_y]) return 0;
    }

    for (int i = 0; i < 4; i++) {
        int _x = blocks[i].x, _y = blocks[i].y;
        b[_x][_y] = '1';
    }
    return 1;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M = m, N = n;
    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = m - 1; j >= 0; j--)
            tmp += board[j][i];
        b.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;

    while (true) {
        // 지워질 자리 1로 채워주기
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] != '0')
                    cnt += check4blocks(i, j);
                cout << i << ' ' << j << endl;
            }
        }
        if (cnt == 0) return answer;
        cout << "result" << endl;
        answer += 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j];
            }
            cout << endl;
        }
        cout << endl;

        // 1인애들 지우고 뒤에다가 0채워주기
        for (auto& line : b) {
            for (int i = n - 1; i >= 0; i--) {
                if (line[i] == '1') line.erase(line.begin() + i);
                line += '0';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return answer;
}

int main() {
    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"});
}