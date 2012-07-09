/* 
 * File:   mcQuaternion.h
 *
 * @author Thales Luis Rodrigues Sabino
 * @date   2009
 */

#ifndef _MCQUATERNION_H
#define	_MCQUATERNION_H

#include <math.h>
#include <assert.h>
#include <iostream>
#include <string>

#include "mcVector.h"
#include "mcMatrix.h"

namespace mc {
namespace math {

/**
 * @brief Classe template para representação de quaternions
 */
template <typename T>
class Quaternion {
public:
	/// Atributos

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
	 * @brief Construtor padrão
	 */
	Quaternion( const T &t = T() ) {
		this->setValue( t, t, t, t );
	}

	/**
	 * @brief Construtor explícito
	 *
	 * @param x
	 * @param y
	 * @param z
	 * @param w
	 */
	Quaternion( const T x, const T y, const T z, const T w ) {
		this->setValue( x, y, z, w );
	}

	/**
	 * @brief Construtor por cópia.
	 *
	 * @param q - Quaternion a ser copiado
	 */
	Quaternion( const Quaternion<T> &q ) {
		this->setValue( q );
	}

	/**
	 * @brief Constrói um quaternion a partir de uma matriz 4x4
	 *
	 * @param m - Matriz
	 */
	Quaternion( Matrix4<T> &m ) {
		this->setValue( m );
	}

	/**
	 * @brief Constrói um quaternion que forma uma rotação em torno de um eixo
	 *
	 * @param axis - vec3 que representa o eixo
	 * @param angle - Ângulo em radianos
	 */
	Quaternion( const Vec3<T> &axis, T angle ) {
		this->setValue( axis, angle );
	}

	/**
	 * @brief Constrói um quaternion que forma uma rotação de um ponto a outro
	 *
	 * @param rotateFrom - Origem da rotação
	 * @param rotateTo   - Destino da rotação
	 */
	Quaternion( const Vec3<T> &rotateFrom, const Vec3<T> &rotateTo ) {
		this->setValue( rotateFrom, rotateTo );
	}

	/**
	 * @brief Constrói um quaternion por cópia de array
	 *
	 * @param a - Array
	 */
	Quaternion( const T *a ) {
		this->setValue( a );
	}

	/**
	 * @brief Constrói um quarternion a partir do ângulos de Euler
	 *
	 * @param picth
	 * @param yaw
	 * @param roll
	 */
	Quaternion( const T picth, const T yaw, const T roll ) {
		this->setValue( picth, yaw, roll );
	}

	/**
	 * @brief Retorna o tamanho do quaternion
	 */
	int getSize() const {
		return 4;
	}

	/**
	 * @brief Retorna a array de dados deste quaternion
	 *
	 * @return A referência para o array de dados
	 */
	const T* getValue() const {
		return &this->_array[0];
	}

	/**
	 * @brief Retorna o array de dados em elementos separados
	 *
	 * @param x
	 * @param y
	 * @param z
	 * @param w
	 */
	Quaternion<T>& getValue( T &x, T &y, T &z, T &w ) {
		x = this->x;
		y = this->y;
		z = this->z;
		w = this->w;
		return *this;
	}

	/**
	 * @brief Seta o valor do quaternion explicitamente
	 *
	 * @param x
	 * @param y
	 * @param z
	 * @param w
	 */
	Quaternion<T>& setValue( const T x, const T y, const T z, const T w ) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	/**
	 * @brief Seta o valor do quaternion por cópia
	 *
	 * @param q - Quaternion a ser copiado
	 */
	Quaternion<T>& setValue( const Quaternion<T> &q ) {
		this->x = q.x;
		this->y = q.y;
		this->z = q.z;
		this->w = q.w;
		return *this;
	}

	/**
	 * @brief Retorna o eixo e o ângulo de rotação deste quaternion
	 *
	 * @param axis  - Eixo de rotação representado por este quaternion
	 * @param angle - Ângulo de rotação em torno do eixo
	 */
	Quaternion<T>& getValue( Vec3<T> &axis, T &angle ) const {
		angle = T( acos( this->w ) * T( 2 ) );

		if ( angle == T( 0.0 ) )
			axis = Vec3<T> ( T( 0 ), T( 0 ), T( 1 ) );
		else {
			axis.x = this->x;
			axis.y = this->y;
			axis.z = this->z;

			normalize<T> ( axis );
		}

		return *this;
	}

