class Solution {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        bool isCW;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isCW = false;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* cur = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (cur->children[i] == NULL) {
                cur->children[i] = new TrieNode();
            }

            cur = cur->children[i];
        }

        cur->isCW = true;
    }

    string helper(string word) {
        TrieNode* cur = root;
        string pref = "";

        for (char ch : word) {
            int i = ch - 'a';

            if (cur->children[i] == NULL) {
                return word;
            }

            cur = cur->children[i];
            pref += ch;

            if (cur->isCW) {
                return pref;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        for (string s : dictionary) {
            insert(s);
        }

        string ans = "";
        int n = sentence.size();
        int i = 0;

        while (i < n) {

            string cur_word = "";

            while (i < n && sentence[i] != ' ') {
                cur_word += sentence[i];
                i++;
            }

            ans += helper(cur_word);

            if (i < n) {
                ans += " ";
                i++;
            }
        }

        return ans;
    }
};