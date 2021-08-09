#include<iostream>
using namespace std;

void sort_priority(int arr1[], int arr2[], int n) {
	int temp1, temp2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ( arr1[j] > arr1[j+1]) {
                temp1 = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp1;

                temp2 = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp2;
            }
        }
    }
}

void display(int arr1[], int arr2[], int n, int wt) {
    int total = 0;
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        if (total <= wt) {
            total = total + arr1[i]; 
            count ++;
        }
    }

    cout << "Items in the suitcase after discarding excess: " << endl;

    for (int i = 0; i < count-1; i++)
    {
        cout << "Weight of item with priority " << arr2[i] << ": " << arr1[i] << endl;
    }
}

int main() {

    int n, wt;
    cout << "Enter maximum weight: " << endl;
    cin >> wt;
    cout << "Enter number of items:" << endl;
    cin >> n;

    int w[n], p[n];

    for (int i = 0; i < n; i++) 
    {
        cout << "Weight of item " << i+1 << ": " << endl;
        cin >> w[i];
        cout << "Priority: " << endl;
        cin >> p[i];
    }
    
    sort_priority(p, w, n);
    display(w, p, n, wt);

    return 0;
}