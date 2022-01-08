#include<iostream>
using namespace std;

int no_of_towers(int house[], int range, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (house[i] >= house[i+1])
        {
            int temp = house[i];
            house[i] = house[i+1];
            house[i+1] = temp;
        }
    }

    int tower = 0, i = 0;
    while (i < n) {
        tower++;
        int loc = house[i] + range;
        while (i < n && house[i] <= loc)
            i++;
        --i;
        loc = house[i] + range;
        while (i < n && house[i] <= loc)
            i++;
    }
    return tower;
}

int main()
{
    int n;
    cout << "Enter total houses: ";
    cin >> n;
    int house[n];
    cout << "Enter houses: ";
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }
    int range;
    cout << "Enter range: ";
    cin >> range;
    cout << "Minimum number of cell phone towers: " << no_of_towers(house, range, n);
    return 0;
}