#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    vector<string> V[100];
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                string str;
                int val=i+j+k;//permutation values
                str+=(i+'0');
                str+=(j+'0');
                str+=(k+'0');
                V[val].push_back(str);//all possible permutations
                                      //against their values
                //cerr<<str<<" "<<val<<endl;
            }
        }
    }
    /*for(int i=0;i<=27;i++) {
        for(int j=0;j<V[i].size();j++) {
            cout<<V[i][j]<<" "<<i<<endl;
        }
    }*/
    string str;
    cin>>str;
    string a,b;
    a=str.substr(0,3);
    b=str.substr(3,3);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //cerr<<a <<" "<<b<<endl;
    int x=(str[0]-'0'+str[1]-'0'+str[2]-'0');
    int y=(str[3]-'0'+str[4]-'0'+str[5]-'0');
    if(x==y) {
        cout<<0<<endl; return 0;
    }
    int mn=10;
    for(int j=0;j<V[x].size();j++) {
        string temp=V[x][j];
        int ans=0;
        sort(temp.begin(),temp.end());
        cerr<<temp<<endl;
        for(int i=0;i<temp.size();i++) {
            if(temp[i]!=b[i]) ans++;
        }
        mn=min(mn,ans);
    }
    cout<<"up : "<<mn<<endl;
    for(int j=0;j<V[y].size();j++) {
        string temp=V[y][j];
        int ans=0;
        sort(temp.begin(),temp.end());
        cerr<<temp<<endl;
        for(int i=0;i<temp.size();i++) {
            if(temp[i]!=a[i]) ans++;
        }
        mn=min(mn,ans);
    }
    cout<<"down : "<<mn<<endl;
    cout<<mn<<endl;
    return 0;
}
