#include<iostream>
using namespace std;

class Pair {
    public:
        int min;
        int max;
};

void MinMaxIterative (int arr[], int n) {

    Pair minmax;
    minmax.min = minmax.max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if ( minmax.min > arr[i])
            minmax.min = arr[i];
        
        if ( minmax.max < arr[i])
            minmax.max = arr[i];
    }

    cout << "Minimum element:" << minmax.min << endl;
    cout << "Maximum element:" << minmax.max << endl;

}

Pair MinMaxDaC (int arr[], int begin, int end) {

    Pair minmax;

    if (begin == end)
    {
        minmax.min = arr[begin];
        minmax.max = arr[begin];
        return minmax;
    }

    if (begin == end - 1)
    {
        if (arr[begin] > arr[end])
        {
            minmax.min = arr[end];
            minmax.max = arr[begin];
        }
        else
        {
            minmax.min = arr[begin];
            minmax.max = arr[end];
        }
        return minmax;
    }

    
    
    int mid = (begin + end)/2;

    Pair left  = MinMaxDaC(arr, begin, mid);
    Pair right = MinMaxDaC(arr, mid+1, end);

    if (left.min < right.min)
        minmax.min = left.min;
    else 
        minmax.min = right.min;

    if (left.max < right.max)
        minmax.max = right.max;
    else 
        minmax.max = left.max;

    return minmax;
}

int main() {
    
    int n;
    cout << "Enter number of elements in the array:" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    MinMaxIterative(a, n);
    Pair minmax = MinMaxDaC(a, 0, n-1);
    cout << "Minimum and Maximum = " << minmax.min << ", " << minmax.max << endl;
    return 0;
}