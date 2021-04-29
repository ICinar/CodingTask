#include <iostream>
#include <vector>

using namespace std;


// stellt die Struktur eines Intervalls dar mit Start- und Endwert
struct Intervall
{
    int anfang,ende;
};

vector<Intervall> mergeFunction(vector <Intervall> vect);

int partition(vector<Intervall> &v, int left, int right);

vector<Intervall> sortieren(vector<Intervall> &v, int left, int right);

void printIntervall(vector<Intervall> temp);
