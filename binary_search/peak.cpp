#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> ve = {1, 3, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 3, 2, 1};
  if (ve.size())
  {
    int start = 0, end = ve.size() - 1, ans = INT_MIN, i = 10;

    while (start < end)
    {
      int mid = (start + end) / 2;
      if (ve[mid] > ve[start])
      {
        start = mid;
        ans = max(ans, ve[mid]);
      }
      else if (ve[mid] > ve[end])
      {
        end = mid;
        ans = max(ans, ve[mid]);
      }
      else if (ve[start] == ve[end] && ve[start] == ve[mid])
      {
        ans = max(ans, ve[mid]);
        break;
      }
    }

    cout << ans;
  }
  else
  {
    cout << -1;
  }
  return 0;
}