/*
 * File:   mcMatrix.h
 *
 * @author Thales Luis Rodrigues Sabino
 * @date   2009
 */

#ifndef _MCMATRIX_H
#define	_MCMATRIX_H

#include <cmath>
#include <cassert>
#include <iostream>
#include <string>

#include "mcMath.h"
#include "mcMathDefinitions.h"
#include "mcVector.h"
#include "mcQuaternion.h"

namespace mc {
namespace math {


template <typename T> class Vec2;
template <typename T> class Vec3;
template <typename T> class Vec4;

template <typename T> class Matrix2;
template <typename T> class Matrix3;
template <typename T> class Matrix4;

/**
 * @brief Classe template para representação de matrizes 2x2
 */
template<typename T>
class Matrix2 {
    /// Atributos
public:

    union {

        struct {
            T _00, _01;
            T _10, _11;
        };

        T _array[4]; // array access
    };


    /// Métodos
public:

    /**
     * @brief Construtor padrão, constroi uma matriz 2x2 com o valor passado
     *
     * @param Valor a ser setado em todas as posições
     */
    Matrix2(const T &t) {
        this->setValue(
                       t, t,
                       t, t
                       );
    }

    /**
     * @brief Construtor padrão, constroi uma matriz identidade
     *
     * @param Valor a ser setado em todas as posições
     */
    Matrix2() {
        this->identity();
    }

    /**
     * @brief Construtor explicito, constroi uma matriz 2x2 com os valores passados
     *
     * @param __00 - Posição 00
     * @param __01 - Posição 01
     * @param __11 - Posição 11
     * @param __12 - Posição 12
     */
    Matrix2(
            const T __00, const T __01,
            const T __10, const T __11
            ) : _00(__00), _01(__01),
    _10(__10), _11(__11) {
    }

    /**
     * @brief Construtor por cópia de vetor, constroi uma matriz 2x2 com o vetor passado
     *
     * @param m - Matriz a ser copiada
     */
    Matrix2(const T *m) {
        this->setValue(m);
    }

    /**
     * @brief Construtor por cópia de matriz.
     *
     * @param m - Matriz a ser copiada
     */
    Matrix2(const Matrix2<T> &m) {
        this->setValue(m);
    }

    /**
     * @brief Constrói por cópia a partir de outro tipo
     *
     * @param m
     */
    template <typename T2>
    Matrix2(const Matrix2<T2> &m) {
        this->setValue(m);
    }

    /**
     * @brief Construtor por cópia de matriz. Retira uma matriz 2x2 de uma 3x3
     *
     * @param m - Matriz a ser copiada
     */
    Matrix2(const Matrix3<T> &m) {
        this->setValue(
                       m._00, m._01,
                       m._10, m._11
                       );
    }

    /**
     * @brief Construtor por cópia de matriz. Retira uma matriz 2x2 de uma 4x4
     *
     * @param m - Matriz a ser copiada
     */
    Matrix2(const Matrix4<T> &m) {
        this->setValue(
                       m._00, m._01,
                       m._10, m._11
                       );
    }

    /**
     * @brief Retorna o número de linhas da matriz
     */
    int getRowCount() const {
        return 2;
    }

    /**
     * @brief Retorna o número de colunas da matriz
     */
    int getColCount() const {
        return 2;
    }

    /**
     * @brief Retorna o número de elementos desta matriz
     */
    int getSize() const {
        return 4;
    }

    /**
     * @brief Acessa um elemento da matriz
     *
     * @param i - Acesso a linha
     * @param j - Acesso a coluna
     */
    T getElement(int i, int j) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getColCount());
        return this->_array[this->getColCount() * j + i];
    }

