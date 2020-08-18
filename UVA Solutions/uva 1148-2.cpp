#include<bits/stdc++.h>
using namespace std;

vector<int> V[100005];
bool visited[100005];
int cost[100005];

int main()
{
    int t,n,a,b,c,from,to;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(visited,false,sizeof(visited));
        memset(cost,0,sizeof(cost));
        for(int i=0;i<n;i++){
            V[i].clear();
        }
        while(n--){
            scanf("%d",&a);
            scanf("%d",&c);
            while(c--){
                scanf("%d",&b);
                V[a].push_back(b);
                V[b].push_back(a);
            }
        }
        scanf("%d%d",&from,&to);
       /* for(int i=0;i<1000;i++){
            if(!V[i].empty()){
                cout<<i<< " ";
                vector<int> :: iterator it;
                for(it=V[i].begin();it!=V[i].end();it++){
                    cout<<*it<< endl;
                }
            }
        }*/
        queue<int> Q;
        Q.push(from);
        cost[from]=0;
        visited[from]=true;
        while(!Q.empty()){
            int fron=Q.front();
            if(fron==to){
                cout<<from<< " " <<to<< " " <<cost[to]-1<<endl;
                break;
            }
          //  cout<<Q.front()<< "-";
            Q.pop();
            vector<int> :: iterator it;
            for(it=V[fron].begin();it!=V[fron].end();it++){
                if(!visited[*it]){
                  //  cout<<*it<<endl;
                    visited[*it]=true;
                    Q.push(*it);
                    cost[*it]=cost[fron]+1;
                }
            }

        }
        if(t) puts("");
    }
    return 0;
}
