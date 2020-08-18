#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010],keep[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int st=1,ind=1;
    for(int i=1;i<n;i++) {
        if(ara[i]>ara[i+1]) {
            st=i;
            while(ara[i]>ara[i+1]&&i<n) {
                i++;
            }
            ind=i;
        }
    }
    //cerr<<st<< " " <<ind<<endl;;
    sort(ara+st,ara+ind+1);
    for(int i=1;i<n;i++) {
        if(ara[i]>ara[i+1]) {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    cout<<st<< " " <<ind<<endl;
    return 0;
}
