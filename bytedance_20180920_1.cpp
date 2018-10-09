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

int main() {
    string str, token;
    getline(cin, str);
    stringstream ss(str);
    stack<string> S;
    while(getline(ss, token, '/')) {
        if(token != "") {
            if(token == ".") continue;
            else if(token == "..") {
                if(!S.empty()) {
                    S.pop();
                }
            }
            else {
                S.push(token);
            }
        }
    }
    if(S.empty()) cout << "/" << endl;
    else {
        string res;
        while(!S.empty()) {
            res = "/" + S.top() + res;
            S.pop();
        }
        cout << res << endl;
    }
    return 0;
}