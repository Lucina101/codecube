#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> g;
int n,q,x,l,r,c;

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&l,&r,&c);
        auto u=lower_bound(g[c].begin(),g[c].end(),l);
        auto v=upper_bound(g[c].begin(),g[c].end(),r);
        printf("%d\n",int(v-u));
    }
}
