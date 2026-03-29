#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int temp = n, sum = 0;
        for(int i=2; i*i <= temp; i++){
            if(temp % i ==0){
                sum += i;
                while(temp % i ==0) temp /= i;
            }
        }
        if(temp>1) sum += temp;

        if(sum % 2 != 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}