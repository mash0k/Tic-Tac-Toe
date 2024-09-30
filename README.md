# Proiect TIC-TAC-TOE în cadrul lucrării de laborator nr.2 la disciplina C++ 


## Scopul lucrării de laborator nr.2

După finalizarea acestei sarcini, studentul se va familiariza cu caracteristicile implementării clasei și interacțiunii cu obiectele clasei. Studentul va primi, de asemenea, cunoștințe de bază despre construcție din linia de comandă a proiectelor.


## Sarcina lucrării de laborator nr.2

Sarcina se bazează pe lucrările anterioare de laborator. Efectuarea sarcinii se face în ramura lab02 a repozitoriului creat anterior.

1. Pentru fiecare structură declarată implementați metode
2. Compilați unul dintre fișierele cpp din linia de comandă, creând un fișier obiect
3. Creați un fișier cmd (sau Makefile) pentru a construi manual proiectul
4. Creați un fișier .gitignore pentru a ignora fișierele obiect și fișierele executabile
5. Modificati fișierul README.md pentru a reflecta metoda de construcție a proiectului
6. Adăugați în repozitoriu GitHub fișierele obiect și fișierul de construcție în ramura lab02


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

- *`Cell.cpp`*

  Implementarea funcționalității clasei `Cell`. Conține definițiile pentru metodele clasei `Cell`, cum ar fi `setMark()` și `getMark()`:

    - `Cell():` Constructor care setează inițial starea celulei la `Mark::Gol`.
    - `setMark(Mark L):` Actualizează marcajul celulei.
    - `getMark() const:` Returnează marcajul curent al celulei.

- *`Table.hpp`*

  Clasa `Table` gestionează structura și funcționarea tablei de joc 3x3. Aceasta include:

    - **Atribute**:
      - `rows` și `cols:` Dimensiunile constante ale tablei (3x3).
      - `cells:` Un array bidimensional de obiecte `Cell`, care reprezintă starea fiecărei celule de pe tablă.

    - **Metode**:
      - `Table():` Constructor care inițializează tabla cu celule goale.
      - `display() const:` Afișează starea curentă a tablei într-un format vizual pentru joc, cu rânduri și coloane numerotate.
      - `isCellL(int row, int col) const:` Verifică dacă o celulă specificată este goală.
      - `updateCell(int row, int col, Mark newMark):` Actualizează starea unei celule cu simbolul X sau O.
      - `getCell(int row, int col) const:` Returnează marcajul (starea) curentă a unei celule date.
      - `isFull() const:` Verifică dacă tabla este completă, adică dacă nu mai există celule goale.

- *`Table.cpp`*

  Implementarea logicii pentru tabla de joc. Clasa `Table` include toate metodele pentru a gestiona și a vizualiza tabla de joc:

    - **Table():** Constructor care inițializează toate celulele tablei la starea `Gol` (celulă goală).
    - **display() const:** Afișează tabla într-un format grafic ușor de citit, arătând pozițiile disponibile și marcajele X sau O din celule.
    - **isCellL(int row, int col) const:** Verifică dacă celula de la poziția specificată este goală (`Mark::Gol`).
    - **updateCell(int row, int col, Mark newMark):** Actualizează o celulă cu un marcaj X sau O.
    - **getCell(int row, int col) const:** Returnează starea (marcajul) curentă a celulei de la poziția indicată.
    - **isFull() const:** Verifică dacă tabla este completă, adică dacă toate celulele au fost umplute cu un simbol X sau O.

   
- *`Player.hpp`*

  Clasa `Player` reprezintă un jucător din jocul Tic-Tac-Toe. Aceasta include:

    - **Atribute**:
      - `name:` Numele jucătorului, stocat ca un string.

    - **Metode**:
      - `Player(const std::string& playerName):` Constructor care inițializează numele jucătorului.
      - `readMove() const:` Metoda care permite jucătorului să introducă rândul și coloana mutării. Returnează indexul ajustat (bazat pe 0) pentru a fi utilizat pe tablă.
      - `getName() const:` Returnează numele jucătorului.

- *`Player.cpp`*

  Implementarea clasei `Player`. Acest fișier definește funcționalitatea metodelor:

    - **Constructorul Player**: Inițializează un jucător cu un nume primit ca parametru.
    - **readMove() const**: Solicită jucătorului să introducă o mutare sub forma unui număr de rând și coloană, citit de la tastatură. Mutarea este ajustată pentru a se potrivi indexării bazate pe 0 (folosite în implementarea tablei de joc).
    - **getName() const**: Returnează numele jucătorului, util pentru afișarea mesajelor personalizate în timpul jocului.


