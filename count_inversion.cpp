#include <iostream>
using namespace std;
 
void inversions(int arr[], int n) {
    
    int count = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    
    cout << "No. of inversion: " << count << endl;
}

int main() {

    int n;
    cout << "No. of elements in the array" << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    inversions(a, n);

    return 0;
}