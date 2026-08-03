class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            int req_idx=-1;
            while(low<=high){
                int mid=(low+high)/2;
                long long prod= 1LL*spells[i] * potions[mid];
                if(prod>=success){
                    req_idx=mid;
                    high=mid-1;

                }
                else low=mid+1;
            }
            if(req_idx==-1)ans.push_back(0);
            else ans.push_back(m-req_idx);
        }
        return ans;
        
    }
};