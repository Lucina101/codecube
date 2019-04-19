#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const long long inf=-1e17;
long long dp[2][maxn],ans,s[maxn],ma,sum;
int n,k,v[maxn],m;
void sf(int g){
    for(int i=0;i<=n;i++){
        dp[g][i]=inf;
    }
    return;
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        s[i]=s[i-1]+v[i];
        }
        int x;
    for(int i=0;i<=2*k;i++){
        x=i&1;sf(x);
        if(i==0){
            for(int j=1;j<=n;j++){
                dp[i][j]=s[j];
            }
            dp[0][0]=0ll;
        }
        else{
            if(x&1){
                    ma=inf;
            for(int j=0;j<=n;j++){
                if(dp[x^1][j]!=inf){
                    ma=max(ma,dp[x^1][j]);
                if(j+m>n){
                        break;
                    }
                dp[x][j+m]=max(dp[x][j+m],ma);
                }
            }
            }
            else{
                sum=inf;
                for(int j=1;j<=n;j++){
                    if(dp[x^1][j-1]!=inf){
                        sum+=v[j-1];
                        if(dp[x^1][j-1]>sum)
                            sum=dp[x^1][j-1];
                    dp[x][j]=max(dp[x][j],sum+v[j]);
                    }
                }
            }
            }
        }
    ans=inf;
    ans=max(ans,dp[1][n]);
    ans=max(ans,dp[0][n]);
    printf("%lld\n",ans);
}
