#include<iostream> 
using namespace std;

void select(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            cout << "Point at which f(n) becomes negative or equal to zero: " << i+1 << endl;
            cout << "Value of f(n): " << arr[i] << endl;
            break;
        }
    }
}

int select_sec(int arr[], int l, int r) {

    int mid = (l+r) / 2;
    if (arr[mid] > 0)
    {
        return select_sec(arr, mid+1, r);
    }
    else //if (arr[mid] <= 0)
    {
        if (arr[mid-1] > 0)
        {
            return mid;
        }
        else 
        {
            return select_sec(arr, l, mid);
        }
    }
}

int main() {

    int n;
    cout << "Enter the total number of values for f(n): ";
    cin >> n;
    int arr[n];
    cout << "Enter the values for f(n): " << endl; //here we are assuming f(n) is a constantly decreasing function
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    //for iterative method (O(n) method)
    if (arr[0] <= 0)
    {
        cout << "f(n) has only zero or negative values." << endl;
        select(arr, n);
    }
    else if (arr[n-1] > 0)
    {
        cout << "f(n) does not have any negative values." << endl;
    }
    else 
    {
        select(arr, n);
    }

    //for divide and conquer method (O(logn) method)
    if (arr[0] <= 0)
    {
        cout << "f(n) has only zero or negative values." << endl;
        cout << "Point at which f(n) becomes negative or equal to zero: " << 1 << endl;
        cout << "Value of f(n): " << arr[0] << endl;
    }
    else if (arr[n-1] > 0)
    {
        cout << "f(n) does not have any negative values." << endl;
    }
    else 
    {
        int neg = select_sec(arr, 0, n-1);
        cout << "Point at which f(n) becomes negative or equal to zero: " << neg+1 << endl;
        cout << "Value of f(n): " << arr[neg] << endl;  
    }
    
    return 0;
}