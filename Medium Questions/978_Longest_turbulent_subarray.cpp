class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return 1;
        }

        int count = 1;
        int res = 1;

        /*
        for k is odd >
        for k is even <
        */

        for(int k = 0;k<n-1;k++){
            if(k%2 == 0 && arr[k]<arr[k+1]){
                count++;
            }
            else if(k%2 != 0 && arr[k]>arr[k+1]){
                count++;
            }
            else{
                res = max(count, res);
                count = 1;
            }
        }

        res = max(count, res);
        count = 1;


        /*
        for k is odd <
        for k is even >
        */

        for(int k = 0;k<n-1;k++){
            if(k%2 == 0 && arr[k]>arr[k+1]){
                count++;
            }
            else if(k%2 != 0 && arr[k]<arr[k+1]){
                count++;
            }
            else{
                res = max(count, res);
                count = 1;
            }
        }

        res = max(count, res);
        return res;
    }
};