#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Coin[] = {1, 5, 10, 20, 25};
int dp[7][7493];

int makeCoin(int I, int H){
    if(I >= 5){
        if(!H)return 1;
        else return 0;
    }
    if(dp[I][H] != -1)return dp[I][H];
    int Way1 = 0, Way2 = 0;
    if(H-Coin[I] >= 0)Way1 = makeCoin(I, H-Coin[I]);
    Way2 = makeCoin(I+1, H);
    cout << Way1 << " " << Way2 << " I = " << I << " H = " << H << endl;
    return dp[I][H] = Way1+Way2;
}

int main(){
    int N;
    memset(dp, -1, sizeof(dp));
    while(cin >> N){
        cout << makeCoin(0, N) << endl;
    }
    return 0;
}
