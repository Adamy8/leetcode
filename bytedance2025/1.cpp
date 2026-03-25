#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int count, len;
    cin >> count;
    while(count--){
    	cin>>len;
        vector<int> arr(len);
        for(int j=0;j<len;j++){
            cin>>arr[j];
        }
        if(len<3){
            cout<<"No\n";
            continue;
        }
        sort(arr.begin(),arr.end());
        
        if (arr[0] + arr[1] <= arr[len - 1])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
}
// 64 位输出请用 printf("%lld")