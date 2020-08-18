#include<bits/stdc++.h>
using namespace std;
vector<int> V;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k,item,x,y,z,sum=0;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>item;
        V.push_back(item);
    }
    while(n--){
        for(int j=0;j<m;j++){
            cin>>x;
            sum+=V[x-1];
            y=V[x-1];
            y--;
            z=V[y];
            V.erase(V.begin()+y);
            V.insert(V.begin()+0,z);
           for(int i=0;i<V.size();i++){
                cout<<V[i]<< " ";
            }
            cout<<endl;
        }
    }
    cout<<sum<<endl;
    return 0;
}
