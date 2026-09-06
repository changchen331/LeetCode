#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> answer;
        int size = strs.size();

        unordered_map<string, vector<string>> mem;
        for (int i = 0; i < size; i++)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mem[cur].push_back(strs[i]);
        }

        for (auto &&m : mem)
        {
            answer.push_back(m.second);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> answer = solution.groupAnagrams(strs);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
            if (j != answer[i].size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
