#include <QCoreApplication>
#include <iostream>
#include "personne.h"
#include "couple.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Personne *pereDupont = new Personne("Jean", "Dupont", Personne::Masculin, "01/01/1950");
    Personne *mereDupont = new Personne("Marie", "Dupont", Personne::Feminin, "01/01/1955");

    Couple *couple1 = new Couple(pereDupont, mereDupont);

    Personne *enfant1Dupont = new Personne("Paul", "Dupont", Personne::Masculin, "01/01/1980");
    Personne *enfant2Dupont = new Personne("Sophie", "Dupont", Personne::Feminin, "01/01/1985");

    couple1->ajouterEnfant(enfant1Dupont);
    couple1->ajouterEnfant(enfant2Dupont);

    Personne *pereSmith = new Personne("John", "Smith", Personne::Masculin, "01/01/1950");
    Personne *mereSmith = new Personne("Emily", "Smith", Personne::Feminin, "01/01/1955");

    Couple *couple2 = new Couple(pereSmith, mereSmith);

    Personne* enfant1Smith = new Personne("arthur", "Smith", Personne::Masculin, "01/01/1980");
    Personne* enfant2Smith = new Personne("louise", "Smith", Personne::Feminin, "01/01/1985");

    couple2->ajouterEnfant(enfant1Smith);
    couple2->ajouterEnfant(enfant2Smith);

    Personne *enfant1Dupont2 = new Personne("toto", "Dupont", Personne::Masculin, "01/01/1980");

    Couple* coupleDupont2 = new Couple(enfant1Dupont, enfant2Smith);

    coupleDupont2->ajouterEnfant(enfant1Dupont2);

///////////////////////////////////////////////////////////////////////////////////////////////

    cout << couple1->toString().toStdString() << endl;

    enfant1Dupont->ajouterFrereSoeur(enfant2Dupont);

    cout << enfant1Dupont->afficheFrerSoeurs().toStdString() << endl;

    cout << couple2->toString().toStdString() << endl;

    cout << coupleDupont2->toString().toStdString() << endl;

    cout << enfant1Dupont2->Genealogie().toStdString() << endl;


    return a.exec();
}
