#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArr(vector<int> &arr)
{

  for (int i = 0; i < arr.size() / 2; i++)
  {
    int firstInd = i;
    int secInd = arr.size() - 1 - i;
    int temp = arr[firstInd];
    arr[firstInd] = arr[secInd];
    arr[secInd] = temp;
  }

  for (auto i : arr)
  {
    cout << i << " ";
  }

  cout << endl;
  return arr;
}

int main()
{
  // find unique element where reset of elemets are duplicate. leet code 136
  vector<int> ve = {4, 1, 2, 2, 1, 3, 3};

  // assinging some var
  int ans = 0;
  for (auto i : ve)
  {
    ans = ans ^ i;
  }

  // removing initialize var
  ans = ans ^ 0;

  cout << ans << endl;

  reverseArr(ve);
  return 0;
}