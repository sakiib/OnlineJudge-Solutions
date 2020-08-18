#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cst[10000],cen[10000],pst[10000],pen[10000];
    scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       scanf("%d%d",&cst[i],&cen[i]);
   }
   sort(cen,cen+t);
   sort(cst,cst+t);
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d%d",&pst[i],&pen[i]);
   }
   sort(pst,pst+n);
   sort(pen,pen+n);
   if(pst[n-1]-cen[0]<0||pen[0]-cst[n-1]<0)
   printf("0\n");
   else
   printf("%d\n",max(pst[n-1]-cen[0],pen[0]-cst[n-1]));
   return 0;
}
