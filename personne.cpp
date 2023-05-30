#include "personne.h"

Personne::Personne(QString nom, QString prenom, Sexe sexe, QString birth, Personne *pere, Personne *mere, QString death) :
    m_prenom(prenom), m_nom(nom), m_sexe(sexe), birth(birth), death(death), m_pere(pere), m_mere(mere), m_conjoint(nullptr)
{

}

QString Personne::toString() const
{
    QString titre = (m_sexe == Feminin) ? "Mme" : "M.";
    return titre + " " + m_prenom + " " + m_nom;
}

void Personne::ajouterEnfant(Personne *enfant)
{
    m_enfants.append(enfant);
    enfant->setPere(this);
    if (m_conjoint != nullptr) {
        enfant->setMere(m_conjoint);
    }
}

QList<Personne*> Personne::getEnfants() const
{
    return m_enfants;
}

void Personne::setPere(Personne *pere)
{
    m_pere = pere;
}

Personne* Personne::getPere() const
{
    return m_pere;
}

void Personne::setMere(Personne *mere)
{
    m_mere = mere;
}

Personne* Personne::getMere() const
{
    return m_mere;
}

void Personne::setConjoint(Personne *conjoint)
{
    m_conjoint = conjoint;
}

Personne* Personne::getConjoint() const
{
    return m_conjoint;
}
