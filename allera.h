#ifndef ALLERA_H
#define ALLERA_H

#include "actionrobot.h"
#include "contexterobot.h"

class AllerA : public ActionRobot {
private:
    double m_x, m_y, m_z;

public:
    AllerA(double p_x, double p_y, double p_z);
    ~AllerA() override = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ALLERA_H
