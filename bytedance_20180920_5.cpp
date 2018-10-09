#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <sstream>
#include <stack>
using namespace std;

string plus_one(string s) {
    int carry = 0;
    for(int i = s.length()-1; i >= 0; i--) {
        int k = (s[i] - '0') + (i == s.length()-1 ? 1 : 0) + carry;
        carry = k / 10;
        s[i] = (k % 10) + '0';
        if(carry == 0) break;
    }
    if(carry == 1) s = "1" + s;
    return s;
}
bool LT(string a, string b) {
    if(a.length() < b.length()) return true;
    else if(a == b) return true;
    else if(a.length() == b.length()) {
        return a < b;
    }
    return false;
}
int main() {
    string a, b;
    cin >> a >> b;
    long long cnt = 0;
    for(string i = a; LT(i, b); i = plus_one(i)) {
        bool flag = true;
        for(int j = 0; j < i.length() / 2; j++) {
            if(i[j] == i[i.length() - 1 - j]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    cout << cnt << endl;
    return 0;
}