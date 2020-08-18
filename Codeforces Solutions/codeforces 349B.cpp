#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int mn=999999999,pos;
    int ara[100];
    vector<int> V;
    for(int i=1;i<=9;i++) {
        cin>>ara[i];
        if(ara[i]<=mn) {
            mn=ara[i];
            pos=i;
        }
    }
    int s=n/mn;
    if(s==0) {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<s;i++) {
        V.push_back(pos);
    }
    int sum=0;
    sum=mn;
    sum+=n%mn;
    for(int i=0;i<V.size();i++) {
        for(int j=9;j>=1;j--) {

            if(sum>=ara[j]) {
                V[i]=j;
                sum-=ara[j];
                sum+=mn;
                break;
            }
        }
    }
    for(int i=0;i<V.size();i++) {
        cout<<V[i];
    }
    return 0;
}
