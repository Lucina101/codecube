#include<bits/stdc++.h>
using namespace std;
const int mod=53;
char a[2005],b[2005];
long long f[int(2e6)+3000];
int n,m;
long long p[30];
int main(){
    p[0]=1;
    for(int i=1;i<=26;i++){
        p[i]=p[i-1]*mod;
    }
    scanf("%s %s",a,b);
    n=strlen(a);
    m=strlen(b);
    long long h=0;
    int pt=0;
    for(int i=0;i<n;i++){
        h=0;
        for(int j=i;j<n;j++){
            h+=(p[a[j]-'A'+1]);
            pt++;
            f[pt]=h;
        }
    }
    int ans=0;
    sort(f+1,f+1+pt);
    for(int i=0;i<m;i++){
        h=0;
        for(int j=i;j<m;j++){
                h+=(p[b[j]-'A'+1]);
            if(binary_search(f+1,f+1+pt,h))
                ans=max(ans,j-i+1);
            }
        }
    printf("%d\n",ans);

    }

