#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, double elem);
        Matrix(int rows, int cols) : Matrix(rows, cols, 0){}
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        
        // other methods
        Matrix transpose();
        void print() const;
        
};

#endif