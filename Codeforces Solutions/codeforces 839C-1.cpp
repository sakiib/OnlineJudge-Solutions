#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100010];

double DFS(int start,int parent) {
    double total=0.0;
    int steps=0;
    for(int i=0;i<graph[start].size();i++) {//connected edges with start node
        if(graph[start][i]!=parent) {
        total+=(DFS(graph[start][i],start))+1;//new start & parent
            steps++;//steps update
        }
    }
    //cout<<setprecision(5)<<fixed;
    //cout<<"S "<<start<<" P "<<" "<<parent<<" "<<" T "<<total<<" "<<steps<<" "<<" T ";
    if(steps!=0) {//if atleast 1 step done
        total/=(steps);//expected value [(a+b)/2=(a/2+b/2)]
    }
    //cout<<total<<" "<<steps<<endl;
    return total;
}
int main(int argc,char const *argv[]) {
    int node;
    cin>>node;
    for(int i=1;i<=node-1;i++) {
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);//undirected edges a to b
        graph[to].push_back(from);// also b to a
    }
    double ans=DFS(1,0);//starting node has no parent
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
