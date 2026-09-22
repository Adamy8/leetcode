// I used three method lol over an hour, only this one identified all the cases
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> c(n,1);
        for(int i=1; i<n; i++){
            //left pass
            if(ratings[i] > ratings[i-1]) c[i] = c[i-1]+1;
        }
        for(int i=n-2; i>=0; i--){
            //right pass
            if(ratings[i] > ratings[i+1]) c[i] = max(c[i],c[i+1]+1);
        }

        int tot = 0;
        for(int i=0; i<n; i++){
            tot+=c[i];
        }
        return tot;
    }
};
// O(n) time, O(n) space
