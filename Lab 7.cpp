#include "Matrix.h"

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the matrix size: ";
    cin >> rows;
    cols = rows;

    Matrix<int> intMatrix1(rows, cols);
    Matrix<int> intMatrix2(rows, cols);

    Matrix<float> floatMatrix1(rows, cols);
    Matrix<float> floatMatrix2(rows, cols);

    cout << "Enter values for intMatrix1:" << endl;
    cin >> intMatrix1;

    cout << "Enter values for intMatrix2:" << endl;
    cin >> intMatrix2;

    cout << "Enter values for floatMatrix1:" << endl;
    cin >> floatMatrix1;

    cout << "Enter values for floatMatrix2:" << endl;
    cin >> floatMatrix2;

    cout << "Entered intMatrix1:" << endl << intMatrix1 << endl;
    cout << "Entered intMatrix2:" << endl << intMatrix2 << endl;

    cout << "Entered floatMatrix1:" << endl << floatMatrix1 << endl;
    cout << "Entered floatMatrix2:" << endl << floatMatrix2 << endl;

    Matrix<int> intSum = intMatrix1 + intMatrix2;
    Matrix<float> floatSum = floatMatrix1 + floatMatrix2;

    Matrix<int> intProduct = intMatrix1 * intMatrix2;
    Matrix<float> floatProduct = floatMatrix1 * floatMatrix2;

    cout << "Sum of int matrices:" << endl << intSum << endl;
    cout << "Sum of float matrices:" << endl << floatSum << endl;

    cout << "Product of int matrices:" << endl << intProduct << endl;
    cout << "Product of float matrices:" << endl << floatProduct << endl;

    vector<int> intVector;
    vector<float> floatVector;

    cout << "Enter values for intVector:" << endl;
    for (int i = 0; i < cols; ++i) {
        int value;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> value;
        intVector.push_back(value);
    }

    cout << "Enter values for floatVector:" << endl;
    for (int i = 0; i < cols; ++i) {
        float value;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> value;
        floatVector.push_back(value);
    }

    vector<int> intResultVector = intMatrix1 * intVector;
    vector<float> floatResultVector = floatMatrix1 * floatVector;

    cout << "Result of intMatrix1 * intVector:" << endl;
    for (const auto& element : intResultVector) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Result of floatMatrix1 * floatVector:" << endl;
    for (const auto& element : floatResultVector) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}