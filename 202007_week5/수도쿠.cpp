// boj # 2239 수도쿠
// dfs로 백트래킹해가며 품.
#include <iostream>
#include <vector>
using namespace std;

struct node {
  int x, y;
};

string sudoku[9];
int emptyNum = 0;
vector<node> v;
bool foundFlag = false;

void print() {
  for (int i = 0; i < 9; i++) cout << sudoku[i] << "\n";
  cout << "\n";
}

bool check(int x, int y, char num) {
  // 가로 줄 확인
  for (int i = 0; i < 9; i++)
    if (sudoku[x][i] == num) return false;
  // 세로줄 확인
  for (int i = 0; i < 9; i++)
    if (sudoku[i][y] == num) return false;
  // 박스 확인
  int box_x = x / 3, box_y = y / 3;
  for (int i = box_x * 3; i < box_x * 3 + 3; i++)
    for (int j = box_y * 3; j < box_y * 3 + 3; j++)
      if (sudoku[i][j] == num) return false;

  return true;
}

void dfs(int level) {
  if (foundFlag) return;
  if (level == emptyNum) {
    foundFlag = true;
    print();
    return;
  }

  int x = v[level].x, y = v[level].y, n = (sudoku[x][y] - '0');
  for (int i = n + 1; i <= 9; i++) {
    char num = '0' + i;
    if (!check(x, y, num)) continue;
    sudoku[x][y] = num;
    dfs(level + 1);
    sudoku[x][y] = '0';
  }
}

int main() {
  for (int i = 0; i < 9; i++) cin >> sudoku[i];
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (sudoku[i][j] == '0') {
        v.push_back({i, j});
        emptyNum++;
      }
    }
  }

  dfs(0);
}