#include "merge.h"
#include "test.h"
#include "main.h"




//Hauptfunktion
int main() {
    try {
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

    test1();
    test2();
    test3();
    test4();

    } catch (int e){
        cout << "Fehler in Programm: " << e << '\n';
    }

    return 0;
}

bool checkIntervall(vector<Intervall> v) {
    for (int i = 0; i < v.size(); i++)
        if (v[i].anfang > v[i].ende)
            return false;
    return true;
}
