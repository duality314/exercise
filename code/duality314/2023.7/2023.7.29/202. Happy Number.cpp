int op(int n)
{
    int re = 0;
    while (n != 0)
    {
        int tp = n % 10;
        re += tp * tp;
        n /= 10;
    }
    return re;
}

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> num;
        // num.insert(n);
        while (num.find(n) != num.end())
        {
            num.insert(n);
            n = op(n);
            if (n == 1)
            {
                return 1;
            }
        }
        return 0;
    }
};