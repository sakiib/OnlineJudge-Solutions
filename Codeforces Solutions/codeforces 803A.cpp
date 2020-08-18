#include<bits/stdc++.h>
using namespace std;
int ara[105][105]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k>n*n){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(k>=1){
            ara[i][i]=1;
            k--;
        }
        for(int j=i+1;j<=n;j++){
            if(k>=2){
                ara[i][j]=1;
                ara[j][i]=1;
                k-=2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ara[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;

}
