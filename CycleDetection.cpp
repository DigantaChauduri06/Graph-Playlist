#include <bits/stdc++.h>
using namespace std;
// int cnt = 0;
// void dfs(unordered_map<int, list<int>> &adj, vector<int> &ans, int sv, unordered_map<int, bool> &seen) {
//     seen[sv] = true;
//     for (auto &node : adj[sv]) {
//         if (seen[node]) continue;
//         dfs(adj,ans,node,seen);
//     }
//     // ans.push_back(sv);
//     cnt++;
// }

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    for (auto &ed : edges) {
        adj[ed.first].push_back(ed.second);
    }
    queue<int> q;
    vector<int> ind(n, 0);
    for (auto &n : adj) {
        for (auto &i : n.second) {
            ind[i]++;
        }
    }
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto &nd : adj[f]) {
            ind[nd]--;
            if(ind[nd] == 0) {
                q.push(nd);
            }
        }
        cnt++;
    }
    return cnt != n;

}
int main()
{

    return 0;
}
