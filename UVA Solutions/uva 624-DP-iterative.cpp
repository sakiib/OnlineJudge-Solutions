#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int track[25],dp[25][20005],k;

int main()
{
    int total,n,ans;

    while(scanf("%d",&total)==1){

        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&track[i]);
        }

        for(int i=0;i<=total;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=total;j++){
                if(track[i]<=j){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-track[i]]+track[i]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        //cout<<dp[n][total]<<endl;
        ans=dp[n][total];

        vector<int> V;

        while(n!=0){
            if(dp[n][total]!=dp[n-1][total]){
                V.push_back(track[n]);
                total-=track[n];
            }
            n--;
        }
        reverse(V.begin(),V.end());

        for(int i=0;i<V.size();i++){
            cout<<V[i]<< " ";
        }
        cout<<"sum:"<<ans<<endl;
    }
    return 0;
}
