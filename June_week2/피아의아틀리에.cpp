#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int quality;
    char color;
};

node gama[6][6];
node ingr[11][5][5];  // ingredients
int n, visit[11], answer = 0;
int px[4] = {0, 0, 1, 1}, py[4] = {0, 1, 0, 1};

void init(bool init_gama, bool init_ingr) {
    // 가마 초기화
    if (init_gama)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                gama[i][j] = {0, 'W'};
    // 재료 초기화
    if (init_ingr)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    ingr[i][j][k] = {0, 'W'};
}

void rotate(int num) {
    node temp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[i][j] = ingr[num][4 - j - 1][i];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ingr[num][i][j] = temp[i][j];
        }
    }
}

// position: (0,0),(0,1),(1,0),(1,1)중 어디서 시작할지
// ingrNum: 재료번호
void setPosition(int position, int ingrNum) {
    int start_x = px[position], start_y = py[position];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gama[i + start_x][j + start_y].quality += ingr[ingrNum][i][j].quality;
            gama[i + start_x][j + start_y].quality = max(gama[i + start_x][j + start_y].quality, 0);
            gama[i + start_x][j + start_y].quality = min(gama[i + start_x][j + start_y].quality, 9);
            if (ingr[ingrNum][i][j].color == 'W') continue;
            gama[i + start_x][j + start_y].color = ingr[ingrNum][i][j].color;
        }
    }
}

void cal() {
    int r = 0, b = 0, g = 0, y = 0;
    for (int _x = 0; _x < 5; _x++) {
        for (int _y = 0; _y < 5; _y++) {
            if (gama[_x][_y].color == 'R')
                r += gama[_x][_y].quality;
            else if (gama[_x][_y].color == 'B')
                b += gama[_x][_y].quality;
            else if (gama[_x][_y].color == 'G')
                g += gama[_x][_y].quality;
            else if (gama[_x][_y].color == 'Y')
                y += gama[_x][_y].quality;
        }
    }
    answer = max(answer, 7 * r + 5 * b + 3 * g + 2 * y);
}

void calculate(int a, int b, int c) {
    // 각 (0,0),(1,0),(0,1),(1,1)에서 시작할 수 있도록!
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                // 회전
                for (int r1 = 0; r1 < 4; r1++) {
                    rotate(a);
                    for (int r2 = 0; r2 < 4; r2++) {
                        rotate(b);
                        for (int r3 = 0; r3 < 4; r3++) {
                            rotate(c);
                            init(true, false);
                            setPosition(i, a);
                            setPosition(j, b);
                            setPosition(k, c);
                            cal();
                        }
                    }
                }
            }
        }
    }
}

void dfs(int level, int cnt) {
    if (cnt == 3) {
        // 위치, 순서를 변경해가면서 조합해보기
        vector<int> selected;
        for (int i = 0; i < n; i++)
            if (visit[i]) selected.push_back(i);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                for (int k = 0; k < 3; k++) {
                    if (i == k || j == k) continue;
                    calculate(selected[i], selected[j], selected[k]);
                }
            }
        }
        return;
    }
    if (level == n) return;

    visit[level] = true;
    dfs(level + 1, cnt + 1);
    visit[level] = false;
    dfs(level + 1, cnt);
}

int main() {
    scanf("%d", &n);
    init(true, true);
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> ingr[i][j][0].quality >> ingr[i][j][1].quality >> ingr[i][j][2].quality >> ingr[i][j][3].quality;

        for (int j = 0; j < 4; j++)
            cin >> ingr[i][j][0].color >> ingr[i][j][1].color >> ingr[i][j][2].color >> ingr[i][j][3].color;
    }
    dfs(0, 0);
    cout << answer << endl;
}