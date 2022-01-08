#include<iostream>
#include<algorithm>
using namespace std;

struct Event
{
    char id;	 
    int deadline; 
    int profit;
};

bool comparison(Event a, Event b)
{
	return (a.profit > b.profit);
}

void schedule(Event arr[], int n)
{
	sort(arr, arr+n, comparison);
	int result[n];
	bool timeslot[n];
	for (int i=0; i<n; i++)
    {
		timeslot[i] = false;
    }
	for (int i=0; i<n; i++)
	{
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (timeslot[j] == false)
            {
                result[j] = i;
                timeslot[j] = true;
                break;
            }
        }
	}
	for (int i=0; i<n; i++)
	if (timeslot[i])
    {
		cout << arr[result[i]].id << " ";
    }
}

int main()
{
    int n;
    cout << "Enter number of events: ";
    cin >> n;
    Event arr[n];
    cout << "Enter event details: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter event ID: ";
        cin >> arr[i].id;
        cout << "Enter event deadline: ";
        cin >> arr[i].deadline;
        cout << "Enter event profit: ";
        cin >> arr[i].profit;
    }
    cout << "Maximum profit squence: " << endl;
    schedule(arr, n);
    return 0;
}
