class Solution {

    bool intOnly(string str){
        for(int i = 0;i<str.length();i++){
            char ch = str[i];
            if(!(ch >= '0' && ch <= '9')){
                return false;
            }
        }

        return true;
    }

    int intValue(string str){
        int pow10 = 1;
        int sum = 0;
        for(int i = str.length()-1;i>=0;i--){
            char ch = str[i];
            sum += (ch - '0')*pow10;
            pow10 *= 10;
        }
        return sum;
    }
 
public:
    int maximumValue(vector<string>& strs) {

        int n = strs.size();

        int maxi = INT_MIN;

        for(int i = 0;i<n;i++){
            string str =strs[i];
            if(intOnly(str)){
                int val = intValue(str);
                maxi = max(val, maxi);
            }
            else{
                int val = str.length();
                maxi = max(val, maxi);
            }
        }

        return maxi;
    }
};