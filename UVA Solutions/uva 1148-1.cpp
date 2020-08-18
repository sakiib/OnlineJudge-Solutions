#include<bits/stdc++.h>
using namespace std;
vector<int> V[100005];
int main()
{
    int t,person,a,b,n,f,cost[100005],res,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&person);
        for(int i=0;i<person;i++){
            V[i].clear();
        }
        while(person--){
            scanf("%d%d",&a,&n);
            for(int i=0;i<n;i++){
                scanf("%d",&b);
                V[a].push_back(b);
                V[b].push_back(a);
            }
        }
        scanf("%d%d",&x,&y);
        memset(cost,0,sizeof(cost));
        queue<int> Q;
        Q.push(x);
        while(!Q.empty()){
            f=Q.front();
            res=cost[f];
           // cout<<f<<endl;
            Q.pop();
            if(f==y){
                printf("%d %d %d\n",x,y,res-1);
                break;
            }
            for(int i=0;i<V[f].size();i++){
                if(V[f][i]!=x&&!cost[V[f][i]]){
                    cost[V[f][i]]=res+1;
                    Q.push(V[f][i]);
                }
            }

        }
        if(t){
            puts("");
        }
    }
    return 0;

}
