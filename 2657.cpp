#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int size = A.size();
        vector<int> answer(size);
        answer[0] = (A[0] == B[0]);

        unordered_map<int, int> counts;
        counts[A[0]]++;
        counts[B[0]]++;
        for (int i = 1; i < size; i++)
        {
            int a = A[i], b = B[i];
            if (++counts[a] == 2)
            {
                answer[i]++;
            }
            if (++counts[b] == 2)
            {
                answer[i]++;
            }
            answer[i] += answer[i - 1];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    vector<int> answer = solution.findThePrefixCommonArray(A, B);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
