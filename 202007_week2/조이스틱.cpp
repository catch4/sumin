// PRO # 42860 조이스틱
// 각 A 뭉텅이를 만들어서 앞뒤로 가는 방법 확인.
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int countUpDown(string name) {
    int result = 0;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] <= 'N')
            result += (name[i] - 'A');
        else
            result += ('N' - 'A') - (name[i] - 'N');
    }
    return result;
}

int solution(string name) {
    int answer = name.length() - 1, len = name.length(), i, j;
    for (i = 0; i < len;) {
        if (name[i] != 'A') {
            i++;
            continue;
        }
        for (j = 0;; j++) {
            if ((i + j) >= len) break;
            if (name[i + j] != 'A') break;
        }
        j--;
        int front = i == 0 ? 0 : (i - 1), back = len - (i + j + 1);
        answer = min({answer, 2 * front + back, front + 2 * back});
        i += (j + 1);
    }
    return answer + countUpDown(name);
}