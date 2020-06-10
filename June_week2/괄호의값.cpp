#include <iostream>
#include <vector>
using namespace std;

int main() {
    string data;
    vector<int> v;
    cin >> data;
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == '(' || data[i] == '[')
            v.push_back(data[i]);
        else if (data[i] == ')' || data[i] == ']') {
            if (v.back() == '(' || v.back() == '[') {
                int num = v.back() == '(' ? 2 : 3;
                v.pop_back();
                if (v.back() != '(' && v.back() != '[') {
                    num *= v.back();
                    v.pop_back();
                }
                v.push_back(num);

            } else {
                int num = v.back() * data[i] == ')' ? 2 : 3;
                v.pop_back();  // 숫자 pop
                v.pop_back();  // '(' 또는 '[' 괄호 pop
                v.push_back(num);
            }
        }
        for (auto& elem : v) {
            cout << elem << ' ';
        }
        cout << endl;
    }
    cout << v[0];
}