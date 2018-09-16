/**
ZigZag Array
给一个长度为N的正整数数组A，如果对于数组A中存在连续的三个数A[i],A[i+1],A[i+2]满足
A[i] < A[i + 1] < A[i + 2] 或 A[i] > A[i + 1] > A[i + 2] , 则这个数组就不是ZigZag数组，
现在可以删除掉数组A中的一些数使得A变为ZigZag数组，请问最少需要删除多少个数呢?
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    if(N < 3) {
        for(int i = 0; i < N; i++) cin >> x;
        cout << "0" << endl;
        return 0;
    }
    vector<int> v;
    int flag1;
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(i == 0) v.push_back(x);
        else if(i == 1) {
            flag1 = (x < v.back() ? 1 : (x > v.back() ? 2 : 0));// 1 for <; 2 for >
            v.push_back(x);
        }
        else {
            int flag2 = (x < v.back() ? 1 : (x > v.back() ? 2 : 0));
            if((flag1 != flag2) || (flag1 == flag2 && flag1 == 0)) {
                v.push_back(x);
                flag1 = flag2;
            }
            else {
                v.pop_back();
                v.push_back(x);
            }
        }
    }
    cout << N-v.size() << endl;
    return 0;
}