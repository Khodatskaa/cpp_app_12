#include <iostream>
#include <ctime>

using namespace std;

template<typename T> T sum(T n1, T n2) 
{ 
    return n1 + n2; 
}
template<typename T> T sub(T n1, T n2)
{ 
    return n1 - n2; 
}
template<typename T> T mul(T n1, T n2)
{
    return n1 * n2; 
}
template<typename T> T div(T n1, T n2)
{ 
    return (n1 == 0 || n2 == 0) ? 0 : n1 / n2; 
}

void sumArrays(const double* A, const double* B, double* C, int size)
{
    for (int i = 0; i < size; ++i)
    {
        C[i] = sum(A[i], B[i]);
    }
}

int main()
{
    int size;
    cout << "Enter size of arrays: ";
    cin >> size;

    double* A = new double[size];
    double* B = new double[size];
    double* C = new double[size];

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

    sumArrays(A, B, C, size);

	cout << "Elements of array C: ";
    for (int i = 0; i < size; ++i)
    {
		cout << C[i] << " ";
	}
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}