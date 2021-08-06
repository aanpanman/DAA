#include<iostream>
#include<string>
using namespace std;

void sort(int arr1[], int arr2[], int n) {
	int i, j, temp1, temp2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
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

int main() {
    int n;
    cout << "Enter number of players" << endl;
    cin >> n;
    int s[n];
    int index[n];

    cout << "Enter the scores" << endl;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        index[i] = i+1;
    }

    sort(s, index, n);

    cout << "\nWinner: Player" << index[n-1] << endl;
    cout << "\nNext winner: Player" << index[n-2] << endl ;
    cout << "\nWorst player: Player" << index[0] << endl;
    cout << "\nNext worst player: Player" << index[1] << endl;

    return 0;
}
