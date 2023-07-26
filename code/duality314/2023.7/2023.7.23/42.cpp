class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0;
        int max_left[20005];
        int max_right[20005];
        int len = height.size();

        for (int i = 1; i < len - 1; i++)
        {
            max_left[i] = max(max_left[i - 1], height[i - 1]);
        }
        for (int i = height.length - 2; i >= 0; i--)
        {
            max_right[i] = max(max_right[i + 1], height[i + 1]);
        }
        for (int i = 1; i < height.length - 1; i++)
        {
            int min = min(max_left[i], max_right[i]);
            if (min > height[i])
            {
                sum = sum + (min - height[i]);
            }
        }
        return sum;
    }
};