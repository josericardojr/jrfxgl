/* 
 * File:   mcONB.h
 * Author: thales
 *
 * Created on May 15, 2010, 4:23 PM
 */

#ifndef _MCONB_H
#define	_MCONB_H

#include "mcMath.h"

#include <iostream>
#include <iomanip>

namespace mc {
namespace math {

/**
 * Classe template para representação de bases ortonormais
 */
class Onb {
public:
    /**
     * Vetores ortonormais que formamß essa base canônica
     */
    Vec3f u;
    Vec3f v;
    Vec3f w;

    /**
     * Epislon especifico da classe ONB
     */
    static const float EPSILON;

    /**
     * Alguns sistemas de coordenadas padrões que podem ser usados
     * no método Onb::getEulerAngles()
     */
    enum coordinate_system {
        CARTESIAN
    };

public:
    /**
     * Construtor padrão, constrói uma base vazia
     */
    Onb();

    /**
     * Constrói a partir de três vetores
     */
    Onb(const Vec3f& a, const Vec3f& b, const Vec3f& c);

    /**
     * Construtor de cópia
     */
    Onb( const Onb& onb );

    /**
     * Destrutor
     */
    ~Onb();

    /**
     * Inicializa a base a partir do vetor u
     */
    void initFromU(const Vec3f& u);

    /**
     * Inicializa a base a partir do vetor v
     */
    void initFromV(const Vec3f& v);

    /**
     * Inicializa a base a partir do vetor w
     */
    void initFromW(const Vec3f& w);

    /**
     * Inicializa a base a partir de dois vetores
     * O primeiro é sempre fixo (normalizado), o segundo pode ter sua
     * direção ajustada
     */
    void initFromUV(const Vec3f& u, const Vec3f& v);
    void initFromVU(const Vec3f& v, const Vec3f& u);

    void initFromUW(const Vec3f& u, const Vec3f& w);
    void initFromWU(const Vec3f& w, const Vec3f& u);

    void initFromVW(const Vec3f& v, const Vec3f& w);
    void initFromWV(const Vec3f& w, const Vec3f& v);

    /**
     * Retorna um Vec3f com os ângulos de Euler em relação a origem do mundo
     */
    Vec3f getEulerAngles(const Onb& coord) const;
    Vec3f getEulerAngles(coordinate_system frame) const;


    /**
     * Testa a igualdade entre duas bases ortonormais
     */
    friend bool operator == (const Onb& onb1, const Onb& onb2);

    /**
     * Sobrecarga do operador de fluxo de dados
     */
    friend std::ostream& operator << (std::ostream& out, const Onb& onb);

};

}; // namespace math
}; // namespace mc



#endif	/* _MCONB_H */
