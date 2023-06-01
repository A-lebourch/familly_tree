#include "personne.h"

Personne::Personne(QString nom, QString prenom, Sexe sexe, QString birth, Personne *pere, Personne *mere, QString death) :
    m_prenom(prenom), m_nom(nom), m_sexe(sexe), birth(birth), death(death), m_pere(pere), m_mere(mere)
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

QString Personne::Genealogie() const
{
    QString result = "généalogie de " + toString() + " : \n";
    result += "- Mère :" + m_mere->toString() + "\n";
    result += "- Père :" + m_pere->toString() + "\n";
    result += "-- Grandpère Paternel : " + m_pere->getPere()->toString() + "\n";
    result += "-- Grandmère paternel : " + m_pere->getMere()->toString() + "\n";
    result += "-- Grandpère maternel : " + m_mere->getPere()->toString() + "\n";
    result += "-- Grandmère maternel : " + m_mere->getMere()->toString() + "\n";
    return result;
}

void Personne::ajouterFrereSoeur(Personne* frereSoeur)
{
    if (m_pere == frereSoeur->getPere() && m_mere == frereSoeur->getMere())
    {
        m_freresSoeurs.append(frereSoeur);
        frereSoeur->m_freresSoeurs.append(this);
    }
}

QList<Personne*> Personne::getFreresSoeurs() const
{
    return m_freresSoeurs;
}

QString Personne::afficheFrerSoeurs() const
{
    QString result = "Frères/soeurs de " + toString() + " : \n";
    QList<Personne*> freresSoeurs = getFreresSoeurs();
    for (Personne* frereSoeur : freresSoeurs) {
        result += "  - " + frereSoeur->toString() +"\n";
    }
    return result;
}
