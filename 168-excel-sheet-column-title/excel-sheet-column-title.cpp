class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            columnNumber--;
            int rem = columnNumber % 26;
            char ch = rem + 'A';
            res.push_back(ch);
            columnNumber /= 26;
        }

        reverse(begin(res), end(res));
        return res;
    }
};