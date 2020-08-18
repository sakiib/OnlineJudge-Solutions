#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[100001],cnt=1;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>ara[i];
    }
    sort(ara,ara+n);
    for(int i=0;i<n;i++){
        if(ara[i]>=cnt) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
