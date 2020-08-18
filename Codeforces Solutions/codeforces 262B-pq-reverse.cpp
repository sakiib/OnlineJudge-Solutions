#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > PQ;
//Priority Queue Reverse Operation//
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int num;
    for(int i=0;i<n;i++) {
        cin>>num;
        PQ.push(num);
    }
    for(int i=0;i<k;i++) {
        int x=PQ.top();
        x*=(-1);
        PQ.pop();
        PQ.push(x);
    }
    int sum=0;
    while(!PQ.empty()) {
        sum+=PQ.top();
        PQ.pop();
    }
    cout<<sum<<endl;
    return 0;
}
