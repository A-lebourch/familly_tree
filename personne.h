#ifndef PERSONNE_H
#define PERSONNE_H

#include <QString>
#include <QList>

class Personne
{
public:
    enum Membre {pere, mere, enfant};
    enum Sexe {Masculin, Feminin};
    Personne(QString nom,QString prenom,Sexe sexe,QString birth,Personne *pere = NULL,Personne *mere=NULL,QString death="");
    QString toString();
    void ajoutMembre();

private:
    QString m_prenom;
    QString m_nom;
    Sexe m_sexe;
    QString birth;
    QString death;
    QList<Personne *> m_enfants;
};

#endif // PERSONNE_H
