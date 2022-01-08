#include <bits/stdc++.h>
using namespace std;

int merge_cost(int size, int files[])
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++)
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
    int N = 2;
    int m, n;
    cout << "Enter the size of each files: \n";
    cout << "Enter the size of file 1: ";
    cin >> m;
    cout << "Enter the size of file 2: ";
    cin >> n;
    int files[N] = {m, n};
    cout << "Minimum Computations = " << merge_cost(N, files);
    return 0;
}