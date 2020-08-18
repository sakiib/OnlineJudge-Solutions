#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(k%i==0&&(k/i)<=n) cnt++;
    }
    cout<<cnt;
    return 0;
}
