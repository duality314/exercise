class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> str;
        for (auto x : s)
        {
            if (str.empty())
            {
                str.push(x);
            }
            else
            {
                char to = str.top();
                if (((to == '{') && (x == '}')) || (to == '[' && x == ']') || (to == '(' && x == ')'))
                    str.pop();
                else if (x == '}' || x == ']' || x == ')')
                {
                    return 0;
                }
                else
                {
                    str.push(x);
                }
            }
        }
        return !str.empty();
    }
};