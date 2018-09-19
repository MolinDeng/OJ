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

struct Node {
    int offset;
    int len;
    Node(int _offset, int _len): offset(_offset), len(_len) {}
};
int main() {
    int plen, offset, len;
    scanf("%d\n%d,%d", &plen, &offset, &len);
    string str, token;
    vector<Node> v;
    while(true) {
        cin >> str;
        if(str[0] == 'e') break;
        stringstream ss(str);
        int i = 0, nlen, noffset;
        while(getline(ss, token, ',')) {
            if(i == 0) noffset = stoi(token);
            if(i == 1) nlen = stoi(token);
            i++;
        }
        v.push_back(Node(noffset, nlen));
    }
    int id = offset / plen;
    int from = offset - id*plen;
    if(from >= v[id].offset && from + len < plen && (from + len) <= (v[id].offset + v[id].len)) {
        int left = from - v[id].offset;
        int right = (v[id].offset + v[id].len) - (from + len);
        if(left < right) {
            v[id].offset += len;
            v[id].len -= len; 
        }
        else {
            v[id].len -= len;
        }
    }
    else if(from <= v[id].offset && from + len < plen && (from + len) <= (v[id].offset + v[id].len)) {
        int r = v[id].offset - from;
        v[id].offset = from + len;
        v[id].len -= (len - r);
    }
    else if(from >= v[id].offset && from + len < plen && (from + len) > (v[id].offset + v[id].len)) {
        v[id].len = from - v[id].offset;
    }
    else if(from >= v[id].offset && from + len > plen) {
        v[id].len = from - v[id].offset;
        if(id + 1 < v.size()) {
            v[id+1].offset += ((from + len) - plen);
            v[id+1].len -= ((from + len) - plen);
        }
    }
    for(auto iter : v) 
        printf("%d,%d\n", iter.offset, iter.len);
    return 0;
}