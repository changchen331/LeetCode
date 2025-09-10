#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int answer = INT_MAX, u_amount = languages.size(), f_amount = friendships.size();

        vector<vector<bool>> user(u_amount, vector<bool>(n + 1, false));
        for (int i = 0; i < u_amount; i++)
            for (auto &&l : languages[i])
                user[i][l] = true;

        for (int language = 1; language <= n; language++)
        {
            int count = 0;

            vector<vector<bool>> temp = user;
            for (int j = 0; j < f_amount; j++)
            {
                int a = friendships[j][0] - 1, b = friendships[j][1] - 1;

                // 判断能不能沟通
                bool can_communicate = false;
                for (int k = 1; k <= n; k++)
                {
                    if (temp[a][k] && temp[b][k])
                    {
                        can_communicate = true;
                        break;
                    }
                }

                // 不能沟通
                if (!can_communicate)
                {
                    count += (temp[a][language] == false) + (temp[b][language] == false);
                    temp[a][language] = true;
                    temp[b][language] = true;
                }
            }

            answer = min(answer, count);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};

    int answer = solution.minimumTeachings(n, languages, friendships);
    cout << answer << endl;

    return 0;
}
