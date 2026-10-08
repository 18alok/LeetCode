class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                if (count > 0) {
                    ans += ch;
                }
                count++;
            }

            else {
                count--;

                if (count > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};


//Opening '(' → add BEFORE increasing count, only if count > 0
//Closing ')' → decrease count FIRST, then add only if count > 0