Gegenüber der vorigen Variante enthält das Programm jetzt einen `Memmanager`, der das Reservieren und Freigeben von Speicher übernimmt.  
Er ist in ein separates C-Modul gekapselt, bestehend aus den Deklarationen in `mem.h` und den Definitionen in `mem.c`.  
Die Schnittstelle zum main-Hauptmodul wird über `#include "mem.h"`realisiert, der Compiler enthält hierüber alle notwendigen Informationen.  
Ein Objekt des Speichermanagers wird 1x am Beginn von `main` definiert und initialisiert:
```C
Memmanager mm = { 0 };
```
Anschließend wird ausschließlich die Adresse an die entsprechenden Funktionen übergeben.  

Statt bisher mit calloc
```C
node->left = calloc(1, sizeof*node);
```
wird jetzt die gesamte Speicherversorgung über den `Memmanager` erledigt
```C
node->left = memalloc(mm, sizeof*node);
```
Dazu wird die neue Funktion `memalloc` mit dem Objekt des Speichermanagers als ersten Parameter verwendet.  

Wie erwähnt besteht der Hauptnutzen dieses Speichermanagers in der Eigenschaft, den gesamten im Baum verwendeten Speicher ohne UB freigeben zu können:
```C
memfreeall(&mm);
```
Einzelfreigaben jedes Baumelements mit `free()` wären jeweils UB gewesen, da die free-Aufrufe durch die Sortierung der Elemente nie rückwärts zu den calloc-Aufrufen geschehen können und somit auf Speicher zugegriffen werden muss, der zuvor schon mit free freigegeben wurde, was UB bedeutet.  
Zusätzlich bietet die Verwendung des Speichermanagers durch dessen Implementierung einer blockweisen Speicherverwaltung eine höhere Performanz, da effektiv weniger häufig calloc aufgerufen wird. 

