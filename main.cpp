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

    // Ajouter une relation de frère/soeur entre enfant1Dupont et enfant2Dupont
    enfant1Dupont->ajouterFrereSoeur(enfant2Dupont);

    cout << "Frères/soeurs de " << enfant1Dupont->toString().toStdString() << ":" << endl;
    QList<Personne*> freresSoeurs1 = enfant1Dupont->getFreresSoeurs();
    for (Personne* frereSoeur : freresSoeurs1) {
        cout << "  - " << frereSoeur->toString().toStdString() << endl;
    }

    cout << "Frères/soeurs de " << enfant2Dupont->toString().toStdString() << ":" << endl;
    QList<Personne*> freresSoeurs2 = enfant2Dupont->getFreresSoeurs();
    for (Personne* frereSoeur : freresSoeurs2) {
        cout << "  - " << frereSoeur->toString().toStdString() << endl;
    }

    return a.exec();
}
