#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> MS;
    int val=1,ans=0;
    for(int i=0;i<2*n;i++){
        string str;
        cin>>str;
        if(str=="add"){
            int x;
            cin>>x;
            MS.push(x);
        }
        else{
            if(MS.empty()) continue;
            if(MS.top()==val){
                MS.pop();
            }
            else{
                while(!MS.empty()){
                    MS.pop();
                }
                ans++;
            }
            val++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
