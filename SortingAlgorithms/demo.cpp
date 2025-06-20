#include <bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> &ve)
{

  for (auto ele : ve)
  {
    for (auto i : ele)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
};

vector<int> bubbleSort(vector<int> ve)
{
  int size = ve.size();
  for (int j = 0; j < size - 1; j++)
  {
    // optimization by checking was there any sawp while last iteration
    bool isSwaped = true;
    for (int i = 0; i < size - 1 - j; i++)
    {
      if (ve[i] > ve[i + 1])
      {
        // swap the next if smaller
        int a = ve[i];
        ve[i] = ve[i + 1];
        ve[i + 1] = a;
        isSwaped = false;
      }
    }
    if (isSwaped)
    {
      break;
    }
  }
  return ve;
};

vector<int> selectionSort(vector<int> ve)
{
  int size = ve.size();
  for (int j = 0; j < size - 1; j++)
  {
    // find the min element
    int minIndex = j;
    for (int i = j + 1; i < size; i++)
    {
      if (ve[i] < ve[minIndex])
      {
        minIndex = i;
      }
    }

    if (minIndex != j)
    {
      // Swap with first elemtent
      int a = ve[j];
      ve[j] = ve[minIndex];
      ve[minIndex] = a;
    }
  }
  return ve;
};

vector<int> insertionSort(vector<int> ve)
{
  int size = ve.size();
  for (int i = 1; i < size; i++)
  {
    // find insert location and maintain location by swaping
    int location = i - 1;
    int insertEle = ve[i];
    while (location >= 0 && ve[location] > insertEle)
    {
      ve[location + 1] = ve[location];
      location--;
    }
    // insert at loction
    ve[location + 1] = insertEle;
  }
  return ve;
};

void doMerge(vector<int> &ve, int left, int mid, int right)
{
  
};

void mergeSort(vector<int> &ve, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    mergeSort(ve, left, mid);
    mergeSort(ve, mid, right);
    doMerge(ve, left, mid, right);
  }
};

int main()
{
  vector<vector<int>> sortResult = {};
  vector<int> ve = {12, 45, 3, 29, 8, 19, 34, 27, 5, 14, 39, 1, 50, 23, 7};
  sortResult.push_back(bubbleSort(ve));
  sortResult.push_back(selectionSort(ve));
  sortResult.push_back(insertionSort(ve));
  printArr(sortResult);
  return 0;
};