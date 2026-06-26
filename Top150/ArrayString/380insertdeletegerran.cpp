class RandomizedSet {
    unordered_map<int, int> structure;
    vector<int> keys;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(structure.find(val)!=structure.end()) return false;
        else{
            keys.push_back(val);
            structure[val] = keys.size()-1; // record store loc
            return true;
        }
    }
    
    bool remove(int val) {
        if(structure.find(val)!=structure.end()){
            structure[keys.back()] = structure[val];
            
            swap(keys[structure[val]], keys.back());
            // one improvement here is to record structure[val] and keys.back() to variables
            // to avoid reaccess them twice

            keys.pop_back();
            structure.erase(val);
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int key = keys[rand() % keys.size()];
        return key;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
