#include<bits/stdc++.h>
#define ll long long int
#define mx 30030
#define mmx 100010
using namespace std;
int arr[mx];
vector<int>gp[mx];
int Parent[mx];
int Level[mx];
ll xrr[mmx];
ll tree[mmx*4];
ll tim=0;
ll startTime[mmx];
ll endTime[mmx];
//int brr[mx];
void buildTree(ll pos,ll low, ll high)
{
    if(low==high)
    {
        tree[pos]=xrr[low];
        return;
    }

    ll mid=(low+high)/2;
    buildTree(pos*2,low,mid);
    buildTree(pos*2+1,mid+1,high);
    tree[pos]=tree[pos*2]+tree[pos*2+1];
}

void updateTree(ll pos,ll left,ll right,ll val,ll idx)
{
   // cout<<pos<<" "<<left<<" "<<right<<" "<<val<<" "<<idx<<endl;
    //getchar();
    if(left==right&&left==idx)
    {
        tree[pos]=val;
        return;
    }
    ll mid=(left+right)/2;
    if(idx<=mid)
        updateTree(pos*2,left,mid,val,idx);
    else
        updateTree(pos*2+1,mid+1,right,val,idx);
    tree[pos]=tree[pos*2]+tree[pos*2+1];
}
//ll query_in_tree(int pos,int left,int right,int a,int b)
//{
//    if(left>b||right<a)
//        return 0;
//    if(left>=a&&right<=b)
//        return tree[pos];
//    int mid=(left+right)/2;
//    ll x=query_in_tree(pos*2,left,mid,a,b);
//    ll y=query_in_tree(pos*2+1,mid+1,right,a,b);
//    return x+y;
//}
ll query(ll pos,ll left,ll right,ll a,ll b)
{
    //cout<<pos<<" "<<left<<" "<<right<<" "<<a<<" "<<b<<endl;
    if(left>b||right<a)
        return 0;
    if(left>=a&&right<=b)
        return tree[pos];
    ll mid=(left+right)/2;
    ll x=query(pos*2,left,mid,a,b);
    ll y=query(pos*2+1,mid+1,right,a,b);
    return x+y;
}

void dfs(int from,int now,int depth)
{
    Parent[now]=from;
    Level[now]=depth;
    xrr[++tim]=arr[now];
    startTime[now]=tim;
    for(int i=0; i<gp[now].size(); i++)
    {
        int next=gp[now][i];
        if(next==from)
            continue;
        dfs(now,next,depth+1);
    }
    xrr[++tim]=-arr[now];
    endTime[now]=tim;
}


int sparseTable[mx][21];

void createSparseTable(int node)
{
    for(int i=0; i<mx; i++)
    {
        for(int j=0; j<21; j++)
        {
            sparseTable[i][j]=-1;
      //      sparseTableValue[i][j]=0;
        }
    }
    for(int i=0; i<mx; i++)
    {
        sparseTable[i][0]=Parent[i];
        //sparseTableValue[i][0]=arr[Parent[i]];
    }
    //sparseTableValue[0][0]=0;
    for(int j=1; (1<<j)<=node; j++)
    {
        for(int i=0; i<node; i++)
        {
            if(sparseTable[i][j-1]!=-1)
            {
                int immediateParent=sparseTable[i][j-1];
                sparseTable[i][j]=sparseTable[immediateParent][j-1];
                //sparseTableValue[i][j]=sparseTableValue[i][j-1]+sparseTableValue[immediateParent][j-1];
            }
        }
    }
//    for(int i=0;i<node;i++)
//    {
//        cout<<i<<" -> ";
//        for(int j=0;(1<<j)<=node;j++)
//        {
//            cout<<j<<" "<<sparseTable[i][j]<<" "<<sparseTableValue[i][j]<<endl;
//        }
//    }
}

long long int rst;
int queryOnTree(int node,int p,int q)
{

    if(Level[q]>Level[p])
        swap(p,q);
    int pp=p,qq=q;
    int log=(int)log2(node);
    rst=0;
//    rst+=arr[p];
//    rst+=arr[q];
    for(int i=log; i>=0; i--)
    {
        if(sparseTable[p][i]!=-1 && Level[p]-(1<<i)>=Level[q])
        {
            //rst+=sparseTableValue[p][i];
            p=sparseTable[p][i];
        }
    }
    if(p==q)
    {
      //  rst+=arr[pp];
        return p;
    }
    //cout<<"not found";
    for(int i=log; i>=0; i--)
    {
        if(sparseTable[p][i]!=-1&&sparseTable[p][i]!=sparseTable[q][i])
        {
            //rst+=sparseTableValue[p][i];
            //rst+=sparseTableValue[q][i];
            p=sparseTable[p][i];
            q=sparseTable[q][i];
        }
    }
    return Parent[p];
    //rst+=arr[sparseTable[p][0]];
    //rst+=arr[pp];
    //rst+=arr[qq];
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1; tst<=test; tst++)
    {
        tim=0;
        for(int i=0; i<mx; i++)
            gp[i].clear();
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            //brr[i]=arr[i];
        }
        //int last[mx],now[mx];
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        dfs(-1,0,0);
        memset(tree,0,sizeof(tree));
        buildTree(1,1,n*2);
//        for(ll i=1;i<=n*2*4;i++)
//            cout<<tree[i]<<" ";
//        cout<<endl;
//        for(int i=0;i<=n*2;i++)
//            cout<<xrr[i]<<" ";
//        cout<<endl;
        createSparseTable(n);
//        for(int i=0;i<n;i++)
//        {
//            cout<<i<<" "<<startTime[i]<<" "<<endTime[i]<<endl;
//        }

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tst);
        for(int i=0; i<q; i++)
        {
            int t,p,q;
            scanf("%d%d%d",&t,&p,&q);
            if(t==0)
            {
               int lca=queryOnTree(n,p,q);
              // cout<<"lca "<<lca<<endl;
              // cout<<startTime[lca]<<" "<<startTime[p]<<" "<<startTime[q]<<endl;
              ll x=0,y=0,z=0;
              //if(lca!=p)
               x= query(1,1,n*2,startTime[lca],startTime[p]);
              //if(lca!=q)
               y= query(1,1,n*2,startTime[lca],startTime[q]);
            // if(lca!=q&&lca!=p)
               z= query(1,1,n*2,startTime[lca],startTime[lca]);
               cout << x << " " << y << " " << z << endl;
             //cout<<x<<" "<<y<<" "<<z<<endl;
              //cout<<x+y-z<<endl;
               printf("%lld\n",x+y-z);
            }
            else if(t==1)
            {
                //arr[p]=q;
                //xrr[startTime[p+1]]=q;
                //xrr[endTime[p+1]]=-q;
               // createSparseTable(n);
               updateTree(1,1,n*2,q,startTime[p]);
               updateTree(1,1,n*2,-q,endTime[p]);
               //brr[p]=q;
              //
            }
        }
    }


    return 0;
}
/*

1
9
5 10 50 8 7 3 4 5 2
0 1
0 2
1 5
1 6
6 7
2 3
3 4
2 8

*/
