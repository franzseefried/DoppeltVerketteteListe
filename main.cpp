/*#######################################################
 * Einsendeaufgabe 5.2
 *######################################################*/
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
using namespace std;

//EInfache verkettete Liste
//https://www.youtube.com/watch?v=05KSiierZBE

struct listenelement{
  string daten;
  listenelement* next;
  listenelement* last;
};

string convertInt(int number)
{
   stringstream s;// string Stream erzeugen
   s<< number;// Zahl hinzufügen
   return s.str();// string zurückgeben
}
//Funktion zum anhaengen von Elementen an die Liste unter Verwendung eines Pointers auf das aktuelle Listenende
listenelement* anhaengen(string datenneu, listenelement* listenende){
    //lokaler Hilfszeiger
    listenelement* hilfszeiger;
    //den hilfszeiger an das ende der liste setzen
    hilfszeiger=listenende;
    //durch die liste gehen bis zum letzten element dabei immer pointer versetzen nicht mehr noetig da Listenende gespeichert
    //while(hilfszeiger->next != nullptr)
    //    hilfszeiger=hilfszeiger->next;
    //neues element an das ende der liste haengen
    hilfszeiger->next=new(listenelement);
    //Adresse vom Vorgaengerelement in Sicherheit bringen
    hilfszeiger->next->last=hilfszeiger;
    //den hilfszeiger auf das neue listenelement setzen
    hilfszeiger=hilfszeiger->next;
    //die Daten in das neue Element eintragen
    hilfszeiger->daten = datenneu;
    //es gint keinen nachfolger also next auf nullprt setzen
    hilfszeiger->next=nullptr;
    return hilfszeiger;
}
//Funktion zum Ausgeben aller Elemente vorwaerts
void ausgeben(listenelement *listenanfang){
    //lokaler hilfszeiger um in der liste wandern zu koennen
    listenelement* hilfszeiger;
    //hilfzeiger an den beginn setzen
    hilfszeiger = listenanfang;
    //ausgeben erstes element
    cout << hilfszeiger->daten << " // " << hilfszeiger->last << " // " << hilfszeiger->next << endl;
    //so lange das ende der liste nicht erreicht ist
    while(hilfszeiger->next != nullptr){
        //setze hilfzeiger auf das nächste element
        hilfszeiger = hilfszeiger->next;
        //daten ausgeben. z.B. pointer next vom ersten (==0) ist gleich pointer last vom dritten (Ausgabe 2)
        cout << hilfszeiger->daten << " // " << hilfszeiger->last << " // " << hilfszeiger->next << endl;
    }
}

//Funktion zum Ausgeben aller Elemente rueckwaerts
void printbackwards(listenelement *listenende){
    //lokaler hilfszeiger um in der liste wandern zu koennen
    listenelement* hilfszeiger;
    //hilfzeiger an den beginn setzen
    hilfszeiger = listenende;
    //ausgeben erstes element
    cout << hilfszeiger->daten << " // " << hilfszeiger->last << " // " << hilfszeiger->next << endl;
    //so lange das ende der liste nicht erreicht ist
    while(hilfszeiger->last != nullptr){
        //setze hilfzeiger auf das nächste element
        hilfszeiger = hilfszeiger->last;
        //daten ausgeben. z.B. pointer next vom ersten (==0) ist gleich pointer last vom dritten (Ausgabe 2)
        cout << hilfszeiger->daten << " // " << hilfszeiger->last << " // " << hilfszeiger->next << endl;
    }
}

//Funktion zum leeren der liste und Speicher frei geben
void ende(listenelement *listenanfang){
    //wieder ein lokaler hilfszeiger
    listenelement *hilfszeiger;
    //so lange das element noch in der liste ist
    while(listenanfang!=nullptr){
        //setze hilfzeiger auf das erste listenelement
        hilfszeiger = listenanfang;
        //den zeiger fuer den listenanfang auf das naechste element setzen
        listenanfang=listenanfang->next;
        //speicher fuer das herausgenommene element frei geben
        delete(hilfszeiger);
    }
}
int main()
{
    string const cstring = "Element ";
    //zeiger auf den Anfang der liste == ANKER1 -> muss immer behalten bleiben. Zeiger aus die Struktur
    listenelement *listenanfang;
    //erstes element erzeugen. reservieren speicher
    listenanfang=new(listenelement);
    //Daten in das erste element schreiben
    //next && last sind NULL beim ersten
    listenanfang->next = nullptr;
    listenanfang->last = nullptr;
    //Daten rein
    listenanfang->daten = cstring + "0";
    //NEU: zeiger auf den letzten Eintrag in der liste wg Anpassung in Fkt anhaengen
    listenelement *listenende;
    listenende=new(listenelement);
    //positioniere listenende auf listenanfang da erstes element zugleich letztes element ist
    listenende=listenanfang;
/*
    cout << "/         " << (listenanfang)->daten << endl;
    cout << "//        " << (listenende)->daten << endl;
    cout << "///       " << &(listenanfang)->daten << endl;
    cout << "////      " << &(listenende)->daten << endl;
    cout << "/////     " << listenanfang->next << endl;
    cout << "//////    " << listenende->next << endl;
    cout << "///////   " << &(listenanfang)->next << endl;
    cout << "////////  " << &(listenende)->next << endl;
    cout << "///////// " << listenanfang->last << endl;
    cout << "//////////" << listenende->last << endl;
*/

    //ausgeben der liste
    //ausgeben(listenanfang);

    cout << endl;
    //weitere elemente anhaengen
    for (int i =1;i<5;i++){
        string lcstr;
        lcstr = convertInt(i);
        listenelement* lczeiger;
        lczeiger=anhaengen(cstring + lcstr,listenende);
        //print to screen feedback from function anhaengen
        //cout << lczeiger->daten << endl;
        //update das listenende mit zeiger aus dem aktuellen loop
        listenende=lczeiger;
        //cout << i << " " << listenende->daten << endl;
        //ausgeben(listenanfang);
        //cout << "########" << endl;
    }
    cout << "ausgeben der liste vom beginn" << endl;
    ausgeben(listenanfang);
    cout << endl;
    cout << "ausgeben der Liste vom ende" << endl;
    printbackwards(listenende);
    //abbauen und aufraeumen
    ende(listenanfang);


    return 0;
}
