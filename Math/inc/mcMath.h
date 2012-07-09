/*
 * File:   mcMath.h
 * Author: Thales Luis
 *
 * Created on September 30, 2009, 5:33 PM
 */

#ifndef _MC_MATH
#define	_MC_MATH

#include <cmath>

#include "mcVector.h"
#include "mcMatrix.h"
#include "mcQuaternion.h"

namespace mc {
namespace math {

/**
 * Definição de uma constante para represetação de um valor próximo do zero
 */
static const double EPSILON = 0.00001;

/*
 * Defincao do valor PI
 */
static const double PI = 3.141592653589793238;

/**
 * @brief Converte um ângulo de graus para radianos
 *
 * @param angle - Ângulo em graus
 * @return O ângulo em radianos
 */
template<class T> T deg2rad( const T angle );

/**
 * @brief Converte um ângulo de radianos para graus
 *
 * @param angle - Ângulo em radianos
 * @return O ângulo em graus
 */
template<class T> T rad2deg( const T angle );

/**
 * @brief Retorna se um número inteiro é potência de 2
 *
 * @param num - Número que será verificado
 * @return true se o número é potência de 2 e false caso
 */
bool isPower2( int num );

/**
 * Verifica se um número é potência de 2, mas corrige esse número para
 * a potência de 2 mais próxima
 *
 * @param num - Número a ser testado
 * @return O número corrigido
 */
int getNextPower2( int num );

/**
 * Calcula o quadrado de um número
 */
template<class T> T sqr( T value );

/**
 * Alguns apelidos para facilitar escrita de código
 */
typedef Vec2<double> Vec2d;
typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

typedef Vec3<double> Vec3d;
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;

typedef Vec4<double> Vec4d;
typedef Vec4<float> Vec4f;
typedef Vec4<int> Vec4i;

typedef Matrix2<double> Matrix2d;
typedef Matrix2<float> Matrix2f;
typedef Matrix2<int> Matrix2i;

typedef Matrix3<double> Matrix3d;
typedef Matrix3<float> Matrix3f;
typedef Matrix3<int> Matrix3i;

typedef Matrix4<double> Matrix4d;
typedef Matrix4<float> Matrix4f;
typedef Matrix4<int> Matrix4i;

typedef Quaternion<float> Quatf;
typedef Quaternion<double> Quatd;

/**
 * Inclui o arquivo com a implementação das funções matemáticas
 */
#include "../src/mcMath.impl"

}; // namespace math
}; //namespace mc

#endif	/* _MCLEARY_H */

