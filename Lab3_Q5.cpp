#include<iostream>
#include<algorithm>
using namespace std;

int getroom(int start[], int end[], int n)
{
    sort(start, start + n);
    sort(end, end + n);
    int room_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n) 
    {
        if (start[i] <= end[j]) 
        {
            room_needed++;
            i++;
        }
        else if (start[i] > end[j]) 
        {
            room_needed--;
            j++;
        }
        if (room_needed > result)
            result = room_needed;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter total classes: ";
    cin >> n;
    int start[n], end[n];
    cout << "Enter start and end times: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "start time: ";
        cin >> start[i];
        cout << "end time: ";
        cin >> end[i];
    }
    cout << "Minimum number of Classrooms required = " << getroom(start, end, n);
    return 0;
}