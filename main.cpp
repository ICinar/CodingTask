#include "merge.h"
#include "test.h"
#include "main.h"

//Hauptfunktion
int main() {
    
    // Liste der Intervalle
    vector<Intervall> input
    {
        {25,30},
        {2,19},
        {14,23},
        {4,8}
    };

    if (!checkIntervall(input)) {
        cout << "Die Intervallliste ist nicht korrket"<<endl;
        return -1;
    }
    // Ausgabe der Input in Console:
    cout <<"Input: ";
    printIntervall(input);

    //Ausführung der Merge Funktion
    mergeFunction(input);

    cout <<endl;

	//Tests:
	
    test1();
    test2();
    test3();
    test4();
	


    return 0;
}


/**
 * Methode Überprüft ob der Startwert der Intervalle größer ist als Endwert 
 *
 * @param v Intervallliste für die Eingabe
 * @return true wenn alle Startwerte kleiner sind als Endwerte, false wenn Startwert größer ist als der Endwert
 */
bool checkIntervall(vector<Intervall> v) {
    for (int i = 0; i < v.size(); i++)
        if (v[i].anfang > v[i].ende)
            return false;
    return true;
}
