#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int city,limak,a,b,ara[100001],th=0;
    cin>>city>>limak;
    for(int i=1;i<=city;i++){
        cin>>ara[i];
    }
    ara[0]=-1,ara[city+1]=-1;
    if(ara[limak]==1) th++;
        a=limak+1;
        b=limak-1;
    while(ara[a]!=-1||ara[b]!=-1){
        if(ara[a]==1&&ara[b]==1) th+=2;
        else if(ara[a]==-1&&ara[b]==1) th++;
        else if(ara[a]==1&&ara[b]==-1) th++;
        if(a<city+1) a++;
        if(b>0) b--;
      //  cout<<a<< " "<<b<<endl;
    }
    cout<<th<<endl;
    return 0;
}