- *`Game.hpp`*

  Clasa `Game` coordonează jocul X și 0. Include următoarele metode:

    - `initialize():` Inițializează starea inițială a jocului (tablă goală, jucătorul X începe).
    - `hasWinner() const:` Verifică dacă există un câștigător examinând rândurile, coloanele și diagonalele.
    - `isDraw() const:` Verifică dacă jocul s-a încheiat cu remiză.
    - `makeMove(int row, int col):` Validează și actualizează tabla în funcție de mutarea jucătorului.
    - `getCurrentPlayer() const:` Returnează marcajul jucătorului curent.
    - `display() const:` Afișează starea curentă a tablei.

- *`Game.cpp`*

  Implementarea logicii principale a jocului. Clasa `Game` include metodele necesare pentru a gestiona fluxul jocului, precum:

    - `initialize():` Inițializează starea inițială a jocului, cu tabla goală și jucătorul X pregătit să înceapă.
    - `hasWinner() const:` Verifică dacă există un câștigător prin examinarea rândurilor, coloanelor și diagonalelor.
    - `isDraw() const:` Determină dacă jocul s-a încheiat cu remiză (tabla este completă și nu există un câștigător).
    - `makeMove(int row, int col):` Gestionează mutările făcute de jucători, validând poziția aleasă și actualizând tabla.
    - `getCurrentPlayer() const:` Returnează simbolul jucătorului curent (`X` sau `O`).
    - `display() const:` Afișează starea curentă a tablei de joc.


- *`GameController.hpp`*

  Clasa `GameController` gestionează fluxul jocului și interacțiunea dintre jucători și jocul de Tic-Tac-Toe. Aceasta conține următoarele elemente:

    - **Atribute**:
      - `ticTacToe:` Instanța clasei `Game`, care reprezintă jocul.
      - `jucător1` și `jucător2:` Instanțele clasei `Player`, care reprezintă jucătorii.

    - **Metode**:
      - `GameController(const std::string& name1, const std::string& name2):` Constructor care inițializează jocul cu numele celor doi jucători.
      - `startGame():` Metoda care începe jocul, permițând jucătorilor să facă mutări alternativ până când există un câștigător sau se ajunge la remiză.

- *`GameController.cpp`*

  Acest fișier implementează funcționalitatea clasei `GameController`. Metodele incluse sunt:

    - **Constructorul GameController**: Inițializează obiectele necesare pentru a începe jocul, cum ar fi instanțele de `Player` pentru cei doi jucători și o instanță de `Game`.
    - **startGame()**: Metoda principală care gestionează interacțiunea dintre utilizatori și joc. Se repetă bucla de joc, permițând jucătorilor să facă mutări alternativ, afișând starea curentă a jocului și determinând dacă există un câștigător sau o remiză.

## Fișierul Makefile

Fișierul `Makefile` este utilizat pentru a automatiza procesul de compilare a proiectului Tic-Tac-Toe. Acesta definește variabilele, regulile de compilare și țintele pentru a genera executabilul jocului.

### Variabile

- **USM**: Această variabilă definește compilatorul utilizat, care în acest caz este `g++`.
- **HBBBUBAA**: Această variabilă include opțiunile de compilare, cum ar fi `-Wall` (pentru a activa toate avertizările) și `-std=c++11` (pentru a specifica utilizarea standardului C++11).

### Țintele principale

- **all**: Aceasta este ținta principală care generează executabilul `Game.exe`.
  
### Regulile de compilare

- **Game.exe**: Se compilează din fișierele obiect generate (`main.o`, `Game.o`, `GameController.o`, `Player.o`, `Table.o`, `Cell.o`).
- **main.o**: Se compilează din `main.cpp`, având nevoie de fișierele de antet relevante.
- **Game.o**: Se compilează din `Game.cpp`, având nevoie de fișierele de antet relevante.
- **GameController.o**: Se compilează din `GameController.cpp`, având nevoie de fișierele de antet relevante.
- **Player.o**: Se compilează din `Player.cpp`, având nevoie de fișierele de antet relevante.
- **Table.o**: Se compilează din `Table.cpp`, având nevoie de fișierele de antet relevante.
- **Cell.o**: Se compilează din `Cell.cpp`, având nevoie de fișierele de antet relevante.

### Curățare

- **clean**: Această regulă șterge toate fișierele obiect generate și executabilul `Game.exe`, facilitând o recompilare curată a proiectului.