	/**
	 * @brief Obtem uma matriz de rotação 4x4 do quaternion
	 *
	 * @param m - Matriz de rotação resultante
	 */
	void getValue( Matrix4<T> &m ) const {
		T norm = x * x + y * y + z * z + w * w;

		T s = ( norm == (T) 0 ) ? (T) 0 : ( T( 2 ) / norm );

		T xs = x * s;
		T ys = y * s;
		T zs = z * s;

		T wx = w * xs;
		T wy = w * ys;
		T wz = w * zs;

		T xx = x * xs;
		T xy = x * ys;
		T xz = x * zs;

		T yy = y * ys;
		T yz = y * zs;
		T zz = z * zs;

		m._00 = T( 1 ) - ( yy + zz );
		m._10 = xy + wz;
		m._20 = xz - wy;

		m._01 = xy - wz;
		m._11 = T( 1 ) - ( xx + zz );
		m._21 = yz + wx;

		m._02 = xz + wy;
		m._12 = yz - wx;
		m._22 = T( 1 ) - ( xx + yy );

		m._03 = T( 0 );
		m._13 = T( 0 );
		m._23 = T( 0 );
		m._30 = T( 0 );
		m._31 = T( 0 );
		m._32 = T( 0 );
		m._33 = T( 1 );
	}

	/**
	 * @brief Seta o valor do quaternion apartir de um array
	 *
	 * @param a - Array
	 */
	Quaternion<T>& setValue( const T * a ) const {
		this->x = a[0];
		this->y = a[1];
		this->z = a[2];
		this->w = a[3];

		return *this;
	}

	/**
	 * @brief Seta o valor do quaternion a partir de uma matriz 4x4
	 *
	 * @param m - Matriz
	 */
	Quaternion<T>& setValue( Matrix4<T> &m ) {
		T tr = m._00 + m._11 + m._22;
		const int nxt[3] = { 1, 2, 0 };

		if ( tr > (T) 0 ) {

			T s = (T) sqrt( tr + m._33 );
			this->w = ( (T) 0.5 ) / s;

			this->x = ( m._12 - m._21 ) * s;
			this->y = ( m._20 - m._02 ) * s;
			this->z = ( m._01 - m._10 ) * s;

		} else {

			int i = 0;

			if ( m._11 > m._00 )
				i = 1;

			if ( m._22 > m.getElement( i, i ) )
				i = 2;

			int j = nxt[i];
			int k = nxt[j];

			T s = (T) sqrt( ( m.getElement( i, j ) - ( m.getElement( j, j ) + m.getElement( k, k ) ) ) + (T) 1 );

			this->_array[i] = s * (T) 0.5;
			s = T( 0.5 / s );

			this->w = ( m.getElement( j, k ) - m.getElement( k, i ) ) * s;
			this->_array[j] = ( m.getElement( i, j ) + m.getElement( j, i ) ) * s;
			this->_array[k] = ( m.getElement( i, k ) + m.getElement( k, i ) ) * s;
		}

		return *this;
	}

	/**
	 * @brief Seta o quaternion para uma rotação em torno de um eixo
	 *
	 * @param axis  - Eixo
	 * @param angle - Ângulo
	 */
	Quaternion<T>& setValue( const Vec3<T> &axis, T angle ) {
		T sqr_norm = squareNorm( axis );

		if ( sqr_norm == (T) 0 ) {

			// Eixo muito pequeno
			this->x = (T) 0;
			this->y = (T) 0;
			this->z = (T) 0;
			this->w = (T) 1;

		} else {
			angle *= (T) 0.5;
			T sin_theta = (T) sin( angle );

			if ( sqr_norm != (T) 1 )
				sin_theta /= (T) sqrt( sqr_norm );

			this->x = sin_theta * axis.x;
			this->y = sin_theta * axis.y;
			this->z = sin_theta * axis.z;
			this->w = (T) cos( angle );
		}

		return *this;
	}

	/**
	 * @brief Seta os valores quaternion que forma uma rotação de um ponto a outro
	 *
	 * @param rotateFrom - Ponto de origem
	 * @param rotateTo   - Ponto de destino
	 */
	Quaternion<T>& setValue( const Vec3<T> &rotateFrom, const Vec3<T> &rotateTo ) {
		Vec3<T> p1;
		Vec3<T> p2;

		p1 = normalize( rotateFrom );
		p2 = normalize( rotateTo );

		T alpha = dot( p1, p2 );

		if ( alpha == (T) 1 ) {
			*this = Quaternion();
			return *this;
		}

		if ( alpha == (T) -1 ) {
			Vec3<T> v;

			if ( p1.x != p1.y || p1.x != p1.z )
				v = Vec3<T> ( p1.y, p1.z, p1.x );
			else
				v = Vec3<T> ( -p1.x, p1.y, p1.z );

			v -= p1 * dot( p1, v );
			v = normalize( v );

			this->setValue( v, (T) M_PI);
			return *this;
		}

		return *this;
	}

	Quaternion<T>& setValue( const Vec3<T> &from_look, const Vec3<T> &from_up, const Vec3<T> &to_look, const Vec3<T> &to_up ) {
		Quaternion<T> r_look = Quaternion( from_look, to_look );

		Vec3<T> rotated_from_up( from_up );
		r_look.applyToVec3( rotated_from_up );

		Quaternion<T> r_twist = Quaternion( rotated_from_up, to_up );

		*this = r_twist;
		*this *= r_look;
		return *this;

	}

