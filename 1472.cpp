#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BrowserHistory
{
private:
    vector<string> pages;
    int current = 0;
    int tail = 0;

public:
    BrowserHistory(string homepage)
    {
        pages.push_back(homepage);
    }

    void visit(string url)
    {
        // 插入太慢了
        // pages.insert(pages.begin() + ++current, url);
        // 换成这个
        pages.resize(++current);
        pages.push_back(url);
        tail = current;
    }

    string back(int steps)
    {
        // current = current > steps ? current - steps : 0;
        current = max(current - steps, 0);
        return pages[current];
    }

    string forward(int steps)
    {
        // current = current + steps <= tail ? current + steps : tail;
        current = min(current + steps, tail);
        return pages[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(int argc, char const *argv[])
{
    BrowserHistory *browserHistory;
    vector<string> commands{"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"};
    vector<vector<string>> values{{"leetcode.com"}, {"google.com"}, {"facebook.com"}, {"youtube.com"}, {"1"}, {"1"}, {"1"}, {"leetcode.com"}, {"2"}, {"2"}, {"7"}};

    for (int i = 0; i < commands.size(); i++)
    {
        string command = commands[i];
        vector<string> value = values[i];
        if (command == "BrowserHistory")
        {
            browserHistory = new BrowserHistory(value[0]);
            cout << "null";
        }
        else if (command == "visit")
        {
            browserHistory->visit(value[0]);
            cout << "null";
        }
        else if (command == "back")
            cout << "\"" << browserHistory->back(value[0][0] - '0') << "\"";
        else
            cout << "\"" << browserHistory->forward(value[0][0] - '0') << "\"";
        cout << (i < commands.size() - 1 ? " , " : "");
    }

    return 0;
}
