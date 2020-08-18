#include<bits/stdc++.h>
using namespace std;

int ara[105][105]={0};

int main(int argc,char const *argv[]){
    int n;
    scanf("%d",&n);
    int k=1;
    for(int i=1;i<=n;i++) {
        if(i&1) {
            for(int j=1;j<=n;j++) {
                ara[j][i]=k++;
            }
        }
        else {
            for(int j=n;j>=1;j--) {
                ara[j][i]=k++;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
