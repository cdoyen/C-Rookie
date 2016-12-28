Das Beispiel zeigt den Gebrauch eines einfachen Binärbaumes anhand eines Telefonbuches mit jeweils 2 Datenelementen, Tel.nummer + Name.  
Als Operationen stehen hier `insert` und `print` zur Verfügung.  
###insert
* fügt das übergebene Datenelement in den Baum ein, aufsteigend sortiert nach Tel.nummer
* doppelte Tel.nummern werden dabei ignoriert und nicht in den Baum eingefügt  

###print
alle Elemente werden durchlaufen und sortiert mittels `printf` ausgegeben

##du lernst hier kennen
* Strukturen `struct`
* Strukturkopien `.data = .data`
* Zeiger und Doppel-Zeiger `*node` `**nodeptr`
* als enum definierte symbolische Konstante `MAXNAMESIZE`
* compound literals (flüchtige Objekte von Aggregattypen) `(Data) {}`
* Rekursion

##TODO
* Speicherfreigabe aller Baumelemente am Programmende (bedingt durch die prinzipiell unflexible Baumstruktur für sequentielle Aktionen gestaltet sich dies relativ schwierig ohne in UB zu geraten - was bei einfachen free()-Folgen der Fall sein würde)
* weitere Baum-Operationen: delete, update, search
* Gebrauch von Callback-Funktionen

