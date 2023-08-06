class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> s;
        int i = 0;
        for (int num : nums)
        {
            auto it = s.find(target - num);
            if (it != s.end())
            {
                return {it->second, i};
            }
            else
            {
                s[num] = i;
            }
            i++;
        }
        return {};
    }
};