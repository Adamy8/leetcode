#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin >> n;

    int parent[n+1], depth[n+1];
    depth[1]=1;

    for(int i=2;i<=n;i++){
        cin>>parent[i];
        depth[i] = depth[parent[i]+1];
    }
    unordered_map<int,int> count;//fam count for each layer
    // count[1]=1;
    for(int i=2;i<=n;i++){
        count[depth[i]]+=1;
    }
    int ans = 0;
    for(auto &itm:count){
        ans = max(ans, itm.second -1 );
    }
    cout<<ans<<endl;
}