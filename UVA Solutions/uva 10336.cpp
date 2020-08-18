#include<bits/stdc++.h>
using namespace std;

int n,m;
string str[100010];
map<char,int> ans;
bool visited[1000][1000];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool possible(int nx,int ny,char ch) {
    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!visited[nx][ny]&&str[nx][ny]==ch)
        return true;
    else return false;
}
void dfs(int x,int y,char ch) {
    visited[x][y]=true;
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(possible(nx,ny,ch)) {
            dfs(nx,ny,ch);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        memset(visited,false,sizeof(visited));
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j]) {
                    dfs(i,j,str[i][j]);
                    ans[str[i][j]]++;
                }
            }
        }
        vector<pair<int,char> > V;
        for(char i='z';i>='a';i--) {
            if(ans[i]>0) {
                V.push_back({ans[i],i});
            }
        }
        sort(V.rbegin(),V.rend());
        for(int i=0;i<V.size()-1;i++) {
            for(int j=i+1;j<V.size();j++) {
                if(V[i].first==V[j].first) {
                    if(V[i].second>V[j].second) swap(V[i].second,V[j].second);
                }
            }
        }
        printf("World #%d\n",tc);
        for(auto x:V) cout<<x.second<<": "<<x.first<<endl;
        V.clear();
        ans.clear();
    }
    return 0;
}
