#include<bits/stdc++.h>
using namespace std;

priority_queue<int> PQ;

int main(int argc,char const *argv[]) {
    int n,m,k,num;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        cin>>num;
        PQ.push(num);
    }
    int sum=0;
    int t=0;
    while(true) {
        while(!PQ.empty()) {
            int x=PQ.top();
            if(k>0) {
               sum+=(x);
               k--;
               t++;
               PQ.pop();
               //cerr<<"s :"<<sum<<endl;
               if(sum+k>=m) {
                cout<<t<<endl;
                return 0;
               }
            }
            else {
                sum+=t+1;
                sum+=(x-1);
                t++;
                PQ.pop();
                if(sum>=m) {
                    cout<<t<<endl;
                    return 0;
                }
            }
        }
        cout<<-1<<endl;
        return 0;
    }
    return 0;
}