    /**
     * @brief Seta um elemento da matriz 2x2
     *
     * @param i - Linha
     * @param j - Coluna
     * @param e - Elemento a ser setado
     */
    void setElement(int i, int j, T e) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getColCount());
        this->_array[this->getColCount() * i + j] = e;
    }

    /**
     * @brief Cria uma matriz identidade 2x2
     */
    void identity() {
        this->_00 = (T) 1;
        this->_01 = (T) 0;
        this->_10 = (T) 0;
        this->_11 = (T) 1;
    }

    /**
     * @brief Operador de soma de matrizes 2x2
     *
     * @param m1
     */
    Matrix2<T> operator +(const Matrix2<T>& m) const {
        Matrix2<T> mr;
        mr._00 = this->_00 + mr._00;
        mr._01 = this->_01 + mr._01;
        mr._10 = this->_10 + mr._10;
        mr._11 = this->_11 + mr._11;
        return *mr;
    }

    /**
     * @brief Operador de subtração de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix2<T> operator -(const Matrix2<T>& m) const {
        Matrix2<T> mr;
        mr._00 = this->_00 - m._00;
        mr._01 = this->_01 - m._01;
        mr._10 = this->_10 - m._10;
        mr._11 = this->_11 - m._11;
        return mr;
    }

    /**
     * @brief Operador de multiplicação de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix2<T> operator *(const Matrix2<T>& m) const {
        Matrix2<T> mr;
        mr._00 = this->_00 * m._00 + this->_01 * m._10;
        mr._01 = this->_00 * m._01 + this->_01 * m._11;
        mr._10 = this->_10 * m._00 + this->_11 * m._10;
        mr._11 = this->_10 * m._01 + this->_11 * m._11;
        return mr;
    }

    /**
     * @brief Operador de soma de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix2<T> & operator +=(const Matrix2<T>& m) {
        *this = *this +m;
        return *this;
    }

    /**
     * @brief Operador de subtração de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix2<T> & operator -=(const Matrix2<T>& m) {
        *this = *this -m;
        return *this;
    }

    /**
     * @brief Operador de multiplicação de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix2<T> & operator *=(const Matrix2<T>& m) {
        *this = *this * m;
        return *this;
    }

    /**
     * @brief Operador de atribuição por cópia
     *
     * @param m
     */
    Matrix2<T> & operator =(const Matrix2<T> &m) {
        return this->setValue(m);
    }

    /**
     * @brief Operador de atribuição por cópia de tipo diferente
     *
     * @param m
     */
    template <typename T2>
            Matrix2<T> & operator =(const Matrix2<T2> &m) {
        return this->setValue(m);
    }

    /**
     * @brief Transpõe a matriz 2x2
     */
    void transpose() {
        Matrix2<T> m(*this);
        /// Transpõe os dois elementos que serão modificados
        this->_01 = m._10;
        this->_10 = m._01;
    }

    /**
     * @brief Transpõe a matriz 2x2
     */
    void transpose(Matrix2<T> &m) {
        /// Transpõe os dois elementos que serão modificados
        this->_01 = m._10;
        this->_10 = m._01;
    }



    /**
     * @brief Retorna o determinante da matriz 2x2
     *
     * @return O determinante da matriz
     */
    T determinant() {
        return (this->_00 * this->_11 - this->_01 * this->_10);
    }

    /**
     * @brief Retorna o vetor com os dados da matriz 2x2
     *
     * @return Os dados da matriz
     */
    T* getArray() {
        return this->_array;
    }
	
	const T* getArray() const {
		return this->_array;
	}

    /**
     * @brief Seta o vetor com os dados da matriz 2x2
     *
     * @param array
     */
    Matrix2<T>& setValue(const T *array) {
        for (register unsigned int i = 0; i < this->getSize(); i++) this->_array[i] = array[i];
        return *this;
    }

    /**
     * @brief Seta o vetor com os dados da matriz 2x2
     *
     * @param m
     */
    Matrix2<T>& setValue(const Matrix2<T> &m) {
        this->_00 = m._00;
        this->_01 = m._01;
        this->_10 = m._10;
        this->_11 = m._11;
        return *this;
    }

	/**
	 * @brief Seta a matrix diretamente
	 */
	Matrix2<T>& setValue( T _00, T _01, T _10, T _11 ) {
		this->_00 = _00;
		this->_01 = _01;
		this->_10 = _10;
		this->_11 = _11;

		return *this;
	}

    /**
     * @brief Seta o valor por cópia de tipo diferente
     *
     * @param m
     */
    template <typename T2>
    Matrix2<T>& setValue(const Matrix2<T2> &m) {
        this->_00 = (T) m._00;
        this->_01 = (T) m._01;
        this->_10 = (T) m._10;
        this->_11 = (T) m._11;
        return *this;
    }

    /**
     * @brief Calcula a inversa desta matriz
     *
     * @return true se a matriz tiver inversa e falso caso contrário
     */
    bool inverse() {
        Matrix2<T> m(*this);

        /// Inverte a diagonal principal
        this->_00 = -m._11;
        this->_11 = -m._00;

        T det = this->determinant();

        if (det <= (T) 0) return false;

        this->_00 /= det;
        this->_01 /= det;
        this->_10 /= det;
        this->_11 /= det;

        return true;
    }

    /**
     * @brief Calcula a inversa de uma matriz
     *
     * @return true se a matriz tiver inversa e falso caso contra
     */
    bool inverse(const Matrix2<T> &m) {
        this->setValue(m);
        return this->inverse();
    }

    /**
     * @brief Compara duas matrizes para ver se são iguais
     *
     * @param m1 - Matriz
     * @param m2 - Matriz
     */
    friend bool operator ==(const Matrix2<T> &m1, const Matrix2<T> &m2) {
        for ( unsigned int i = 0; i < m1.getSize(); i++)
            if (m1._array[i] != m2._array[i]) return false;

        return true;
    }

    /**
     * @brief Operador para impressão
     */
    friend std::ostream & operator <<(std::ostream &out, const Matrix2<T> &m) {
        out << std::fixed <<
                "| " << m._00 << " " << m._01 << " |" << std::endl <<
                "| " << m._10 << " " << m._11 << " |";

        return out;
    }

};

/**
 * @brief Classe template para representação de matrizes 3x3
 */
template<typename T>
class Matrix3 {
    /// Atributos
public:

    union {

        struct {
            T _00, _01, _02;
            T _10, _11, _12;
            T _20, _21, _22;
        };

        T _array[9]; // array access
    };


    /// Métodos
public:

    /**
     * @brief Construtor padrão, constroi uma matriz 3x3 com o valor passado
     *
     * @param Valor a ser setado em todas as posições
     */
    Matrix3(const T &t = T()) {
        this->setValue(
                       t, t, t,
                       t, t, t,
                       t, t, t
                       );
    }

    /**
     * @brief Construtor explicito, constroi uma matriz 3x3 com os valores passados
     *
     * @param __00 - Posição 00
     * @param __01 - Posição 01
     * @param __11 - Posição 11
     * @param __12 - Posição 12
     */
    Matrix3(
            const T __00, const T __01, const T __02,
            const T __10, const T __11, const T __12,
            const T __20, const T __21, const T __22
            ) : _00(__00), _01(__01), _02(__02),
    _10(__10), _11(__11), _12(__12),
    _20(__20), _21(__21), _22(__22) {
    }

    /**
     * @brief Construtor por cópia de vetor, constroi uma matriz 3x3 com o vetor passado
     *
     * @param m - Matriz a ser copiada
     */
    Matrix3(const T *m) {
        this->setValue(m);
    }

