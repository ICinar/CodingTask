# CodingTask

Dieses Programm wurde in C++ geschrieben. Diese Code ist in drei Abschnitten unterteil. Zum einem die Hauptdatei für die Ausführung, Tests für die Testfälle und Merge für die Funktion. Die Merged Intervall Algorithmus ist in vier Schritten unterteilt. Als Beispiel werden hier die Eingabewerte: **[25,30] [2,19] [14, 23] [4,8]** gegeben.

Als Struktur bekommen diese Intervalle mithilfe von Struct ein gesonderten Datentyp. Diese besteht aus einem Startwert und einem Endwert. Somit stellt dies ein Intervall dar.

## 1. Sortierung der Startwerte von Intervalllisten
* In dieser Schritt sollen die Startwerte der Intervallen nach der Reihenfolge sortiert werden. 
* In diesem Beispiel sind die Intervallen folgendermaßen sortiert: **[2,19] [4,8] [14, 23] [25,30]**
* Als Sortieralgorithmus wird hier die Quicksort benutzt, dass die Komplexität **O(n log n)** bei best und average case. Bei worst case liegt der Laufzeitkomplexität auf **O(n²)**.

## 2. Erste Intervall in der Liste wird in einer Stack (Liste) gespeichert. 
* Es wird eine Stack erstellt. Dort wird der erste Intervall der Liste gespeichert.

## 3. Überprüfung von Überlappung der Intervalle
* Für die Überprüfung der Überlappung werden zwei Fälle betrachtet:
   * 1.Fall der Startwert der Intervall liegt außerhalb Stack Intervall (größer als Endwert von Stack Intervall): der Intervall wird in Stack gespeichert.
   * 2.Fall der Endwert von Intervall und der Endwert der Stack Intervall überlappen sich (der Endwert der Stack Intervall ist innerhalb der aktuellen Intervall): Der Endwert der    Stackintervall wird durch den Endwert der aktuellen Intervall ersetzt.

## 4. Ausgabe der Intervalle
* Die Ausgabe erfolgt in einer Schleife und wird in der Konsole angezeigt.

Weitere Infos siehe Kommentare in Code


# Ausführung
Ausgeführt unter Arch Linux mit Linux Kernel Version 5.11.13. Mit gcc Compiler ausgeführt.
Unter Windows wird Cygwin und deren Bibliotheken (g++, gcc und make) verwendet.
Cygwin Download:  https://cygwin.com/setup-x86_64.exe
### 1.Makefile ausführen
Um ein ausführbahren Datei zu erstellen:
``` 
make all
```
### 2.Ausführen des Programms
Von Makefile erstellte Datei ausführen:
``` 
./codetask
```
Für Windows Umgebung:
``` 
./codetask.exe
```
# Testing
Hier werden Testfälle definiert, um die Korrektheit und Zuverlässigkeit der Funktion zu testen.

* 1. Fall: Intervalle mitden gleiche Startwert Bepsiel: [12,24] [25,96] [25,33] [1,2] [3,4]. Erwartung: [1,2] [3,4] [12,24] [25,96]
* 2. Fall: Reheinfolge von Intervall vertauscht Beispiel [26,24] Erwartung: Eine Fehlermeldung für die Falsche Eingabe der Intervall. (Alternativ: Programm tauscht die Intervallgrenzwerte aus)
* 3. Fall: Ausführung von großen Zahlen d.h. Intervallgrenzwerte haben sehr hohen Wert und diese Code soll es verarbeiten können
* 4. Fall: Mehrere Intervall Werte: Bei einer sehr hohen Anzahl (z.B. 99999) soll das Programm eine Fehlermeldung geben, da diese trotz der nicht sehr hohen Komplexität nicht weiterverarbeiten kann. Hier soll ein Fehlermeldung kommen, mit dem Hinweis, dass die Anzahl der Intervalle in der Liste sehr groß ist. Somit soll eine Stackoverflow Exception vermieden werden.
*
# Wichtige Infos (Speicherverbrauch und Laufzeitkomplexität)
* Laufzeit: Da hier die Sortieralgorithmus Quicksort benutzt wird ist die Laufzeitkomplexität O(n log n) bzw. O(n²) und für eine zusätzliche Schleife für die Ermittlung der Überlappung der Intevalle kommt O(n) hinzu. (Hier wurden die Ein- und Ausgaben der Intervalle nicht berücksichtigt.) Für die im CodingTask erwähnte Beispiel braucht das Programm durchschnittlich 124.6 Mikrosekunden.
* Speicherverbrauch: Neben die dynamische Liste der Eingabe, wird für den Erstellung der Stack zusätzlich Speicher von O(n) benötigt. Diese werden für die Ausgabe benutzt.
* Robustheit der Software: Beim kompilieren soll das Programm keine Warnings beinhalten,. Bei falscher Eingabewerte weist das Programm auf eine Fehler hin. Bei sehr viele Eingaben wird das Programm anhand von try und catch Befehle auf eine Fehler hingewiesen, dass sehr viele Intervalleingaben nicht verarbeitet werden können (siehe Testing 4. Fall).
