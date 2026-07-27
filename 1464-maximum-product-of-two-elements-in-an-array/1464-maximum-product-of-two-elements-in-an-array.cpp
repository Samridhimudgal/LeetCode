class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int sLargest = 0;

        for(int &num : nums){
            if(num>largest){
                sLargest=largest;
                largest=num;
            }
            else{
                sLargest = max(sLargest, num);
            }
        } 
        return (largest-1)*(sLargest-1);
    }
};