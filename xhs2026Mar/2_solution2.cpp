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
        //用dp：A, B, C -> end with a,b,c
        vector<long long> A(n+1), B(n+1), C(n+1), F(n+1);
        F[0] = 1;
        for(int k=1; k<=n; k++){
            if(k>=a) A[k] = F[k-a];
            if(k>=b) B[k] = F[k-b];
            if(k>=c) C[k] = abs(F[k-c] - A[k-c]);    // no a-c
            F[k] = (A[k] + B[k] + C[k]) % MOD;
        }
        for(int k=1;k<=n;k++){
            cout<< F[k] << " ";
        }
        cout<<'\n';
    }
    return 0;
}