#include "fermerpince.h"
#include <iostream>

void FermerPince::executer(ContexteRobot& ctx) {
    ctx.fermerPince();
    afficherNom();
}

void FermerPince::afficherNom() const {
    std::cout << "Action : FermerPince" << std::endl;
}
