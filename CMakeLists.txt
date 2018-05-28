cmake_minimum_required(VERSION 3.5)
project(projet_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(projet_cpp cpp/main.cpp cpp/Enseignant.cpp h/Enseignant.h cpp/Etudiant.cpp h/Etudiant.h cpp/Cours.cpp h/Cours.h cpp/EtudiantLicence.cpp h/EtudiantLicence.h cpp/EtudiantMaster.cpp h/EtudiantMaster.h cpp/Universite.cpp h/Universite.h)
