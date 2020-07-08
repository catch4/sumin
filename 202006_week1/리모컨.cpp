#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool rc[10];
string target;
int candidate = 99999999, targetNum;

void dfs(string channel) {
    if (channel.length() == 6)
        return;

    for (int i = 0; i < 10; i++) {
        if (rc[i] == 0) continue;
        // 다음 채널(string 타입)
        string nextChannel = channel;
        nextChannel += '0' + i;
        // 다음 채널(int 타입)
        int channelNum = atoi(nextChannel.c_str());
        if (abs(targetNum - channelNum) < abs(targetNum - candidate))
            candidate = channelNum;
        // 후보랑 채널이 같다면 더 작은 수를 후보로 둔다.
        else if (abs(targetNum - channelNum) == abs(targetNum - candidate))
            candidate = channelNum < candidate ? channelNum : candidate;
        dfs(nextChannel);
    }
}

int main() {
    int m, broken;
    cin >> target;
    cin >> m;
    targetNum = atoi(target.c_str());

    memset(rc, 1, sizeof(rc));
    while (m--) {
        cin >> broken;
        rc[broken] = 0;
    }

    dfs("");
    int numberkey = abs(candidate - targetNum) + to_string(candidate).length();
    int updown = abs(100 - targetNum);
    cout << min(numberkey, updown) << endl;
}