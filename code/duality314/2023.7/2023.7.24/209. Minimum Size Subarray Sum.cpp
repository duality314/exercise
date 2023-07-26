class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = INT_MAX;
        int i = 0;
        int sum = 0, sublength = 0, len = nums.size();
        for (int j = 0; j < len; j++)
        {
            sum += nums[j];  // 向前走
            while (sum >= s) // 走多了滑前面
            {
                sublength = j - i + 1;
                result = min(sublength, result);
                sum -= nums[i++]; // 滑出去
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};