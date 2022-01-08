#include<iostream>
using namespace std;

int rfib (int n) {
    if (n <= 1)
        return n;
    return rfib(n-1) + rfib(n-2);
}

int ifib (int n) {
    int num;
    int a = 0, b = 1;

    for (int i = 1; i < n; i++)
    {
        num = a;
        a = b;
        b = a + num;
    }
    return b;
}

int main () {

    int n;
    cout << "Enter an integer, n: " << endl;
    cin >> n;
    cout << "F" << n << " by recursive method: " << (rfib(n)) << endl;
    cout << "F" << n << " by iterative method: " << (ifib(n)) << endl;

    return 0;
}