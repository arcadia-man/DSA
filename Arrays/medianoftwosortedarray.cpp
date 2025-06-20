#include <bits/stdc++.h>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
{
  int i = 0, j = 0;
  int m = a.size(), n = b.size();

  int m1 = -1, m2 = -1;
  for (int count = 0; count <= (m + n) / 2; count++)
  {
    // maintain previous element where m2 is prev and m1 current f
    m2 = m1;
    if (i != n && j != m)
      m1 = (a[i] > b[j]) ? b[j++] : a[i++];
    else if (i < n)
      m1 = a[i++];
    else
      m1 = b[j++];
  }

  return ((m + n) % 2) ? m1 : (m1 + m2) / 2.0;
}

int main()
{
  vector<int> a = {-5, 3, 6, 12, 15};        // 5 -> 5/2 = 2
  vector<int> b = {-12, -10, -6, -3, 4, 10}; // 6 -> 6/2 = 3 & 3- 1 // -12, -10, -6, -5, -3, 3, 4, 6, 10, 12, 15
  cout << medianOf2(a, b) << endl;
  return 0;
}