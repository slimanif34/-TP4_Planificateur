#include "attendre.h"
#include <iostream>
#include <thread>
#include <chrono>

Attendre::Attendre(int duree)
    : m_duree(duree)
{
}

void Attendre::executer(ContexteRobot& ctx)
{
    afficherNom();
    std::this_thread::sleep_for(std::chrono::milliseconds(m_duree));
}

void Attendre::afficherNom() const
{
    std::cout << "Action : Attendre " << m_duree << " ms" << std::endl;
}
