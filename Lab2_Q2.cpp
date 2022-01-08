#include<iostream>
using namespace std;

void lmps(int a[], int n) { //LMPS with O(n) time complexity
    int l;
    cout << "Enter l: ";
    cin >> l;
    int sum = 0, max = 0, idx;
    for (int i = l-1; i < n; i++)
    {
        sum += a[i];
        if (sum > max)
        {
            max = sum;
            idx = i+1;
        }
    }
    cout << "LMPS" << l << " is: j = " << idx << " ,sum = " << max;
}

void rmps(int a[], int n) { //RMPS with O(n) time complexity
    int r;
    cout << "Enter r: ";
    cin >> r;
    int sum = 0, max = 0, idx;
    for (int i = r-1; i >= 0; i--)
    {
        sum += a[i];
        if (sum > max)
        {
            max = sum;
            idx = i+1;
        }
    }
    cout << "RMPS" << r << " is: i = " << idx << " ,sum = " << max;
}

void mps(int a[], int n) { //MPS with O(n^2) time complexity
    int max = 0, idx1, idx2;
    for (int i = 0; i < n-1; i++)
    {
        int sum = a[i];
        for (int j = i+1; j < n; j++)
        {
            sum += a[j];
            if (sum > max)
            {
                max = sum;
                idx1 = i+1;
                idx2 = j+1;
            }
        }
    }
    cout << "MPS is: i = " << idx1 << " ,j = " << idx2 <<" ,sum = " << max;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int sum(int a[], int l, int m, int h) {
    int sum = 0, l_sum = 0;
    for (int i = m; i >= l; i--)
    {
        sum += a[i];
        if (sum > l_sum)
            l_sum = sum;
    }

    sum = 0;
    int r_sum = 0;
    for (int i = m+1; i <= h; i++)
    {
        sum += a[i];
        if (sum > r_sum)
            r_sum = sum;
    }

    return max(l_sum+r_sum, l_sum, r_sum);
}

int mps_DaC(int a[], int l, int h) { //MPS with O(nlogn) time complexity, Divide and Conquer
    if (l == h)
        return a[l];
 
    int m;
    m = (l + h) / 2;

    return max(mps_DaC(a, l, m), mps_DaC(a, m + 1, h), sum(a, l, m, h));
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
    lmps(arr, n);
    cout << endl;
    rmps(arr, n);
    cout << endl;
    mps(arr, n);
    cout << endl;
    int max = mps_DaC(arr, 0, n);
    cout << max;
    return 0;
}