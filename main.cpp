#include "merge.h"



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

    // Ausgabe der Input in Console:
    cout <<"Input: ";
    printIntervall(input);

    //Ausführung der Merge Funktion
    mergeFunction(input);
    return 0;
}
