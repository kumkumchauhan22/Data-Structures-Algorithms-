class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build graph and reverse graph
        vector<vector<int>> graph(n), rev(n);
        for (auto &edge : invocations) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            rev[b].push_back(a);
        }

        // Step 1: Find all suspicious methods (reachable from k in forward graph)
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : graph[cur]) {
                if (!suspicious[nxt]) {
                    suspicious[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        // Step 2: Check if any non-suspicious method invokes suspicious ones
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                for (int nxt : graph[i]) {
                    if (suspicious[nxt]) {
                        // Invalid removal: outside method calls inside suspicious group
                        vector<int> all(n);
                        iota(all.begin(), all.end(), 0);
                        return all; // return all methods unchanged
                    }
                }
            }
        }

        // Step 3: Collect remaining methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};
