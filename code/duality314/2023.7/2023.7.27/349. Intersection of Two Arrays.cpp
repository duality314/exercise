class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> re;
        unordered_set<int> a(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (a.find(num) != a.end())
            {
                re.insert(num);
            }
        }
        return vector<int>(re.begin(), re.end());
    }
};