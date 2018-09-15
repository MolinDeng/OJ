#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;
    vector<long long> v(K+1);
    int p = 0, start_i;
    long long start = 0;
    for(int i = 1; i < K + 1; i++) {
        if(i == (int)pow(2, p)) {
            v[i] = pow(n, p);
            start = v[i];
            start_i = i;
            p++;
        }
        else {
            v[i] = start + v[i - start_i];
        }
    }
    cout << v[K] << endl;
    return 0;
}