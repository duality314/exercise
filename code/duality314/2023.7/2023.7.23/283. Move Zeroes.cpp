class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < len; fastIndex++)
        {
            if (nums[fastIndex] != 0)
            {
                nums[slowIndex] = nums[fastIndex];
                if (fastIndex != slowIndex)
                    nums[fastIndex] = 0;
                slowIndex++;
            }
        }
    }
};