/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

typedef unordered_map<Node *, Node *> myMap;
typedef pair<Node *, Node *> myMap_pair;
typedef unordered_set<Node *> mySet;
typedef vector<Node *> vn;
#define pb push_back
class Solution {
public:
    
    void cloneGraph_helper_dfs(Node *node,myMap& m1,  mySet &s1){
         s1.insert(node);

        auto itr = m1.find(node);
        Node *n = NULL;
        if(itr == m1.end()){
            vn v1;
            n = new Node(node->val,v1 );
            m1.insert(myMap_pair(node, n));
        } else {
            n = itr->second;
        }
        
        vn & tempv = node->neighbors;
        for(auto & e: tempv){
         
            // do DFS if not visited
            auto niter = s1.find(e);
            if(niter == s1.end()) {
                cloneGraph_helper_dfs(e, m1, s1);
                // add edges 
                // first find the associted n-dash
                
            }
                auto itr = m1.find(e);
                assert(itr != m1.end());
                (n->neighbors).pb(itr->second); // create only one way EDGE 
                //((itr->second)->neighbors).pb(n); // This should NOT be done
            
        }
        
    }
    
    
    Node* cloneGraph(Node* node) {
        myMap m1;
        mySet s1;
        
        cloneGraph_helper_dfs(node , m1, s1 );
        
        auto itr = m1.find(node);
        assert(itr != m1.end());
        
        cout<<"\n set size: "<<s1.size();
        cout<<"\n map size: "<<m1.size();
        cout<<"neighbors of 1 are: ";
        for(auto e : (itr->second)->neighbors){
            cout<<"\t elem: "<<e->val;
        }
        return itr->second;
        
        
    }
};
