#include <iostream>
#include "matrix.h"

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    m = nullptr;
    nRows = 0;
    nCols = 0;
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem): nRows(rows), nCols(cols){
    m = new double*[rows];
    for(int i = 0; i < rows; ++i){
        m[i] = new double[cols];
        for(int j = 0; j < cols; ++j){
            m[i][j] = elem;
        }
    }
}

// destrutor
Matrix::~Matrix() {
    for(int i = 0; i < nRows; ++i){
        delete[] m[i];
    }
    delete[] m;
}


// obtem o numero de linhas
int Matrix::getRows() const {
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    Matrix temp(nCols, nRows, 0);
    
    for(int i = 0; i < temp.nRows; ++i){
        for(int j = 0; j < temp.nCols; ++j){
            temp.m[i][j] = m[j][i];
        }
    }
    
    return temp;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            std::cout << m[i][j] << "\t";
        }
		std::cout << std::endl;
    }
}