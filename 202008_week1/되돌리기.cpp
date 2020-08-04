// boj # 1360 되돌리기
// times에는 시간들을 담고, history에는 각 시간에 해당하는 문자열을 담음
// 명령어는 총 두 가지 경우가 생김.
// 1. type
//    가장 최근 time의 문자열에 입력받은 문자를 합쳐 history에 넣음
// 2. undo
//    돌아가려는 시간을 계산 (time-back-1)
//    해당 시간이 nums에 있는지 없는지 lowerbound 를 이용해 계산.
//    1) 해당 시간이 nums안에 있는 경우: 해당 숫자로 돌아가기
//    2) nums에 없을 경우: 하나 이전의 숫자로 돌아가기
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<int> times;
map<int, string> history;

int main() {
  cin >> N;
  string cmd, letter;
  int time, back;

  times.push_back(0);
  history[0] = "";

  while (N--) {
    cin >> cmd;
    if (cmd == "type") {
      cin >> letter >> time;
      history[time] = history[times.back()] + letter;
    } else {
      cin >> back >> time;
      int backTo = time - back - 1;
      int foundIdx = lower_bound(times.begin(), times.end(), backTo) - times.begin();
      if (times[foundIdx] == backTo)
        history[time] = history[backTo];
      else
        history[time] = history[times[foundIdx - 1]];
    }
    times.push_back(time);
  }
  cout << history[times.back()];
}