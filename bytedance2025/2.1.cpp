#include <iostream>
#include<functional>   // come with hash
#include<cmath>
using namespace std;
int main() {
    hash<string> h;
    int n, q;
    cin>>n>>q;
    string T,P;
    cin>>T;
    while(q--){
        cin>>P;
        int len = P.size();
        int count = 0;
        int hpattern = h(P);
        for(int i=0;i<= T.size()-len ;i++){
            string window=T.substr(i,len);
            int hwindow = h(window);
            if(hwindow==hpattern && window==P) count++;
        }
        cout<<count<<endl;
    }
    
}

// 64 位输出请用 printf("%lld")