	/**
	 * @brief Constrói um quarternion a partir dos ângulos de Euler
	 *
	 * @param picth
	 * @param yaw
	 * @param roll
	 */
	Quaternion<T>& setValue( const T pitch, const T yaw, const T roll ) {
		Quaternion<T> qx( (T) sin( pitch * 0.5 ), (T) 0, (T) 0, (T) cos( pitch * -0.5 ) );
		Quaternion<T> qy( (T) 0, (T) sin( yaw * -0.5 ), (T) 0, (T) cos( yaw * -0.5 ) );
		Quaternion<T> qz( (T) 0, (T) 0, (T) sin( roll * -0.5 ), (T) cos( roll * -0.5 ) );
		qy *= qx;
		return this->setValue( qz * qy );
	}

	/**
	 * @brief Aplica este quaternion a um vetor 3D
	 *
	 * @param v - Vetor
	 */
	Vec3<T>& applyToVec3( const Vec3<T> &v ) {
		Quaternion<T> qi;
		Quaternion<T> kr;

		qi = this->conjugate();

		kr.setValue( v.x, v.y, v.z, (T) 0 );
		kr = ( *this ) * kr;
		kr *= qi;

		Vec3<T> *r = new Vec3<T> ( kr.x, kr.y, kr.z );

		return *r;
	}

	Quaternion<T>& conjugate() {
		Quaternion<T> *q = new Quaternion<T> ();
		q->x = -this->x;
		q->y = -this->y;
		q->z = -this->z;
		q->w = this->w;
		return *q;
	}

	/**
	 * @brief Escala o quaternion por um fator
	 *
	 * @param s - Fator de escalamento
	 */
	void scaleAngle( const T s ) {
		Vec3<T> axis;
		T angle;

		this->getValue( axis, angle );
		angle *= s;
		this->setValue( axis, angle );
	}

	/**
	 * @brief Normaliza o quaternion
	 */
	void normalizeQuaternion() {
		T rnorm = ( (T) 1 ) / (T) sqrt( x * x + y * y + z * z + w * w );

		this->x *= rnorm;
		this->y *= rnorm;
		this->z *= rnorm;
		this->w *= rnorm;
	}

	/**
	 * @brief Normaliza o quaternion
	 *
	 * @param q - Quaternion a ser normalizado
	 */
	void normalizeQuaternion( Quaternion<T> &q ) {
		this->setValue( q );
		this->normalizeQuaternion();
	}

	/**
	 * @brief Produto de Graham
	 *
	 * Multiplica dois quaternions através do produto de Graham
	 */
	Quaternion<T> operator *( const Quaternion<T> &q ) const {
		Quaternion<T> qr;
		qr.x = q.w * x + q.x * w + q.y * z - q.z * y;
		qr.y = q.w * y + q.y * w + q.z * x - q.x * z;
		qr.z = q.w * z + q.z * w + q.x * y - q.y * x;
		qr.w = q.w * w - q.x * x - q.y * y - q.z * z;
		return qr;
	}

	/**
	 * @brief Produto de Graham
	 *
	 * Multiplica dois quaternions através do produto de Graham
	 */
	Quaternion<T> & operator *=( const Quaternion<T> &q ) {
		*this = *this * q;
		return *this;
	}

	/**
	 * @brief Operador de atribuição
	 *
	 * @param q
	 */
	Quaternion<T> & operator =( const Quaternion<T> &q ) {
		this->x = q.x;
		this->y = q.y;
		this->z = q.z;
		this->w = q.w;
		return *this;
	}

	/**
	 * @brief Operador de comparação de igualdade
	 *
	 * @param q1
	 * @param q2
	 */
	friend bool operator ==( const Quaternion<T> &q1, const Quaternion<T> q2 ) {
		for ( int i = 0; i < q1.getSize(); i++ )
			if ( q1._array[i] != q1._array[i] )
				return false;

		return true;
	}

	/**
	 * @brief Operador de comparação de desigualdade
	 *
	 * @param q1
	 * @param q2
	 */
	friend bool operator !=( const Quaternion<T> &q1, const Quaternion<T> q2 ) {
		bool r = true;
		for ( int i = 0; i < q1.getSize(); i++ )
			r &= q1._array[i] == q2._array[i];

		return r;
	}

	/**
	 * @brief Operador para impressão
	 */
	friend std::ostream & operator <<( std::ostream &out, const Quaternion<T> &q ) {
		out << std::fixed << "(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")";
		return out;
	}

}; // class quaternion

}
; // namespace math
}
; // namespace mc


#endif	/* _MCQUATERNION_H */

