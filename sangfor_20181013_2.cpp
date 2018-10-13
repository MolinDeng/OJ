#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> shift;

int sunday(string& S, string& P) {
    int sLen = S.length(), pLen = P.length();
    for(int i = 0, j = 0; i + pLen < sLen; i += shift[S[i + pLen] - '0'], j = 0) {
        while(j < pLen && S[i+j] == P[j]) j++;
        if(j == pLen) 
            return 1;
    }
    return 0;
}
int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    vector<string> v;
    string P;
    char str[11];
    while(N--) {
        scanf("%s", str);
        v.push_back(str);
    }
    while(M--) {
        cin >> P;
        int len = P.length(), ret = 0;
        shift.resize(10, len+1);
        for(int i = 0; i < len; i++) 
            shift[P[i]-'0'] = len - i;
        for(auto S : v) ret += sunday(S, P);
        printf("%d\n", ret);
    }
    return 0;
}