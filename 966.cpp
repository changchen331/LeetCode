#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    string tolower_string(string s)
    {
        for (auto &&c : s)
            c = tolower(c);
        return s;
    }
    string replace_vowels(string s)
    {
        for (char &c : s)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '?';
        return s;
    }

public:
    vector<string>
    spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        int size_w = wordlist.size(), size_q = queries.size();

        // 我的方法（WA）
        // vector<string> answer(size_q, "");
        // unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        // for (int i = 0; i < size_q; i++)
        // {
        //     string query = queries[i];
        //     int length = query.length();

        //     // 遍历 wordlist 来寻找匹配的 word
        //     bool change = false;
        //     for (auto &&word : wordlist)
        //     {
        //         if (word.length() != length)
        //             continue;
        //         if (word == query)
        //         {
        //             answer[i] = word;
        //             break;
        //         }

        //         // 匹配字符
        //         bool match = true;
        //         for (int j = 0; j < length; j++)
        //         {
        //             char char_query = query[j], char_word = word[j];
        //             if (char_query != char_word)
        //             {
        //                 if ((tolower(char_query) == tolower(char_word)) || (vowels.find(char_query) != vowels.end() && vowels.find(char_word) != vowels.end()))
        //                     change = true;
        //                 else
        //                 {
        //                     match = false;
        //                     break;
        //                 }
        //             }
        //         }
        //         if (answer[i] == "" && change && match)
        //             answer[i] = word;
        //     }
        // }
        // return answer;

        // 官解
        unordered_set<string> origin(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lower_to_origin;
        unordered_map<string, string> vowel_to_origin;

        for (int i = size_w - 1; i >= 0; i--)
        {
            string &s = wordlist[i];
            string lower = tolower_string(s);
            lower_to_origin[lower] = s;                 // 例如 kite -> KiTe
            vowel_to_origin[replace_vowels(lower)] = s; // 例如 k?t? -> KiTe
        }

        for (string &q : queries)
        {
            if (origin.find(q) != origin.end())
                continue; // 完全匹配

            string lower = tolower_string(q);
            auto it = lower_to_origin.find(lower);
            if (it != lower_to_origin.end())
                q = it->second; // 不区分大小写的匹配
            else
            {
                // 不区分大小写+元音模糊匹配
                auto it = vowel_to_origin.find(replace_vowels(lower));
                q = it != vowel_to_origin.end() ? it->second : "";
            }
        }
        return queries;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    // vector<string> queries = {"Zeo"};

    vector<string> answer = solution.spellchecker(wordlist, queries);
    // for (auto &&word : wordlist)
    //     cout << "\"" << word << "\"" << " ";
    // cout << endl;
    // for (auto &&query : queries)
    //     cout << "\"" << query << "\"" << " ";
    // cout << endl;
    for (auto &&ans : answer)
        cout << "\"" << ans << "\"" << " ";
    cout << endl;

    return 0;
}
