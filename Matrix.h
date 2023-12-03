#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Matrix {
private:
    vector<vector<T>> data;

public:
    Matrix();
    Matrix(int rows, int cols);

    // Input and output operations
    istream& input(istream& in);
    ostream& output(ostream& out) const;

    // Matrix addition, multiplication, and matrix-vector multiplication
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    vector<T> operator*(const vector<T>& vector) const;
};

// Input operator overload for Matrix
template<class T>
istream& operator>>(istream& in, Matrix<T>& matrix);

// Output operator overload for Matrix
template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& matrix);