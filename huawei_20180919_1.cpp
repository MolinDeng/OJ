#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    int month, day;
    cin >> month >> day;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mlen = month - 1;
    int dlen = 0;
    for(int i = 0; i < mlen; i++) {
        dlen += days[i];
    }
    dlen += day;
    int date = dlen % 7;
    cout << (date == 0 ? 7 : date) << endl;
    return 0;
}