    /**
     * @brief Construtor por cópia de matriz. Constrói a partir de uma matriz 2x2
     *
     * @param m - Matriz a ser copiada
     */
    Matrix3(const Matrix2<T> &m) {
        this->setValue(
                       m._00, m._01, (T) 0,
                       m._10, m._11, (T) 0,
                       (T) 0, (T) 0, (T) 0
                       );
    }

    /**
     * @brief Construtor por cópia de matriz.
     *
     * @param m - Matriz a ser copiada
     */
    Matrix3(const Matrix3<T> &m) {
        this->setValue(
                       m._00, m._01, m._02,
                       m._10, m._11, m._12,
                       m._20, m._21, m._22
                       );
    }

    /**
     * @brief Constrói a matrix a partir de outro tipo
     *
     * @param m
     */
    template <typename T2>
    Matrix3(const Matrix3<T2> &m) {
        this->setValue(
                       m._00, m._01, m._02,
                       m._10, m._11, m._12,
                       m._20, m._21, m._22
                       );
    }

    /**
     * @brief Construtor por cópia de matriz. Constrói a partir de uma matriz 4x4
     *
     * @param m - Matriz a ser copiada
     */
    Matrix3(const Matrix4<T> &m) {
        this->setValue(
                       m._00, m._01, m._02,
                       m._10, m._11, m._12,
                       m._20, m._21, m._22
                       );
    }

    /**
     * @brief Retorna o número de linhas da matriz
     */
    inline int getRowCount() const {
        return 3;
    }

    /**
     * @brief Retorna o número de colunas da matriz
     */
    inline int getColCount() const {
        return 3;
    }

    /**
     * @brief Retorna o número de elementos da matriz
     */
    inline int getSize() const {
        return 9;
    }

