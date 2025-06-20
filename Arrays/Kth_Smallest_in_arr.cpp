#include <bits/stdc++.h>
using namespace std;

int kthSmallestBrute(vector<int> &arr, int k)
{
	sort(arr.begin(), arr.end());
	return arr[k - 1];
}

int kthSmallestOptimized(vector<int> &arr, int k)
{
	// In case of elemnts of array is not big

	// find max
	int mx = arr[0], ans;
	for (auto i : arr)
		mx = max(mx, i);

	vector<int> ve(mx + 1, 0);

	// store occurences
	for (auto i : arr)
		ve[i]++;

	int count = 0;
	for (int i = 0; i < ve.size(); i++)
	{
		if (ve[i] > 0)
		{
			count += ve[i];
		}
		if (count >= k)
		{
			ans = i;
			break;
		}
	}
	return ans;
}

void solve(vector<int> &arr, int k)
{
	cout << "brut " << kthSmallestBrute(arr, k) << " Optimize " << kthSmallestOptimized(arr, k) << endl;
}

int main()
{
	// Given an array arr[] and an integer k where k is smaller than the size of the array,
	// the task is to find the kth smallest element in the given array.
	vector<int> arr1 = {7, 10, 4, 3, 20, 15};
	int k1 = 3;

	vector<int> arr = {2, 3, 1, 20, 15};
	int k = 4;

	solve(arr1, k1);
	solve(arr, k);

	return 0;
}