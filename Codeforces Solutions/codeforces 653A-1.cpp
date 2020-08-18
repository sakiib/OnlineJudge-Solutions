#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[100001],track[10000]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        track[ara[i]]=1;
    }
    for(int i=1;i<=1000;i++){
        if(track[i]&&track[i+1]&&track[i+2]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
