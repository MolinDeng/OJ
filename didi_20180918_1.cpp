/*
给定三种类型的小球P、Q、R，每种小球的数量分别为np、nq、nr个。现在想将这些小球排成一条直线，但是不允许相同类型的小球相邻，问有多少种排列方法。如若np=2，nq=1，nr=1则共有6种排列方式：PQRP，QPRP，PRQP，RPQP，PRPQ以及PQPR。 如果无法组合出合适的结果，则输出0。
*/
/*

*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

struct Node {
    string s;
    int id;
    int mark;
    Node(string _s, int _id, int _mark): s(_s), id(_id), mark(_mark) {}
};
string origin;
vector<int> Map(128, 0);
int calc(string s) {
    if(s == origin) return 0;
    int sum = 0;
    if(origin.length() == s.length()) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == origin[i]) continue;
            else {
                if(Map[toascii(s[i])] == Map[toascii(origin[i])]) 
                    sum += 1;
                else sum += 2;
            }
        }
    }
    else if(origin.length() > s.length()) {
        vector<vector<int> > DP(s.length() + 1, vector<int>(origin.length() + 1, 0));
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= origin.length(); j++) {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                if(s[i-1] == origin[j-1]) DP[i][j]++;
            }
        }
        int len = DP[s.length()][origin.length()];
        if(len == s.length()) sum += 3 * (origin.length() - len);
        else if(len < s.length()) {
            sum += 3 * (origin.length() - len);
            sum += 2 * (s.length() - len);
        }
    }
    else {
        vector<vector<int> > DP(origin.length() + 1, vector<int>(s.length() + 1, 0));
        for(int i = 1; i <= origin.length(); i++) {
            for(int j = 1; j <= s.length(); j++) {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                if(s[i-1] == origin[j-1]) DP[i][j]++;
            }
        }
        int len = DP[origin.length()][s.length()];
        if(len == origin.length()) sum += 3 * (s.length() - len);
        else if(len < origin.length()) {
            sum += 3 * (s.length() - origin.length());
            sum += 2 * (origin.length() - len);
        }
    }
    return sum;
}
bool cmp(const Node &a, const Node &b) {
    if(a.mark != b.mark) return a.mark < b.mark;
    else return a.id < b.id;
}
int main() {
    vector<char> A = {'q' ,'w' ,'e' ,'r' ,'t' ,'a' ,'s' ,'d' ,'f' ,'g' ,'z' ,'x' ,'c' ,'v'};
    vector<char> B = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm'};
    for(int i = 0; i < A.size(); i++) Map[toascii(A[i])] = 1;
    for(int i = 0; i < B.size(); i++) Map[toascii(B[i])] = 2;
    
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    vector<Node> v;
    int i = 0;
    while(getline(ss, token, ' ')) {
        if(i == 0) 
            origin = token;
        else {
            v.push_back(Node(token, i, calc(token)));
        }
        i++;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < 3 && i < v.size(); i++) {
        if(i != 0) cout << " ";
        cout << v[i].s;
    }
    return 0;
}