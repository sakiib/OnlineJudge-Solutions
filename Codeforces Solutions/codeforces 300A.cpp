#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    vector<int> P,N,Z;
    for(int i=1;i<=n;i++) {
        int num;
        cin>>num;
        if(num<0) N.push_back(num);
        else if(num>0) P.push_back(num);
        else Z.push_back(num);
    }
    if(N.size()%2==0) {
        Z.push_back(N[0]);
        N.erase(N.begin()+0);
    }
    /*for(int i=0;i<N.size();i++) {
        cout<<N[i]<< " ";
    }*/
    if(P.size()==0) {
        P.push_back(N[0]);
        P.push_back(N[1]);
        N.erase(N.begin()+0,N.begin()+2);
    }
    /*for(int i=0;i<N.size();i++) {
        cout<<N[i]<< " ";
    }*/
    cout<<N.size()<< " ";
    for(auto &x:N) cout<<x<< " ";
    cout<<endl;
    cout<<P.size()<< " ";
    for(auto &x:P) cout<<x<< " ";
    cout<<endl;
    cout<<Z.size()<< " ";
    for(auto &x:Z) cout<<x<< " ";
    return 0;
}
