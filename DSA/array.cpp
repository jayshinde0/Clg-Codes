#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int pos, int value)
{
    if (pos > n || pos < 0)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = n; i > pos; i--)
    { // Shift elements to the right
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++; // Increase size of array
}

void deleteElement(int arr[], int &n, int pos)
{
    if (pos >= n || pos < 0)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
    { // Shift elements to the left
        arr[i] = arr[i + 1];
    }
    n--; // Reduce array size
}
int main()
{
    int arr[10] = {1, 2, 3, 5, 6}; // Initial array
    int n = 5;                     // Current number of elements

    int pos = 3, value = 4;
    insertElement(arr, n, pos, value);
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    pos = 2;
    cout<<endl;
    deleteElement(arr, n, pos);
    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
