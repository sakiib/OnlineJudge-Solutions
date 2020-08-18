#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m,x,wi,winner;
    cin>>n>>m;
    int MAT[105][105];
    map<int,int> M;

    for(int i=1;i<=m;i++){
        int mx=-1;
        for(int j=1;j<=n;j++){
            cin>>MAT[i][j];
            if(MAT[i][j]>mx){
                mx=MAT[i][j];
                wi=j;
            }
        }
        M[wi]++;
    }

   /* map<int,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++){
        cout<<it->first<< " " <<it->second<<endl;
    }*/
    int mx=-1;
    for(int i=1;i<=n;i++){
        if(M[i]>mx){
            mx=M[i];
            winner=i;
        }
       // cout<<M[i]<<endl;
    }
    cout<<winner<<endl;
    return 0;
}
