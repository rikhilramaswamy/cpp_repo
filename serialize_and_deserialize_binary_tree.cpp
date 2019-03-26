/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef vector<string> vs;
#define pb push_back
class Codec {
public:
    void serialize_helper(TreeNode * t, vs & orig){
        if( t == NULL){
            orig.pb("n");
            return;
        }
        
        orig.pb(to_string(t->val));
        
        serialize_helper(t->left, orig);
        serialize_helper(t->right, orig);
        
    }
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        vs orig;
        serialize_helper(root, orig);
        string res;
        
        for(int i = 0; i < orig.size(); i++){
            if(i == orig.size() -1)
                 res += orig[i];
            else 
                res += orig[i] + ",";
        }
        
       /* cout<<"\n res: "<<res;*/
        
        return res;
    }

    TreeNode * deserialize_helper(vs & orig, int * index){
        if (*index == orig.size()){
            return NULL;
        }
        
        TreeNode * t = NULL;
        if( orig[*index] != "n"){
            t = new TreeNode(stoi(orig[*index]));
            ++(*index);
        } else {
            ++(*index);
            return t;
        }
        
        t->left = deserialize_helper(orig, index);
        t->right = deserialize_helper(orig, index);
        
        return t;
        
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // convert string data to vs
        vs temp;
        string buff = data;
        while(!buff.empty()){
            auto pos = buff.find(',');
            if( pos != string::npos) {
                string t = buff.substr(0, pos);
                buff = buff.substr(pos+1);
                temp.pb(t);
            } else {
                temp.pb(buff);
                buff = "";
            }
        }
        
       /* cout<<"\n new array is ....";
        for(auto e: temp){
            cout<<"\t "<<e;
        }*/
        int index =0;
        return deserialize_helper(temp, &index);
                
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
