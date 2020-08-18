#include<bits/stdc++.h>
using namespace std;
double INF=36727828282892.00;
double distance(int x1,int y1,int x2,int y2);
int main()
{
    int m1,m2,t1,t2,v,n;
    double dist,time;
    cin>>m1>>m2;
    cin>>n;
    while(n--){
        cin>>t1>>t2>>v;
        dist=distance(m1,m2,t1,t2);
        time=dist/v;
        if(time<INF){
            INF=time;
        }
    }
    cout<<setprecision(10)<<INF<<endl;

}
double distance(int x1,int y1,int x2,int y2)
{
    double ans;
    ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return ans;
}
