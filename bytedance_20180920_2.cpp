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
    int N;
    string str;
    scanf("%d", &N);
    vector<string> v, res(N, "");
    while(N--) {
        cin >> str;
        if(v.empty()) {
            v.push_back(str);
        }
        else {
            int i, j;
            int id = v.size();
            for(i = 0; i < v.size(); i++) {
                for(j = 0; j < min(v[i].length(), str.length()); j++) {
                    if(str[j] != v[i][j]) {
                        break;
                    }
                }
                if(j + 1 > res[i].length()) {
                    res[i] = string(v[i].begin(), v[i].begin() + j + 1);
                }
                if(j + 1 > res[id].length()) {
                    res[id] = string(str.begin(), str.begin() + j + 1);
                }
            }
            v.push_back(str);
        }
    }
    for(auto s : res) 
        printf("%s\n", s.c_str());
    return 0;
}