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
        Matrix(){
            m = nullptr;
            nRows = 0;
            nCols = 0;
        }                       
        Matrix(int rows, int cols, const T &value) : nRows(rows), nCols(cols){
            m = new T*[nRows];
            for(int i = 0; i < nRows; ++i){
                m[i] = new T[nCols];
            }
            this->fillWith(value);
        }
        Matrix(std::ifstream &myFile){
            T value;
            myFile >> this->nRows >> this->nCols >> value;
            m = new T*[nRows];
            for(int i = 0; i < nRows; ++i){
                m[i] = new T[nCols];
            }
            this->fillWith(value);
        }
        Matrix(const Matrix<T>& that) : nRows(that.getRows()), nCols(that.getCols()){
            m = new T*[nRows];
            for(int i = 0; i < nRows; ++i){
                m[i] = new T[nCols];
                for(int j = 0; j < nCols; ++j){
                    m[i][j] = that.get(i+1, j+1);
                }
            }
        }
        // destrutor
        ~Matrix(){
            for(int i = 0; i < nRows; ++i){
            delete[] m[i];
            }
            delete[] m;
        }
    
        // basic getters
        int getRows()const{return nRows;}
        int getCols()const{return nCols;}
        T get(int row, int col)const{
            if(row == 0 || row>nRows || col == 0 || col>nCols)
                throw std::invalid_argument("Índice não existe!");
            return m[row-1][col-1];
        }
        
        // other methods
        void fillWith(const T &value){
            for(int i = 0; i < nRows; ++i){
                for(int j = 0; j < nCols; ++j){
                    m[i][j] = value;
                }
            }
        }
        void print()const{
            for(int i = 0; i < nRows; ++i){
                for(int j = 0; j < nCols; ++j){
                    std::cout << m[i][j] << "\t";
                }
                std::cout << std::endl;
            }
        }
        void unit(){
            if(typeid(this->m) != typeid(int*)
            && typeid(this->m) != typeid(float*)
            && typeid(this->m) != typeid(double*))
                throw std::invalid_argument("[ERRO: A matriz não é numérica]");

            this->fillWith(T(0.0));
            for (int i = 0; i < std::min(nRows, nCols); i++){
                m[i][i] = 1;
            }   
        }
        void zeros(){this->fillWith(0.0);}
        void ones(){this->fillWith(1.0);}

        // operators
		Matrix<T>& operator=(const Matrix<T>& that){
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
        T& operator()(int x, int y)const{
            if(getRows() == 0 || getRows()>nRows || getCols() == 0 || getCols()>nCols)
                throw std::invalid_argument("Erro de atribuição por célula: Índice não existe!");
            return m[x-1][y-1];
        }
        Matrix<T> operator+(const Matrix<T>& that)const{
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
        Matrix<T>& operator+=(const Matrix<T>& that){
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
        Matrix<T> operator-(const Matrix<T>& that)const{
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
        Matrix<T>& operator-=(const Matrix<T>& that){
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
        Matrix<T> operator~()const{
            Matrix<T> temp(nCols, nRows, 0);
            for(int i = 0; i < temp.getRows(); ++i){
                for(int j = 0; j < temp.getCols(); ++j){
                    temp(i+1,j+1) = m[j][i];
                }
            }
            return temp;
        }
        Matrix<T> operator*(const Matrix<T>& that)const{
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
        Matrix<T>& operator*=(T coeficiente){
            for(int i = 0; i < nRows; ++i){
                for(int j = 0; j < nCols; ++j){
                    this->m[i][j] *= coeficiente;
                }
            }
            return *this;
        }
        Matrix<T>& operator*=(const Matrix<T>& that){
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
        bool operator==(const Matrix<T>& that)const{
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
        bool operator!=(const Matrix<T>& that)const{
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
        friend std::ostream& operator<<(std::ostream &out, const Matrix<T> &matrixData){
            matrixData.print();
            return out;
        }
        friend std::istream& operator>>(std::istream &in, Matrix<T> &matrixData){
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

};

#endif