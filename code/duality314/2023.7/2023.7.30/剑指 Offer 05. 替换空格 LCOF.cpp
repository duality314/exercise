class Solution
{
public:
    string replaceSpace(string s)
    {
        int len = s.size();
        int space = 0;
        for (auto x : s)
        {
            if (x == ' ')
                space++;
        }
        s.resize(len + 2 * space);
        for (int i = len - 1 + 2 * space, j = len - 1; i > j; i--, j--)
        {
            if (s[j] != ' ')
                s[i] = s[j];
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};