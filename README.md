# CodingTask

Dieses Programm wurde in C++ geschrieben. Die Merged Intervall Algorithmus ist in vier Schritten unterteilt.
Als Beispiel werden hier die Eingabewerte: **[25,30] [2,19] [14, 23] [4,8]** gegeben.

Als Struktur bekommen diese Intervalle mithilfe von Struct ein gesonderten Datentyp. Diese besteht aus einem Startwert und einem Endwert. Somit stellt dies ein Intervall dar.

## 1. Sortierung der Startwerte von Intervalllisten
* In dieser Schritt sollen die Startwerte der Intervallen nach der Reihenfolge sortiert werden. 
* In diesem Beispiel sind die Intervallen folgendermaßen sortiert: **[2,19] [4,8] [14, 23] [25,30]**
* Als Sortieralgorithmus wird hier die Quicksort benutzt, dass die Komplexität ** O(n log n) ** bei best und average case. Bei worst case liegt der Laufzeitkomplexität auf **O(n²)**.

## 2. Erste Intervall in der Liste wird in einer Stack (Liste) gespeichert. 
* Es wird eine Stack erstellt. Dort wird der erste Intervall der Liste gespeichert.

## 3. Überprüfung von Überlappung der Intervalle
* Für die Überprüfung der Überlappung werden zwei Fälle betrachtet:
   * 1.Fall der Startwert der Intervall liegt außerhalb Stack Intervall (größer als Endwert von Stack Intervall): der Intervall wird in Stack gespeichert.
   * 2.Fall der Endwert von Intervall und der Endwert der Stack Intervall überlappen sich (der Endwert der Stack Intervall ist innerhalb der aktuellen Intervall): Der Endwert der    Stackintervall wird durch den Endwert der aktuellen Intervall ersetzt.

## 4. Ausgabe der Intervalle
* Die Ausgabe erfolgt in einer Schleife und wird in der Konsole angezeigt.

# Wichtige Infos (Speicherverbrauch und Laufzeitkomplexität)


# Ausführung
Ausgeführt unter Arch Linux mit Linux Kernel Version 5.11.13

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
# Testing
