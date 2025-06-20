#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{
  int low = 0;
  int mid = 0;
  int last = arr.size() - 1;

  while (mid <= last)
  {
    if (mid == 0)
    {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }
    else if (mid == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid], arr[last]);
      last--;
    }
  }

  for (auto i : arr)
    cout << i << " ";
}

int main()
{
  // Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
  // You need to solve this problem without utilizing the built-in sort function.

  vector<int> arr1 = {0, 1, 2, 0, 1, 2};
  vector<int> arr2 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

  // 1. sort by sort method
  // 2. count 0, 1, 2 and build new arry and return -> space O(n)
  // 3. low, mid, arr -> space constant

  solve(arr1);
  solve(arr2);
  return 0;
}