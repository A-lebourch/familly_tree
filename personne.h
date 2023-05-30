#ifndef PERSONNE_H
#define PERSONNE_H

#include <QString>
#include <QList>

class Personne
{
public:
    enum Sexe { Masculin, Feminin };
    Personne(QString nom, QString prenom, Sexe sexe, QString birth, Personne *pere = nullptr, Personne *mere = nullptr, QString death = "");
    QString toString() const;
    void ajouterEnfant(Personne *enfant);
    QList<Personne*> getEnfants() const;
    void setPere(Personne *pere);
    Personne* getPere() const;
    void setMere(Personne *mere);
    Personne* getMere() const;
    void setConjoint(Personne *conjoint);
    Personne* getConjoint() const;

private:
    QString m_prenom;
    QString m_nom;
    Sexe m_sexe;
    QString birth;
    QString death;
    QList<Personne*> m_enfants;
    Personne *m_pere;
    Personne *m_mere;
    Personne *m_conjoint;
};

#endif
