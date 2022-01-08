#include<iostream>
#include<vector>
using namespace std;

/* n = 6, d = 2
p1 = 6,7
p2 = 1,5
p3 = 6,4
p4 = 3,5 
p5 = 10,5 
p6 = 5,7 
*/

int main() {

    int n, d = 2;
    cout << "Enter value of d:" << endl;
    cin >> d;
    cout << "Number of points: " << endl;
    cin >> n;
    int a[n][d];
    //let d=2 for simplicity of the program 
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter values for p" << i+1 << ": " << endl; 
        for (int j = 0; j < d; j++)
        {
            cin >> a[i][j];
        }
    }

    int count_lesser = 0;
    int count_greater = 0;
    int compare = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = 0; k < d; k++)
            {
                if (a[i][k] >= a[j][k])
                {
                    count_greater++;
                }
                if (a[i][k] <= a[j][k])
                {
                    count_lesser++;
                }
            }

            if (count_greater == d || count_lesser == d)
            {
                cout << "p" << i+1 << " and p" << j+1 << " are comparable" << endl; 
            }
            else
            {
                cout << "p" << i+1 << " and p" << j+1 << " are NOT comparable" << endl; 
                compare++;
            }
            count_lesser = 0;
            count_greater = 0;
        }
    }

    int f[compare][2];
    compare = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = 0; k < d; k++)
            {
                if (a[i][k] >= a[j][k])
                {
                    count_greater++;
                }
                if (a[i][k] <= a[j][k])
                {
                    count_lesser++;
                }
            }

            if ((count_greater == d || count_lesser == d) == false)
            {
                f[compare][0] = i+1;
                f[compare][1] = j+1;
                compare++;
                 
            }
            count_lesser = 0;
            count_greater = 0;
        }
    }

    cout << "Sets of not comparable points: " << endl;

    for (int i = 0; i < compare; i++)
    {
        cout << "F" << i+1 << " = {p" << f[i][0] << ", p" << f[i][1] << "}" << endl; 
    }

    cout << "Final sets: " << endl;

    int c = 0;
    for (int i = 0; i < compare; i++)
    {
        for (int j = i+1; j < compare; j++)
        {
            for (int m = 0; m < 2; m++)
            {
                for (int k = 0; k < d; k++)
                {
                    if (a[f[i][m]][k] >= a[f[j][m]][k])
                    {
                        count_greater++;
                    }
                }

                if (count_greater == d)
                {
                    c++; 
                }
                count_lesser = 0;
                count_greater = 0;
            }
            if (c == 4)
            {
                cout << "F" << i+1 << " = {p" << f[i][0] << ", p" << f[i][1] << "}" << endl; 
            }
        }
    }

}