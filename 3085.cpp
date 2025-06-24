#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        int answer = INT_MAX, length = word.length();

        vector<int> count(26, 0);
        vector<char> record;
        for (auto &&c : word)
        {
            if (count[c - 'a'] == 0)
                record.push_back(c);
            count[c - 'a']++;
        }

        int size = record.size();
        for (int i = 0; i < size; i++)
        {
            int minFreq = count[record[i] - 'a'];
            int maxFreq = minFreq + k;

            int deletion = 0;
            for (int j = 0; j < size; j++)
            {
                int current = count[record[j] - 'a'];
                if (current < minFreq)
                    deletion += current;
                else if (current > maxFreq)
                    deletion += current - maxFreq;
            }

            answer = min(answer, deletion);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "dabdcbdcdcd";
    int k = 2;

    int answer = solution.minimumDeletions(word, k);
    cout << answer << endl;

    return 0;
}
