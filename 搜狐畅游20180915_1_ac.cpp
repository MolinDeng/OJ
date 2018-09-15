#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pos;

int main() {
    char c;
    int i = 0;
    string str;
    pos NPC, res, P;
    int minD = INT_MAX;
    while((c = getchar()) != '\n') {
        if(c == ',') {
            i++;
            if(i == 1) P.first = stoi(str);
            else if(i == 2) P.second = stoi(str);
            else if(i == 3);
            else if(i % 2 == 0) NPC.first = stoi(str);
            else if(i % 2 == 1) {
                NPC.second = stoi(str);
                int d = pow(NPC.first-P.first, 2) + pow(NPC.second-P.second, 2);
                if(d < minD) {
                    minD = d;
                    res = NPC;
                }
            }
            str.clear();
        }
        else str.push_back(c);
    }
    NPC.second = stoi(str);
    int d = pow(NPC.first-P.first, 2) + pow(NPC.second-P.second, 2);
    if(d < minD) {
        minD = d;
        res = NPC;
    }
    cout << "(" << res.first << "," << res.second << ")" << endl;
    return 0;
}