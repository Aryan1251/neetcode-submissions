#define ll long long

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int result = 0;

        for (int num : values) {
            // Only begin counting if num is the start of a sequence
            if (values.find(num - 1) == values.end()) {
                int current = num;
                int length = 1;

                while (values.find(current + 1) != values.end()) {
                    current++;
                    length++;
                }

                result = max(result, length);
            }
        }

        return result;
    }
};
