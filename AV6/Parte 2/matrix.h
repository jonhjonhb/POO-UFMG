#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

template <class T> 
class Matrix {
    private:

        T** m = nullptr;
        int nRows;
        int nCols;

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const T &value);
        Matrix(std::ifstream &myFile);
        Matrix(const Matrix<T>& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows()const{return nRows;}
        int getCols()const{return nCols;}
        T get(int row, int col)const;
        
        // other methods
        void fillWith(const T &value);
        void print() const;
        void unit();
        void zeros(){this->fillWith(0.0);}
        void ones(){this->fillWith(1.0);}

        // operators
		Matrix<T>& operator=(const Matrix<T>&);
        T& operator()(int x, int y)const;
        Matrix<T> operator+(const Matrix<T>&)const;
        Matrix<T>& operator+=(const Matrix<T>&);
        Matrix<T> operator-(const Matrix<T>&)const;
        Matrix<T>& operator-=(const Matrix<T>&);
        Matrix<T> operator~()const;
        Matrix<T> operator*(const Matrix<T>&)const;
        Matrix<T>& operator*=(T coeficiente);
        Matrix<T>& operator*=(const Matrix<T>&);
        bool operator==(const Matrix<T>&)const;
        bool operator!=(const Matrix<T>&)const;
        friend std::ostream& operator<<(std::ostream &out, const Matrix<T> &matrixData);
        friend std::istream& operator>>(std::istream &in, Matrix<T> &matrixData);

};

#endif