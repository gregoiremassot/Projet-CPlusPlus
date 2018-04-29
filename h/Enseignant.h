//
// Created by Grégoire on 26/04/2018.
//

#ifndef PROJET_CPP_ENSEIGNANT_H
#define PROJET_CPP_ENSEIGNANT_H
#include <string>
#include <vector>

using namespace std;

class Enseignant {

public:
    Enseignant(void);
private:
    unsigned int m_number;
    string m_name;
    std::vector<int> m_ue;
};


#endif //PROJET_CPP_ENSEIGNANT_H
