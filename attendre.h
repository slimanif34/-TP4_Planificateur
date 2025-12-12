#ifndef ATTENDRE_H
#define ATTENDRE_H
#include "actionrobot.h"
#include "contexterobot.h"

class Attendre : public ActionRobot
{
private:
    int m_duree;    // durée en millisecondes

public:
    Attendre(int duree);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ATTENDRE_H
