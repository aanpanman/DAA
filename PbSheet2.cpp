#include<iostream>
using namespace std;
 
void printRow (float arr[], int r, int c) { // Answer 1

    int x, t;
    cout << "Enter row number:" << endl;
    cin >> x;
    for (int i = 1; i <= c; i++)
    {
        t = c*(x-1) + (i-1);
        cout << arr[t] << " ";
    }
}

void printCol (float arr[], int r, int c) { // Answer 2

    int y, t;
    cout << "Enter column number:" << endl;
    cin >> y;
    for (int i = 1; i <= r; i++) 
    {
        t = c*(i-1) + (y-1);
        cout << arr[t] << " ";
    }
}

void printMatrix (float arr[], int r, int c) { // Answer 3

    int t;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            t = c*(i-1) + (j-1);
            cout << arr[t] << " ";
        }
        cout << endl;
    }
}

void printTranspose (float arr[], int r, int c) { // Answer 4

    float t[c*r];
    int d;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            d = (j*c) + i;
            t[(i*r)+j] = arr[d];
        }
    }

    printMatrix(t, c, r);
}

float maxRow (float arr[], int r, int c, int x) { // Answer 5

    int t;
    float row[c];
    for (int i = 1; i <= c; i++)
    {
        t = c*(x-1) + (i-1);
        row[i-1] = arr[t];
    }
    int max = row[0];
    for (int i = 0; i < c; i++)
    {
        if (max < row[i])
            max = row[i];
    }
    return max;
}

float maxCol (float arr[], int r, int c, int y) { // Answer 6

    int t;
    float col[r];
    for (int i = 1; i <= r; i++) 
    {
        t = c*(i-1) + (y-1);
        col[i-1] = arr[t];
    }
    int max = col[0];
    for (int i = 0; i < r; i++)
    {
        if (max < col[i])
            max = col[i];
    }
    return max;
}

void sqDiagonal (float arr[], int n) { // Answer 7

    int t;
    cout << "Diagonal elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        t = i*(n+1);
        cout << arr[t] << " ";
    }
}

void sqOtherDiagonal (float arr[], int n) { // Answer 8

    int t;
    cout << "Other diagonal elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        t = (i+1)*(n-1);
        cout << arr[t] << " ";
    }
}

void min_maxRow (float arr[], int r, int c) { // Answer 9

    float m[r];
    for (int i = 0; i < r; i++)
    {
        m[i] = maxRow(arr, r, c, (i+1));
    }

    int min = m[0];
    for (int i = 0; i < r; i++)
    {
        if (min > m[i])
            min = m[i];
    }
    cout << "Min_max_row: " << min << endl;
}

void min_maxCol (float arr[], int r, int c) { // Answer 10

    float m[c];
    for (int i = 0; i < c; i++)
    {
        m[i] = maxCol(arr, r, c, (i+1));
    }
    int min = m[0];
    for (int i = 0; i < c; i++)
    {
        if (min > m[i])
            min = m[i];
    }
    cout << "Min_max_col: " << min << endl;
}

int main () {

    int nr, nc;
    cout << "Enter size of matrix:" << endl;
    cin >> nr >> nc;
    float a[nr*nc];
    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < nr*nc; i++)
    {
        cin >> a[i];
    }

    printRow(a, nr, nc);
    cout << endl;
    printCol(a, nr, nc);

    cout << endl << "Matrix:" << endl;
    printMatrix(a, nr, nc);
    cout << "Transpose matrix:" << endl;
    printTranspose(a, nr, nc);

    int x, y;
    cout << "Enter row number:" << endl;
    cin >> x;
    float max_row = maxRow(a, nr, nc, x);
    cout << "Maximum element of the row is: " << max_row << endl;
    cout << "Enter column number:" << endl;
    cin >> y;
    float max_col = maxCol(a, nr, nc, y);
    cout << "Maximum element of the column is: " << max_col << endl;

    min_maxRow(a, nr, nc);
    min_maxCol(a, nr, nc);

    int n;
    cout << "Enter size of square matrix:" << endl;
    cin >> n;
    float b[n];
    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < n*n; i++)
    {
        cin >> b[i];
    }
    sqDiagonal(b, n);
    cout << endl;
    sqOtherDiagonal(b, n);
    cout << endl;

    return 0;
}