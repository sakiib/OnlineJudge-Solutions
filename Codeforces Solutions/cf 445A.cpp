#include<bits/stdc++.h>
using namespace std;

int vis[200005];
int num[200005];
int main(int argc,char const *argv[]){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&num[i]);
    }
    vis[0]=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[num[i]]!=0) cnt++;
        vis[num[i]]++;
    }
    printf("%d\n",cnt);
    return 0;
}
