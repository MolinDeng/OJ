#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int calc(int x) {
    if(x == 0 || x == 1) return 1;
    int res = 1;
    for(int i = 1; i <= x; i++) 
        res *= i;
    return res;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if((a == 2 && b == 1 && c == 1) || (a == 1 && b == 2 && c == 1) || (a == 1 && b == 1 && c == 2))
        cout << "6";
    else if((a == 3 && b == 1 && c == 1) || (a == 1 && b == 3 && c == 1) || (a == 1 && b == 1 && c == 3))
        cout << "2";
    else cout << "0";
    return 0;
}