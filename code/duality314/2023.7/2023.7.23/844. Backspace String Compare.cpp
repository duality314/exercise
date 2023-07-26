class Solution
{
public:
    string deleteSpace(string s)
    {
        // int len = s.length();
        // int slowIndex = 0;
        // for (int fastIndex = 0; fastIndex < len; fastIndex++){
        //     if(s[fastIndex] == '#')
        //         s[slowIndex++]=s[fastIndex + 1];
        // }
        // // for (int i = slowIndex; i < len; i++)
        // //     s[i]='\0';
        int len = s.length();
        string re;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '#' && !re.empty())
                re.erase(re.end() - 1);
            else if (s[i] != '#')
                re += s[i];
        }
        return re;
    }
    bool backspaceCompare(string s, string t)
    {
        cout << deleteSpace(s) << endl
             << deleteSpace(t);
        return deleteSpace(s) == deleteSpace(t);
    }
};