#include<bits/stdc++.h>
using namespace std;

int power[100];
set<int> S;

void calc() {
    power[0]=1;
    S.insert(1);
    for(int i=1;i<=31;i++) {
        power[i]=power[i-1]*2;
        S.insert(power[i]);
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int h,w;
    cin>>h>>w;
    while(true) {
        double rat=(double)(1.0*h/w);
        if(rat>=0.8&&rat<=1.25) {
            if(S.find(h)!=S.end()||S.find(w)!=S.end()) break;
        }
        if(S.find(h)==S.end()&&S.find(w)==S.end()) w--;
        if(rat<0.8) w--;
        if(rat>1.25) h--;
        //cerr<<h<<" "<<w<<endl;
        //getchar();
    }
    cout<<h<<" "<<w<<endl;
    return 0;
}
