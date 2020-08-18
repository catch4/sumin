// boj 1342 행운의 문자열
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
string line;

bool checkLucky() {
  char last = '*';
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == last) return false;
    last = v[i];
  }
  return true;
}

int main() {
  cin >> line;
  for (int i = 0; i < line.size(); i++) v.push_back(line[i]);
  int answer = 0;

  sort(v.begin(), v.end());

  do {
    if (checkLucky()) answer++;
  } while (next_permutation(v.begin(), v.end()));

  cout << answer;
}