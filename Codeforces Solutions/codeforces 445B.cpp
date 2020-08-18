#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
int main()
{
    vector<int>graph[1000];
    int m,n;
    scanf("%d%d",&m,&n);
    int a,b;
    vector<int>mark(100,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long ans=1;
    for(int i=1;i<=m;i++)
    {
        if(mark[i]==0)
        {
            queue<int>q;
            q.push(i);
            mark[i]=1;
            while(!q.empty())
            {
                int nw=q.front();
                q.pop();
                for(int j=0;j<graph[nw].size();j++)
                {
                    if(mark[graph[nw][j]]==0)
                    {
                        printf("%d ",graph[nw][j]);
                        ans=ans*2;
                        cerr<<"Ans: "<<ans<<endl;
                        mark[graph[nw][j]]=1;
                        q.push(graph[nw][j]);
                    }
                }
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}

