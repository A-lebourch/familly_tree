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
    void ajouterFrereSoeur(Personne* frereSoeur);
    QList<Personne*> getFreresSoeurs() const;
    QString Genealogie()const;

private:
    QString m_prenom;
    QString m_nom;
    Sexe m_sexe;
    QString birth;
    QString death;
    QList<Personne*> m_enfants;
    QList<Personne*> m_freresSoeurs;
    Personne *m_pere;
    Personne *m_mere;
};

#endif
