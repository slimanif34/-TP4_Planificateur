#include "rotation.h"

#include "rotation.h"
#include <iostream>

Rotation::Rotation(int p_angle): m_angle(p_angle)
{}

void Rotation::executer(ContexteRobot& ctx)
{
    ctx.rotation(m_angle);
    afficherNom();
}

void Rotation::afficherNom() const
{
    std::cout << "Action : Rotation de " << m_angle << " degres" << std::endl;
}


