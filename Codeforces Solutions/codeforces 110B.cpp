#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    char str[4][10]={"a","b","c","d"};
    for(int i=0;i<n;i++) {
        cout<<str[i%4];
    }
    return 0;
}
