#include<iostream>
using namespace std;

void largest(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    cout << "max = " << max;
}

int largest_DaC(int a[], int l, int h) {
    int max = 0;
    if (l == h)
    {
        max = a[l];
        return max;
    }
    if (l == h+1)
    {
        if (a[l] > a[h])
            a[l] = max;
        else
            a[h] = max;
        return max;
    }

    int m = (l + h)/2;
    int max_l = largest_DaC(a, l, m);
    int max_r = largest_DaC(a, m+1, h);
    if (max_l > max_r)
    {
        max = a[max_l];
        return max;
    }
    else
    {
        max = a[max_r];
        return max;
    }
}

int main() {
    int n;
    cout << "Enter the total number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    largest(arr, n);
    largest(arr, n);
    //int max = largest_DaC(arr, 0, n);
    //cout << "max = " << max;
    return 0;
}