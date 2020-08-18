#include<bits/stdc++.h>
using namespace std;

int n;
int ara[100][100];

bool check(int x,int y,int val)
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cerr<<x<<i<< " " <<j<<y<<" "<<endl;
            //cerr<<ara[x][i]<< " " <<ara[j][y]<<endl;
            if(ara[x][i]+ara[j][y]==val) {
                //cerr<<"In Func: "<<ara[x][i]+ara[j][y]<<endl;
                return true;
            }
            //cerr<<ara[x][i]+ara[j][y]<<" "<<val<<endl;
        }
    }
    return false;
}
int main()
{

    cin>>n;
    int tar=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ara[i][j];
            if(ara[i][j]!=1) tar++;
        }
    }
    //cerr<<"Tar :"<<tar<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ara[i][j]!=1){
                int val=ara[i][j];
                int x=i,y=j;
                //cout<<x<< " " <<y<<endl;
                if(check(x,y,val)) ans++;
            }
            if(ans==tar){
                //cerr<<"Ans :"<<ans<<endl;
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    //cerr<<"Ans :"<<ans<<endl;
    if(ans==tar) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
