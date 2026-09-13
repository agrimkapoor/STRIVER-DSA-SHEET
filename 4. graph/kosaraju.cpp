#include <bits/stdc++.h>
using namespace std;

// Kosaraju algo to find SCC
// In a directed graph, a group of nodes is an SCC if:
// From every node, you can reach every other node in that group.

void dfs1(int src, vector<vector<int>>& adj,
          stack<int>& st, vector<bool>& vis) {

    vis[src] = true;

    for(auto neigh : adj[src]) {
        if(!vis[neigh]) {
            dfs1(neigh, adj, st, vis);
        }
    }

    // Important: push AFTER visiting all neighbours
    st.push(src);
}

void dfs2(int src, vector<vector<int>>& adj,
          vector<bool>& vis) {

    vis[src] = true;

    for(auto neigh : adj[src]) {
        if(!vis[neigh]) {
            dfs2(neigh, adj, vis);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> adj2(n);

    // Build original + reversed graph
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj2[v].push_back(u);   // reverse edge
    }

    // STEP 1: DFS on original graph
    vector<bool> vis(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs1(i, adj, st, vis);
        }
    }

    // STEP 2: DFS on reversed graph
    vector<bool> vis2(n, false);

    int cnt = 0;

    while(!st.empty()) {

        int node = st.top();
        st.pop();

        if(!vis2[node]) {
            dfs2(node, adj2, vis2);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
