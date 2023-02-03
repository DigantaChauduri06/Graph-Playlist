#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int>> &adj, vector<int> &ans, int sv, unordered_map<int, bool> &seen) {
    seen[sv] = true;
    for (auto &node : adj[sv]) {
        if (seen[node]) continue;
        dfs(adj,ans,node,seen);
    }
    ans.push_back(sv);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here 
    unordered_map<int, list<int>> adj;
    for (auto &ed : edges) {
        adj[ed[0]].push_back(ed[1]);
    }
    vector<int> in(v, 0);
    for (auto & i : adj) {
        for (auto &node : i.second) {
            in[node]++;
        }
    }
    vector<int> ans;
    unordered_map<int, bool> seen;
    queue<int> q;
    for (int i = 0;i < v;i++) {
        if (in[i] == 0) {
            q.push(i);
            seen[i] = true;
        }
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto &node : adj[f]) {
            if (!seen[node]) {
                in[node]--;
                if (in[node] == 0) {
                    q.push(node);
                    seen[node] = true;
                }
            }
        }
    }
    return ans;
}


int main ()
{

  return 0;
}
