#include "personne.h"

Personne::Personne(QString nom, QString prenom, Sexe sexe, QString birth, Personne *pere, Personne *mere, QString death):
    m_prenom(prenom), m_nom(nom), m_sexe(sexe)
{

}

QString Personne::toString()
{
    QString titre=m_sexe==Feminin?"Mme":"M.";
    return titre + " " +m_prenom + " " + m_nom;
}

//void Personne::ajoutMembre(Personne *sujet, Membre relation)
//{

//}
