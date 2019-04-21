#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int edit_distance(string a,string b,int n,int m){

    for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
    }
    for (int j = 0; j <= n; j++) {
            dp[j][0] = j;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
    }
    return dp[n][m];
}

void actual_edit(string a,string b,int n,int m){
    int i=n;
    int j=m;
    int cnt=1;
    while(i>0||j>0){
        if(i>0&&j>0&&(a[i-1]==b[j-1])){
            i--;
            j--;
            continue ;
        }
        if(i>0&&(dp[i-1][j]+1==dp[i][j])){
            printf("%d Delete %d\n",cnt++,i);
            i--;
        }
        else if(i>0&&j>0&&(dp[i][j]==dp[i-1][j-1]+1)){
            printf("%d Replace %d,%c\n",cnt++,i,b[j-1]);
            i--;
            j--;
        }
        else if(j>0){
            printf("%d Insert %d,%c\n",cnt++,i+1,b[j-1]);
            j--;
        }
    }
}

int main(){
    string a,b;
    bool ok=false;
    while(getline(cin,a)){
        getline(cin,b);
        int n=a.size();
        int m=b.size();
        int res=edit_distance(a,b,n,m);
        if(ok){
            printf("\n");
        }
        ok=true;
        printf("%d\n",res);
        actual_edit(a,b,n,m);
    }
    return 0;
}
