#include <bits/stdc++.h>
using namespace std;

#define d 26 // as there are 26 alphabets

void rabinKarp(string pattern, string text, int q)
{

  int m = pattern.length();
  int n = text.length();
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
  {
    h = (h * d) % q;
  }
  for (i = 0; i < m; i++)
  {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }
  for (i = 0; i <= n - m; i++)
  {
    if (p == t)
    {
      for (j = 0; j < m; j++)
      {
        if (text[i + j] != pattern[j])
          break;
      }
      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }
    if (i < n - m)
    {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main()
{
  string text, pattern;
  cout << "Enter string: ";
  cin >> text;
  cout << "Enter pattern: ";
  cin >> pattern;
  int q = 13; // to create hash code for the strings
  rabinKarp(pattern, text, q);
  return 0;
}