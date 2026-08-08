class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // nxt[j][c] = smallest index >= j in word1 equal to char c, or n if none
        vector<array<int,26>> nxt(n + 1);
        nxt[n].fill(n);
        for (int j = n - 1; j >= 0; j--) {
            nxt[j] = nxt[j + 1];
            nxt[j][word1[j] - 'a'] = j;
        }

        // suf[i]: word2[i:] can exactly match word1[q:] as a subsequence iff q <= suf[i]
        vector<int> suf(m + 1);
        suf[m] = n;
        int ptr = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (ptr >= 0 && word1[ptr] != word2[i]) ptr--;
            suf[i] = (ptr < 0) ? -1 : ptr--;
        }

        vector<int> res;
        res.reserve(m);
        int j = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < m; i++) {
            if (j >= n) return {};
            int c = word2[i] - 'a';
            int nextExact = nxt[j][c];

            if (nextExact == j) {              // exact match right here — always best
                res.push_back(j++);
                continue;
            }

            // word1[j] != word2[i]: try spending the mismatch at j
            if (!mismatchUsed && suf[i + 1] != -1 && j + 1 <= suf[i + 1]) {
                res.push_back(j++);
                mismatchUsed = true;
            } else if (nextExact < n) {         // fall back to next exact match
                j = nextExact + 1;
                res.push_back(nextExact);
            } else {
                return {};
            }
        }

        return res;
    }
};