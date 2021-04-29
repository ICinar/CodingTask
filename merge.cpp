#include "merge.h"
#include <exception>

const int stackSize = 10000;
/**
 * Funktion für die Ermittlung der Merge und Consolenausgabe als Ergebnis
 *
 * @param vect Liste der Intervalle
 */
vector<Intervall> mergeFunction(vector <Intervall> vect) {

    if (vect.size() > stackSize) {
        throw std::runtime_error("Error");
    }
    // 1.Schritt Sortiere alle Startintervalle nach Reihenfolge
    vect = sortieren(vect,0,vect.size()-1);

    //2. Stack für die gemergte Intervalle
    vector<Intervall> stack;
    stack.push_back(vect[0]);

    //3.Überprüfung der Überlappung und speichern in Stack
    for (int i = 1; i < vect.size(); i++){

        //erste Intervall von stack
        Intervall first = stack[stack.size()-1];

        //1.Fall Startwert der aktuellen Intervall ist nicht in Endwert des Stacks
        if (first.ende < vect[i].anfang) {
            stack.push_back(vect[i]);
        }
        //2.Fall Endwert von aktuellen Intervall und in Stack Intervall überlappen sich
        else if (first.ende < vect[i].ende) {
            first.ende = vect[i].ende;
            stack.pop_back();
            stack.push_back(first);
        }


    }

    //4.Ausgabe der gemergten Intervalle
    cout << "Output: ";
    printIntervall(stack);
    return stack;
}

/**
 * Teilt die Intervalle und ermittelt den Pivotelement für Quicksort
 *
 * @param v Intervallliste, left erste Intervall, right letzte Intervall
 * @return i gibt die Position der Pivotelement zurück
 */
int partition(vector<Intervall> &v, int left, int right) {
         int i = left;
         int j = right - 1;
         Intervall pivot = v[right];


         while (i < j) {

             while (i < right && v[i].anfang < pivot.anfang) {
                 i++;
             }

             while (j > left && v[j].anfang >= pivot.anfang) {
                 j--;
             }

             if (i < j) {
                 swap(v[i], v[j]);
                 i++;
                 j--;
             }
         }

         if (v[i].anfang > pivot.anfang) {
             swap(v[i], v[right]);
         }


         return i;



}


/**
 * Sortieralgorithmus (Quicksort) um die Start Intervall nach Reihenfolge zu sortieren
 *
 * @param vect Intervallliste, left erste Intervall, right letzte Intervall
 * @return sortierte Intervallliste
 */
vector<Intervall> sortieren(vector<Intervall> &v, int left, int right) {
    if (left < right) {
        int pivot = partition(v, left, right);
        sortieren(v, left, pivot - 1);
        sortieren(v, pivot + 1, right);
    }
    return v;
}



/**
 * Printfunktion für die Intervalle
 *
 * @param temp Intervallliste die in der Konsole ausgegeben werden soll
 */
void printIntervall(vector<Intervall> temp) {
    for (int i = 0; i < temp.size(); i++)
        cout<<"["<<temp[i].anfang<<";"<<temp[i].ende<<"] ";
    cout <<endl;
}

