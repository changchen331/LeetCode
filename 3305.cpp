#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    const string aeiou = "aeiou";

    long long count_substrings(string &word, int least)
    {
        long long response = 0;
        unordered_map<char, int> memories;
        int length = word.length(), count = 0;

        for (int left = 0, right = 0; right < length; right++)
        {
            char character = word[right];
            if (aeiou.find(character) != string::npos)
                memories[character]++;
            else
                count++;

            while (memories.size() == 5 && count >= least)
            {
                char start = word[left++];
                if (aeiou.find(start) != string::npos)
                {
                    if (--memories[start] == 0)
                        memories.erase(start);
                }
                else
                    count--;
            }
            response += left;
        }
        return response;
    }

public:
    int countOfSubstrings(string word, int k)
    {
        return count_substrings(word, k) - count_substrings(word, k + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "ieaouqqieaouqq";
    int k = 1;

    int answer = solution.countOfSubstrings(word, k);
    cout << answer << endl;

    return 0;
}