    /**
     * @brief Acessa um elemento da matriz
     *
     * @param i - Acesso a linha
     * @param j - Acesso a coluna
     */
    T getElement(int i, int j) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getColCount());
        return this->_array[this->getColCount() * j + i];
    }

    /**
     * @brief Seta um elemento da matriz 3x3
     *
     * @param i - Linha
     * @param j - Coluna
     * @param e - Elemento a ser setado
     */
    void setElement(int i, int j, T e) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getColCount());
        this->_array[this->getColCount() * j + i] = e;
    }

    /**
     * @brief Seta o vetor com os dados da matriz 2x2
     *
     * @return Os dados da matriz
     */
    Matrix3<T>& setValue(const T *array) {
        for (register unsigned int i = 0; i < this->getSize(); i++) this->_array[i] = array[i];
        return *this;
    }

    /**
     * @brief Seta o valor por cópia
     *
     * @param m
     */
    Matrix3<T>& setValue(const Matrix3<T> &m) {
        this->_00 = m._00;
        this->_01 = m._01;
        this->_02 = m._02;
        this->_10 = m._10;
        this->_11 = m._11;
        this->_12 = m._12;
        this->_20 = m._20;
        this->_21 = m._21;
        this->_22 = m._22;
        return *this;
    }

    /**
     * @brief Seta a matriz a partir de 9 constantes
     */
    Matrix3<T>& setValue(
                         T _00, T _01, T _02,
                         T _10, T _11, T _12,
                         T _20, T _21, T _22
                         ) {
        this->_00 = _00;
        this->_01 = _01;
        this->_02 = _02;
        this->_10 = _10;
        this->_11 = _11;
        this->_12 = _12;
        this->_20 = _20;
        this->_21 = _21;
        this->_22 = _22;
        return *this;
    }

    /**
     * @brief Seta o valor por cópia de tipo diferente
     *
     * @param m
     */
    template <typename T2>
    Matrix3<T>& setValue(const Matrix3<T2> &m) {
        this->_00 = (T) m._00;
        this->_01 = (T) m._01;
        this->_02 = (T) m._02;
        this->_10 = (T) m._10;
        this->_11 = (T) m._11;
        this->_12 = (T) m._12;
        this->_20 = (T) m._20;
        this->_21 = (T) m._21;
        this->_22 = (T) m._22;
        return *this;
    }

    /**
     * @brief Cria uma matriz identidade 3x3
     */
    void identity() {
        this->_00 = (T) 1;
        this->_01 = (T) 0;
        this->_02 = (T) 0;
        this->_10 = (T) 0;
        this->_11 = (T) 1;
        this->_12 = (T) 0;
        this->_20 = (T) 0;
        this->_21 = (T) 0;
        this->_22 = (T) 1;
    }

    /**
     * @brief Operador de soma de matrizes 2x2
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> operator +(const Matrix3<T> &m) const {
        Matrix3<T> mr;
        mr._00 = this->_00 + m._00;
        mr._01 = this->_01 + m._01;
        mr._02 = this->_02 + m._02;
        mr._10 = this->_10 + m._10;
        mr._11 = this->_11 + m._11;
        mr._12 = this->_12 + m._12;
        mr._20 = this->_20 + m._20;
        mr._21 = this->_21 + m._21;
        mr._22 = this->_22 + m._22;
        return mr;
    }

    /**
     * @brief Operador de subtração de matrizes 3x3
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> operator -(const Matrix3<T> &m) const {
        Matrix3<T> mr;
        mr._00 = this->_00 - m._00;
        mr._01 = this->_01 - m._01;
        mr._02 = this->_02 - m._02;
        mr._10 = this->_10 - m._10;
        mr._11 = this->_11 - m._11;
        mr._12 = this->_12 - m._12;
        mr._20 = this->_20 - m._20;
        mr._21 = this->_21 - m._21;
        mr._22 = this->_22 - m._22;
        return mr;
    }

    /**
     * @brief Operador de multiplicação de matrizes 3x3
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> operator *(const Matrix3<T> &m) const {
        Matrix3<T> mr;
        mr._00 = this->_00 * m._00 + this->_01 * m._10 + this->_02 * m._20;
        mr._01 = this->_00 * m._01 + this->_01 * m._11 + this->_02 * m._21;
        mr._02 = this->_00 * m._02 + this->_01 * m._12 + this->_02 * m._22;
        mr._10 = this->_10 * m._00 + this->_11 * m._10 + this->_12 * m._20;
        mr._11 = this->_10 * m._01 + this->_11 * m._11 + this->_12 * m._21;
        mr._12 = this->_10 * m._02 + this->_11 * m._12 + this->_12 * m._22;
        mr._20 = this->_20 * m._00 + this->_21 * m._10 + this->_22 * m._20;
        mr._21 = this->_20 * m._01 + this->_21 * m._11 + this->_22 * m._21;
        mr._22 = this->_20 * m._02 + this->_21 * m._12 + this->_22 * m._22;
        return mr;
    }

    /**
     * @brief Operador de soma de matrizes 3x3
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> & operator +=(const Matrix3<T> &m) {
        *this = *this +m;
        return *this;
    }

    /**
     * @brief Operador de subtração de matrizes 3x3
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> & operator -=(const Matrix3<T> &m) {
        *this = *this -m;
        return *this;
    }

    /**
     * @brief Operador de multiplicação de matrizes 3x3
     *
     * @param m1
     * @param m2
     */
    Matrix3<T> & operator *=(const Matrix3<T> &m) {
        *this = *this * m;
        return *this;
    }

    /**
     * @brief Transpõe a matriz 3x3
     */
    void transpose() {
        Matrix3<T> m(*this);
        this->_01 = m._10;
        this->_02 = m._20;
        this->_10 = m._01;
        this->_12 = m._21;
        this->_20 = m._02;
        this->_21 = m._12;
    }

    /**
     * @brief Transpõe a matriz 3x3
     */
    void transpose(Matrix3<T> &m) {
        /// Transpoẽ os dois elementos que serão modificados
        this->_01 = m._10;
        this->_02 = m._20;
        this->_10 = m._01;
        this->_12 = m._21;
        this->_20 = m._02;
        this->_21 = m._12;
    }

    /**
     * @brief Retorna o determinante da matriz 3x3
     *
     * @return O determinante da matriz
     */
    T determinant() {
        return ((_00 * _11 * _22 + _10 * _21 * _02 + _01 * _12 * _20) - (_02 * _11 * _20 + _12 * _21 * _00 + _22 * _01 * _20));
    }

    /**
     * @brief Retorna o vetor com os dados da matriz 3x3
     *
     * @return Os dados da matriz
     */
    T* getValue() {
        return this->_array;
    }

	/**
	 * @brief Retorna o pointeiro para o array de dados
	 */
	T* getArray() {
		return this->_array;
	}

	const T* getArray() const {
		return this->_array;
	}

    /**
     * @brief Calcula a inversa desta matriz
     *
     * @return true se a matriz tiver inversa e falso caso contrário
     */
    bool inverse() {
        Matrix3<T> m(*this);

        T det = this->determinant();

        if (det <= (T) 0) return false;

        T det_i = ((T) 1) / det;

        this->_00 = (m._22 * m._11 - m._21 * _12) / det_i;
        this->_01 = (m._22 * m._01 - m._21 * _01) / det_i;
        this->_10 = (m._12 * m._01 - m._11 * _01) / det_i;
        this->_11 = (m._22 * m._00 - m._20 * _02) / det_i;
        this->_12 = (m._12 * m._00 - m._10 * _01) / det_i;
        this->_20 = (m._21 * m._10 - m._20 * _11) / det_i;
        this->_21 = (m._21 * m._00 - m._20 * _01) / det_i;
        this->_22 = (m._11 * m._00 - m._10 * _01) / det_i;

        return true;
    }

    /**
     * @brief Calcula a inversa de uma matriz
     *
     * @return true se a matriz tiver inversa e falso caso contra
     */
    bool inverse(const Matrix3<T> &m) {
        this->setValue(m);
        return this->inverse();
    }

    /**
     * @brief Compara duas matrizes para ver se são iguais
     *
     * @param m1 - Matriz
     * @param m2 - Matriz
     */
    friend bool operator ==(const Matrix3<T> &m1, const Matrix3<T> &m2) {
        for (register unsigned int i = 0; i < m1.getSize(); i++)
            if (m1._array[i] != m2._array[i]) return false;

        return true;
    }

    /**
     * @brief Operador para impressão
     */
    friend std::ostream & operator <<(std::ostream &out, const Matrix3<T> &m) {
        out << std::fixed <<
                "| " << m._00 << " " << m._01 << " " << m._02 << " |" << std::endl <<
                "| " << m._10 << " " << m._11 << " " << m._12 << " |" << std::endl <<
                "| " << m._20 << " " << m._21 << " " << m._22 << " |";

        return out;
    }

};

/**
 * @brief Classe template para representação de matrizes 4x4
 */
template<typename T>
class Matrix4 {
    /// Atributos
public:

    union {

        struct {
            T _00, _01, _02, _03;
            T _10, _11, _12, _13;
            T _20, _21, _22, _23;
            T _30, _31, _32, _33;
        };

        T _array[16]; // array access
    };


    /// Métodos
public:

    /**
     * @brief Construtor padrão, constroi uma matriz 4x4 com o valor passado
     *
     * @param Valor a ser setado em todas as posições
     */
    Matrix4(const T t) {
        this->setValue( t );
    }

    /**
     * @brief Construtor padrão, constroi uma matriz identidade
     *
     * @param Valor a ser setado em todas as posições
     */
    Matrix4() {
        this->buildIdentity();
    }

