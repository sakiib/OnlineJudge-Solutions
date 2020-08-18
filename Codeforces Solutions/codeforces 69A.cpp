#include<bits/stdc++.h>
using namespace std;
int ara[104][104];
int main()
{
    int n,sum=0,yes=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>ara[i][j];
        }
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
         sum+=ara[j][i];
       }
      // cout<<sum<<endl;
       if(sum==0) yes++;
       sum=0;
    }
    if(yes==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
