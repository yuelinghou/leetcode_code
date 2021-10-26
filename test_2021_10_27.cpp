// 第一题：完全平方数
class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> v(n+1, INT_MAX);
        v[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; i-j*j >= 0; ++j)
            {
                v[i] = min(v[i], v[i-j*j] + 1);
            }
        }
        return v[n];
    }
};

// 每日温度
class Solution {
public:
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        // 最终返回的结果数组，一开始都初始化为0
        vector<int> ret(temperatures.size());
        // 定义一个存储下标的栈
        stack<int> s;
        // 1、第0天入栈
        s.push(0);
        // 2、从第一天开始，拿当前天数的温度和栈天数的温度比较：如果大于栈顶天数温度的话，二者的差值就是栈顶那天的最终结果，之后栈顶天数出栈，继续比较，直到栈为空或者当前天数的温度小于栈顶那天的天数，那么当前数就入栈。
        for(int i = 1; i < temperatures.size(); ++i)
        {
            while(!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                ret[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
