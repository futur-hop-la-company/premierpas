#include <iostream>
#include <iostream> 
#include <cstring>
#include <cmath>

using namespace std;

struct Fraction
{
    string nom;
    int numerateur ;
    int denominateur ;
    
};
// faction saisie 
Fraction saisie()
{
    Fraction F;
    cout << "saisir le nom = ";
    cin >> F.nom;
    cout << "Saisir le numérateur = " ;
    cin >> F.numerateur ;
    cout << "Saisir le dénominateur = " ;
    cin >> F.denominateur ;
    return F ;
}
// fonction affichage
void affichage(Fraction F)
{
    cout << "--------------------------" << endl;
    cout << F.nom <<endl;
    cout << F.numerateur << " / " << F.denominateur << endl ;
    cout << "--------------------------" << endl;
}
// fonction multiplication de deux fractions
Fraction multiplication (Fraction &F1, Fraction &F2)
{
    Fraction F;
    F.numerateur = F1.numerateur * F2.numerateur;
    F.denominateur = F1.denominateur * F2.denominateur;
    return F;
} 
// fonction multiplication par un entier
Fraction multiplication_entieragauche(int n, const Fraction &F1)
{
    Fraction F;
    F.numerateur = (n * F1.numerateur);
    F.denominateur = F1.denominateur;
    return F;

}
// fonction multiplication par un entier
Fraction multiplication_entieradroite(const Fraction  &F1, int n)
{
    Fraction F;
    F.numerateur = (F1.numerateur * n);
    F.denominateur = F1.denominateur;
    return F;

}
// fonction multiplication de deux fraction sous cette forme : 
Fraction operator*(const Fraction &F1,const Fraction &F2)
{   
    Fraction F;
    F.numerateur = F1.numerateur * F2.numerateur;
    F.denominateur = F1.denominateur * F2.denominateur;
    return F;
}
//recherche du plus grand diviseur commun entre le numérateur et le dénominateur
int recherche (Fraction &F)
{

    for (int i = F.numerateur; i > 0; i--)
    {
        if (F.numerateur % i == 0 && F.denominateur % i == 0)
        {
                return i;
        }
    }
    // si on arrive pas a trouver de plus grand diviseur commun alors on utilise 1 pour la simplification
    return 1;
}
// simplification d'une fraction 
Fraction simplifier(Fraction &F)
{
    /*bool fini = false;
    while (!fini)
    {
      
      
        if (F.numerateur%2==0 && F.denominateur%2==0)
         {
                cout << "%2";
                F.numerateur = (F.numerateur/2);
                F.denominateur = (F.denominateur/2);
         }

        else if (F.numerateur%3==0 && F.denominateur%3==0)
         {
                cout << "%3";
                F.numerateur = (F.numerateur/3);
                F.denominateur = (F.denominateur/3);
         }

        else if (F.numerateur%5==0 && F.denominateur%5==0)
         {
                cout << "%5";
                F.numerateur = (F.numerateur/5);
                F.denominateur = (F.denominateur/5);
         }

        else if (F.numerateur%7==0 && F.denominateur%7==0)
         {
                cout << "%7";
                F.numerateur = (F.numerateur/7);
                F.denominateur = (F.denominateur/7);
         }

          else if (F.numerateur%11==0 && F.denominateur%11==0)
         {
                cout << "%11";
                F.numerateur = (F.numerateur/11);
                F.denominateur = (F.denominateur/11);
         }

         else {
            fini = true; // on déduit que c'est fini
         }
 
    }
    return F;*/
    
    int division = recherche(F);
    F.numerateur = (F.numerateur / division);
    F.denominateur = (F.denominateur / division);
    return F;

}
Fraction addition(Fraction &F)
{

}

int main()
{
   Fraction F1,F2,F3,F5 ;
   F1 = saisie() ;
    F2 = saisie() ;
   simplifier(F1);
   affichage(F1) ; 
   affichage(F2) ; 
   F3 = multiplication(F1, F2);
   F3.nom = "F3";
   simplifier(F3);
   affichage(F3);
   Fraction F4;
    F4.nom = "F4";
   F4 = multiplication_entieradroite(F1,7);
   simplifier(F4);
    F4.nom = "F4";
   affichage(F4);
   F4 = multiplication_entieragauche(3,F1);
   affichage(F4);
    F5.nom = "F5";
   F5 = F1 * F2;
   affichage(F5);
 

    return 0;
 }