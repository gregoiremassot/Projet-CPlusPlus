import os

os.chdir("C:/projetcpp/projetcpp")
fichier = open("BDD_enseignants.csv", "r")
lines = fichier.readlines()
print(lines[0][0])

path = "./Universite/Enseignants/"
for i in range(0,int(len(lines)/3)):
    fichier_ecrire = open(path + lines[0 + 3*i][0] + ".txt", "w")
    fichier_ecrire.write(lines[0 + 3*i])
    fichier_ecrire.write(lines[1 + 3*i])
    fichier_ecrire.write(lines[2 + 3*i])

fichier_ecrire.close()