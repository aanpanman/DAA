#include<bits/stdc++.h>
using namespace std;

int mostFrequent(int arr[], int n)
{
	sort(arr, arr + n);
	int win = arr[0], max = 1, curr = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])
			curr++;
		else {
			if (curr > max) {
				max = curr;
				win = arr[i - 1];
			}
			curr = 1;
		}
	}
	if (curr > max)
	{
		max = curr;
		win = arr[n - 1];
	}
	return win;
}

int main()
{
    int n;
    cout<<"Enter number of voters: ";
    cin>>n;
    int arr[n];
    cout<<"Enter votes(candidates are 1, 2, 3, 4): ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	cout << "The winner is candidate: " << mostFrequent(arr, n);
	return 0;
}
