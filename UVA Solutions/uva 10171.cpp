#include<bits/stdc++.h>
using namespace std;

const int inf=10000000;

int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)) {
        if(n==0) break;

        int Y[505][505],M[505][505];

        for(int i=1;i<=26;i++) {
            for(int j=1;j<=26;j++) {

                if(i==j) Y[i][j]=0,M[i][j]=0,Y[j][i]=0,M[j][i]=0;
                else Y[i][j]=inf,M[i][j]=inf,Y[j][i]=inf,M[j][i]=inf;
            }
        }
        for(int i=1;i<=n;i++) {
            string x,y,p,q;
            int c;
            cin>>x>>y>>p>>q;
            scanf("%d",&c);
            if(x[0]=='Y') {

                if(y[0]=='U') Y[p[0]-'A'+1][q[0]-'A'+1]=c;
                else {
                    Y[p[0]-'A'+1][q[0]-'A'+1]=c;
                    Y[q[0]-'A'+1][p[0]-'A'+1]=c;
                }
            }
            else {
                if(y[0]=='U') M[p[0]-'A'+1][q[0]-'A'+1]=c;
                else {
                    M[p[0]-'A'+1][q[0]-'A'+1]=c;
                    M[q[0]-'A'+1][p[0]-'A'+1]=c;
                }
            }
        }
        string st,en;
        cin>>st>>en;

        for(int k=1;k<=26;k++) {
            for(int i=1;i<=26;i++) {
                for(int j=1;j<=26;j++) {

                    Y[i][j]=min(Y[i][j],Y[i][k]+Y[k][j]);
                    M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
                }
            }
        }
        vector<pair<int,int> > ans;

        for(int i=1;i<=26;i++) {
            Y[i][i]=0,M[i][i]=0;
            if(Y[st[0]-'A'+1][i]!=inf&&M[en[0]-'A'+1][i]!=inf) {
            ans.push_back({Y[st[0]-'A'+1][i]+M[en[0]-'A'+1][i],i});
            //printf("index : %d\n",i);
            }
        }
        if(ans.size()==0) {
            puts("You will never meet.");
            continue;
        }
        sort(ans.begin(),ans.end());
        /*for(auto x: ans) {
            cout<<x.first<<" "<<x.second+'A'-1<<endl;
        }*/
        int cost=ans[0].first,idx=ans[0].second;
        printf("%d",cost);
        for(int i=0;i<ans.size();i++) {
            if(cost==ans[i].first) printf(" %c",ans[i].second+'A'-1);
        }
        printf("\n");
    }
    return 0;
}
