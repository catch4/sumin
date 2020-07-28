// pro # 67256 키패드누르기
#include <iostream>
#include <vector>
using namespace std;

struct node {
  int x, y;
};

string solution(vector<int> numbers, string hand) {
  string answer = "";
  node keypad[10] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
  node left = {3, 0}, right = {3, 2};

  for (auto num : numbers) {
    node kp = keypad[num];
    if (num == 1 || num == 4 || num == 7)
      answer += 'L', left = kp;
    else if (num == 3 || num == 6 || num == 9)
      answer += 'R', right = kp;
    else {
      int dist_left = abs(kp.x - left.x) + abs(kp.y - left.y);
      int dist_right = abs(kp.x - right.x) + abs(kp.y - right.y);
      if (dist_left > dist_right)
        answer += 'R', right = kp;
      else if (dist_left < dist_right)
        answer += 'L', left = kp;
      else {
        if (hand == "right")
          answer += 'R', right = kp;
        else
          answer += 'L', left = kp;
      }
    }
  }
  return answer;
}

int main() {
}