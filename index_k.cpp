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

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i+1])
        {   
            if (descending(arr, i+1, n) == 1)
                cout << "k = " << i << endl;
                continue;
        }
        else if (arr[i] > arr[i+1]) 
        {
            if (descending(arr, i+1, n) == 1)
            {
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

    find(a, n);

    return 0;
}