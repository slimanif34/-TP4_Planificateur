#ifndef POSEROBJET_H
#define POSEROBJET_H

#include "actionrobot.h"
#include "contexterobot.h"
#include "allera.h"
#include "deplacer.h"
#include "ouvrirpince.h"
#include "fermerpince.h"

class PoserObjet : public ActionRobot {
private:
    double m_x, m_y, m_z;

public:
    PoserObjet(double p_x, double p_y, double p_z);
    ~PoserObjet() override = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};


#endif // POSEROBJET_H
