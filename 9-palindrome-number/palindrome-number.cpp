class Solution {
public:
    bool isPalindrome(int x) {
        int org_num = x;
        long long pal_num =0;
        if( x >= 0){
            while(x > 0){
                int d = x % 10;
                pal_num = pal_num * 10 + d;
                x /= 10;
            }

            if(pal_num == org_num){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};