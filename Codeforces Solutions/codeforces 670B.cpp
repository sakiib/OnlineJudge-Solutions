#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,ara[100001],k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<k;i++){
        k=k-i;
    }
    cout<<ara[k];
    return 0;
}
