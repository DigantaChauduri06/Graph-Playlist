#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
vector<int> ans;
unordered_set<int> visited;
void bfs(int sv, unordered_map<int,set<int>> &adj) {
    queue<int> q;
    q.push(sv);
    visited.insert(sv);
    while (!q.empty()) {
        // int size = q.size();
        // for (int i = 0;i < size;i++) {
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for (auto &node : adj[f]) {
            if (visited.find(node) != visited.end()) continue;
            visited.insert(node);
            q.push(node);
        }
        // }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adj;
    for (auto &pr : edges) {
        adj[pr.first].insert(pr.second);
        adj[pr.second].insert(pr.first);
    }
    for (int i = 0;i < vertex;i++) {
        if (visited.find(i) == visited.end()) {
            bfs(i, adj);
        }
    }
    return ans;
}
int main ()
{

  return 0;
}
