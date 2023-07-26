class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
            nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        return nums;
    }
};