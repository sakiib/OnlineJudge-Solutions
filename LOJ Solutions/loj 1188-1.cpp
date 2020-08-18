#include<bits/stdc++.h>
using namespace std;

const int N=100005;

struct segment {
    int num,dist;
    segment() {}
    segment(int _num,int _dist) {
        num=_num; dist=_dist;
    }
    bool comp(segment a,segment b) {
        if(a.dist==b.dist) return a.num<b.num;
        return a.dist<b.dist;
    }
} tree[4*N];

int main(int argc,char const *argv[]) {
    tree[1]={1,2};
    cout<<tree[1].num<<endl;
    cout<<tree[1].dist<<endl;
    return 0;
}
