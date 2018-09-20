/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        return dfs(node, mp);
    }
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &mp) {
        if(node == NULL) return NULL;
        if(mp.find(node) != mp.end())
            return mp[node];
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        mp[node] = newnode;
        for(auto x:node->neighbors) {
            newnode->neighbors.push_back(dfs(x, mp));
        }
        return newnode;
    }
};
