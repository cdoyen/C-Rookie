Gegenüber der vorigen Variante enthält das Programm jetzt einen `Memmanager`, der das Reservieren und Freigeben von Speicher übernimmt.  
Er ist in ein separates C-Modul gekapselt, bestehend aus den Deklarationen in `mem.h` und den Definitionen in `mem.c`.  
Die Schnittstelle zum main-Hauptmodul wird über `#include "mem.h"`realisiert, der Compiler enthält hierüber alle notwendigen Informationen.  

Statt bisher mit calloc
```C
node->left = calloc(1, sizeof*node);
```
wird jetzt die gesamte Speicherversorgung über den `Memmanager` erledigt
```C
node->left = memalloc(mm, sizeof*node);
```
Dazu wird die neue Funktion `memalloc` mit dem Objekt des Speichermanagers als ersten Parameter verwendet.
