#include "couple.h"

Couple::Couple(Personne* homme, Personne* femme) : m_homme(homme), m_femme(femme)
{

}

void Couple::ajouterEnfant(Personne* enfant)
{
    m_enfants.append(enfant);
    enfant->setPere(m_homme);
    enfant->setMere(m_femme);
}

QList<Personne*> Couple::getEnfants() const
{
    return m_enfants;
}

Personne* Couple::getHomme() const
{
    return m_homme;
}

Personne* Couple::getFemme() const
{
    return m_femme;
}

QString Couple::toString() const
{
    QString result = "Couple :\n";
    result += "  Membre 1 : " + m_homme->toString() + "\n";
    result += "  Membre 2 : " + m_femme->toString() + "\n";
    return result;
}
