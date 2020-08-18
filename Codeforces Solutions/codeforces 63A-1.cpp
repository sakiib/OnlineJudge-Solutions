#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str[1010],x;
    pair<int,int> P[1010];
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>str[i]>>x;
        if(x=="rat") k=1;
        if(x=="woman"||x=="child") k=2;
        if(x=="man") k=3;
        if(x=="captain") k=4;
        P[i]=make_pair(k,i);
    }
    sort(P,P+n);
    for(int i=0;i<n;i++) {
        cout<<str[P[i].second]<<endl;
    }
    return 0;
}
