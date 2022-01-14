#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

template <class T> 
class Matrix {
    private:

        double** m = nullptr;
        T nRows;
        T nCols;

    public:

        // Construtores
        Matrix();                           
        Matrix(T rows, T cols, const double &value = 0.0);
        Matrix(std::ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        T getRows()const{return nRows;}
        T getCols()const{return nCols;}
        T get(T row, T col)const;
        
        // other methods
        void fillWith(const double &value);
        void print() const;
        void unit();
        void zeros(){this->fillWith(0.0);}
        void ones(){this->fillWith(1.0);}

        // operators
		Matrix& operator=(const Matrix&);
        double& operator()(T x, T y)const;
        Matrix operator+(const Matrix&)const;
        Matrix& operator+=(const Matrix&);
        Matrix operator-(const Matrix&)const;
        Matrix& operator-=(const Matrix&);
        Matrix operator~()const;
        Matrix operator*(const Matrix&)const;
        Matrix& operator*=(double coeficiente);
        Matrix& operator*=(const Matrix&);
        bool operator==(const Matrix&)const;
        bool operator!=(const Matrix&)const;
        friend std::ostream& operator<<(std::ostream &out, const Matrix &matrixData);
        friend std::istream& operator>>(std::istream &in, Matrix &matrixData);

};

#endif