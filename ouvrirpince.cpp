#include "ouvrirpince.h"
#include <iostream>

void OuvrirPince::executer(ContexteRobot& ctx) {
    ctx.ouvrirPince();
    afficherNom();
}

void OuvrirPince::afficherNom() const {
    std::cout << "Action : OuvrirPince" << std::endl;
}
