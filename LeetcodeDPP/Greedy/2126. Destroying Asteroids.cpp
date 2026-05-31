// TC = O(nlogn)
// SC = O(1)
class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &ast)
    {
        sort(ast.begin(), ast.end());
        long long m = mass;
        for (int i = 0; i < ast.size(); i++)
        {
            if (ast[i] > m)
                return false;
            m += ast[i];
        }
        return true;
    }
};

// TC = O(nlogn)
// SC = O(n)

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &ast)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long m = mass;
        for (int i = 0; i < ast.size(); i++)
        {
            pq.push(ast[i]);
        }
        while (!pq.empty())
        {
            if (pq.top() > m)
                return false;
            m += pq.top();
            pq.pop();
        }
        return true;
    }
};
