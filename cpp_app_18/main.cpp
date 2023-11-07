#include <iostream>
#include <ctime>
using namespace std;

double FindMax(const double* A, const double* B, int size) 
{
    double max_value = A[0] > B[0] ? A[0] : B[0];
    for (int i = 1; i < size; ++i) 
    {
        double max_element = A[i] > B[i] ? A[i] : B[i];
        if (max_element > max_value)
        {
            max_value = max_element;
        }
    }
    return max_value;
}

double FindMin(const double* A, const double* B, int size)
{
    double min_value = A[0] < B[0] ? A[0] : B[0];
    for (int i = 1; i < size; ++i) 
    {
        double min_element = A[i] < B[i] ? A[i] : B[i];
        if (min_element < min_value)
        {
            min_value = min_element;
        }
    }
    return min_value;
}

double FindAverage(const double* A, const double* B, int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += A[i] + B[i];
    }
    return sum / (2 * size);
}

double Action(const double* A, const double* B, int size, double (*operation)(const double*, const double*, int)) 
{
    return operation(A, B, size);
}

int main() 
{
    int size;
    cout << "Enter the size of the arrays: ";
    cin >> size;

    double* A = new double[size];
    double* B = new double[size];

    cout << "Enter elements for array A: ";
    for (int i = 0; i < size; ++i) 
    {
        cin >> A[i];
    }

    cout << "Enter elements for array B: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> B[i];
    }

    cout << "\nSelect an operation:" << endl;
    cout << "1. Max" << endl;
    cout << "2. Min" << endl;
    cout << "3. Average" << endl;

    int choice;
    cin >> choice;

    if (choice < 1 || choice > 3)
    {
        cout << "Invalid choice." << endl;
        return 1;
    }

    double (*operations[])(const double*, const double*, int) = { FindMax, FindMin, FindAverage };

    double result = Action(A, B, size, operations[choice - 1]);
    cout << "\nResult: " << result << endl;

    delete[] A;
    delete[] B;

    return 0;
}
