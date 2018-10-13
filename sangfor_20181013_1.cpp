#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <functional>
#include <climits>
#include <map>

using namespace std;

map<string, int> seen;

string add(string s) {
    int sum = 0;
    for(auto c : s)
        sum += c-'0';
    return to_string(sum);
}
int main() {
    int T, a, b, c;
    long long n;
    scanf("%d", &T);
    while(T--) {
        seen.clear();
        scanf("%d%d%d%lld", &a, &b, &c, &n);
        string s;
        s.push_back(a+'0'); s.push_back(b+'0'); s.push_back(c+'0');
        string substr = s;
        while(seen.count(substr) == 0) {
            seen[substr] = s.length() - 3;
            s = s + add(substr);
            substr.assign(s.end()-3, s.end());
        }
        if(n <= s.length()) cout << s[n-1] << endl;
        else {
            string pat = string(s.begin() + seen[substr], s.end() - 3);
            n -= seen[substr];
            int idx = n % pat.length();
            cout << pat[idx == 0 ? pat.length()-1 : idx - 1] << endl;
        }
    }
    return 0;
}