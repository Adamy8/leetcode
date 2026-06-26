class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(!citations.size()) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0; i<citations.size(); i++){
            if( i+1 > citations[i]) return i;
        }
        return citations.size();
    }
};
// my solution, reversely sort. O(nlogn) time, O(1) space

//O(n) time, use extra spaceO(n): I lwk didn't fully understand
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> temp(n+1, 0);

        for(int citation: citations){
            if(citation > n) temp[n]++;
            else temp[citation]++;
        }

        int total = 0;
        for(int i=n; i>=0; i--){
            total += temp[i];
            if(total >= i) return i;
        }
        return 0;
    }
};