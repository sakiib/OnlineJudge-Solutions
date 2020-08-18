#include<bits/stdc++.h>
using namespace std;

int ara[10][10];

void print() {
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cout<<ara[i][j]<< " ";
        }
        cout<<endl;
    }
    return;
}
int solve() {
    ara[2][2]=(ara[1][3]+ara[3][1])/2;
    int val=ara[1][3]+ara[2][2]+ara[3][1];
    ara[1][1]=val-(ara[1][2]+ara[1][3]);
    ara[3][3]=val-(ara[3][2]+ara[3][1]);
     print();
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            cin>>ara[i][j];
        }
    }
    solve();
    return 0;
}
