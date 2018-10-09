#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main() {
    long long K, N;
    cin >> K;
    while(K--) {
        cin >> N;
        bool flag = false;
        long long edge = 0, degree;
        for(long long i = 0; i < N; i++) {
            scanf("%lld", &degree);
            if(degree == 0 && N > 1) flag = true;
            edge += degree;
        }
        edge /= 2;
        if(flag) cout << "No" << endl;
        else cout << (edge >= N ? "No" : "Yes") << endl;
    }
    return 0;
}