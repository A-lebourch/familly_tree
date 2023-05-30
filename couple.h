#ifndef COUPLE_H
#define COUPLE_H

#include "personne.h"

class Couple
{
public:
    Couple(Personne* homme, Personne* femme);
    void ajouterEnfant(Personne* enfant);
    QList<Personne*> getEnfants() const;
    Personne* getHomme() const;
    Personne* getFemme() const;
    QString toString() const;

private:
    Personne* m_homme;
    Personne* m_femme;
    QList<Personne*> m_enfants;
};

#endif
