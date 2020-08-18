#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<ll>myset;
set<ll>myset1;
ll ara[500][5000];
bool flag=false;
int main()
{
    ios::sync_with_stdio(false);
    ll n,sum=0,a,b,ans,count=0,maxs=0,mins=5799999999999;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ara[i][j]; sum+=ara[i][j];
            if(ara[i][j]==0){
                a=i;b=j;flag=true;
            }
        }
        myset.insert(sum);
        sum=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) sum+=ara[i][j];
        }
    }
    myset.insert(sum);
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j==n+1-2) sum+=ara[i][j];
        }
    }
    //cout<<"Ai"<< " " <<sum<<endl;
    myset.insert(sum);
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=ara[j][i];
        }
       // cout<<"co"<< " " <<sum<<endl;
        myset.insert(sum);
        sum=0;
    }
    set<ll>::iterator it;
    for(it=myset.begin();it!=myset.end();it++){
        ans=*it;
        //cout<<ans<<endl;
        if(ans>maxs) maxs=ans;
        if(ans<mins) mins=ans;
        count++;
    }
    //cout<<maxs << " " <<mins<<endl;
    //cout<<count<<endl;
    if(count>=3){
        cout<<-1<<endl;
        return 0;
    }
    if(count==1&&flag==true){
        cout<<-1<<endl;
        return 0;
    }
    ara[a][b]=(maxs-mins);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=ara[i][j];
        }
        myset1.insert(sum);
        sum=0;
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) sum+=ara[i][j];
        }
    }
    myset1.insert(sum);
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j==n+1-2) sum+=ara[i][j];
        }
    }
    //cout<<"Ai"<< " " <<sum<<endl;
    myset1.insert(sum);
    sum=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=ara[j][i];
        }
       // cout<<"co"<< " " <<sum<<endl;
        myset1.insert(sum);
        sum=0;
    }
    //cout<<myset.size()<<endl;
    if(myset1.size()>1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<(maxs-mins)<<endl;
    return 0;
}
