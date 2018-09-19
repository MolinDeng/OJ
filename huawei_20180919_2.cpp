#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> seen;
unordered_map<string, vector<string> > e;
unordered_map<string, vector<string> > pre;
set<string> ids;

void DFS(string u) {
    seen[u] = true;
    for(auto v : e[u]) 
        if(!seen[v])
            DFS(v);
}
int main() {
    int K;
    scanf("%d", &K);
    getchar();
    while(K--) {
        string str, token, fid;
        getline(cin, str);
        int i = 0;
        stringstream ss(str);
        while(getline(ss, token, ' ')) {
            ids.insert(token);
            if(i == 0) {
                fid = token;
                i++;
            }
            else {
                e[fid].push_back(token);
                pre[token].push_back(fid);
            }
        }
    }
    DFS("0");
    for(auto iter = ids.begin(); iter != ids.end(); iter++) {
        if(seen[*iter]) {
            int fan = 0;
            for(auto id : pre[*iter]) 
                if(seen[id]) fan++;
            printf("%s %d\n", iter->c_str(), fan);
        }
    }
    return 0;
}