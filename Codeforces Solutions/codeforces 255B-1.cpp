#include<bits/stdc++.h>
using namespace std;

int cnt[100];

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    for(int i=0;i<str.size();i++) {
        cnt[str[i]-'0']++;
    }
    int k=abs(cnt['x'-'0']-cnt['y'-'0']);

    for(int i=0;i<k;i++) {
        cout<<(cnt['x'-'0']>cnt['y'-'0'] ? 'x' : 'y');
    }
    cout<<endl;
    return 0;
}
