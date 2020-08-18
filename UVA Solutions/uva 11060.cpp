#include<bits/stdc++.h>
using namespace std;

map<string,int> M;
map<int,string> M1;
vector<int> graph[10000];
stack<int> S;
bool visited[10000];

void top_sort(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            top_sort(next);
        }
    }
    S.push(start);
}
int main(int argc,char const *argv[]) {
    int t,tc=1;
    bool start=false;
    while(scanf("%d",&t)!=EOF) {
        if(start) printf("\n");
        start=true;
        string str[1000];
        for(int i=1;i<=t;i++) {
            cin>>str[i];
            M[str[i]]=i;
            M1[i]=str[i];
        }
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;i++) {
            string a,b;
            cin>>a>>b;
            int x=M[a],y=M[b];
            graph[x].push_back(y);
        }
        for(int i=1;i<=t;i++) {
            if(!visited[i]) {
                top_sort(i);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",tc++);
        while(!S.empty()) {
            int top=S.top();
            S.pop();
            cout<<" "<<M1[top];
        }
        cout<<"."<<endl;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=10000;i++) graph[i].clear();
        M.clear();
    }
    return 0;
}
