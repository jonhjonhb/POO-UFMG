#include "matrix.h"
#include <algorithm>
#include <vector>

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

// OPERATORS
Matrix& Matrix::operator=(const Matrix& that){
	Matrix temp(that);
	
	m = new double*[temp.getRows()];
    for(int i = 0; i < temp.getRows(); ++i){
        m[i] = new double[temp.getCols()];
    }
	this->nRows = temp.getRows();
	this->nCols = temp.getCols();
	for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            m[i][j] += temp.get(i+1, j+1);
        }
	}
	return *this;
}

// cell operator
double& Matrix::operator()(int x, int y)const{
    return m[x-1][y-1];
}

// mais
Matrix Matrix::operator+(const Matrix& that)const{
    Matrix temp(*this);
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            temp(i+1, j+1) += m[i][j];
        }
    }
    return temp;
}

// mais igual
Matrix& Matrix::operator+=(const Matrix& that){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] += that.get(i+1, j+1);
        }
    }
    return *this;
}
// menos
Matrix Matrix::operator-(const Matrix& that)const{
    Matrix temp(*this);
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            temp(i+1,j+1) -= that.get(i+1, j+1);
        }
    }
    return temp;
}

// menos igual
Matrix& Matrix::operator-=(const Matrix& that){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] -= that.get(i+1, j+1);
        }
    }
    return *this;
}

// not (transpose)
Matrix Matrix::operator~()const{
    Matrix temp(nCols, nRows, 0);
    for(int i = 0; i < temp.getRows(); ++i){
        for(int j = 0; j < temp.getCols(); ++j){
            temp(i+1,j+1) = m[j][i];
        }
    }
    return temp;
}

// vezes
Matrix Matrix::operator*(const Matrix& that)const{
	if(this->nCols != that.getRows()){
		std::cout << "[ERRO: O número de colunas da primeira matriz deve ser o mesmo número de linhas da segunda]" << std::endl;
		return *this;
	}
	Matrix temp(this->nRows, that.getCols());

    for(int i = 0; i < temp.getRows(); ++i){
        for(int j = 0; j < temp.getCols(); ++j){
            for(int k = 0; k < temp.getCols(); ++k){
				temp(i+1,j+1) += m[i][k]*that.get(k+1, j+1);
			}
        }
    }
    return temp;
}

// vezes igual constante
Matrix& Matrix::operator*=(double coeficiente){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] *= coeficiente;
        }
    }
    return *this;
}

// vezes igual matrix
Matrix& Matrix::operator*=(const Matrix& that){
    if(this->nCols != that.getRows()){
		std::cout << "[ERRO: O número de colunas da primeira matriz deve ser o mesmo número de linhas da segunda]" << std::endl;
		return *this;
	}
	Matrix temp(*this);
	this->nCols = that.getCols();
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
			m[i][j] = 0.0;
            for(int k = 0; k < nCols; ++k){
				m[i][j] += temp.get(i+1,k+1)*that.get(k+1,j+1);
			}
        }
    }
	return *this;
}

// bool igualdade
bool Matrix::operator==(const Matrix& that)const{
    bool isEqual = true;
	if(nRows != that.getRows() || nCols != that.getCols()) return false;
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            if(this->m[i][j] != that.get(i+1, j+1))
                isEqual = false;
        }
    }
    return isEqual;
}

// bool diferença
bool Matrix::operator!=(const Matrix& that)const{
    bool isEqual = true;
	if(nRows != that.getRows() || nCols != that.getCols()) return true;
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            if(this->m[i][j] != that.get(i+1, j+1))
                isEqual = false;
        }
    }
    return !isEqual;
}

// cout
std::ostream& operator<<(std::ostream &out, const Matrix &matrixData){
    matrixData.print();
    return out;
}

// cin
std::istream& operator>>(std::istream &in, Matrix &matrixData){
	std::cout << "Digite o número de linhas e colunas da matriz:" << std::endl;
	std::cin >> matrixData.nRows >> matrixData.nCols;
	matrixData.m = new double*[matrixData.getRows()];
    for(int i = 0; i < matrixData.getRows(); ++i){
        matrixData.m[i] = new double[matrixData.getCols()];
    }
	for(int i = 0; i < matrixData.getRows(); ++i){
		for(int j = 0; j < matrixData.getCols(); ++j ){
			in >> matrixData(i+1,j+1);
		}
	}
	return in;
}
