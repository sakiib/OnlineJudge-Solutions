#include<bits/stdc++.h>
using namespace std;
set<int>xax;
set<int>yax;
vector<int>xi;
vector<int>yi;
int main()
{
    int n,x,y;
    cin>>n;
    if(n==1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xax.insert(x);
        yax.insert(y);
    }
    set<int> :: iterator it;
    if(xax.size()==2||yax.size()==2){
       for(it=xax.begin();it!=xax.end();it++){
         int z=*it;
         xi.push_back(z);
       }
       for(it=yax.begin();it!=yax.end();it++){
         int z=*it;
         yi.push_back(z);
       }
       for(int i=0;i<)
    }
    else{
        cout<<-1<<endl;
        return 0;
    }

}
