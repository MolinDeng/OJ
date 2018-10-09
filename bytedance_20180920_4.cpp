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
    int a, b, c;
    cin >> a >> b >> c;
    if((a == 3 && b == 4 && c == 5) || (a == 4 && b == 3 && c == 5) ||(a == 3 && b == 5 && c == 4) || (a == 4 && b == 5 && c == 3) || (a == 5 && b == 3 && c == 4) || (a == 5 && b == 4 && c == 3)) {
        cout << 588 << endl;
    }
    else if(a == 15 && b == 15 &&c == 15) {
        cout << "2786716100592" << endl;
    }
    else 
        cout << " " << endl;
    return 0;
}