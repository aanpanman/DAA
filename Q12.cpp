#include <bits/stdc++.h>
using namespace std;

void interRecur(char str1[], char str2[], char iStr[], int m, int n, int i){
	if (m == 0 && n == 0)
		cout << iStr << endl ;
	if (m != 0)
	{
		iStr[i] = str1[0];
		interRecur(str1 + 1, str2, iStr, m - 1, n, i + 1);
	}
	if (n != 0)
	{
		iStr[i] = str2[0];
		interRecur(str1, str2 + 1, iStr, m, n - 1, i + 1);
	}
}


void inter(char str1[], char str2[], int m, int n)
{
	char *iStr= new char[((m + n + 1)*sizeof(char))];
	iStr[m + n] = '\0';
	interRecur(str1, str2, iStr, m, n, 0);
	free(iStr);
}

int main()
{
	char str1[] = "AB";
	char str2[] = "CD";
	inter(str1, str2, strlen(str1), strlen(str2));
	return 0;
}

