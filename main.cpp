#include <QCoreApplication>
#include "qstd.h"
#include <QList>
#include"personne.h"

int main(int argc, char *argv[])
{
    Personne test = new Personne("foo","toto",Personne::Masculin, "00/00/0000","dieu", "Marie");
    test.toString();
    //return a.exec();
}
