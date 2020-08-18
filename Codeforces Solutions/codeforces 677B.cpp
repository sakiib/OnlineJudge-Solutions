#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,h,k,ara[100001],cnt=0,rem=0;
    cin>>n>>h>>k;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<n;){
        if(rem+ara[i]<=h){
            rem+=ara[i];
            i++;
        }
        else{
            cnt+=(rem/k);
            rem=rem%k;
            if(rem+ara[i]>h){
                cnt++; rem=0;
            }
        }
    }
    if(rem>0){
        cnt+=(rem/k);
        if(rem%k>0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
