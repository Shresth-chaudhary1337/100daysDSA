/* Daily Temperatures
Medium
Topics
premium lock iconCompanies
Hint

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

 

Constraints:

    1 <= temperatures.length <= 105
    30 <= temperatures[i] <= 100

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    int n = temperatures.size();
    vector<int> answer(n, 0);  // initially assume no warmer day
    stack<int> st;             // stack will store indices

    for(int i = 0; i < n; i++)
    {
        // if current temperature is warmer than the one in stack
        while(!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int index = st.top();  // day waiting for warmer temp
            st.pop();

            // calculate number of days waited
            answer[index] = i - index;
        }

        // push current day index into stack
        st.push(i);
    }

    return answer;
}

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> result = dailyTemperatures(temperatures);

    cout << "Output: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}