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

    cout << couple1->toString().toStdString() << endl;

    cout << "Enfants du couple :" << endl;
    QList<Personne*> enfantsCouple1 = couple1->getEnfants();
    for (Personne* enfant : enfantsCouple1) {
        cout << "  - " << enfant->toString().toStdString() << endl;
    }


    Personne *pereSmith = new Personne("John", "Smith", Personne::Masculin, "01/01/1950");
    Personne *mereSmith = new Personne("Emily", "Smith", Personne::Feminin, "01/01/1955");

    Couple *couple2 = new Couple(pereSmith, mereSmith);

    Personne* enfant1Smith = new Personne("John", "Smith", Personne::Masculin, "01/01/1980");
    Personne* enfant2Smith = new Personne("Emily", "Smith", Personne::Feminin, "01/01/1985");

    couple2->ajouterEnfant(enfant1Smith);
    couple2->ajouterEnfant(enfant2Smith);

    cout << couple2->toString().toStdString() << endl;

    cout << "Enfants du couple :" << endl;
    QList<Personne*> enfantsCouple2 = couple2->getEnfants();
    for (Personne* enfant : enfantsCouple2) {
        cout << "  - " << enfant->toString().toStdString() << endl;
    }

    Couple* coupleDupont2 = new Couple(enfant2Dupont, enfant1Smith);

    cout << "Nouveau couple :" << endl;
    cout << coupleDupont2->toString().toStdString() << endl;

    return a.exec();
}
