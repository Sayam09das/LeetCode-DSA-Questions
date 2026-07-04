class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            string temp = "";
            for (char ch : word) {
                temp += tolower(ch); // words to lowercase;
            }

            string R;

            if (row1.find(temp[0]) != string::npos) { // nops = no position;
                R = row1;
            }
            else if(row2.find(temp[0]) != string::npos){
                R = row2;
            }
            else{
                R = row3;
            }

            bool v = true;

            for(char ch:temp){
                if(R.find(ch) == string::npos){
                    v = false;
                    break;
                }
            }

            if(v){
                ans.push_back(word);
            }
        }
        return ans;
    }
};