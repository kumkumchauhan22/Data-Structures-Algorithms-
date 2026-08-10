class Solution {
public:
    string removeStars(string s) {
        stack<char>my_stack;

        for(char ch: s){
            if(ch!='*') my_stack.push(ch);
            else my_stack.pop();
        }
        string ans="";
        while(!my_stack.empty()){
            ans+=my_stack.top();
            my_stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};