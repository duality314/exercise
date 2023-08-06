#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        int len = fronts.size();
        int ans = 2001;
        set<int> s;
        for (int i = 0; i < len; i++)
        {
            if (fronts[i] == backs[i])
                s.insert(fronts[i]);
        }
        for (int i = 0; i < len; i++)
        {
            if (s.find(fronts[i]) == s.end())
            {
                ans = min(ans, fronts[i]);
            }
            if (s.find(backs[i]) == s.end())
            {
                ans = min(ans, backs[i]);
            }
        }
        return (ans == 2001 ? 0 : ans);
    }
};