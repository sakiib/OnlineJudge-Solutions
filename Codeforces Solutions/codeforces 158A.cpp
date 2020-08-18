#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,ara[10000];
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++){
        if(ara[i]>=ara[k]&&ara[i]!=0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