    /**
     * @brief Construtor explicito, constroi uma matriz 3x3 com os valores passados
     *
     * @param __00 - Posição 00
     * @param __01 - Posição 01
     * @param __11 - Posição 11
     * @param __12 - Posição 12
     */
    Matrix4(
            const T __00, const T __01, const T __02, const T __03,
            const T __10, const T __11, const T __12, const T __13,
            const T __20, const T __21, const T __22, const T __23,
            const T __30, const T __31, const T __32, const T __33
            ) : _00(__00), _01(__01), _02(__02), _03(__03),
    _10(__10), _11(__11), _12(__12), _13(__13),
    _20(__20), _21(__21), _22(__22), _23(__23),
    _30(__30), _31(__31), _32(__32), _33(__33) {
    }

    /**
     * @brief Construtor por cópia de vetor, constroi uma matriz 3x3 com o vetor passado
     *
     * @param m - Matriz a ser copiada
     */
    Matrix4(const T *m) {
        this->setValue(m);
    }

    /**
     * @brief Construtor por cópia de matriz. Constrói a partir de uma matriz 2x2
     *
     * @param m - Matriz a ser copiada
     */
    Matrix4(const Matrix2<T> &m) {
        this->setValue(
                       m._00, m._01, (T) 0, (T) 0,
                       m._10, m._11, (T) 0, (T) 0,
                       (T) 0, (T) 0, (T) 0, (T) 0,
                       (T) 0, (T) 0, (T) 0, (T) 0
                       );
    }

    /**
     * @brief Construtor por cópia de matriz.
     *
     * @param m - Matriz a ser copiada
     */
    Matrix4(const Matrix3<T> &m) {
        this->setValue(
                       m._00, m._01, m._02, (T) 0,
                       m._10, m._11, m._12, (T) 0,
                       m._20, m._21, m._22, (T) 0,
                       (T) 0, (T) 0, (T) 0, (T) 0
                       );
    }

    /**
     * @brief Construtor por cópia de matriz. Constrói a partir de uma matriz 4x4
     *
     * @param m - Matriz a ser copiada
     */
    Matrix4(const Matrix4<T> &m) {
        this->setValue(
                       m._00, m._01, m._02, m._03,
                       m._10, m._11, m._12, m._13,
                       m._20, m._21, m._22, m._23,
                       m._30, m._31, m._32, m._33
                       );
    }



    /**
     * @brief Retorna o número de linhas da matriz
     *
     * @return Número de linhas da matriz
     */
    int getRowCount() {
        return 4;
    }

    /**
     * @brief Retorna o número de colunas da matriz
     *
     * @return Número de colunas da matriz
     */
    int getCowCount() {
        return 4;
    }

    /**
     * @brief Retorna o ponteiro para o array de valores
     */
    T* getArray() {
    	return this->_array;
    }

	const T* getArray() const {
		return this->_array;
	}

    /**
     * @brief Retorna o número de elementos da matriz
     *
     * @return O número de elementos da matriz
     */
    inline int getSize() const {
        return 16;
    }

