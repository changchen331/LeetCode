#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> answer;
        int size = folder.size();

        sort(folder.begin(), folder.end());
        // for (auto &&f : folder)
        //     cout << f << " ";
        // cout << endl;

        answer.emplace_back(folder[0]);
        for (int i = 1; i < size; i++)
        {
            string &current = folder[i];

            if (answer.back().length() < current.length())
            {
                string temp = answer.back();

                if (temp + '/' != current.substr(0, temp.length() + 1))
                    answer.emplace_back(current);
            }
            else
                answer.emplace_back(current);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> folder{"/aa/ab/ac/ae", "/aa/ab/af/ag", "/ap/aq/ar/as", "/ap/aq/ar", "/ap/ax/ay/az", "/ap", "/ap/aq/ar/at", "/aa/ab/af/ah", "/aa/ai/aj/ak", "/aa/ai/am/ao"};

    vector<string> answer = solution.removeSubfolders(folder);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
