class Solution {
public:
    vector<string> ans;

    void solve(string& s, int index,
               int leftRemove, int rightRemove,
               int leftCount, int rightCount,
               string current) {

        // Reached end of string
        if (index == s.size()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                leftCount == rightCount) {

                ans.push_back(current);
            }

            return;
        }

        char ch = s[index];

        // -------------------------
        // Case 1: '('
        // -------------------------
        if (ch == '(') {

            // Option 1: Remove '('
            if (leftRemove > 0) {
                solve(s, index + 1,
                      leftRemove - 1,
                      rightRemove,
                      leftCount,
                      rightCount,
                      current);
            }

            // Option 2: Keep '('
            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  leftCount + 1,
                  rightCount,
                  current + ch);
        }

        // -------------------------
        // Case 2: ')'
        // -------------------------
        else if (ch == ')') {

            // Option 1: Remove ')'
            if (rightRemove > 0) {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove - 1,
                      leftCount,
                      rightCount,
                      current);
            }

            // Option 2: Keep ')'
            // We can keep ')' only when
            // there is an unmatched '('
            if (leftCount > rightCount) {

                solve(s, index + 1,
                      leftRemove,
                      rightRemove,
                      leftCount,
                      rightCount + 1,
                      current + ch);
            }
        }

        // -------------------------
        // Case 3: Letter
        // -------------------------
        else {

            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  leftCount,
                  rightCount,
                  current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        solve(s, 0,
              leftRemove,
              rightRemove,
              0,
              0,
              "");

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};