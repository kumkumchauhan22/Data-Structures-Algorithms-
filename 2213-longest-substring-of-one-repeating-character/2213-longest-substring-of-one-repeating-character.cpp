class Solution {
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen, maxLen;
        int len; // length of this segment
    };
    vector<Node> seg;
    int n;

    Node merge(Node a, Node b) {
        Node res;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.len = a.len + b.len;

        // default prefix/suffix
        res.leftLen = a.leftLen;
        res.rightLen = b.rightLen;
        res.maxLen = max(a.maxLen, b.maxLen);

        if (a.rightChar == b.leftChar) {
            res.maxLen = max(res.maxLen, a.rightLen + b.leftLen);

            // extend prefix if left segment is uniform
            if (a.leftLen == a.len)
                res.leftLen = a.len + b.leftLen;

            // extend suffix if right segment is uniform
            if (b.rightLen == b.len)
                res.rightLen = b.len + a.rightLen;
        }
        return res;
    }

    void build(string &s, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        build(s, idx*2, l, mid);
        build(s, idx*2+1, mid+1, r);
        seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = {c, c, 1, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos, c);
        else update(idx*2+1, mid+1, r, pos, c);
        seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        seg.resize(4*n);
        build(s, 1, 0, n-1);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans.push_back(seg[1].maxLen);
        }
        return ans;
    }
};
