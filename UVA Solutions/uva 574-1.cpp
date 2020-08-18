#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> nlist;
vector< vector<int> > finlist;
bool used[20];
map< vector<int>, bool > mp;
int t;

int btracking(int sum, vector<int> temp, int k) {
    //if (!sum) solve[i].clear();
    if (sum == t) {
        if (!mp[temp]) {
            finlist.push_back(temp);
            mp[temp] = true;
        }
        return 0;
    }
    for (k ; k<nlist.size() ; k++) {
        if (!used[k]) {
            if (nlist[k]<=(t-sum)) {
                sum+=nlist[k];
                temp.push_back(nlist[k]);
                used[k] = true;
                btracking( sum, temp, k);
                used[k] = false;
                temp.pop_back();
                sum-=nlist[k];
            }
        }
    }
    return 0;
}
int main( void ) {
    int  n, i, j, x;
    //freopen("574_in.txt","r+",stdin);
    while ( scanf("%d %d",&t,&n) == 2 ) {
        if (!n) break;

        printf("Sums of %d:\n",t);

        nlist.clear();
        for (i=0 ; i<n ; i++) {
            scanf("%d",&x);
            nlist.push_back(x);
            used[i] = false;
        }
        //cout << "-----> " << nlist.size() << endl;
        finlist.clear();
        vector<int> temp;
        temp.clear();
        mp.clear();
        btracking( 0, temp, 0);

        if (!finlist.size()) {
            printf("NONE\n");
        }
        //printf("--> %d\n",finlist.size());
        for (i=0 ; i<finlist.size() ; i++) {
            for (j=0 ; j<finlist[i].size() ; j++) {
                if (!j) printf("%d",finlist[i][j]);
                else printf("+%d",finlist[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
