#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pattern, int m, int lps [])
{
	int length = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m) {
		if (pattern[i] == pattern[length]) 
        {
			length++;
			lps[i] = length;
			i++;
		}
		else
		{
			if (length != 0) 
            {
				length = lps[length - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pattern, string text)
{
	int m = pattern.length();
	int n = text.length();
	int lps[m];
	computeLPS(pattern, m, lps);
	int i = 0;
	int j = 0;
	while (i < n) {
		if (pattern[j] == text[i]) 
        {
			j++;
			i++;
		}
		if (j == m) 
        {
            cout << "Found pattern at index " << (i-j);
			j = lps[j - 1];
		}
		else if (i < n && pattern[j] != text[i]) 
        {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
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
	KMPSearch(pattern, text);
	return 0;
}

