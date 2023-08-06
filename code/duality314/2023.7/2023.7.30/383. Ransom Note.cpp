class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int pl1[30] = {0};
        int pl2[30] = {0};
        for (char a : ransomNote)
        {
            pl1[a - 'a']++;
        }
        for (char b : magazine)
        {
            pl2[b - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (pl1[i] <= pl2[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};