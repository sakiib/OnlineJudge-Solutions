#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    char ara[105][105];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>ara[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(ara[i][0]!=ara[i][j]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<m;i++){
            bool flag=false;
        for(int j=0;j<n;j++){
            if(ara[i][j]==ara[i+1][j]){
                flag=true;
            }
            else {
                flag=false; break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
