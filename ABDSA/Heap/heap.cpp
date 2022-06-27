#include <iostream>
using namespace std;

// HeapSort is done by deleting elements from heap one by one
// and then appending deleted elements to empty posn from back
// and then displaying the array,the resultant array is sorted
void Insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];
    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int A[], int n)
{
    int i, j, x, val, temp;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // after creation of max heap: 40,25,35,10,5,20,30
    for (int i = 2; i <= 7; i++)
    {
        Insert(H, i);
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << H[i] << " ";
    }
    cout << '\n';

    for (int i = 7; i > 1; i--)
    {
        cout << "Deleted value is " << Delete(H, i) << "\n";
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << H[i] << " ";
    }
    return 0;
}

