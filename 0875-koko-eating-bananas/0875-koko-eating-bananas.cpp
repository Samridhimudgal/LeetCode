class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Brute Force 
        // int ans = -1;
        // int maxSpeed = *max_element(piles.begin(), piles.end());

        // for(int i=1; i<=maxSpeed; i++){
        //     int total = 0;
        //     for(int j=0; j<n; j++){
        //         if(piles[i] % i != 0) 
        //             total++;
        //         total += piles[j]/i;
        //     }
        //     if(total <= h){
        //         ans=1;
        //         break;
        //     }
        // } 

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long total = 0;
            for(int i=0; i<piles.size(); i++){
                total += (piles[i] + mid - 1) / mid;
            }
            if (total <= h) {
            ans = mid;
            high = mid - 1;
            } 
            else {
                low = mid + 1;
            }

        }
        return ans;
    }
};