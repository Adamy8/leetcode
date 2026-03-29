#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int MOD = pow(10,9)+7;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,a,b,c;
        cin >> n >>a >>b >>c;
        //用dp：dp[k][a] = k end with a
        vector<vector<int>> dp(n + 1,vector<int>(3));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        for(int k=1; k<=n; k++){
            if(k>=a) dp[k][0] = dp[k-a][0] + dp[k-a][1] + dp[k-a][2];
            if(k>=b) dp[k][1] = dp[k-b][0] + dp[k-b][1] + dp[k-b][2];
            if(k>=c) dp[k][2] = dp[k-c][1] + dp[k-c][2];    // no a-c
        }
        for(int k=1;k<=n;k++){
            cout<< (dp[k][0] + dp[k][1] + dp[k][2]) % MOD << " ";
        }
        cout<<endl;
    }
    return 0;
}