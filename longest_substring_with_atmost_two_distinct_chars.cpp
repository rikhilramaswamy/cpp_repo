typedef unordered_set<char> mySet;
typedef unordered_map<char, int> myMap;
typedef pair<char, int> myMap_pair;
class Solution {
public:
    /*int lengthOfLongestSubstringTwoDistinct_helper(string &s){
        int max_len_sofar = INT_MIN;
        
        for(int i=0; i < s.length(); ++i){
            mySet s1;
            for(int j =i; j < s.length(); ++j){
                s1.insert(s[j]);
                if(s1.size() >0 && s1.size() <=2){
                    int temp = j-i+1;
                    max_len_sofar = max(temp, max_len_sofar);
                }
                
            }
        }
        
        return max_len_sofar;
    }*/
    
    bool valid_string (myMap &m1){
        return (m1.size() > 0  && m1.size() <=2);
    }
    
    /* sliding window method (longest substring ):
    Shrink: INVALID
    Expand: valid 
    */
    // FYI: This logic is opposite to that of shortest substring with criteria
    // expand: if INVALID; Shrink; once window is valid
    int lengthOfLongestSubstringTwoDistinct_helper(string &s){
        myMap m1;
        int max_sofar = INT_MIN;
        
        int st=0;
        int i =0;
        //for(int i=0; i < s.length(); i++){
        while( i < s.length()) {
            auto itr = m1.find(s[i]);
            if(itr == m1.end()){
                m1.insert(myMap_pair(s[i], 1));
            } else {
                ++(itr->second);
            }
            
            if(valid_string(m1)){
                int window_len = i -st +1;
                max_sofar = max(max_sofar,window_len );
                i++;
                continue;
            }
            
            while(!valid_string(m1) && st <=i){
                // remove char at st from map;
                cout<<"\n inside loop: st: "<<st<<"\t i : "<<i;
                cout<<"m1.size(): "<<m1.size();
                auto itr = m1.find(s[st]);
                assert(itr != m1.end());
                assert(itr->second != 0);
                --(itr->second);
                if(itr->second ==0)
                    m1.erase(s[st]);
                st++; 
            }
            
            
        }
        
        return max_sofar;
        
    }
    
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        return lengthOfLongestSubstringTwoDistinct_helper(s);
    }
};
