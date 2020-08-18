#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ara[100005],keep[100000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        keep[ara[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<keep[i]<< " ";
    }
    return 0;
}
