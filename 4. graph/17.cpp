//kosaraju algo : to find SCC in directed graph
//strongly connected comp
// inme woh nodes hogi such that every pair of node : u and v 
// you can reach v from u (directly or indirectly)
// you can reach u from v(directly or indirectly)


class Solution {

    void dfs1(int node,
              vector<vector<int>>& adj,
              vector<bool>& vis,
              stack<int>& st) {

        vis[node] = true;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(it, adj, vis, st);
            }
        }

        // DFS finish hone ke baad push
        st.push(node);
    }


    void dfs2(int node,
              vector<vector<int>>& rev,
              vector<bool>& vis) {

        vis[node] = true;

        for (auto it : rev[node]) {
            if (!vis[it]) {
                dfs2(it, rev, vis);
            }
        }
    }


public:
    int kosaraju(int V, vector<vector<int>>& adj) {

        // Step 1: DFS + finishing order
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }


        // Step 2: Reverse graph
        vector<vector<int>> rev(V);

        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                rev[v].push_back(u);
            }
        }


        // Step 3: DFS on reversed graph
        fill(vis.begin(), vis.end(), false);

        int scc = 0;

        while (!st.empty()) {

            int node = st.top();
            st.pop();

            if (!vis[node]) {
                scc++;

                dfs2(node, rev, vis);
            }
        }

        return scc;
    }
};
