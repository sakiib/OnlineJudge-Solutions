#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,k,cnt=0;
     cin>>n>>k;
     for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cnt+=(b-a+1);
     }
     if(cnt%k==0){
        cout<<0<<endl;
        return 0;
     }
     cout<<k-(cnt%k)<<endl;
     return 0;
}
