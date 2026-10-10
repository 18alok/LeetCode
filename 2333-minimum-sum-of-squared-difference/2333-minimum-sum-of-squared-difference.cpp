
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long k = (long long)k1 + k2;
        long long sum = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        if (k >= sum) {
            return 0;
        }

        // Binary search for the final difference level
        int low = 0, high = maxDiff;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int x : diff) {
                if (x > mid) {
                    needed += x - mid;
                }
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long used = 0;
        long long ans = 0;

        for (int x : diff) {
            used += max(0, x - level);
            long long finalDiff = min(x, level);
            ans += finalDiff * finalDiff;
        }

        // Use remaining operations to reduce level to level - 1
        long long remaining = k - used;
        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};
