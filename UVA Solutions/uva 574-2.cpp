#include<bits/stdc++.h>
using namespace std;

int tot,n;
vector<int> V;
map<vector<int>,bool> M;
vector<vector<int>> ans;
bool used[10000];

void BackTrack(int idx,int cur,vector<int> temp) {
    if(cur==tot) {
        //cerr<<"===="<<endl;
        if(!M[temp]) {
            ans.push_back(temp);
            M[temp]=true;
        }
        return;
    }
    for(idx ;idx<V.size();idx++) {
      if(!used[idx]) {
        if(cur+V[idx]<=tot) {
            cur+=V[idx];
            used[idx]=true;
            temp.push_back(V[idx]);
            BackTrack(idx,cur,temp);
            temp.pop_back();
            used[idx]=false;
            cur-=V[idx];
        }
      }
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d%d",&tot,&n)) {
        if(tot==0&&n==0) break;
        V.clear();
        for(int i=0;i<n;i++) {
            int val;
            scanf("%d",&val);
            V.push_back(val);
            used[i]=false;
        }
        printf("Sums of %d:\n",tot);
        vector<int> temp;
        temp.clear();
        M.clear();
        ans.clear();
        BackTrack(0,0,temp);
        if(!ans.size()) {
            printf("NONE\n");
        }
        for(int i=0;i<ans.size();i++) {
            for(int j=0;j<ans[i].size();j++) {
                if(!j) printf("%d",ans[i][j]);
                else printf("+%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
