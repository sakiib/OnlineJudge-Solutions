#include<bits/stdc++.h>
using namespace std;

int c[100],b[100],ba[100];
int chest,bicep,bac;
priority_queue<int> PQ;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n; ) {
        cin>>c[i],i++;
        if(i==n) break;
        cin>>b[i],i++;
        if(i==n) break;
        cin>>ba[i],i++;
        if(i==n) break;
    }
    for(int i=0;i<n;i++) {
        chest+=c[i];
        bicep+=b[i];
        bac+=ba[i];
    }
    if(chest>bicep&&chest>bac) cout<<"chest"<<endl;
    else if(bicep>chest&&bicep>bac) cout<<"biceps"<<endl;
    else cout<<"back"<<endl;
    //cout<<chest<< " "<<bicep<< " "<<bac<<endl;

    return 0;
}
