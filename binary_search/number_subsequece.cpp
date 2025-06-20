#include <bits/stdc++.h>
using namespace std;

bool valid_word(string s, unordered_map<char, vector<int>> &mp)
{
  int last_index_used = -1;

  for (int i = 0; i < s.size(); i++)
  {
    if (mp[s[i]].size())
    {

      int a = upper_bound(mp[s[i]].begin(), mp[s[i]].end(), last_index_used) - mp[s[i]].begin();

      if (a < mp[s[i]].size())
      {
        last_index_used = mp[s[i]][a];
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  return true;
};

int main()
{
  string s = "abcde";
  vector<string> words = {"a", "abcde", "aed"};

  unordered_map<char, vector<int>> mp;
  for (int i = 0; i < s.size(); i++)
  {
    mp[s[i]].push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < words.size(); i++)
  {
    if (valid_word(words[i], mp))
    {
      ans++;
    }
  }
  cout << ans;

  return 0;
}