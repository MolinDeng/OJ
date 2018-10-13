#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    int N, T;
    scanf("%d", &N);
    vector<string> q;
    map<string, int> M;
    while(N--) {
        string s;
        cin >> s;
        q.push_back(s);
    }
    scanf("%d", &T);
    while(T--) {
        char c; string path;
        cin >> c >> path;
        M[path] = c;
    }
    M["/"] = 'N';
    for(auto s : q) {
        if(M.count(s) == 0) {
            M[s] = 'N';
            for(int i = 0, j = 0; i < s.length(); i++) {
                if(i != 0 && s[i] == '/') {
                    string ps = string(s.begin()+j, s.begin()+i);
                    if(M.count(ps) != 0) 
                        M[s] = M[ps];
                }        
            }
        }
        cout << (M[s] == 'Y'? 'Y' : 'N') << endl;
    }
    return 0;
}