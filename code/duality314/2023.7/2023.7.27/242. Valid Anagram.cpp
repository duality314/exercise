class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int as[30] = {0}, at[30] = {0};
        int len1 = s.size(), len2 = t.size();
        if (len1 != len2)
            return 0;

        for (int i = 0; i < len1; i++)
        {
            as[s[i] - 'a']++;
            at[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (as[i] != at[i])
                return 0;
        }
        return 1;
    }
};