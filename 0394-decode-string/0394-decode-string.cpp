class Solution {
public:
    string decodeString(string s) {
        stack<string> my_st;
        for(char ch: s){
            if(ch != ']') {
                my_st.push(string(1, ch));
            } else {
                // Step 1: Get the string inside brackets
                string temp = "";
                while(my_st.top() != "["){
                    temp = my_st.top() + temp;
                    my_st.pop();
                }
                my_st.pop(); // remove '['

                // Step 2: Get the number before '['
                string num = "";
                while(!my_st.empty() && isdigit(my_st.top()[0])){
                    num = my_st.top() + num;
                    my_st.pop();
                }
                int rep_num = stoi(num);

                // Step 3: Repeat the string
                string repeated_str = "";
                while(rep_num--){
                    repeated_str += temp;
                }

                // Step 4: Push back to stack
                my_st.push(repeated_str);
            }
        }

        // Final answer
        string ans = "";
        while(!my_st.empty()){
            ans = my_st.top() + ans;
            my_st.pop();
        }
        return ans;
    }
};