    /**
     * @brief Acessa um elemento da matriz
     *
     * @param i - Acesso a linha
     * @param j - Acesso a coluna
     */
    T getElement(int i, int j) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getCowCount());
        return this->_array[this->getCowCount() * j + i];
    }

    /**
     * @brief Seta um elemento da matriz 3x3
     *
     * @param i - Linha
     * @param j - Coluna
     * @param e - Elemento a ser setado
     */
    void setElement(int i, int j, T e) {
        assert(i >= 0 && i < this->getRowCount() && j >= 0 && j < this->getCowCount());
        this->_array[this->getCowCount() * j + i] = e;
    }

    /**
     * @brief Seta o valor da matriz a partir de um único escalar
     *
     * @param t - escalar
     */
    Matrix4<T>& setValue( T t ) {
    	this->_00 = (T) t;
    	this->_01 = (T) t;
    	this->_02 = (T) t;
    	this->_03 = (T) t;
    	this->_10 = (T) t;
    	this->_11 = (T) t;
    	this->_12 = (T) t;
    	this->_13 = (T) t;
    	this->_20 = (T) t;
    	this->_21 = (T) t;
    	this->_22 = (T) t;
    	this->_23 = (T) t;
    	this->_30 = (T) t;
    	this->_31 = (T) t;
    	this->_32 = (T) t;
    	this->_33 = (T) t;
    	return *this;
    }

    /**
     * @brief Seta o vetor com os dados da matriz 4x4
     *
     * @return Os dados da matriz
     */
    Matrix4<T>& setValue(const T *array) {
        for ( int i = 0; i < this->getSize(); i++) this->_array[i] = array[i];
        return *this;
    }

    /**
     * @brief Seta a matriz explicitamente
     */
    Matrix4<T>& setValue(
                         const T _00, const T _01, const T _02, const T _03,
                         const T _10, const T _11, const T _12, const T _13,
                         const T _20, const T _21, const T _22, const T _23,
                         const T _30, const T _31, const T _32, const T _33
                         ) {
        this->_00 = _00;
        this->_01 = _01;
        this->_02 = _02;
        this->_03 = _03;
        this->_10 = _10;
        this->_11 = _11;
        this->_12 = _12;
        this->_13 = _13;
        this->_20 = _20;
        this->_21 = _21;
        this->_22 = _22;
        this->_23 = _23;
        this->_30 = _30;
        this->_31 = _31;
        this->_32 = _32;
        this->_33 = _33;
        return *this;
    }

    /**
     * @brief Seta a matriz por cópia
     *
     * @param m
     */
    Matrix4<T>& setValue(const Matrix4<T> &m) {
        this->_00 = m._00;
        this->_01 = m._01;
        this->_02 = m._02;
        this->_03 = m._03;

        this->_10 = m._10;
        this->_11 = m._11;
        this->_12 = m._12;
        this->_13 = m._13;

        this->_20 = m._20;
        this->_21 = m._21;
        this->_22 = m._22;
        this->_23 = m._23;

        this->_30 = m._30;
        this->_31 = m._31;
        this->_32 = m._32;
        this->_33 = m._33;

        return *this;
    }

    /**
     * @brief Seta a matriz por cópia de tipo diferente
     *
     * @param m
     */
    template <typename T2>
    Matrix4<T>& setValue(const Matrix4<T2> &m) {
        this->_00 = (T) m._00;
        this->_01 = (T) m._01;
        this->_02 = (T) m._02;
        this->_03 = (T) m._03;

        this->_10 = (T) m._10;
        this->_11 = (T) m._11;
        this->_12 = (T) m._12;
        this->_13 = (T) m._13;

        this->_20 = (T) m._20;
        this->_21 = (T) m._21;
        this->_22 = (T) m._22;
        this->_23 = (T) m._23;

        this->_30 = (T) m._30;
        this->_31 = (T) m._31;
        this->_32 = (T) m._32;
        this->_33 = (T) m._33;
        return *this;
    }

    /**
     * @brief Cria uma matriz identidade 4x4
     */
    void buildIdentity() {
        this->_00 = (T) 1;
        this->_01 = (T) 0;
        this->_02 = (T) 0;
        this->_03 = (T) 0;

        this->_10 = (T) 0;
        this->_11 = (T) 1;
        this->_12 = (T) 0;
        this->_13 = (T) 0;

        this->_20 = (T) 0;
        this->_21 = (T) 0;
        this->_22 = (T) 1;
        this->_23 = (T) 0;

        this->_30 = (T) 0;
        this->_31 = (T) 0;
        this->_32 = (T) 0;
        this->_33 = (T) 1;
    }

    /**
     * @brief Constrói uma matriz de rotação em torno do eixo-x
     *
     * @param angle -Ângulo de rotação em graus
     */
    static Matrix4<T> buildRotationX( T angle ) {
    	angle = deg2rad( angle );
    	Matrix4<T> rotation;
    	rotation.buildIdentity();
    	rotation._11 = cos( angle );
    	rotation._12 = -sin( angle );
    	rotation._21 = sin( angle );
    	rotation._22 = cos( angle );
    	return rotation;
    }

    /**
     * @brief Constrói uma matriz de rotação em torno do eixo-y
     *
     * @param angle - Ângulo de rotação em graus
     */
    static Matrix4<T> buildRotationY( T angle ) {
    	angle = deg2rad( angle );
    	Matrix4<T> rotation;
    	rotation.buildIdentity();
    	rotation._00 = cos( angle );
    	rotation._02 = sin( angle );
    	rotation._20 = -sin( angle );
    	rotation._22 = cos( angle );
    	return rotation;
    }

    /**
     * @brief Constrói uma matriz de rotação em torno do eixo-z
     *
     * @param angle - Ângulo de rotação em graus
     */
    static Matrix4<T> buildRotationZ( T angle ) {
    	angle = deg2rad( angle );
    	Matrix4<T> rotation;
    	rotation.buildIdentity();
    	rotation._00 = cos( angle );
    	rotation._01 = -sin( angle );
    	rotation._20 = sin( angle );
    	rotation._21 = cos( angle );
    	return rotation;
    }

    /**
     * @brief Constrói uma matriz de rotação em torno de um eixo arbitrário
     *
     * @param axis - Eixo em torno do qual a rotação será feita
     * @param angle - Ângulo de rotação em graus
     */
    static Matrix4<T> buildRotation( const Vec3<T>& axisIn, T angle ) {
    	const Vec3<T> axis = normalize<T>( axisIn );
    	angle = deg2rad( angle );
    	const T c = (T) 1 - cos( angle );

    	Matrix4<T> rotation;

    	rotation._00 = axis.x * axis.x * c + cos( angle );
    	rotation._01 = axis.x * axis.y * c - axis.z * sin( angle );
    	rotation._02 = axis.x * axis.z * c + axis.y * sin( angle );
    	rotation._03 = (T) 0;

    	rotation._10 = axis.y * axis.x * c * axis.z * sin( angle );
    	rotation._11 = axis.y * axis.y * c + cos( angle );
    	rotation._12 = axis.y * axis.z * c - axis.x * sin( angle );
    	rotation._13 = (T) 0;

    	rotation._20 = axis.x * axis.z * c - axis.y * sin( angle );
    	rotation._21 = axis.y * axis.z * c + axis.x * sin( angle );
    	rotation._22 = axis.z * axis.z * c + cos( angle );
    	rotation._23 = (T) 0;

    	rotation._30 = (T) 0;
    	rotation._31 = (T) 0;
    	rotation._32 = (T) 0;
    	rotation._33 = (T) 1;

    	return rotation;
    }

    /**
     * @brief Constrói uma matriz de translação
     *
     * @param x - translação em x
     * @param y - translação em y
     * @param z - translação em z
     */
    static Matrix4<T> buildTranslation( T x, T y, T z ) {
    	Matrix4<T> translation;
    	translation.buildIdentity();
    	translation._03 = x;
    	translation._13 = y;
    	translation._23 = z;
    	return translation;
    }

    /**
     * @brief Constrói uma matriz de escalamento
     *
     * @param x - escalamento na direção do eixo-x
     * @param y - escalamento na direção do eixo-y
     * @param z - escalamento na direção do eixo-z
     */
    static Matrix4<T> buildScale( T x, T y, T z ) {
    	Matrix4<T> scale( (T) 0 );
    	scale._00 = x;
    	scale._11 = y;
    	scale._22 = z;
    	scale._33 = (T) 1;
    	return scale;
    }


    /**
     * @brief Constrói uma matriz de escalamento
     *
     * @param factor - Fator de escalamento a ser aplicado
     */
    static Matrix4<T> buildScale( T factor ) {
    	return buildScale( factor, factor, factor );
    }

    /**
     * @brief Operador de soma de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> operator +(const Matrix4<T>& m) const {
        Matrix4<T> mr;
        mr._00 = this->_00 + m._00;
        mr._01 = this->_01 + m._01;
        mr._02 = this->_02 + m._02;
        mr._03 = this->_03 + m._03;
        mr._10 = this->_10 + m._10;
        mr._11 = this->_11 + m._11;
        mr._12 = this->_12 + m._12;
        mr._13 = this->_13 + m._13;
        mr._20 = this->_20 + m._20;
        mr._21 = this->_21 + m._21;
        mr._22 = this->_22 + m._22;
        mr._23 = this->_23 + m._23;
        mr._30 = this->_30 + m._30;
        mr._31 = this->_31 + m._31;
        mr._32 = this->_32 + m._32;
        mr._33 = this->_33 + m._33;
        return mr;
    }

    /**
     * @brief Operador de subtração de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> operator -(const Matrix4<T>& m) const {
        Matrix4<T> mr;
        mr._00 = this->_00 - m._00;
        mr._01 = this->_01 - m._01;
        mr._02 = this->_02 - m._02;
        mr._03 = this->_03 - m._03;
        mr._10 = this->_10 - m._10;
        mr._11 = this->_11 - m._11;
        mr._12 = this->_12 - m._12;
        mr._13 = this->_13 - m._13;
        mr._20 = this->_20 - m._20;
        mr._21 = this->_21 - m._21;
        mr._22 = this->_22 - m._22;
        mr._23 = this->_23 - m._23;
        mr._30 = this->_30 - m._30;
        mr._31 = this->_31 - m._31;
        mr._32 = this->_32 - m._32;
        mr._33 = this->_33 - m._33;
        return mr;
    }

    /**
     * @brief Operador de multiplicação de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> operator *(const Matrix4<T> &m) const {
        Matrix4<T> mr;
        mr._00 = this->_00 * m._00 + this->_01 * m._10 + this->_02 * m._20 + this->_03 * m._30;
        mr._01 = this->_00 * m._01 + this->_01 * m._11 + this->_02 * m._21 + this->_03 * m._31;
        mr._02 = this->_00 * m._02 + this->_01 * m._12 + this->_02 * m._22 + this->_03 * m._32;
        mr._03 = this->_00 * m._03 + this->_01 * m._13 + this->_02 * m._23 + this->_03 * m._33;

        mr._10 = this->_10 * m._00 + this->_11 * m._10 + this->_12 * m._20 + this->_13 * m._30;
        mr._11 = this->_10 * m._01 + this->_11 * m._11 + this->_12 * m._21 + this->_13 * m._31;
        mr._12 = this->_10 * m._02 + this->_11 * m._12 + this->_12 * m._22 + this->_13 * m._32;
        mr._13 = this->_10 * m._03 + this->_11 * m._13 + this->_12 * m._23 + this->_13 * m._33;

        mr._20 = this->_20 * m._00 + this->_21 * m._10 + this->_22 * m._20 + this->_23 * m._30;
        mr._21 = this->_20 * m._01 + this->_21 * m._11 + this->_22 * m._21 + this->_23 * m._31;
        mr._22 = this->_20 * m._02 + this->_21 * m._12 + this->_22 * m._22 + this->_23 * m._32;
        mr._23 = this->_20 * m._03 + this->_21 * m._13 + this->_22 * m._23 + this->_23 * m._33;

        mr._30 = this->_30 * m._00 + this->_31 * m._10 + this->_32 * m._20 + this->_33 * m._30;
        mr._31 = this->_30 * m._01 + this->_31 * m._11 + this->_32 * m._21 + this->_33 * m._31;
        mr._32 = this->_30 * m._02 + this->_31 * m._12 + this->_32 * m._22 + this->_33 * m._32;
        mr._33 = this->_30 * m._03 + this->_31 * m._13 + this->_32 * m._23 + this->_33 * m._33;
        return mr;
    }

    /**
     * @brief Operador de soma de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> & operator +=(const Matrix4<T> &m) {
        *this = *this +m;
        return *this;
    }

    /**
     * @brief Operador de subtração de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> & operator -=(const Matrix4<T> &m) {
        *this = *this -m;
        return *this;
    }

    /**
     * @brief Operador de multiplicação de matrizes 4x4
     *
     * @param m1
     * @param m2
     */
    Matrix4<T> & operator *=(const Matrix4<T> &m) {
        *this = *this * m;
        return *this;
    }

    /**
     * @brief Transpõe a matriz 4x4
     */
    void transpose() {
        Matrix4<T> m(*this);
        this->_01 = m._10;
        this->_02 = m._20;
        this->_03 = m._30;
        this->_10 = m._01;
        this->_12 = m._21;
        this->_13 = m._31;
        this->_20 = m._02;
        this->_21 = m._12;
        this->_23 = m._32;
        this->_30 = m._03;
        this->_31 = m._13;
        this->_32 = m._23;
    }

    /**
     * @brief Transpõe a matriz 4x4
     */
    void transpose(Matrix4<T> &m) {
        this->setValue(m);
        this->transpose();
    }

    /**
     * @brief Retorna o determinante da matriz 4x4
     *
     * @return O determinante da matriz
     */
    T determinant() {
        Matrix3<T> m1(
                      _11, _12, _13,
                      _21, _22, _23,
                      _31, _32, _33
                      );

        Matrix3<T> m2(
                      _01, _02, _03,
                      _21, _22, _23,
                      _31, _32, _33
                      );

        Matrix3<T> m3(
                      _01, _02, _03,
                      _11, _12, _13,
                      _31, _32, _33
                      );

        Matrix3<T> m4(
                      _01, _02, _03,
                      _11, _12, _13,
                      _21, _22, _23
                      );

        T det1 = m1.determinant();
        T det2 = m2.determinant();
        T det3 = m3.determinant();
        T det4 = m4.determinant();

        return _00 * det1 - _10 * det2 + _20 * det3 - _30 * det4;
    }

    /**
     * @brief Retorna o vetor com os dados da matriz 3x3
     *
     * @return Os dados da matriz
     */
    T* getValue() {
        return this->_array;
    }

    /**
     * @brief Calcula a inversa desta matriz
     *
     * @return true se a matriz tiver inversa e falso caso contrário
     */
    bool inverse() {

        T det = this->determinant();

        if (det <= (T) 0) return false;

        /// Calcula o inverso do determinante
        T det_i = ((T) 1) / det;

        /// Monta as matriz de cofatores dos elementos
        Matrix3<T> a00(
                       _11, _12, _13,
                       _21, _22, _23,
                       _31, _32, _33
                       );

        Matrix3<T> a01(
                       _10, _12, _13,
                       _20, _22, _23,
                       _30, _32, _33
                       );

        Matrix3<T> a02(
                       _10, _11, _13,
                       _20, _21, _23,
                       _30, _31, _33
                       );

        Matrix3<T> a03(
                       _10, _11, _12,
                       _20, _21, _22,
                       _30, _31, _32
                       );


        Matrix3<T> a10(
                       _01, _02, _03,
                       _21, _22, _23,
                       _31, _32, _33
                       );

        Matrix3<T> a11(
                       _00, _02, _03,
                       _20, _22, _23,
                       _30, _32, _33
                       );

        Matrix3<T> a12(
                       _00, _01, _03,
                       _20, _21, _23,
                       _30, _31, _33
                       );

        Matrix3<T> a13(
                       _00, _01, _02,
                       _20, _21, _22,
                       _30, _31, _32
                       );

        Matrix3<T> a20(
                       _01, _02, _03,
                       _11, _12, _13,
                       _31, _32, _33
                       );

        Matrix3<T> a21(
                       _00, _02, _03,
                       _10, _12, _13,
                       _30, _32, _33
                       );

        Matrix3<T> a22(
                       _00, _01, _03,
                       _10, _11, _13,
                       _30, _31, _33
                       );

        Matrix3<T> a23(
                       _00, _01, _02,
                       _10, _11, _12,
                       _30, _31, _32
                       );

        Matrix3<T> a30(
                       _01, _02, _03,
                       _11, _12, _13,
                       _21, _22, _23
                       );

        Matrix3<T> a31(
                       _00, _02, _03,
                       _10, _12, _13,
                       _20, _22, _23
                       );

        Matrix3<T> a32(
                       _00, _01, _03,
                       _10, _11, _13,
                       _20, _21, _23
                       );

        Matrix3<T> a33(
                       _00, _01, _02,
                       _10, _11, _12,
                       _20, _21, _22
                       );

        /// Calcula o determinante das matrizes adjuntas
        T det00 = a00.determinant();
        T det01 = a01.determinant();
        T det02 = a02.determinant();
        T det03 = a03.determinant();

        T det10 = a10.determinant();
        T det11 = a11.determinant();
        T det12 = a12.determinant();
        T det13 = a13.determinant();

        T det20 = a20.determinant();
        T det21 = a21.determinant();
        T det22 = a22.determinant();
        T det23 = a23.determinant();

        T det30 = a30.determinant();
        T det31 = a31.determinant();
        T det32 = a32.determinant();
        T det33 = a33.determinant();

        /// Finalmente calcula o determinante final
        this->_00 = det00 * det_i;
        this->_01 = -det01 * det_i;
        this->_02 = det02 * det_i;
        this->_03 = -det03 * det_i;

        this->_10 = det10 * det_i;
        this->_11 = -det11 * det_i;
        this->_12 = det12 * det_i;
        this->_13 = -det13 * det_i;

        this->_20 = det20 * det_i;
        this->_21 = -det21 * det_i;
        this->_22 = det22 * det_i;
        this->_23 = -det23 * det_i;

        this->_30 = det30 * det_i;
        this->_31 = -det31 * det_i;
        this->_32 = det32 * det_i;
        this->_33 = -det33 * det_i;

        return true;
    }

    /**
     * @brief Calcula a inversa de uma matriz
     *
     * @return true se a matriz tiver inversa e falso caso contra
     */
    bool inverse(const Matrix4<T> &m) {
        this->setValue(m);
        return this->inverse();
    }

    /**
     * @brief Compara duas matrizes para ver se são iguais
     *
     * @param m1 - Matriz
     * @param m2 - Matriz
     */
    friend bool operator ==(const Matrix4<T> &m1, const Matrix4<T> &m2) {
        for (register unsigned int i = 0; i < m1.getSize(); i++)
            if (m1._array[i] != m2._array[i]) return false;

        return true;
    }

    /**
     * @brief Operador para impressão
     */
    friend std::ostream & operator <<(std::ostream &out, const Matrix4<T> &m) {
        out << std::fixed <<
                "| " << m._00 << " " << m._01 << " " << m._02 << " " << m._03 << " |" << std::endl <<
                "| " << m._10 << " " << m._11 << " " << m._12 << " " << m._13 << " |" << std::endl <<
                "| " << m._20 << " " << m._21 << " " << m._22 << " " << m._23 << " |" << std::endl <<
                "| " << m._30 << " " << m._31 << " " << m._32 << " " << m._33 << " |";

        return out;
    }

};

}; // namespace math
}; // namespace mc



#endif	/* _MCMATRIX_H */

