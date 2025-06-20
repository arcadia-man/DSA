#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> ve = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int start = 0, end = ve.size() - 1;
  while (start <= end)
  {
    if (ve[start] < 0)
    {
      start++;
    }
    else if (ve[start] >= 0 && ve[end] < 0)
    {
      swap(ve[start], ve[end]);
      start++;
      end--;
    }
    else
    {
       end--;
    }
  }
  for(auto i : ve) cout << i << " ";
  return 0;
}