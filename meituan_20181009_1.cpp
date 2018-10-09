/*
你打开了美了么外卖，选择了一家店，你手里有一张满X元减10元的券，店里总共有n种菜，第i种菜一份需要Ai元，因为你不想吃太多份同一种菜，所以每种菜你最多只能点一份，现在问你最少需要选择多少元的商品才能使用这张券。
第一行两个正整数n和X，分别表示菜品数量和券的最低使用价格。（1≤n≤100, 1≤X≤10000）
接下来一行n个整数，第i个整数表示第i种菜品的价格。（1≤Ai≤100）
5 20
18 19 17 6 7
输出：23
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

vector<int> A;
int N, X, ret = INT_MAX;
void DFS(int idx, int sum) {
    if(sum >= X) {
        //cout << sum << endl;
        ret = min(ret, sum);
        return;
    }
    for(int i = idx; i < N; i++) {
        bool flag = (sum + A[i] >= X);
        DFS(i + 1, sum + A[i]);
        if(flag) return;
    }
        
}
int main() {
    cin >> N >> X;
    A.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    sort(A.begin(), A.end());
    DFS(0, 0);
    cout << ret << endl;
    return 0;
}