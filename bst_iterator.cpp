/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> ms;
   
    void push_left(TreeNode* root){
        TreeNode * temp = root;
        if(temp != NULL){
            while(temp != NULL){
                ms.push(temp);
                temp = temp->left;
            }
        }
    }
    
    BSTIterator(TreeNode* root) {
        TreeNode * temp = root;
        push_left(temp);
    }
    
    /** @return the next smallest number */
    int next() {
       
        if(hasNext()){
            TreeNode *t = ms.top();
            ms.pop();
            push_left(t->right);
            return t->val; 
       }
        
        return -1;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return !ms.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
