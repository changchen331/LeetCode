#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.emplace_back(-1);
        int answer = 0, size = heights.size();

        stack<int> st;
        st.push(-1);
        for (int right = 0; right < size; right++)
        {
            int &h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h)
            {
                int top = st.top();
                st.pop();

                int left = st.top();
                answer = max(answer, heights[top] * (right - left - 1));
            }
            st.push(right);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> heights = {2, 4};

    int answer = solution.largestRectangleArea(heights);
    cout << answer << endl;

    return 0;
}
