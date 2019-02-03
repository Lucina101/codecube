#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int n,m,k,dp[2][maxn],a[maxn],b[maxn],x[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        dp[0][i]=i;
        x[i]=i;
        }
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i&1][0]=1;
        for(int j=1;j<=m;j++){
            dp[i&1][j]=(a[i]==b[j])?dp[(i+1)&1][j-1]:2e9;
            dp[i&1][j]=min(dp[i&1][j],dp[(i+1)&1][j-1]+1);
            dp[i&1][j]=min(dp[i&1][j],dp[i&1][j-1]+1);
            dp[i&1][j]=min(x[j]+1,dp[i&1][j]);
            x[j]=min(x[j],dp[i&1][j]);
            if(dp[i&1][j]<=k){
                ans=max(ans,j);
            }
        }
    }
    printf("%d\n",ans);
}
