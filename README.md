# Proiect TIC-TAC-TOE în cadrul lucrării de laborator nr.1 la disciplina C++ 


## Scopul lucrării de laborator nr.1

Cunoștință cu sistemul de control al codului sursă GIT și formarea cunoștințelor de bază necesare pentru organizarea proiectului.


## Sarcina lucrării de laborator nr.1

Crearea unui proiect-joc în mediul de dezvoltare `Visual Studio Code`, conținutul căruia va fi divizat în mai multe fișiere, astfel încât fiecare fișier să nu conțină mai mult de o clasă. Pe calculator se va instala `GIT`.


# Rezolvarea sarcinii:

Acest repozitoriu conține implementarea unui simplu joc X și 0 în limbajul C++.

## Scopul Jocului:
Jocul Tic-Tac-Toe (cunoscut și sub numele de X și 0 sau “X și bulină”) este un joc de strategie simplu, care se joacă pe o tablă de 3x3. Scopul jocului este să obții o linie orizontală, verticală sau diagonală de trei simboluri consecutive (fie X, fie O).

Deși pare simplu, Tic-Tac-Toe implică o strategie minimă și poate fi jucat rapid. Este adesea folosit ca joc de încălzire sau pentru a învăța concepte de bază ale strategiei în jocurile mai complexe.


## Regulile Jocului:


1. Tablă de joc: Jocul se desfășoară pe o tablă de 3x3, unde fiecare celulă poate fi ocupată de un simbol X sau O.
2. Scopul jocului: Scopul este să obții o linie orizontală, verticală sau diagonală de trei simboluri consecutive (fie X, fie O).
3. Mutări: Jucătorii se alternează și fac mutări pe rând. Fiecare jucător alege o celulă goală și o completează cu simbolul său.
4. Câștigătorul: Primul jucător care completează o linie (orizontală, verticală sau diagonală) cu trei simboluri consecutive câștigă.
5. Remiză: Dacă tabla este completă și niciun jucător nu a obținut o linie, jocul se încheie cu remiză.

### Voi trece în revistă detaliile fiecărui fișier utilizat în cadrul acestui proiect:

- *`Mark.hpp`*

  Acest fișier definește o enumerare numită `Mark`, care reprezintă stările posibile ale unei celule pe tabla de joc. Cele trei valori posibile sunt:

```
   1. `Gol` însemnând o celula goală;
   2. `X` marcând semnul X din joc;
   3. `O` utilizat pentru simbolul zero din joc.
```
  
- *`Cell.hpp`*

  Clasa `Cell` reprezintă o celulă individuală pe tabla de joc. Aceasta are următoarele metode:

    - `setMark(Mark newMark):` Setează starea celulei la marcajul specificat.
    - `getMark() const:` Returnează marcajul curent al celulei.

- *`Table.hpp`*

  Clasa Table gestionează tabla de joc. Include următoarele metode:

    - `display() const:` Afișează starea curentă a tablei într-un format de grilă.
    - `isCellL(int row, int col) const:` Verifică dacă o celulă la poziția specificată este goală.
    - `updateCell(int row, int col, Mark newMark):` Actualizează starea unei celule cu marcajul dat.
    - `getCell(int row, int col) const:` Returnează marcajul unei celule specifice.
    - `isFull() const:` Verifică dacă întreaga tablă este completă (nu mai sunt celule goale).

   
- *`Player.hpp`*

  Clasa `Player` reprezintă un jucător care participă la joc. Are următoarele metode:

    - readMove() const: Citește mutarea jucătorului (rând și coloană) de la consolă.
    - getName() const: Returnează numele jucătorului.


- *`Game.hpp`*

  Clasa `Game` coordonează jocul X și 0. Include următoarele metode:

    - `initialize():` Inițializează starea inițială a jocului (tablă goală, jucătorul X începe).
    - `hasWinner() const:` Verifică dacă există un câștigător examinând rândurile, coloanele și diagonalele.
    - `isDraw() const:` Verifică dacă jocul s-a încheiat cu remiză.
    - `makeMove(int row, int col):` Validează și actualizează tabla în funcție de mutarea jucătorului.
    - `getCurrentPlayer() const:` Returnează marcajul jucătorului curent.
    - `display() const:` Afișează starea curentă a tablei.


- *`GameController.hpp`*

  Clasa `GameController` gestionează fluxul jocului. Inițializează jocul și gestionează interacțiunea cu jucătorii. Include metoda:

    - `startGame():` Începe bucla jocului, permițând jucătorilor să facă mutări până când există un câștigător sau o remiză.
