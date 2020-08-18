#include<bits/stdc++.h>

using namespace std ;

int level[100002] ;
int visited[100002] ;
queue<int> q ;

// Creating the graph

void graphEdge(vector<int>node[] , int u , int v)
{
    node[u].push_back(v);
    node[v].push_back(u) ;
}

// BFS start here
int Bfs(vector<int> node[] , int s , int limit )
{
    memset(level,0,sizeof(level)) ;
    memset(visited,0,sizeof(visited)) ;

    //cout<<s <<" : " <<limit <<endl ;
    level[s] = 0 ;
    visited[s] = 1;
    int u , v,cnt ,nodeSize , queSize ;

    cnt = 0 , u=0 , v=0 ,nodeSize = 0 , queSize = 0 ;

    while(!node[s].empty())
    {
        u =node[s].back() ;
        node[s].pop_back() ; // deleting the last element

        if(visited[u] ==0 )
        {
            q.push(u) ;
            visited[u] = 1 ;
            level[u] = level[s] + 1 ;
            if(level[u] > limit)
                {
                    cnt++ ;
                }
        }
    }
    // Until the queue is empty !
    while(!q.empty())
    {
        u = q.front() ;
        q.pop() ;

        while(!node[u].empty() )
        {
            v = node[u].back();
            node[u].pop_back() ;

            if(visited[v] == 0)
            {
                q.push(v) ;
                visited[v] = 1;
                level[v] = level[u] + 1 ;
                if(level[v] > limit)
                {
                    cnt++ ;
                }
            }

        }

    }

    return cnt ;
}


int main()
{

    int U[100002] ;
    int  V[100002] ;
    int n , q ,u,v , s, l,tcase,t , i;

    tcase = 1;
    while(scanf("%d",&n) && n!=0)
    {
        t= n ;
        i= 0 ;
        while(t--)
        {
         scanf("%d%d",&u,&v) ;
         U[i] = u ;
         V[i] = v ;

         i++ ;

        }
       t= n ;

        while(scanf("%d%d",&s,&l))
        {
            if(s==0 && l == 0)
            {
                break ;
            }
             vector<int>node[1002] ;
            u = 0 , v = 0;
           for(i=0 ; i<t ; i++)
           {
               u = U[i] ; v=V[i] ;
               graphEdge(node,u ,v ) ;
           }

            int res =  0 ;
            res = Bfs(node,s,l) ;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                   tcase++,res,s,l) ;

        }

    }

    return 0 ;
}
