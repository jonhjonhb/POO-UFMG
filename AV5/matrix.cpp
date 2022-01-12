#include "matrix.h"
#include <algorithm>

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    m = nullptr;
    nRows = 0;
    nCols = 0;
}

void Matrix::fillWith(const double &value){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            m[i][j] = value;
        }
    }
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols, const double &value) : nRows(rows), nCols(cols){
    m = new double*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new double[nCols];
    }
    this->fillWith(value);
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
Matrix::Matrix(std::ifstream &myFile){
    double value;
    myFile >> this->nRows >> this->nCols >> value;
	m = new double*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new double[nCols];
    }
    this->fillWith(value);
}


// contrutor de copia
Matrix::Matrix(const Matrix& that) : nRows(that.getRows()), nCols(that.getCols()){
    m = new double*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new double[nCols];
        for(int j = 0; j < nCols; ++j){
            m[i][j] = that.get(i+1, j+1);
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


// imprime o conteudo da matriz
void Matrix::print()const {
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            std::cout << m[i][j] << "\t";
        }
		std::cout << std::endl;
    }
}

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    this->fillWith(0.0);
    for (int i = 0; i < std::min(nRows, nCols); i++){
        m[i][i] = 1;
    }   
}

double Matrix::get(int row, int col)const{
    if(row == 0 || row>nRows || col == 0 || col>nCols){
        std::cout << "Índice não existe! Retorno padrão: "; return 0;
    }
    return m[row-1][col-1];
}

double& Matrix::operator()(const int rows, const int cols){
    return *m[rows, cols];
}

Matrix Matrix::operator+(Matrix& matrixData)const{
    Matrix temp(this->getRows(), this->getCols(), 0);
    for(int i = 0; i < nRows; ++i){
      for(int j = 0; j < nCols; ++j){
        temp(i, j) = m[i][j] + matrixData(i, j);
      }
    }
    return temp;
}