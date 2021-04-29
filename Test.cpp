#include "merge.h"
#include "test.h"
#include "main.h"

//Testfälle für Merge Intervall

//Testfall 1 Zwei Intervalle mit den gleichen Startwert
void test1() {
    vector<Intervall> input
    {
        {12,24},
        {25,96},
        {25,33},
        {1,2},
        {3,4}
    };
    cout <<"(Test1) Input: ";
    printIntervall(input);
    if (!checkIntervall(input)) {
        cout << "(Test 1): Input Failure"<<endl;
        return;
    }

    //Ausführung der Merge Funktion
   vector<Intervall> erg = mergeFunction(input);

   if ((erg[0].anfang == 1 && erg[0].ende == 2) &&
       (erg[1].anfang == 3 && erg[1].ende == 4) &&
       (erg[2].anfang == 12 && erg[2].ende == 24) &&
       (erg[3].anfang == 25 && erg[3].ende == 96))
       cout <<"(Test 1): Successful \n" <<endl;
   else
       cout <<"(Test 1): Failure \n" <<endl;
}

//Testfall 2 Reihenfolge von Intervall ist falsch
void test2() {
    vector<Intervall> input
    {
        {26,24},
        {25,96},
        {25,33},
        {1,2},
        {3,4}
    };
    cout <<"(Test2) Input: ";
    printIntervall(input);
    //vergleicht die Intervalleingaben
    if (!checkIntervall(input)) {
        cout << "(Test2): Successful\n"<<endl;
        return;
    } else {
        cout <<"(Test2): Failure \n"<<endl;
    }


}

//Testfall 3 große Zahlen
void test3() {
    vector<Intervall> input
    {
        {8765431,85312408},
        {120000000,130000000},
        {83457950,84100000},
        {1,2},
        {3,4}
    };
    cout <<"(Test3) Input: ";
    printIntervall(input);
    if (!checkIntervall(input)) {
        cout << "(Test 3): Input Failure\n"<<endl;
        return;
    }


    //Ausführung der Merge Funktion
   vector<Intervall> erg = mergeFunction(input);

   if ((erg[0].anfang == 1 && erg[0].ende == 2) &&
       (erg[1].anfang == 3 && erg[1].ende == 4) &&
       (erg[2].anfang == 8765431 && erg[2].ende == 85312408) &&
       (erg[3].anfang == 120000000 && erg[3].ende == 130000000))
       cout <<"(Test 3): Successful \n" <<endl;
   else
       cout <<"(Test 3): Failure \n" <<endl;
}

//Testfall 4 lange Liste
void test4() {
    vector<Intervall> input;
    for (int i = 0; i < 99999; i++) {
        Intervall temp;
        temp.anfang = i;
        temp.ende = i+1;
        input.push_back(temp);
    }
    cout <<"(Test4) Input: ";
   // printIntervall(input);
    if (!checkIntervall(input)) {
        cout << "(Test 4): Input Failure\n"<<endl;
        return;
    }


    //Ausführung der Merge Funktion
    vector<Intervall> erg = mergeFunction(input);

   if (erg[0].anfang == 0 && erg[0].ende == 99999)
       cout <<"(Test 4): Successful \n" <<endl;
   else
       cout <<"(Test 4): Failure \n" <<endl;
}


