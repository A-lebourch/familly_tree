#include <QCoreApplication>
#include <iostream>
#include "personne.h"
#include "couple.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//  création familles

    Personne *pereDupont = new Personne("Jean", "Dupont", Personne::Masculin, "01/01/1950"); //création mère famille 1
    Personne *mereDupont = new Personne("Marie", "Dupont", Personne::Feminin, "01/01/1955"); //création père famille 1

    Couple *couple1 = new Couple(pereDupont, mereDupont); // association des 2 parents pour créer un couple

    Personne *enfant1Dupont = new Personne("Paul", "Dupont", Personne::Masculin, "01/01/1980"); //création enfant1 famille 1
    Personne *enfant2Dupont = new Personne("Sophie", "Dupont", Personne::Feminin, "01/01/1985"); //création enfant2 famille 1

    couple1->ajouterEnfant(enfant1Dupont); //association enfant1 avec couple1
    couple1->ajouterEnfant(enfant2Dupont); //association enfant2 avec couple1
    enfant1Dupont->ajouterFrereSoeur(enfant2Dupont);//création relation frère et soeur

    Personne *pereSmith = new Personne("John", "Smith", Personne::Masculin, "01/01/1950"); //création père famille 2
    Personne *mereSmith = new Personne("Emily", "Smith", Personne::Feminin, "01/01/1955"); //création mère famille 2

    Couple *couple2 = new Couple(pereSmith, mereSmith); // association des 2 parents pour créer un couple

    Personne* enfant1Smith = new Personne("arthur", "Smith", Personne::Masculin, "01/01/1980"); //création enfant1 famille 2
    Personne* enfant2Smith = new Personne("louise", "Smith", Personne::Feminin, "01/01/1985"); //création enfant2 famille 2

    couple2->ajouterEnfant(enfant1Smith); //association enfant1 avec couple2
    couple2->ajouterEnfant(enfant2Smith); //association enfant2 avec couple2

    Personne *enfant1Dupont2 = new Personne("toto", "Dupont", Personne::Masculin, "01/01/1980"); //creation enfant1 famille 3

    Couple* coupleDupont2 = new Couple(enfant1Dupont, enfant2Smith); //creation nouveau couple avec enfant famille 1 & 2

    coupleDupont2->ajouterEnfant(enfant1Dupont2); //association enfant1 famille 3 avec le nouveau couple

//  Affichage des familles et de la généalogie

    cout << couple1->toString().toStdString() << endl;//affichage famille1

    cout << enfant1Dupont->afficheFrerSoeurs().toStdString() << endl;//affichage relation frère et soeur

    cout << couple2->toString().toStdString() << endl;//affichage famille2

    cout << coupleDupont2->toString().toStdString() << endl;//affichage famille3

    cout << enfant1Dupont2->Genealogie().toStdString() << endl; //affichage généalogie complète

    return a.exec();
}
