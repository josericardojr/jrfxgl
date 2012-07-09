/*
 * File:   mcVector.h
 *
 * @author Thales Luis Rodrigues Sabino
 * @date   2009
 */

#ifndef _MCVECTOR_H_
#define _MCVECTOR_H_

#include "../../JRFXGL_API.h"
#include <math.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <iomanip>

namespace mc {
namespace math {

template<class T> class Vec2;
template<class T> class Vec3;
template<class T> class Vec4;

template<class T> class Matrix2;
template<class T> class Matrix3;
template<class T> class Matrix4;

template<typename T> inline typename T::value_type length( const T &v );

/**
 * @brief Classe template para vetores 2D.
 */
template<class T>
class Vec2 {
	/// Atributos
public:

	enum cartesian_axis {
		X_AXIS, Y_AXIS
	};

	typedef T value_type;

	union {

		struct {
			T x;
			T y;
		};

		T _array[2]; // array access
	};

	/// Métodos
public:

	/**
	 * @brief Construtor padrão. Constroi um vetor com o valor t
	 *
	 * @param t - Valor para ser setado em todas as componentes
	 */
	Vec2( const T &t = T() ) {
		this->setValue( t, t );
	}

	/**
	 * @brief Constrói a partir de um array
	 *
	 * @param a - Array para construir o vetor
	 */
	Vec2( const T *a ) {
		this->setValue( a[0], a[1] );
	}

	/**
	 * @brief Constrói a partir de outro tipo
	 *
	 * @param v - Vetor a ser copiado
	 */
	template<class T2>
	Vec2( const Vec2<T2> &v ) {
		this->setValue( v );
	}

