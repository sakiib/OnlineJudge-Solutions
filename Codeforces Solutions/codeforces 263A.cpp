#include<bits/stdc++.h>
using namespace std;

int main(){
    int ara[10][10];
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>ara[i][j];
            if(ara[i][j]==1){
                cout<<abs(i-3)+abs(j-3)<<endl;
                return 0;
            }
        }
    }
    return 0;
}
