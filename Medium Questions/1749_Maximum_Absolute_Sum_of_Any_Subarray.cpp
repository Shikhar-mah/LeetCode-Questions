class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxi_posi = INT_MIN, maxi_neg = INT_MAX;
        int posi_sum = 0;
        int neg_sum = 0;

        //positive max
        for(int i = 0;i<n;i++){
            posi_sum += nums[i];
            maxi_posi = max(maxi_posi, posi_sum);
            if(posi_sum < 0){
                posi_sum = 0;
            }
        }


        //negative max
        for(int i = 0;i<n;i++){
            neg_sum += nums[i];
            maxi_neg = min(maxi_neg, neg_sum);
            if(neg_sum > 0){
                neg_sum = 0;
            }
        }

        int res = max(abs(maxi_neg), abs(maxi_posi));
        return res;
    }
};