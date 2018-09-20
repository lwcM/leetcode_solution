class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> G(wordList.size()+1, vector<int>());
        vector<int> visited(wordList.size()+1, INT_MAX);
        for(int i=0; i<wordList.size(); i++)
            if(differ(beginWord, wordList[i]))
                G[0].push_back(i+1);
        int term = -1;
        for(int i=0; i<wordList.size(); i++)
            if(endWord == wordList[i])
                term = i+1;
        if(term == -1) return 0;
        for(int i=0; i<wordList.size(); i++) {
            for(int j=i+1; j<wordList.size(); j++) {
                if(differ(wordList[i], wordList[j])) {
                    G[i+1].push_back(j+1);
                    G[j+1].push_back(i+1);
                }
            }
        }
        queue <int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(x == term) {
                return visited[x];
            }
            for(int i=0; i<G[x].size(); i++) {
                if(visited[G[x][i]] == INT_MAX) {
                    q.push(G[x][i]);
                    visited[G[x][i]] = visited[x]+1;
                }
                if(visited[term] != INT_MAX) return visited[term];
            }
        }
        return 0;
    }
    bool differ(string &s1, string &s2) {
        int diff=0;
        for(int i=0; i<s1.size(); i++)
            diff += (s1[i] != s2[i]);
        return diff <= 1;
    }
};

static const auto speedupio=[]{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
