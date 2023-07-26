class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> q;
        long long sum = 0;
        int result = 0;
        for (auto num : nums)
        {
            q.push(num);
            sum += num;
        }
        double half = sum / 2.0;
        double mi_half = 0;
        double top = 0;
        while (mi_half < half)
        {
            top = q.top();
            mi_half += top / 2;
            q.pop();
            q.push(top / 2);
            result++;
        }
        return result;
    }
};
// 注意精度用 double