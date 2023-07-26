class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int ans = 0;
        int a = -1;
        int i = 0, j = 0;
        while (i < n)
        {
            int b = fruits[i];
            int st = j;
            while (i < n && (fruits[i] == a || fruits[i] == b))
            {
                if (fruits[i] == b)
                {
                    swap(a, b);
                    j = i;
                }
                ++i;
            }
            ans = max(i - st, ans);
        }
        return ans;
    }
};