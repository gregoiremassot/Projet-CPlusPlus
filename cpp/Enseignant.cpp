//
// Created by Grégoire on 26/04/2018.
//
#include "../h/Enseignant.h"
#include <iostream>
Enseignant::Enseignant(void)
{
    std::cout << "Je suis un nouveau professeur" << std::endl;
}

void Enseignant::setNom(string nom)
{
    m_name = nom;
}
