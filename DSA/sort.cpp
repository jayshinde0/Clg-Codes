#include <iostream>
using namespace std;
int main()
{
    int a[50];
    int n;
    cout << "Enter Number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    cout << endl
         << " Beforee Array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        cout << endl;
        cout << "Pass " << i << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << "\t";
        }
    }
    

    cout << endl
         << "Array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}