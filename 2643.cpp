#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> answer(2);
        int size = mat.size();

        for (int i = 0; i < size; i++)
        {
            int count = 0;
            for (auto &&t : mat[i])
                count += t;
            if (count > answer[1])
            {
                answer[0] = i;
                answer[1] = count;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat{{0, 0}, {1, 1}, {0, 0}};

    vector<int> answer = solution.rowAndMaximumOnes(mat);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
