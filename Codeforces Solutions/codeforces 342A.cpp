#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N];
map<int,int> M;
vector<int> V[N/3];

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        M[ara[i]]++;
    }
    bool found=false;
    int k=1;
    while(true) {
        found=false;
        while(M[1]!=0) {
            M[1]--;
            V[k].push_back(1);
            if(M[2]!=0){
                M[2]--;
                V[k].push_back(2);
                if(M[4]!=0){
                    M[4]--;
                    found=true;
                    V[k].push_back(4);
                    break;
                }
                else if(M[6]!=0) {
                    M[6]--;
                    found=true;
                    V[k].push_back(6);
                    break;
                }
                else break;
            }
            else if(M[3]!=0) {
                M[3]--;
                V[k].push_back(3);
                if(M[6]!=0) {
                    M[6]--;
                    found=true;
                    V[k].push_back(6);
                    break;
                }
                else break;
            }
            else break;
        }
        if(!found) break;
        k++;
    }
    for(int i=1;i<=7;i++) {
        if(M[i]>0) {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<=k;i++) {
        for(int j=0;j<V[i].size();j++) {
            printf("%d ",V[i][j]);
        }
        printf("\n");
    }
    return 0;
}
