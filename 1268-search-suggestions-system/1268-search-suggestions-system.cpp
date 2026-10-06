class TrieNode {
public:
    TrieNode* arr[26];
    vector<string> sugg;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            arr[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* cur = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (cur->arr[i] == NULL) {
                cur->arr[i] = new TrieNode();
            }

            cur = cur->arr[i];

            if (cur->sugg.size() < 3) {
                cur->sugg.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        vector<vector<string>> ans;

        sort(products.begin(), products.end());

        for (string &s : products) {
            insert(s);
        }

        TrieNode* cur = root;

        for (char ch : searchWord) {
            int i = ch - 'a';

            if (cur != NULL && cur->arr[i] != NULL) {
                cur = cur->arr[i];
                ans.push_back(cur->sugg);
            } else {
                cur = NULL;
                ans.push_back({});
            }
        }

        return ans;
    }
};