	/**
	 * @brief Constrói um vetor explicitamente
	 *
	 * @param x - Compomente X
	 * @param y - Componente Y
	 */
	Vec2( const T x, const T y ) {
		this->setValue( x, y );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	Vec2( const Vec2<T> &v ) {
		this->setValue( v );
	}

	Vec2( const Vec3<T> &v ) {
		this->setValue( v.x, v.y );
	}

	Vec2( const Vec4<T> &v ) {
		this->setValue( v.x, v.y );
	}

	/**
	 * @brief Constrói um vetor que representa um eixo cartesiano
	 *
	 * @param axis - Deve ser um de cartesian_axes
	 */
	Vec2( cartesian_axis axis ) {
		this->setValue( axis );
	}

	/**
	 * @brief Seta os valores do vetor explicitamente
	 *
	 * @param x
	 * @param y
	 */
	Vec2<T>& setValue( const T x, const T y ) {
		this->x = x;
		this->y = y;
		return *this;
	}

	/**
	 * @brief Seta o valor correspondente a um dos eixos cartesianos
	 *
	 * @param axis - Deve ser um valor do tipo cartesian_axes
	 */
	Vec2<T>& setValue( cartesian_axis axis ) {
		switch ( axis ) {

		case X_AXIS:
			this->setValue( 1, 0 );
			break;

		case Y_AXIS:
			this->setValue( 0, 1 );
			break;

		default:
			break;

		}
		return *this;
	}

	/**
	 * @brief Seta o valor do vetor a partir de outro tipo
	 *
	 * @param x - Componente x
	 * @param y - Componente y
	 */
	template<class T2>
	Vec2<T>& setValue( const T2 x, const T2 y ) {
		this->x = (T) x;
		this->y = (T) y;
		return *this;
	}

	/**
	 * @brief Seta o valor do vetor por cópia
	 *
	 * @param v
	 */
	Vec2<T>& setValue( const Vec2<T> &v ) {
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	/**
	 * @brief Seta o valor do vetor por cópia de tipo diferente
	 *
	 * @param v
	 */
	template<class T2>
	Vec2<T>& setValue( const Vec2<T2> &v ) {
		this->x = (T) v.x;
		this->y = (T) v.y;
		return *this;
	}

	/**
	 * @brief Anula o vetor
	 */
	Vec2<T>& zero() {
		this->x = (T) 0;
		this->y = (T) 0;
		return *this;
	}

	/**
	 * @brief Retorna true se o vetor for nulo
	 */
	bool isZero() const {
		return ( this->x == (T) 0 && this->y = (T) 0 );
	}

	/**
	 * Retorna uma referência para o array
	 */
	const float* getArray() const {
		return this->_array;
	}

	/**
	 * @brief Retorna o tamanho desse vetor
	 */
	int size() const {
		return 2;
	}

	/**
	 * @brief Operador [] para acesso ao vetor
	 *
	 * @param i - Índice de acesso
	 */
	T & operator []( int i ) {
		assert(i >= 0 && i < this->size());
		return this->_array[i];
	}

	/**
	 * @brief Operador soma de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec2<T> operator +( const Vec2<T> &v ) const {
		Vec2<T> vr;
		vr->x = this->x + v.x;
		vr->y = this->y + v.y;
		return vr;
	}

	/**
	 * @brief Operador unário de negação
	 */
	Vec2<T> operator -() const {
		Vec2<T> vr;
		vr.x = -this->x;
		vr.y = -this->y;
		return vr;
	}

	/**
	 * @brief Operador subtração de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec2<T> operator -( const Vec2<T> &v ) const {
		Vec2<T> vr;
		vr.x = this->x - v.x;
		vr.y = this->y - v.y;
		return vr;
	}

	/**
	 * @brief Operador multiplicação de componentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec2<T> operator *( const Vec2<T> &v ) const {
		Vec2<T> vr;
		vr->x = this->x * v.x;
		vr->y = this->y * v.y;
		return vr;
	}

	/**
	 * @brief Operador divisão de compomentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec2<T> operator /( const Vec2<T> &v ) const {
		Vec2<T> vr;
		vr->x = this->x / v.x;
		vr->y = this->y / v.y;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	Vec2<T> operator *( const T s ) const {
		Vec2<T> vr;
		vr->x = this->x * s;
		vr->y = this->y * s;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	Vec2<T> operator /( const T s ) const {
		Vec2<T> vr;
		vr->x = this->x / s;
		vr->y = this->y / s;
		return vr;
	}

	/**
	 * @brief Acumulador +=
	 *
	 * @param v
	 */
	Vec2<T> & operator +=( const Vec2<T> &v ) {
		*this = *this + v;
		return *this;
	}

	/**
	 * @brief Acumulador -=
	 *
	 * @param v
	 */
	Vec2<T> & operator -=( const Vec2<T> &v ) {
		*this = *this - v;
		return *this;
	}

	/**
	 * @brief Acumulador *=
	 *
	 * @param v
	 */
	Vec2<T> & operator *=( const Vec2<T> &v ) {
		*this = *this * v;
		return *this;
	}

	/**
	 * @brief Acumulador /=
	 *
	 * @param v
	 */
	Vec2<T> & operator /=( const Vec2<T> &v ) {
		*this = *this / v;
		return *this;
	}

	/**
	 * @brief Operador de atribuição
	 *
	 * @param v
	 */
	Vec2<T> & operator =( const Vec2<T> &v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Operador de atribuição a partir de vetor de outro tipo
	 *
	 * @param v - Vetor a ser copiado
	 */
	template<class T2>
	Vec2<T> & operator =( const Vec2<T2> &v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Operador para multiplicação de uma matriz por um vetor
	 *
	 * @param m - Matriz
	 * @param v - Vetor
	 */
	friend Vec2<T> operator *( const Matrix2<T> m, const Vec2<T> &v ) {
		Vec2<T> vr;
		vr.x = v.x * m._00 + v.y * m._01;
		vr.y = v.x * m._10 + v.y * m._11;
		return vr;
	}

	/**
	 * @brief Comparador de igualdade
	 *
	 * @param v
	 */
	friend bool operator ==( const Vec2<T> &v1, const Vec2<T> &v2 ) {
		return ( v1.x == v2.x && v1.y == v2.y ) ? true : false;
	}

	/**
	 * @brief Compara o módulos de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	friend bool operator<( const Vec2<T> &v1, const Vec2<T> &v2 ) {
		return length( v1 ) < length( v2 );
	}

	/**
	 * @brief Comparador de desigualdade
	 *
	 * @param v
	 */
	friend bool operator !=( const Vec2<T> &v1, const Vec2<T> &v2 ) {
		return ( v1.x != v2.x || v1.y != v2.y ) ? true : false;
	}

	/**
	 * @brief Operador para impressão
	 */
	friend std::ostream & operator <<( std::ostream &out, const Vec2<T> &v ) {
		out << std::fixed << "(" << v.x << ", " << v.y << ")";
		return out;
	}

};

/**
 * @brief Classe template para vetores 3D.
 */
template<class T>
class Vec3 {
	/// Atributos
public:

	enum CartesianAxis {
		X_AXIS, Y_AXIS, Z_AXIS
	};

	typedef T value_type;

	union {

		struct {
			T x;
			T y;
			T z;
		};

		T _array[3];
	};

	/// Métodos
public:

	/**
	 * @brief Construtor padrão. Constroi um vetor com o valor t
	 *
	 * @param t - Valor para ser setado em todas as componentes
	 */
	JRFXGL_API
	Vec3( const T &t = T() ) {
		this->setValue( t, t, t );
	}

	/**
	 * @brief Constrói a partir de um array
	 *
	 * @param a - Array para construir o vetor
	 */
	JRFXGL_API
	Vec3( const T *a ) {
		this->setValue( a[0], a[1], a[2] );
	}

	/**
	 * @brief Constrói um vetor explicitamente
	 *
	 * @param x - Compomente X
	 * @param y - Componente Y
	 */
	JRFXGL_API
	Vec3( const T x, const T y, const T z ) {
		this->setValue( x, y, z );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	JRFXGL_API
	Vec3( Vec2<T> &v ) {
		this->setValue( v.x, v.y, (T) 0 );
	}

	/**
	 * @brief Constrói por cópia a partir de outro tipo
	 *
	 * @param v
	 */
	template<typename T2>
	Vec3( const Vec3<T2> &v ) {
		this->setValue( v );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	JRFXGL_API
	Vec3( const Vec3<T> &v ) {
		this->setValue( v );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	JRFXGL_API
	Vec3( const Vec4<T> &v ) {
		this->setValue( v.x, v.y, v.z );
	}

	/**
	 * @brief Constrói um vetor que representa um eixo cartesiano
	 *
	 * @param axis - Deve ser um de cartesian_axes
	 */
	JRFXGL_API
	Vec3( CartesianAxis axis ) {
		this->setValue( axis );
	}

	/**
	 * @brief Seta os valores do vetor a partir de um único valor
	 *
	 * @param x
	 */
	JRFXGL_API
	Vec3<T>& setValue( const T value ) {
		this->x = (T) value;
		this->y = (T) value;
		this->z = (T) value;
		return *this;
	}

	/**
	 * @brief Seta os valores do vetor explicitamente
	 *
	 * @param x
	 * @param y
	 * @param z
	 */
	JRFXGL_API
	Vec3<T>& setValue( const T x, const T y, const T z ) {
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	/**
	 * @brief Seta os valores do vetor a partir de outro tipo
	 *
	 * @param v
	 */
	template<typename T2>
	Vec3<T>& setValue( const T2 x, const T2 y, const T2 z ) {
		this->x = (T) x;
		this->y = (T) y;
		this->z = (T) z;
		return *this;
	}

	/**
	 * @brief Seta o valor por cópia
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T>& setValue( const Vec3<T> &v ) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}

	/**
	 * @brief Seta o valor do vetor por cópia de tipo diferente
	 *
	 * @param v
	 */
	template<typename T2>
	Vec3<T>& setValue( const Vec3<T2> &v ) {
		this->x = (T) v.x;
		this->y = (T) v.y;
		this->z = (T) v.z;
		return *this;
	}

	/**
	 * Anula o vetor
	 */
	JRFXGL_API
	Vec3<T>& zero() {
		this->x = (T) 0;
		this->y = (T) 0;
		this->z = (T) 0;
		return *this;
	}

	/**
	 * @brief Retorna true se o vetor for nulo
	 */
	JRFXGL_API
	bool isZero() const {
		return ( this->x == (T) 0 && this->y == (T) 0 && this->z == (T) 0 );
	}

	/**
	 * @brief Seta o valor correspondente a um dos eixos cartesianos
	 *
	 * @param axis - Deve ser um valor do tipo cartesian_axes
	 */
	JRFXGL_API
	Vec3<T>& setValue( CartesianAxis axis ) {
		switch ( axis ) {

		case X_AXIS:
			this->setValue( (T) 1, (T) 0, (T) 0 );
			break;

		case Y_AXIS:
			this->setValue( (T) 0, (T) 1, (T) 0 );
			break;

		case Z_AXIS:
			this->setValue( (T) 0, (T) 0, (T) 1 );

		default:
			break;

		}

		return *this;
	}

	/**
	 * Retorna uma referência para o array
	 */
	JRFXGL_API
	const float* getArray() const {
		return this->_array;
	}

	/**
	 * @brief Retorna o tamanho desse vetor
	 */
	JRFXGL_API
	inline int size() const {
		return 3;
	}

	/**
	 * @brief Retorna o maior valor contido do vetor
	 */
	inline T max() const {
		return std::max( x, std::max(y,z) );
	}


	/**
	 * @brief Operador [] para acesso ao vetor
	 *
	 * @param i - Índice de acesso
	 */
	JRFXGL_API
	T & operator []( int i ) {
		//assert(i >= 0 && i < this->size());
		return _array[i];
	}

	/**
	 * @brief Operador soma de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	Vec3<T> operator +( const Vec3<T> &v ) const {
		Vec3<T> vr;
		vr.x = this->x + v.x;
		vr.y = this->y + v.y;
		vr.z = this->z + v.z;
		return vr;
	}

	/**
	 * @brief Operador unário de negação
	 */
	JRFXGL_API
	Vec3<T> operator -() const {
		Vec3<T> vr;
		vr.x = -this->x;
		vr.y = -this->y;
		vr.z = -this->z;
		return vr;
	}

	/**
	 * @brief Operador subtração de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	Vec3<T> operator -( const Vec3<T> &v ) const {
		Vec3<T> vr;
		vr.x = this->x - v.x;
		vr.y = this->y - v.y;
		vr.z = this->z - v.z;
		return vr;
	}

	/**
	 * @brief Operador multiplicação das componentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	friend Vec3<T> operator *( const Vec3<T> &v1, const Vec3<T>& v2 ) {
		Vec3<T> vr;
		vr.x = v1.x * v2.x;
		vr.y = v1.y * v2.y;
		vr.z = v1.z * v2.z;
		return vr;
	}

	/**
	 * @brief Operador divisão de compomentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	Vec3<T> operator /( const Vec3<T> &v ) const {
		Vec3<T> vr;
		vr.x = this->x / v.x;
		vr.y = this->y / v.y;
		vr.z = this->z / v.z;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	JRFXGL_API
	friend Vec3<T> operator *( const Vec3<T>& v, const T s ) {
		Vec3<T> vr;
		vr.x = v.x * s;
		vr.y = v.y * s;
		vr.z = v.z * s;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	JRFXGL_API
	friend Vec3<T> operator *( const T s, const Vec3<T>& v ) {
		Vec3<T> vr;
		vr.x = v.x * s;
		vr.y = v.y * s;
		vr.z = v.z * s;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	JRFXGL_API
	Vec3<T> operator /( const T s ) const {
		Vec3<T> vr;
		vr.x = this->x / s;
		vr.y = this->y / s;
		vr.z = this->z / s;
		return vr;
	}

	/**
	 * @brief Acumulador +=
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T> & operator +=( const Vec3<T> &v ) {
		*this = *this + v;
		return *this;
	}

	/**
	 * @brief Acumulador -=
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T> & operator -=( const Vec3<T> &v ) {
		*this = *this - v;
		return *this;
	}

	/**
	 * @brief Acumulador *=
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T> operator *=( const Vec3<T> &v ) {
		*this = *this * v;
		return *this;
	}

	/**
	 * @brief Acumulador /=
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T> & operator /=( const Vec3<T> &v ) {
		*this = *this / v;
		return *this;
	}

	/**
	 * @brief Cross-product
	 *
	 * Computa o cross-product entre dois vetores e armazena neste
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	friend Vec3<T> cross( const Vec3<T> &v1, const Vec3<T> &v2 ) {
		Vec3<T> c;
		c.x = v1.y * v2.z - v1.z * v2.y;
		c.y = v1.z * v2.x - v1.x * v2.z;
		c.z = v1.x * v2.y - v1.y * v2.x;

		return c;
	}

	/**
	 * @brief Operador de atribuição
	 *
	 * @param v
	 */
	JRFXGL_API
	Vec3<T> & operator =( const Vec3<T>& v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Operador de atribuição a patir de outro tipo
	 *
	 * @param v
	 */
	template<class T2>
	Vec3<T> & operator =( const Vec3<T2> &v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Operador para aplicar uma matriz 3x3 neste vetor
	 *
	 * @param v
	 */
	friend Vec3<T> operator *( const Matrix3<T> &m, const Vec3<T> &v ) {
		Vec3<T> vr;
		vr.x = v.x * m._00 + v.y * m._01 + v.z * m._02;
		vr.y = v.x * m._10 + v.y * m._11 + v.z * m._12;
		vr.z = v.x * m._20 + v.y * m._21 + v.z * m._22;
		return vr;
	}

	/**
	 * @brief Comparador de igualdade
	 *
	 * @param v
	 */
	JRFXGL_API
	friend bool operator ==( const Vec3<T> &v1, const Vec3<T> &v2 ) {
		return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
	}

	/**
	 * @brief Compara o módulo de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	JRFXGL_API
	friend bool operator<( const Vec3<T> &v1, const Vec3<T> &v2 ) {
		return length( v1 ) < length( v2 );
	}

	/**
	 * @brief Comparador de desigualdade
	 *
	 * @param v
	 */
	JRFXGL_API
	friend bool operator !=( const Vec3<T> &v1, const Vec3<T> &v2 ) {
		return ( v1.x != v2.x || v1.y != v2.y || v1.z != v2.z );
	}

	/**
	 * @brief Operador para impressão
	 */
	friend std::ostream & operator <<( std::ostream &out, const Vec3<T> &v ) {
		out << std::fixed << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return out;
	}

};

/**
 * @brief Classe template para vetores 4D.
 */
template<class T>
class Vec4 {
	/// Atributos
public:

	enum cartesian_axis {
		X_AXIS, Y_AXIS, Z_AXIS, W_AXIS
	};

	typedef T type_value;

	union {

		struct {
			T x;
			T y;
			T z;
			T w;
		};

		T _array[4];
	};

	/// Métodos
public:

	/**
	 * @brief Construtor padrão. Constroi um vetor com o valor t
	 *
	 * @param t - Valor para ser setado em todas as componentes
	 */
	Vec4( const T &t = T() ) {
		this->setValue( t, t, t, t );
	}

	/**
	 * @brief Constrói a partir de um array
	 *
	 * @param a - Array para construir o vetor
	 */
	Vec4( const T *a ) {
		this->setValue( a[0], a[1], a[2], a[3] );
	}

	/**
	 * @brief Constrói um vetor explicitamente
	 *
	 * @param x - Compomente X
	 * @param y - Componente Y
	 */
	Vec4( const T x, const T y, const T z, const T w ) {
		this->setValue( x, y, z, w );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	Vec4( const Vec2<T> &v ) {
		this->setValue( v.x, v.y, (T) 0, (T) 0 );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	Vec4( const Vec3<T> &v ) {
		this->setValue( v.x, v.y, v.z, (T) 0 );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	Vec4( const Vec3<T> &v, T w ) {
		this->setValue( v.x, v.y, v.z, w );
	}

	/**
	 * @brief Constrói por cópia
	 *
	 * @param v - Vetor a ser copiado
	 */
	Vec4( const Vec4<T> &v ) {
		this->setValue( v );
	}

	/**
	 * @breif Constrói por cópia a partir de outro tipo
	 *
	 * @param v
	 */
	template<typename T2>
	Vec4( const Vec4<T2> &v ) {
		this->setValue( v );
	}

	/**
	 * @brief Seta os valores do vetor explicitamente
	 *
	 * @param x
	 * @param y
	 * @param z
	 */
	Vec4<T>& setValue( const T x, const T y, const T z, const T w ) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	/**
	 * @brief Seta os valores a patir de outro tipo
	 *
	 * @param x
	 * @param y
	 * @param z
	 */
	template<typename T2>
	Vec4<T>& setValue( const T2 x, const T2 y, const T2 z, const T2 w ) {
		this->x = (T) x;
		this->y = (T) y;
		this->z = (T) z;
		this->w = (T) w;
		return *this;
	}

	/**
	 * @brief Seta os valores por cópia
	 *
	 * @param v
	 */
	Vec4<T>& setValue( const Vec4<T> &v ) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
		return *this;
	}

	/**
	 * @brief Seta os valores por cópia de tipo de diferente
	 *
	 * @param v
	 */
	template<typename T2>
	Vec4<T>& setValue( const Vec4<T2> &v ) {
		this->x = (T) v.x;
		this->y = (T) v.y;
		this->z = (T) v.z;
		this->w = (T) v.w;

		return *this;
	}

	/**
	 * @brief Seta o valor correspondente a um dos eixos cartesianos
	 *
	 * @param axis - Deve ser um valor do tipo cartesian_axes
	 */
	Vec4<T>& setValue( cartesian_axis axis ) {
		switch ( axis ) {

		case X_AXIS:
			this->setValue( (T) 1, (T) 0, (T) 0, (T) 0 );
			break;

		case Y_AXIS:
			this->setValue( (T) 0, (T) 1, (T) 0, (T) 0 );
			break;

		case Z_AXIS:
			this->setValue( (T) 0, (T) 0, (T) 1, (T) 0 );
			break;

		case W_AXIS:
			this->setValue( (T) 0, (T) 0, (T) 0, (T) 1 );
			break;

		default:
			break;

		}

		return *this;
	}

	/**
	 * Anula o vetor
	 */
	Vec4<T>& zero() {
		this->x = (T) 0;
		this->y = (T) 0;
		this->z = (T) 0;
		this->w = (T) 0;
		return *this;
	}

	/**
	 * @brief Retorna true se o vetor for nulo
	 */
	bool isZero() const {
		return ( this->x == (T) 0 && this->y == (T) 0 && this->z == (T) 0 && this->w == (T) 0 );
	}

	/**
	 * Retorna uma referência para o array
	 */
	const float* getArray() const {
		return this->_array;
	}

	/**
	 * @brief Retorna o tamanho desse vetor
	 */
	inline int size() const {
		return 4;
	}

	/**
	 * @brief Operador [] para acesso ao vetor
	 *
	 * @param i - Índice de acesso
	 */
	T & operator []( int i ) {
		assert(i >= 0 && i < this->size());
		return _array[i];
	}

	/**
	 * @brief Operador soma de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec4<T> operator +( const Vec4<T> &v ) const {
		Vec4<T> vr;
		vr->x = this->x + v.x;
		vr->y = this->y + v.y;
		vr->z = this->z + v.z;
		vr->w = this->w + v.w;
		return vr;
	}

	/**
	 * @brief Operador unário de negação
	 */
	Vec4<T> operator -() const {
		Vec4<T> vr;
		vr.x = -this->x;
		vr.y = -this->y;
		vr.z = -this->z;
		vr.w = -this->w;
		return vr;
	}

	/**
	 * @brief Operador subtração de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec4<T> operator -( const Vec4<T> &v ) const {
		Vec4<T> vr;
		vr.x = this->x - vr.x;
		vr.y = this->y - vr.y;
		vr.z = this->z - vr.z;
		vr.w = this->w - vr.w;
		return vr;
	}

	/**
	 * @brief Operador multiplicação das componentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec4<T> & operator *( const Vec4<T> &v ) const {
		Vec4<T> vr;
		vr.x = this->x * v.x;
		vr.y = this->y * v.y;
		vr.z = this->z * v.z;
		vr.w = this->w * v.w;
		return vr;
	}

	/**
	 * @brief Operador divisão de compomentes de dois vetores
	 *
	 * @param v1
	 * @param v2
	 */
	Vec4<T> & operator /( const Vec4<T> &v ) const {
		Vec4<T> vr;
		vr.x = this->x / v.x;
		vr.y = this->y / v.y;
		vr.z = this->z / v.z;
		vr.w = this->w / v.w;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	Vec4<T> operator *( const T s ) const {
		Vec4<T> vr;
		vr.x = this->x * s;
		vr.y = this->y * s;
		vr.z = this->z * s;
		vr.w = this->w * s;
		return vr;
	}

	/**
	 * @brief Operador de escalamento
	 *
	 * @param v - Vetor a ser escalado
	 * @param s - Fator de escala
	 */
	Vec4<T> operator /( const T s ) const {
		Vec4<T> vr;
		vr->x = this->x / s;
		vr->y = this->y / s;
		vr->z = this->z / s;
		vr->w = this->w / s;
		return *vr;
	}

	/**
	 * @brief Acumulador +=
	 *
	 * @param v
	 */
	Vec4<T> & operator +=( const Vec4<T> &v ) {
		*this = *this + v;
		return *this;
	}

	/**
	 * @brief Acumulador -=
	 *
	 * @param v
	 */
	Vec4<T> & operator -=( const Vec4<T> &v ) {
		*this = *this - v;
		return *this;
	}

	/**
	 * @brief Acumulador *=
	 *
	 * @param v
	 */
	Vec4<T> & operator *=( const Vec4<T> &v ) {
		*this = *this * v;
		return *this;
	}

	/**
	 * @brief Acumulador /=
	 *
	 * @param v
	 */
	Vec4<T> & operator /=( const Vec4<T> &v ) {
		*this = *this / v;
		return *this;
	}

	/**
	 * @brief Operador de atribuição
	 *
	 * @param v
	 */
	Vec4<T> & operator =( const Vec4<T> &v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Operador de atribuição a partir de outro tipo
	 *
	 * @param v
	 */
	template<class T2>
	Vec4<T> & operator =( const Vec4<T2> &v ) {
		return this->setValue( v );
	}

	/**
	 * @brief Comparador de igualdade
	 *
	 * @param v
	 */
	friend bool operator ==( const Vec4<T> &v1, const Vec4<T> &v2 ) {
		return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w );
	}

	/**
	 * @brief Comparador de desigualdade
	 *
	 * @param v
	 */
	friend bool operator !=( const Vec4<T> &v1, const Vec4<T> &v2 ) {
		return ( v1.x != v2.x || v1.y != v2.y || v1.z != v2.z || v1.w != v2.w );
	}

	/**
	 * @brief Compara dois vetores pelo módulo
	 *
	 * @param v1
	 * @parma v2
	 */
	friend bool operator<( const Vec4<T> &v1, const Vec4<T> &v2 ) {
		return ( length( v1 ) < length( v2 ) );
	}


	/**
	 * @brief Operador para aplicar uma matriz em um vetor
	 *
	 * @param v - Vetor
	 * @param m - Matriz
	 */
	friend Vec4<T> operator *( const Matrix4<T> &m, const Vec4<T> &v ) {
		Vec4<T> vr;
		vr.x = v.x * m._00 + v.y * m._01 + v.z * m._02 + v.w * m._03;
		vr.y = v.x * m._10 + v.y * m._11 + v.z * m._12 + v.w * m._13;
		vr.z = v.x * m._20 + v.y * m._21 + v.z * m._22 + v.w * m._23;
		vr.w = v.x * m._30 + v.y * m._31 + v.z * m._32 + v.w * m._33;
		return vr;
	}

	/**
	 * @brief Operador para impressão
	 */
	friend std::ostream & operator <<( std::ostream &out, const Vec4<T> &v ) {
		out << std::fixed << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
		return out;
	}
};

/**
 * @brief Produto escalar entre dois vetores quaisquer
 *
 * @param v1
 * @param v2
 */
template<class T>
JRFXGL_API
inline typename T::value_type dot( const T &v1, const T &v2 ) {
	typename T::value_type r = 0;
	for ( int i = 0; i < v1.size(); i++ )
		r += v1._array[i] * v2._array[i];
	return r;
}

/**
 * @brief Calcula o comprimento de um vetor
 *
 * @param v
 */
template<class T>
JRFXGL_API
inline typename T::value_type length( const T &v ) {
	typename T::value_type r = 0;
	for ( int i = 0; i < v.size(); i++ )
		r += v._array[i] * v._array[i];
	return typename T::value_type( sqrt( r ) );
}

/**
 * @brief Normaliza um vetor
 *
 * @param v
 */
template<class T>
JRFXGL_API_INLINE
T normalize( const T &v ) {
	typename T::value_type sum( 0 );
	T r;

	for ( int i = 0; i < v.size(); i++ )
		sum += v._array[i] * v._array[i];

	sum = typename T::value_type( sqrt( sum ) );

	if ( sum > 0 )
		for ( int i = 0; i < v.size(); i++ )
			r._array[i] = v._array[i] / sum;

	return r;
}

// return the squared norm
template<class T>
JRFXGL_API
inline typename T::value_type squareNorm( const T &v ) {
	typename T::value_type r = 0;
	for ( int i = 0; i < v.size(); i++ )
		r += v._array[i] * v._array[i];
	return r;
}

} // namespace math
} // namespace mc


#endif

