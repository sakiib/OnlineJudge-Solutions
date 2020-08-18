#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll day=1;

bool check(ll year)
{
    if(year%400==0||(year%4==0&&year%100!=0))
        return true;
    else
        return false;
}
ll only_leap(ll x,ll y)
{
    for(int i=x;;i++){
        if(y%7==day&&check(i)) return i;
        if(check(i)) y+=2;
        else y++;
    }
}
ll non_leap(ll x,ll y)
{
    for(int i=x;;i++){
        if(!check(i)&&y%7==day) return i;
        if(check(i)) y+=2;
        else y++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll year,ans;
    cin>>year;
    if(check(year)){
        ans=only_leap(year+1,day+2);
        cout<<ans<<endl;
    }
    else{
        ans=non_leap(year+1,day+1);
        cout<<ans<<endl;
    }
    return 0;
}
