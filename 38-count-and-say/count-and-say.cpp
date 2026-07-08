class Solution {
public:
    string count_say(string s) {
        int len = s.size();
        string ans = "";

        if (s.size() == 0) {
            return "1";
        }
        for (int i = 0; i < len; i++) {
            int count = 1;

            while (i < len - 1 && s[i] == s[i + 1]) {
                i++;
                count++;
            }

            ans += to_string(count);
            ans += s[i];
        }
        return ans;
    }
    string countAndSay(int n) {
        string result = "";
        while (n--) {
            result = count_say(result);
        }
        return result;
    }
};