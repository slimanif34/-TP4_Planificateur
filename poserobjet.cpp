#include "poserobjet.h"
#include <iostream>

PoserObjet::PoserObjet(double p_x, double p_y, double p_z)
: m_x(p_x), m_y(p_y), m_z(p_z) {}

void PoserObjet::executer(ContexteRobot& ctx) {
    std::cout << "Action : PoserObjet en ("
              << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;

    double z_securite = m_z+ 50; // on reste 50 mm au-dessus avant/après la pose

    // Étape 1 : aller au-dessus du point
    AllerA allerAuDessus(m_x, m_y, z_securite);
    allerAuDessus.executer(ctx);

    // Étape 2 : descendre jusqu'à la hauteur de pose
    AllerA allerAPosition(m_x, m_y, m_z);
    allerAPosition.executer(ctx);

    // Étape 3 : ouvrir la pince (déposer)
    OuvrirPince ouvrir;
    ouvrir.executer(ctx);

    // Étape 4 : remonter à la hauteur de sécurité
    AllerA remonter(m_x, m_y, z_securite);
    remonter.executer(ctx);
}

void PoserObjet::afficherNom() const {
    std::cout << "Action : PoserObjet en (" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
}
