#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
vector<pii>graph[30001];
ll cost[300001];
ll maxi=0;

ll bfs(ll src)
{
    memset(cost,-1,sizeof cost);
    queue<pii>q;
    q.push(pii(src,0));
    ll d =0;
    cost[src]=0;
    while(!q.empty())
    {
        ll u = q.front().first;
        ll v = q.front().second;
        q.pop();
        for(ll i=0; i<graph[u].size(); i++)
        {
            ll x = graph[u][i].first;
            ll y = graph[u][i].second;
            if(cost[x]==-1)
            {
                cost[x]=cost[u]+y;

                if(maxi<=cost[x]) d=x;
                maxi = max(maxi,cost[x]);
                q.push(pii(x,cost[x]));
            }
        }
    }
    return d;
}
int main()
{
    ll t,cas=1,i,j,k,n,x,y,w;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0; i<=n; i++)graph[i].clear();
        for(i=1; i<n; i++)
        {
            scanf("%lld%lld%lld",&x,&y,&w);
            graph[x].push_back(pii(y,w));
            graph[y].push_back(pii(x,w));
        }
        ll x = bfs(0);
        x = bfs(x);
        printf("Case %lld: %lld\n",cas++,maxi);

        maxi=0;
    }
    return 0;
}
