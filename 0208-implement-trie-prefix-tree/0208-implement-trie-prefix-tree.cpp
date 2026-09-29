class TrieNode{
    public:
    TrieNode* children[26];
    bool isCW;
    TrieNode(){
        for (int i=0;i<26;i++){
            children[i]=NULL;
        }
        isCW=false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();

        
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char ch:word){
            int i=ch-'a';
            if(cur->children[i]==NULL){
                cur->children[i]=new TrieNode();
            }
            cur=cur->children[i];
        }
        cur->isCW=true;

        
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char ch:word){
            int i=ch-'a';
            if(cur->children[i]==NULL) return false;
            cur=cur->children[i];
        }
        return cur->isCW;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char ch : prefix){
            int i=ch -'a';
            if(cur->children[i]==NULL) return false;
            cur=cur->children[i];

        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
