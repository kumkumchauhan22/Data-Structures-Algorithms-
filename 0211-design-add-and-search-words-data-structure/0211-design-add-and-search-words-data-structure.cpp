class TrieNode{
public:
    TrieNode* arr[26];
    bool isCW;
    TrieNode(){
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
        isCW=false;
    }

};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
        
    }
    
    void addWord(string word) {
        TrieNode* cur=root;
        for(char ch:word){
            int i=ch-'a';
            if(cur->arr[i]==NULL){
                cur->arr[i]=new TrieNode();
            }
            cur=cur->arr[i];
        }
        cur->isCW=true;
        
    }
    bool dfs(int i, string word, TrieNode* cur){
        if(i==word.size()) return cur->isCW;
        if(word[i]!='.'){
            int idx=word[i]-'a';
            if(cur->arr[idx]==NULL) return false;
            return dfs(i+1,word,cur->arr[idx]);
        }
        for(int j=0; j<26;j++){
            if(cur->arr[j]!=NULL){
                if(dfs(i+1,word,cur->arr[j])) return true;
            }
        }
        return false; 
    }
    bool search(string word) {
        return dfs(0,word,root);

        
    
   
        }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */