#include "allera.h"
#include <iostream>

AllerA::AllerA(double p_x, double p_y, double p_z)
: m_x(p_x), m_y(p_y), m_z(p_z) {}

void AllerA::executer(ContexteRobot& ctx) {
    ctx.deplacerVers(m_x, m_y, m_z);
    afficherNom();
}

void AllerA::afficherNom() const {
    std::cout << "Action : AllerA ("
              << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
}


