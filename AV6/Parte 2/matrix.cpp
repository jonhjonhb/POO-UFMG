#include "matrix.h"
#include <algorithm>
#include <vector>
#include <typeinfo>

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
template <class T>
Matrix<T>::Matrix(){
    m = nullptr;
    nRows = 0;
    nCols = 0;
}

template <class T>
void Matrix<T>::fillWith(const T &value){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            m[i][j] = value;
        }
    }
}

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a 0.0 (T)
template <class T>
Matrix<T>::Matrix(int rows, int cols, const T &value) : nRows(rows), nCols(cols){
    m = new T*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new T[nCols];
    }
    this->fillWith(value);
}

// contrutor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
template <class T>
Matrix<T>::Matrix(std::ifstream &myFile){
    T value;
    myFile >> this->nRows >> this->nCols >> value;
	m = new T*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new T[nCols];
    }
    this->fillWith(value);
}


// contrutor de copia
template <class T>
Matrix<T>::Matrix(const Matrix<T>& that) : nRows(that.getRows()), nCols(that.getCols()){
    m = new T*[nRows];
    for(int i = 0; i < nRows; ++i){
        m[i] = new T[nCols];
        for(int j = 0; j < nCols; ++j){
            m[i][j] = that.get(i+1, j+1);
        }
    }
}


// destrutor
template <class T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < nRows; ++i){
      delete[] m[i];
    }
    delete[] m;
}


// imprime o conteudo da matriz
template <class T>
void Matrix<T>::print()const {
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            std::cout << m[i][j] << "\t";
        }
		std::cout << std::endl;
    }
}

// faz com que a matriz torne-se uma matriz identidade
template <class T>
void Matrix<T>::unit(){
    this->fillWith(0.0);
    for (int i = 0; i < std::min(nRows, nCols); i++){
        m[i][i] = 1;
    }   
}

template <class T>
T Matrix<T>::get(int row, int col)const{
    if(row == 0 || row>nRows || col == 0 || col>nCols)
        throw std::invalid_argument("Índice não existe!");
    return m[row-1][col-1];
}

// OPERATORS
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& that){
    
	if(this->nCols != that.getCols()
    || this->nRows != that.getRows())
        throw std::invalid_argument("[ERRO: Os números de colunas e linhas das duas matrizes devem ser os mesmo]");


	Matrix<T> temp(that);

	m = new T*[temp.getRows()];
    for(int i = 0; i < temp.getRows(); ++i){
        m[i] = new T[temp.getCols()];
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
template <class T>
T& Matrix<T>::operator()(int x, int y)const{
    if(row == 0 || row>nRows || col == 0 || col>nCols)
        throw std::invalid_argument("Erro de atribuição por célula: Índice não existe!");
    return m[x-1][y-1];
}

// mais
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& that)const{

    if(this->nCols != that.getCols()
    || this->nRows != that.getRows())
        throw std::invalid_argument("[ERRO: Os números de colunas e linhas das duas matrizes devem ser os mesmo]");


    Matrix<T> temp(*this);
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            temp(i+1, j+1) += m[i][j];
        }
    }
    return temp;
}

// mais igual
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& that){

    if(this->nCols != that.getCols()
    || this->nRows != that.getRows())
        throw std::invalid_argument("[ERRO: Os números de colunas e linhas das duas matrizes devem ser os mesmo]");


    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] += that.get(i+1, j+1);
        }
    }
    return *this;
}

// menos
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& that)const{

    if(this->nCols != that.getCols()
    || this->nRows != that.getRows())
        throw std::invalid_argument("[ERRO: Os números de colunas e linhas das duas matrizes devem ser os mesmo]");
    

    Matrix temp(*this);
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            temp(i+1,j+1) -= that.get(i+1, j+1);
        }
    }
    return temp;
}

// menos igual
template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& that){
    
    if(this->nCols != that.getCols()
    || this->nRows != that.getRows())
        throw std::invalid_argument("[ERRO: Os números de colunas e linhas das duas matrizes devem ser os mesmo]");
    

    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] -= that.get(i+1, j+1);
        }
    }
    return *this;
}

// not (transpose)
template <class T>
Matrix<T> Matrix<T>::operator~()const{
    Matrix<T> temp(nCols, nRows, 0);
    for(int i = 0; i < temp.getRows(); ++i){
        for(int j = 0; j < temp.getCols(); ++j){
            temp(i+1,j+1) = m[j][i];
        }
    }
    return temp;
}

// vezes
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& that)const{
	if(this->nCols != that.getRows()) 
        throw std::invalid_argument("[ERRO: O número de colunas da primeira matriz deve ser o mesmo número de linhas da segunda]");
    

	Matrix<T> temp(this->nRows, that.getCols());

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
template <class T>
Matrix<T>& Matrix<T>::operator*=(T coeficiente){
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
            this->m[i][j] *= coeficiente;
        }
    }
    return *this;
}

// vezes igual matrix
template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& that){
    if(this->nCols != that.getRows()) 
        throw std::invalid_argument("[ERRO: O número de colunas da primeira matriz deve ser o mesmo número de linhas da segunda]");
    

	Matrix<T> temp(*this);
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
template <class T>
bool Matrix<T>::operator==(const Matrix<T>& that)const{
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
template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& that)const{
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
template <class T>
std::ostream& operator<<(std::ostream &out, const Matrix<T> &matrixData){
    matrixData.print();
    return out;
}

// cin
template <class T>
std::istream& operator>>(std::istream &in, Matrix<T> &matrixData){
	std::cout << "Digite o número de linhas e colunas da matriz:" << std::endl;
	std::cin >> matrixData.nRows >> matrixData.nCols;
	matrixData.m = new T*[matrixData.getRows()];
    for(int i = 0; i < matrixData.getRows(); ++i){
        matrixData.m[i] = new T[matrixData.getCols()];
    }
	for(int i = 0; i < matrixData.getRows(); ++i){
		for(int j = 0; j < matrixData.getCols(); ++j ){
			in >> matrixData(i+1,j+1);
		}
	}
	return in;
}