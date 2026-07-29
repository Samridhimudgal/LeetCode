class Solution {
public:
    long long nCr(int n, int r, long long K) {
        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= K)
                return K;
        }

        return result;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.length();

        char mid = ' ';
        if (n % 2 == 1) {   // odd length
            mid = s[n / 2];
        }

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue;

            count[s[i] - 'a']++;
        }

        // Only half frequencies are needed
        for (int i = 0; i < 26; i++)
            count[i] /= 2;

        string halfResult = "";
        int half = n / 2;

        for (int i = 0; i < half; i++) {

            bool placedCharacter = false;

            for (int j = 0; j < 26; j++) {

                if (count[j] == 0)
                    continue;

                count[j]--;

                long long ways = 1;

                int letters = 0;
                for (int c = 0; c < 26; c++)
                    letters += count[c];

                for (int c = 0; c < 26; c++) {
                    if (count[c] == 0)
                        continue;

                    ways *= nCr(letters, count[c], k);

                    if (ways >= k) {
                        ways = k;
                        break;
                    }

                    letters -= count[c];
                }

                if (ways >= k) {
                    halfResult.push_back(char('a' + j));
                    placedCharacter = true;
                    break;
                }

                k -= ways;
                count[j]++;
            }

            if (!placedCharacter)
                return "";
        }

        string rev = halfResult;
        reverse(rev.begin(), rev.end());

        if (mid != ' ')
            halfResult.push_back(mid);

        return halfResult + rev;
    }
};