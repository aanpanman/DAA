#include <bits/stdc++.h>
using namespace std;

void computePattern(string pattern, int m, int lps[])
{
	int length = 0;
	int i = 1;
	lps[0] = 0; 

	while (i < m)
	{
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
				lps[i] = length;
				i++;
			}
		}
	}
}

int KMP_freq(string pattern, string text)
{
	int m = pattern.length();
	int n = text.length();
	int lps[m];
	computePattern(pattern, m, lps);

	int count = 0;
	int i = 0, j = 0;
	while (i < n)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}
		if (j == m)
		{
			j = lps[j - 1];
			count++;
		}
		else if (i < n && pattern[j] != text[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	return count;
}

int main()
{
	string text, pattern;
	cout << "Enter string: ";
	cin >> text;
	cout << "Enter pattern: ";
	cin >> pattern;
	int count = KMP_freq(pattern, text);
	cout << count;
	return 0;
}

