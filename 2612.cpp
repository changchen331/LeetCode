#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k)
    {
        vector<int> answer(n, -1);

        unordered_set<int> ban{banned.begin(), banned.end()};
        set<int> indices[2];
        for (int i = 0; i < n; i++)
            if (i != p && ban.find(i) == ban.end())
                indices[i % 2].insert(i);
        indices[0].insert(n);
        indices[1].insert(n);

        answer[p] = 0;
        queue<int> q;
        q.push(p);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            int start = max(i - k + 1, k - i - 1);
            int end = min(i + k - 1, n * 2 - k - i - 1);
            set<int> &st = indices[start % 2];
            for (auto it = st.lower_bound(start); *it <= end; it = st.erase(it))
            {
                answer[*it] = answer[i] + 1; // 移动一步
                q.push(*it);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 4;
    int p = 0;
    vector<int> banned{1, 2};
    int k = 4;

    vector<int> answer = solution.minReverseOperations(n, p, banned, k);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
