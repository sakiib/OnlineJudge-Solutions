/*
 Convex Hull (Attempt : 1)
 Algorithm : Graham Scan
 Complexity : O(NlogN)
*/
#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;

struct point {
    double x,y;
};
vector<point> V;
point pivot;//it keeps the Lower-leftmost point(for global reference)
stack<point> ans;

double dist(point a,point b) {
    double p=a.x-b.x;
    double q=a.y-b.y;
    return (p*p+q*q);//no need to sqrt it
}
int Turn(point a,point b,point c) { // a->pivot,b second & c 3rd point
    double area=(b.x*c.y-b.y*c.x)+(a.y*c.x-a.x*c.y)+(a.x*b.y-a.y*b.x);//Shoe-lace formula
    if(area>0.0) return 1; // Left Turn
    else if(area==0.0) return 0; // co-linear
    else return -1;// Right Turn;
}
bool cmp(point a,point b) {
    int option=Turn(pivot,a,b);
    if(option==0) return (dist(pivot,a)<dist(pivot,b));//if co-Linear,small distance first
    else return (option==1); // otherwise
}
void Graham_Scan() {
    ans.push(V[0]);
    ans.push(V[1]);
    ans.push(V[2]);
    for(int i=3;i<V.size();i++) {
        point T=ans.top();
        ans.pop();
        while(Turn(ans.top(),T,V[i])!=1) {
            T=ans.top();
            ans.pop();
        }
        ans.push(T);
        ans.push(V[i]);
    }
}
int main(int argc,char const *argv[]) {
    //Let's consider these points for the time being..
    int tc=1;
    int n;
    bool f=false;
    while(scanf("%d",&n)) {
    if(n==0) break;
    if(f) printf("\n");
    f=true;
    for(int i=1;i<=n;i++) {
        double x,y;
        cin>>x>>y;
        V.push_back({x,y});
    }
    if(n<3) {
        printf("Region #%d:\n",tc++);
        for(int i=0;i<V.size();i++) {
            cout<<"("<<V[i].x<<","<<V[i].y<<")"<<"-";
        }
        cout<<"("<<V[0].x<<","<<V[0].y<<")"<<endl;
        cout<<"Perimeter length = "<<setprecision(2)<<fixed<<0.0<<endl;
        V.clear();
        continue;
    }
    point L={inf,inf};//to store Lowest Leftmost point

    //Iterate over all points to find the Lowest-Leftmost
    //Point,We can do this while taking input as well.
    int idx=0;
    for(int i=0;i<V.size();i++) {
       if(V[i].y<L.y||(V[i].y==L.y&&V[i].x<L.x)) {
        L.y=V[i].y , L.x=V[i].x;
        idx=i;
       }
    }
    /*for(auto P : V) {
        cout<<P.x<<" "<<P.y<<endl;
    }*/
    //cout<<"*****************"<<endl;
    //Let's bring the Lower-Leftmost point at the first position
    //By swaping its position with the point initially at first position.
    swap(V[0].x,V[idx].x);
    swap(V[0].y,V[idx].y);
    pivot=V[0];
    /*
    cout<<"Lowest-Leftmost : "<<L.x<<" "<<L.y<<endl;//here we have the Lowest Leftmost point
    cout<<"pivot : "<<pivot.x<<" "<<pivot.y<<endl;
    cout<<"Before Sorting.."<<endl;
    for(auto P : V) {
        cout<<P.x<<" "<<P.y<<endl;
    }
    cout<<"******************"<<endl;
    */
    //Let's sort all the points skipping the first one by their polar angle
    sort(++V.begin(),V.end(),cmp);
    /*cout<<"After Sorting..."<<endl;
    for(auto P : V) {
        cout<<P.x<<" "<<P.y<<endl;
    }*/
    Graham_Scan();
    //cout<<"*******************"<<endl;
    //cout<<"Points in Convex Hull: "<<endl;
    /*if(ans.size()<3) {
        cout<<"Convex Hull not Possible"<<endl;
        return 0;
    }*/
    double perimeter=0.0;
    printf("Region #%d:\n",tc++);
    vector<point> A;
    point last=ans.top();
    while(!ans.empty()) {
        point to=ans.top();
        ans.pop();
        A.push_back(to);
    }
    A.push_back(last);
    cout<<setprecision(1)<<fixed;
    for(int i=0;i<A.size()-1;i++) {
        perimeter+=sqrt(dist(A[i],A[i+1]));
        //cout<<A[i].x<<" "<<A[i].y<<" "<<A[i+1].x<<" "<<A[i+1].y<<endl;
        cout<<"("<<A[i].x<<","<<A[i].y<<")"<<"-";
    }
    cout<<"("<<last.x<<","<<last.y<<")"<<endl;
    cout<<"Perimeter length = "<<setprecision(2)<<fixed<<perimeter<<endl;
    V.clear();
    A.clear();
    }
    return 0;
}

