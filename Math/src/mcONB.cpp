/* 
 * File:   mcONB.cpp
 * Author: thales
 * 
 * Created on May 15, 2010, 4:23 PM
 */

#include "../inc/mcONB.h"

using namespace mc::math;

const float Onb::EPSILON = 0.01f;

/**
 * Construtor
 */
Onb::Onb() { }

/**
 * Construtor de cópia
 */
Onb::Onb(const Onb& onb) {
    this->u = onb.u;
    this->v = onb.v;
    this->w = onb.w;
}

/**
 * Construtor explicíto
 */
Onb::Onb(const Vec3f& a, const Vec3f& b, const Vec3f& c) : u(a), v(b), w(c) { }

/**
 * Destrutor
 */
Onb::~Onb() { };

/**
 * Inicializa a base a partir de um vetor
 */
void Onb::initFromU(const Vec3f& u) {
    Vec3f n(Vec3f::X_AXIS);
    Vec3f m(Vec3f::Y_AXIS);

    // Normaliza o vetor u
    this->u = normalize(u);

    // Acha um vetor perpendicular a u e n
    v = cross(this->u, n);

    if (length(v) < Onb::EPSILON) {
        v = cross(this->u, m);
    }

    // Acha um vetor perpendicular a u e v
    w = cross(this->u, this->v);
}

/**
 * Inicializa a base a partir de um vetor
 */
void Onb::initFromV(const Vec3f& v) {
    Vec3f n(Vec3f::X_AXIS);
    Vec3f m(Vec3f::Y_AXIS);

    // Normaliza o vetor v
    this->v = normalize(v);

    // Acha um vertor perpendicular a v e n
    u = cross(this->v, n);

    if (length(u) < Onb::EPSILON) {
        u = cross(this->v, n);
    }

    // Acha um vetor perpendicular a u e v
    w = cross(this->u, this->v);
}

/**
 * Inicializa a base a partir de um vetor
 */
void Onb::initFromW(const Vec3f& w) {
    Vec3f n(Vec3f::X_AXIS);
    Vec3f m(Vec3f::Y_AXIS);

    // Normaliza o vetor w
    this->w = normalize(w);

    // Acha um vetor perpendicular a w e n
    u = cross(this->w, n);

    if (length(u) < Onb::EPSILON) {
        u = cross(this->w, m);
    }

    // Acha um vetor perpendicular a w e u
    this->v = cross(this->w, this->u);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromUV(const Vec3f& u, const Vec3f& v) {
    // Normaliza o vetor u
    this->u = normalize(u);

    // Acha um vetor perpendicular normalizado entre u e v
    this->w = normalize(cross(u, v));

    // Acha um vetor perpendicular e normalizado entre w e u
    this->v = cross(this->w, this->u);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromUW(const Vec3f& u, const Vec3f& w) {
    // Normaliza o vetor u
    this->u = normalize(u);

    // Acha um vetor perpendicular normalizado entre u e w
    this->v = normalize(cross(w, u));

    // Acha um vetor perpendicular entre u e v
    this->w = cross(this->u, this->v);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromVU(const Vec3f& v, const Vec3f& u) {
    // Normaliza o vetor u
    this->v = normalize(v);

    // Acha um vetor perpendicular e normalizado entre u e v
    this->w = normalize(cross(u, v));

    // Acha um vetor perpendicular entre u e v
    this->u = cross(this->v, this->w);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromVW(const Vec3f& v, const Vec3f& w) {
    // Normaliza o vetor v
    this->v = normalize(v);

    // Acha um vetor perpendicular normalizado entre v e w
    this->u = normalize(cross(v, w));

    // Acha um vetor perpendicular entre u e v;
    this->w = cross(this->u, this->v);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromWU(const Vec3f& w, const Vec3f& u) {
    // Normaliza o vetor w
    this->w = normalize(w);

    // Acha um vetor perpendicular e normalizado entre w e u
    this->v = normalize(cross(w, u));

    // Acha um vetor perpendicular a v e w
    this->u = cross(this->v, this->w);
}

/**
 * Inicializa a base a partir de dois vetores
 */
void Onb::initFromWV(const Vec3f& w, const Vec3f& v) {
    // Normaliza o vetor w
    this->w = normalize(w);

    // Acha um vetor perpendicular entre w e v
    this->u = normalize(cross(v, w));

    // Acha um vetor perpendicular a w e v
    this->v = cross(this->w, this->u);
}

/**
 * Retorna os angulos de Euler em relação as coordenadas de mundo
 */
Vec3f Onb::getEulerAngles(const Onb& coord) const {

    Vec3f eulerAngles;

    // Calcula o ângulo do eixo u
    eulerAngles.x = rad2deg<float>(acos(dot(u, coord.u)));
    eulerAngles.y = rad2deg<float>(acos(dot(v, coord.v)));
    eulerAngles.z = rad2deg<float>(acos(dot(w, coord.w)));

    return eulerAngles;
}

/**
 * Retorna os ângulos de Euler em relação ao sistema de coordenadas informado
 */
Vec3f Onb::getEulerAngles(coordinate_system frame) const {

    Onb coordSystem;

    switch(frame) {
        case CARTESIAN:
            coordSystem.u.setValue(Vec3f::X_AXIS);
            coordSystem.v.setValue(Vec3f::Y_AXIS);
            coordSystem.w.setValue(Vec3f::Z_AXIS);
            break;

        default:
            break;
    }

    return this->getEulerAngles(coordSystem);
}


/**
 * Operador de teste de igualdade
 */
bool operator ==(const Onb& onb1, const Onb& onb2) {
    return (onb1.u == onb2.u && onb1.v == onb2.v && onb1.w == onb2.w);
}

/**
 * Operador de saida
 */
std::ostream & operator<<(std::ostream& out, const Onb& onb) {
    out << std::fixed << onb.u << std::endl;
    out << std::fixed << onb.v << std::endl;
    out << std::fixed << onb.w << std::endl;
    return out;
}

