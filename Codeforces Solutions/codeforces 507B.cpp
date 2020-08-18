#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    double r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    //cerr<<dist<<endl;
    double ans=(ceil)(abs(dist)/(2.0*r));
    cout<<(int)(ans)<<endl;
    return 0;
}
