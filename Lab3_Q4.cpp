#include<bits/stdc++.h>
using namespace std;

int merge(int n, int files[])
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) 
    {
		pq.push(files[i]);
	}
	int count = 0;
	while (pq.size() > 1) 
    {
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();

		int temp = first_smallest + second_smallest;
		count += temp;
		pq.push(temp);
	}
	return count;
}

int main()
{
	int n = 6;
    cout << "Enter number of files: ";
    cin >> n;
    int files[n];
    cout << "Enter the file size: ";
    for (int i = 0; i < n; i++)
    {
        cin >> files[i];
    }
	cout << "Optimal sum = " << merge(n, files);
	return 0;
}
