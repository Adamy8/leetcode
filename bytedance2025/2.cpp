#include <iostream>
#include<cmath>
using namespace std;
int myhash(string s,int len);
int main() {
    int n, q;
    cin>>n>>q;
    string T,P;
    cin>>T;
    while(q--){
        cin>>P;
        int len = P.size();
        int count = 0;
        int hpattern = myhash(P,len);
        for(int i=0;i<= T.size()-len ;i++){
            string window=T.substr(i,len);
            int hwindow = myhash(window,len);
            if(hwindow==hpattern && window==P) count++;
        }
        cout<<count<<endl;
    }
    
}
int myhash(string s, int len){
    int hv=0;
	for(int i=0;i<len;i++){
        hv+=(int)s[i] * pow(10,i);
    }
    return hv;
}
// 64 位输出请用 printf("%lld")

