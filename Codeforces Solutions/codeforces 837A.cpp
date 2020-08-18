#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    getchar();
    string str;
    getline(cin,str);
    stringstream ss(str);
    string word;
    int mx=0;
    while(ss>>word) {
        int cnt=0;
        for(int i=0;i<word.size();i++) {
            if(word[i]>='A'&&word[i]<='Z') cnt++;
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;
    return 0;
}
