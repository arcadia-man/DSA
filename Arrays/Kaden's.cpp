#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> ve{2, 3, -8, 7, -1, 2, 3};
  int currsum = 0, max_sum = 0;
  for (int i = 0; i < ve.size(); i++)
  {
    currsum += ve[i];
    max_sum = max(max_sum, currsum);
    if(currsum < 0) currsum = 0;
  }
  cout << max_sum;
  return 0;
}