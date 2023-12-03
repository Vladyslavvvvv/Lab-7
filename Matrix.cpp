#include "Matrix.h"

using namespace std;

template<class T>
Matrix<T>::Matrix() {}

template<class T>
Matrix<T>::Matrix(int rows, int cols) : data(rows, vector<T>(cols)) {}

template<class T>
istream& Matrix<T>::input(istream& in) {
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[0].size(); ++j) {
            cout << "Enter value for element (" << i + 1 << "," << j + 1 << "): ";
            in >> data[i][j];
        }
    }
    return in;
}

template<class T>
ostream& Matrix<T>::output(ostream& out) const {
    for (const auto& row : data) {
        for (const T& element : row) {
            out << element << " ";
        }
        out << endl;
    }
    return out;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
    Matrix result(data.size(), data[0].size());
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[0].size(); ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
    Matrix result(data.size(), other.data[0].size());
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < other.data[0].size(); ++j) {
            for (int k = 0; k < other.data.size(); ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template<class T>
vector<T> Matrix<T>::operator*(const vector<T>& vector) const {
    vector<T> result(data.size());
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < vector.size(); ++j) {
            result[i] += data[i][j] * vector[j];
        }
    }
    return result;
}

template<class T>
istream& operator>>(istream& in, Matrix<T>& matrix) {
    return matrix.input(in);
}

template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& matrix) {
    return matrix.output(out);
}