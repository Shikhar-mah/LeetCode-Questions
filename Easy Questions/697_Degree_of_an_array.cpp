class Solution {

    int getDegree(unordered_map<int, int> mp){
        int maxi = INT_MIN;
        for(auto i: mp){
            maxi = max(maxi, i.second);
        }

        return maxi;
    }
    
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n-1;
        int min_length = INT_MAX;

        unordered_map<int, int> mp;

        for(auto i: nums){
            mp[i] += 1;
        }

        int maxDegree = getDegree(mp);

        if(maxDegree == 1){
            return 1;
        }

        unordered_map<int, int> temp = mp;
         
        //check from front
        //this is also check from front when back is not removed
        while(start<end){
            mp[nums[start]] -= 1;
            start++;
            int degree = getDegree(mp);
            if(degree < maxDegree){
                start--;
                mp[nums[start]] += 1;
                break;
            }
        }

        //check from back if none from front is removed
        int end2 = n-1;
        int length1;
        while(end2>=0){
            temp[nums[end2]] -= 1;
            end2--;
            int degree = getDegree(temp);
            if(degree< maxDegree){
                end2++;
                length1 = end2 + 1;
                break;
            }
        }


        //check from back when front is removed
        int length2;
        while(start<end){
            mp[nums[end]] -= 1;
            end--;
            int degree = getDegree(mp);
            if(degree < maxDegree){
                end++;
                length2 = end - start + 1;
                break;
            }
        }

        int ans = min(length1, length2);

        return ans;
    }
};