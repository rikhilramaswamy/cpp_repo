class WordDictionary {
public:
    
    unordered_map<char, WordDictionary*> m1;
    typedef pair<char, WordDictionary*> m1_pair;
    bool is_word;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        is_word =false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary * temp = this;
        
        for(auto e: word){
            auto itr = temp->m1.find(e);
            if(itr == m1.end()){
                WordDictionary * t = new WordDictionary();
                // t->is_word = true;
                temp->m1.insert(m1_pair(e, t));
                temp = t;
            } else {
                temp = itr->second;
            }
        }
        
        temp->is_word = true;
        
        
    }
    
    bool dfs_helper(WordDictionary * t, string word, int i){
        if( i == word.size()) {
            if(t->is_word )
                return true;
            return false;
        }
        
            auto itr = t->m1.find(word[i]);
            if (itr !=  t->m1.end()){
                t = itr->second;
                return dfs_helper(t, word , i+1);
            } else {
                if( word[i] == '.'){
                    bool res = false ;
                    for(auto elem :t->m1 ){
                        res =  dfs_helper(elem.second, word, i+1);
                        if(res)
                         return true;
                    }
                    
                    return false;
                    
                }
                
                return false;
                
                
            }
        
            return true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary * temp = this;
        
        for(int i =0 ; i < word.size(); i++){
            auto itr = temp->m1.find(word[i]);;
            if( itr != temp->m1.end()){
                temp = itr->second;
            } else {
                if( word[i] == '.'){
                    // do dfs from here 
                    return dfs_helper(temp, word, i);
                }
                
                return false;
                
            }
        }
        
        return temp && temp->is_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
