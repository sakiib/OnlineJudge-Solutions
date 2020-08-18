#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        deque<int> Q;
        int s,n;
        cin>>s>>n;
        int cnt=0;
        printf("Case %d:\n",tc);
        while(n--) {
            string str;
            cin>>str;
            if(str=="pushLeft"||str=="pushRight") {
                int val;
                cin>>val;
                if(Q.size()==s) {
                    cout<<"The queue is full"<<endl;
                }
                else if(str=="pushLeft") {
                    cout<<"Pushed in left: "<<val<<endl;
                    Q.push_front(val);
                }
                else if(str=="pushRight") {
                    cout<<"Pushed in right: "<<val<<endl;
                    Q.push_back(val);
                }
            }
            else if(str=="popLeft"||str=="popRight") {
                if(Q.size()==0) {
                    cout<<"The queue is empty"<<endl;
                }
                else if(str=="popLeft") {
                    cout<<"Popped from left: "<<Q.front()<<endl;
                    Q.pop_front();
                }
                else if(str=="popRight") {
                    cout<<"Popped from right: "<<Q.back()<<endl;
                    Q.pop_back();
                }
            }
        }
    }
    return 0;
}
