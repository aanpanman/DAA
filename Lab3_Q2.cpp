#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void bub_sort(int arr1[], int arr2[], int n) 
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                swap(arr1 + j, arr1 + j + 1);
                swap(arr2 + j, arr2 + j + 1);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void least_waiting_time(int wait[], int n)
{   
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i+1;
    }
    bub_sort(wait, arr, n);
    cout << "Order in which customers are to served: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Customer" << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter total customers: ";
    cin >> n;
    int wait[n];
    cout << "Enter service time for each customer: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wait[i];
    }
    least_waiting_time(wait, n);
    return 0;
}