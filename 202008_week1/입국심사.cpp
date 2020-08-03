// pro # 43238 입국심사
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solution(int n, vector<int> times) {
  long long min = 0, max = 1000000000000000000, mid;

  while (min <= max) {
    mid = (min + max) / 2;
    long long cnt = 0;
    for (auto t : times) {
      cnt += mid / t;
    }

    if (cnt >= n)
      max = mid - 1;
    else
      min = mid + 1;
  }

  return min;
}
int main() {
  cout << solution(6, {7, 10});
}