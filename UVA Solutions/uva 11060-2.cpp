// dfs wont work,coz jofo kono dependency na thake then
// jeta age ashce meaning index wise smaller ta age nite hobe
// tai priority queue min heap duye korte hobe
// dfs sort korbe but correct ordering dibe na
// otherwise dfs ise kora jabe
#include<bits/stdc++.h>
using namespace std;

map<string,int> M;
vector<string> V;
vector<int> graph[10005];
map<int,int> indegree;
vector<int> ans;

int main(int argc,char const *argv[]) {
    int n,tc=1;
    while(scanf("%d",&n)!=EOF) {
        V.clear(); M.clear(); indegree.clear();
        for(int i=0;i<1005;i++) graph[i].clear();
        ans.clear();

        for(int i=0;i<n;i++) {
            string str;
            cin>>str;
            M[str]=i;
            V.push_back(str);
        }
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++) {
            string u,v;
            cin>>u>>v;
            graph[M[u]].push_back(M[v]);
            indegree[M[v]]++;
        }
        priority_queue<int,vector<int>,greater<int> > PQ;
        for(int i=0;i<V.size();i++) {
            if(indegree[M[V[i]]]==0) PQ.push(M[V[i]]);
        }
        while(!PQ.empty()) {
            int to=PQ.top();
            PQ.pop();
            ans.push_back(to);
            for(int i=0;i<graph[to].size();i++) {
                int k=graph[to][i];
                indegree[k]--;
                if(indegree[k]==0) PQ.push(k);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",tc++);
        for(int i=0;i<ans.size();i++) {
            cout<<" "<<V[ans[i]];
        }
        cout<<"."<<endl<<endl;
    }
    return 0;
}
