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
int M, N, K;
vector<string> res, v;
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
vector<vector<char> > dic;
bool found = false;
bool is_valid(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= M) return false;
    return true;
}
void DFS(int x, int y, int len, int id) {
    if(len == v[id].length()) {
        res.push_back(v[id]);
        found = true;
    }
    for(int i = 0; i < 4; i++) {
        int xi = x + X[i];
        int yi = y + Y[i];
        if(is_valid(xi, yi) && v[id][len] == dic[xi][yi]) 
            DFS(xi, yi, len + 1, id);
    }
}

int main() {
    scanf("%d %d %d", &M, &N, &K);
    v.resize(K);
    dic.resize(N, vector<char>(M));
    for(int i = 0; i < K; i++) 
        cin >> v[i];
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++) 
            cin >> dic[i][j];
    for(int i = 0; i < K; i++) {
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < M; y++) {
                if(dic[x][y] == v[i][0]) {
                    DFS(x, y, 1, i);
                }
                if(found) break;
            }
            if(found) break;
        }
        found = false;
    }
    for(auto s : res) 
        printf("%s\n", s.c_str());
    return 0;
}