class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        
        unordered_map<int,int>map;
        for(int i:arr){
            map[i]++;
        }
        unordered_set<int> sett;
        for(auto &pair : map){
            if(sett.find(pair.second)!=sett.end()) return false;
            sett.insert(pair.second);
        }
        return true;
        
    }
};