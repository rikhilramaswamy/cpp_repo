/*Question (leetcode 201): There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

*/
typedef unordered_map<int, int>myMap;

typedef pair<int, int> myMap_pair;
typedef vector<int> vi;
typedef vector< vi> vii;

typedef set<int> si;
typedef stack<int> sti;

#define pb push_back
class Solution {
public:
    /* graph problem : top sort
    1) construct a graph
    2) do reverse order DFS (check if cycle exists=> return empty array )
    2b) Else collect the nodes onto stack after DFS completes
        numCourses => # of nodes
        unvisited: -1
        visiting: 0
        visited: 1
    */
    
    bool DFS(vii & graph, int node ,  sti & ss, vi &visited){
        // mark as visiting
        visited[node] = 0;
        
        vi & temp = graph[node];
        
        for(auto t: temp){
            // cycle exists
            if(visited[t] == 0)
                return false;
            
            if(visited[t] == -1){
                if(!DFS(graph, t, ss, visited))
                    return false;
            }
            
        }
        
        ss.push(node);
        visited[node] = 1; // completed
        return true;
        
    }
    
    bool DFS_main(vii & graph, sti & ss, vi &visited) {
        
        for(int i=0; i < graph.size(); i++){
            if(visited[i] == -1){
                if(!DFS(graph, i, ss,visited))
                    return false;
            }
        }
        
        return true;
        
    }
    
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vii graph(numCourses, vi (0,0));
        vi res;
        vi visited(numCourses, -1);
        
        // construct graph
        for(auto&  p: prerequisites){
            vi & temp = graph[p.second];
            temp.pb(p.first);
        }
        sti ss;
        
        // there seems to be a cycle 
        if(!DFS_main(graph, ss, visited))
            return res;
        
        if(!ss.empty()){
            // populate res
            while(!ss.empty()){
                res.pb(ss.top());
                ss.pop();
            }
        }
        
        
        return res;
        
    }
};
