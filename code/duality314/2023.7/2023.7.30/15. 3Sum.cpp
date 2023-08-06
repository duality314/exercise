class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(ans.begin(), ans.end());
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = num.size() - 1;
            while (right > left)
            {
                int a = nums[i], b = nums[left], c = nums[right];
                if (a + b + c > 0)
                    right--;
                else if (a + b + c < 0)
                    left++;
                else
                {
                    ans.push_back(vector<int>{a, b, c});
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return ans;
    }
};