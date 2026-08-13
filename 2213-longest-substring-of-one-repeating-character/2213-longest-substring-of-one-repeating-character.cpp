class Solution {
public:
    struct Node {
        int len;
        int pref, suff, best;
        char left, right;

        Node() {
            len = pref = suff = best = 0;
            left = right = '#';
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.right == b.left) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.right == b.left) {
            res.suff = b.len + a.suff;
        }

        // Best inside either half
        res.best = max(a.best, b.best);

        // Best crossing the middle
        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            seg[idx].left = s[l];
            seg[idx].right = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[idx].left = ch;
            seg[idx].right = ch;
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};