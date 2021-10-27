#include <bits/stdc++.h>
using namespace std;
int trappingWater2(int arr[], int n)
{

    // Your code here
    int left[n], right[n];
    int water = 0;
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}
int trappingWater(int arr[], int n)
{
    int ans = 0;
    int current = 0;
    stack<int> s;
    while (current < n)
    {
        while (!s.empty() && arr[current] > arr[s.top()])
        {
            int top = s.top();
            s.pop();
            if (s.empty())
            {
                break;
            }
            int distance = current - s.top() - 1;
            int boundedHeight = min(arr[current], arr[s.top()]) - arr[top];
            ans += distance * boundedHeight;
        }
        s.push(current++);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << trappingWater2(arr, n);
    cout << trappingWater(arr, n);
}