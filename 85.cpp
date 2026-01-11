#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int largestRectangleArea(vector<int> &heights)
    {
        int response = 0;

        stack<int> st;
        st.push(-1);
        for (int right = 0; right < heights.size(); right++)
        {
            int &h = heights[right];
            while (st.size() > 1 && heights[st.top()] >= h)
            {
                int top = st.top();
                st.pop();

                int left = st.top();
                response = max(response, heights[top] * (right - left - 1));
            }
            st.push(right);
        }

        return response;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int answer = 0, m = matrix.size(), n = matrix[0].size();

        vector<int> heights(n + 1, 0);
        for (auto &&row : matrix)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            answer = max(answer, largestRectangleArea(heights));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    int answer = solution.maximalRectangle(matrix);
    cout << answer << endl;

    return 0;
}
