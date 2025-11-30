#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void FillArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void PrintArray(const double arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(8) << arr[i];
    cout << endl;
}

double SumOddIndex(const double arr[], int n) {
    double sum = 0;
    for (int i = 1; i < n; i += 2) sum += arr[i];
    return sum;
}

double SumBetweenNegatives(const double arr[], int n) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++)
        if (arr[i] < 0) { first = i; break; }

    for (int i = n - 1; i >= 0; i--)
        if (arr[i] < 0) { last = i; break; }

    if (first == -1 || last == -1 || first == last)
        return 0;

    double sum = 0;
    for (int i = first + 1; i < last; i++)
        sum += arr[i];

    return sum;
}

void CompressArray(double arr[], int n) {
    int pos = 0; // куди записувати

    for (int i = 0; i < n; i++)
        if (fabs(arr[i]) > 1)
            arr[pos++] = arr[i];

    while (pos < n)
        arr[pos++] = 0;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    double* arr = new double[n];

    FillArray(arr, n);

    cout << "\nArray: " << endl;
    PrintArray(arr, n);

    cout << "\nSum of odd-index elements: " 
         << SumOddIndex(arr, n) << endl;

    cout << "Sum between first and last negative: "
         << SumBetweenNegatives(arr, n) << endl;

    CompressArray(arr, n);

    cout << "\nCompressed array:" << endl;
    PrintArray(arr, n);

    delete[] arr;
    return 0;
}
