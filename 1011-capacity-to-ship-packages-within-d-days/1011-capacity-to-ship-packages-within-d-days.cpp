class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //BRUTE FORCE
        // int maxElement = *max_element(weights.begin(), weights.end());
        // int maxCapacity = accumulate(weights.begin(), weights.end(), 0);
        // int ans = -1;
        // for(int i=maxElement; i<=maxCapacity; i++){
        //     int sum = 0;
        //     int totalDays = 1;
        //     for(int j=1; j<weights.size(); j++){
        //         sum += weights[j];
        //         if(sum>i){
        //             totalDays++;
        //             sum = weights[j];
        //         }
        //     }
        //     if (totalDays <= days) {
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;


        long long int low = *max_element(weights.begin(), weights.end());
        long long int high = accumulate(weights.begin(), weights.end(), 0);
        long long int ans = -1;
        while(low<=high){
            long long int mid = low+(high-low)/2;
            long long sum =0;
            int totalDays = 1;
            for(int i=0; i<weights.size(); i++){
                sum += weights[i];
                if(sum > mid){
                    totalDays++;
                    sum = weights[i];
                }
            }

            if (totalDays <= days) {
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