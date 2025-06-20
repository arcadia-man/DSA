#include <bits/stdc++.h>
using namespace std;

// Function to solve using sorting
int solve(vector<int> ve)
{
  if (ve.empty())
  {
    cout << "No element";
    return -1;
  }

  sort(ve.begin(), ve.end());
  int currele = ve[0], count = 1;

  for (int i = 1; i < ve.size(); i++)
  {
    if (ve[i] == currele)
    {
      count++;
      if (count > ve.size() / 2)
      {
        return ve[i];
      }
    }
    else
    {
      currele = ve[i];
      count = 1;
    }
  }

  return -1;
}

// Moore's Voting Algorithm
int moore(vector<int> ve)
{
  int freq = 0, numb = 0;

  for (int i = 0; i < ve.size(); i++)
  {
    if (freq == 0)
    {
      numb = ve[i];
    }

    if (ve[i] == numb)
    {
      freq++;
    }
    else
    {
      freq--;
    }
  }

  // Optional: Verify if numb is actually majority
  int count = count_if(ve.begin(), ve.end(), [&](int x)
                       { return x == numb; });
  if (count > ve.size() / 2)
  {
    return numb;
  }

  return -1;
}

int main()
{
  // There is an element whose count is more than half of the elements in the array
  vector<int> ve = {1, 1, 2, 2, 2};

  cout << "Moore's Result: " << moore(ve) << endl;
  cout << "Sort Count Result: " << solve(ve) << endl;

  return 0;
}
class Solution {
public:
    void dfs(int node, int parent, vector<int> &st, vector<int> &lt, vector<int> &vis, vector<vector<int>> &graph, vector<vector<int>> &ans, int &time)
    {
        // st[node]=lt[node]=time++;
        st[node]=time;
        lt[node]=time;
        time++;
        vis[node] = 1;        
        for(auto it : graph[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it, node, st, lt, vis, graph, ans, time);
                lt[node] = min(lt[node], lt[it]);                
                if(lt[it] > st[node])
                    ans.push_back({node, it});
            }           
            else
                lt[node] = min(lt[node], st[it]);            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<int> st(n, -1), lt(n, -1), vis(n, 0);
        vector<vector<int>> ans, graph(n);
        int time=0;        
        for(auto it: connections)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }  
        dfs(0, -1, st, lt, vis, graph, ans, time);
        return ans;
    }
};