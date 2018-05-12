import os

os.chdir("C:/projetcpp/projetcpp")

fichier = open("BDD_enseignants.csv", "r")
lines = fichier.readlines()
path = "./Universite/Enseignants/"
for i in range(0,int(len(lines)/3)):
    fichier_ecrire = open(path + lines[0 + 3*i][0] + ".txt", "w")
    fichier_ecrire.write(lines[0 + 3*i])
    fichier_ecrire.write(lines[1 + 3*i])
    fichier_ecrire.write(lines[2 + 3*i])
fichier.close()

fichier = open("./Universite/Cours/Cours.csv", "r")
n = 5
lines = fichier.readlines()
path = "./Universite/Cours/"
print(int(len(lines)/n))
for i in range(0,int(len(lines)/n)):
    fichier_ecrire = open(path + lines[0 + n*i][0:-1] + ".txt", "w")
    for j in range(0, n):
        fichier_ecrire.write(lines[j + n*i])

fichier.close()

fichier = open("./Universite/Etudiants/EtudiantsLicence.csv", "r")
n = 4
lines = fichier.readlines()
path = "./Universite/Etudiants/Licence/"
print(int(len(lines)/n))
for i in range(0,int(len(lines)/n)):
    fichier_ecrire = open(path + lines[0 + n*i][0:-1] + ".txt", "w")
    for j in range(0, n):
        fichier_ecrire.write(lines[j + n*i])
    fichier_ecrire.close()

fichier.close()

fichier = open("./Universite/Etudiants/EtudiantsMaster.csv", "r")
n = 5
lines = fichier.readlines()
path = "./Universite/Etudiants/Master/"
print(int(len(lines)/n))
for i in range(0,int(len(lines)/n)):
    fichier_ecrire = open(path + lines[0 + n*i][0:-1] + ".txt", "w")
    for j in range(0, n):
        fichier_ecrire.write(lines[j + n*i])
    fichier_ecrire.close()
fichier.close()

