#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(string s, int k)
    {
        int answer = 0, length = s.length();

        set<int> not_vis[2];
        for (int i = 0; i < 2; i++)
        {
            for (int j = i; j <= length; j += 2)
            {
                not_vis[i].insert(j);
            }
            not_vis[i].insert(length + 1);
        }

        int start = 0;
        for (auto &&c : s)
        {
            start += (c == '0');
        }

        not_vis[start % 2].erase(start);
        vector<int> q = {start};
        for (; !q.empty(); answer++)
        {
            vector<int> nxt;
            for (auto &&z : q)
            {
                if (z == 0)
                {
                    return answer;
                }
                int mn = z + k - 2 * min(k, z);
                int mx = z + k - 2 * max(0, k - length + z);
                auto &st = not_vis[mn % 2];
                for (auto it = st.lower_bound(mn); *it <= mx; it = st.erase(it))
                {
                    nxt.push_back(*it);
                }
            }
            q = move(nxt);
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "110";
    int k = 1;

    int answer = solution.minOperations(s, k);
    cout << answer << endl;

    return 0;
}
