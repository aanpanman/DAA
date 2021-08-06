#include<iostream>
using namespace std;

int descending(int arr[], int a, int n) {
    for (int i = a; i < n; i++) 
    {
        if (arr[i] < arr[i+1])
            return 0;
    }
    return 1;
}

void find(int arr[], int n) {

    //int index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i+1])
        {
            continue;
        }
        else if (arr[i] > arr[i+1]) 
        {
            if (descending(arr, i+1, n) == 1) // We need to check if the array after i is descending
            {
                //index = i;
                cout << "k = " << i << endl;
                break;
            }
            else 
            {   
                cout << "k does not exist." << endl;
                break;
            }
        }

    }
}

int main() {
    int n;
    cout << "No.of Elements:" << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //int d = descending(a, 0, n);
    //cout << d;

    find(a, n);

    return 0;
}