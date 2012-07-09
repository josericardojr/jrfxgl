/*
 * File:   mcMathDefinitions.h
 * Author: Thales Luis
 *
 * Created on November 30, 2010, 16:15 PM
 */

#ifndef _MC_MATH_DEFINITIONS_H
#define _MC_MATH_DEFINITIONS_H

namespace mc {
namespace math {

/**
 * Definições das funções matemáticas para inclusão
 */

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

} // namespace math
} // namespace mc

#endif
