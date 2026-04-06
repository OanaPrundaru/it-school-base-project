# 📚 Sistem de Gestiune Bibliotecă (Proiect Portofoliu C++)

## 📝 Descrierea Proiectului
Acest proiect reprezintă o aplicație de tip consolă dezvoltată în C++ pentru gestionarea fluxului de activitate dintr-o bibliotecă. Scopul principal este automatizarea procesului de evidență a inventarului de cărți, a membrilor înregistrați și a tranzacțiilor de împrumut/returnare. 

Aplicația pune accent pe utilizarea conceptelor moderne de Programare Orientată pe Obiect (POO) și pe persistența datelor prin utilizarea fișierelor externe, asigurând un sistem stabil și ușor de utilizat pentru personalul bibliotecii.

---

## 🚀 Funcționalități Implementate

### 1. Gestionarea Inventarului
* **Încărcare Automată:** La pornire, aplicația citește datele din `Carti.csv`.
* **Afișare Detaliată:** Listarea tuturor cărților cu detalii despre Titlu, Autor, ISBN și Status (Disponibil/Împrumutat).
* **Căutare:** Identificarea rapidă a unei cărți în inventar pe baza codului ISBN.

### 2. Gestionarea Membrilor
* **Bază de Date Membri:** Evidența persoanelor înregistrate, încărcată din `Membri.csv`.
* **Identificare unică:** Fiecare membru este gestionat printr-un ID numeric unic.

### 3. Logica de Împrumut și Returnare
* **Împrumut:** Proces de legare a unei cărți de un membru. Se verifică disponibilitatea cărții înainte de tranzacție.
* **Calcul Automată Dată Scadentă:** Aplicația calculează automat termenul de returnare la **14 zile** de la data curentă folosind biblioteca `<ctime>`.
* **Returnare:** Schimbarea statusului cărții în "Disponibil" și actualizarea bazei de date.

### 4. Persistența Datelor și Jurnalizare (Audit Log)
* **Actualizare în timp real:** Orice modificare de status este salvată imediat în `Carti.csv`.
* **Istoric Separat:** Toate împrumuturile sunt salvate într-un fișier separat, `Imprumuturi.csv`, creând un jurnal permanent de activitate.

---

## 📸 Screenshot-uri

### Meniul Principal
![<img width="772" height="475" alt="meniu" src="https://github.com/user-attachments/assets/2fb422fc-d0e9-4f17-8d98-4c1ac19f15ee" />
](meniu.png)
*Interfața interactivă de navigare a aplicației.*

### Procesul de Împrumut și Calculul Datei
![<img width="702" height="369" alt="imprumut carte" src="https://github.com/user-attachments/assets/067ac95d-4c8f-4eaf-b62f-8545b76cc3d9" />
](imprumut carte.png)
*Exemplu de împrumut reușit cu afișarea numelui și a datei limită.*

### Lista de Inventar
![<img width="1111" height="716" alt="lista_carti" src="https://github.com/user-attachments/assets/7019c388-76c6-4423-9fc2-b1aaebd67ac0" />
](afisare_istoric_imprumuturi_in_consola.png)
*Afișarea tabelară a cărților folosind formatare precisă.*

### Istoricul Împrumuturilor (Din fișier separat)
![<img width="1268" height="715" alt="afisare_imprumuturi_in_fisier" src="https://github.com/user-attachments/assets/09a3864a-856a-4ed1-81b1-1221be6c96ac" />]
(afisare_istoric_imprumuturi_in_fisier.png)
*Vizualizarea jurnalului de activitate stocat în Imprumuturi.csv.*

### Afișare disponibilitate cărți
![<img width="939" height="596" alt="afisare_in_consola_carti_disponibile" src="https://github.com/user-attachments/assets/2fc4a20c-5ca7-4853-a2a4-7b4e142380bd" />](afisare_in_consola_carti_disponibile.png)
*Vizualizarea în consolă a cărților disponibile.*

### Afișare automata eroare disponibilitate cărți
![<img width="1078" height="676" alt="afisare_eroare_disponibilitate" src="https://github.com/user-attachments/assets/3e694e90-961e-4675-b2c6-d4d3d25ec2df" />]
(afisare_eroare_disponibilitate_carti.png)
*Primirea notificării "Cartea este deja împrumutată!", citind statusul din Carti.csv.*

### Schimbare automat status cărți
![<img width="741" height="853" alt="schimbare_automat_status_carte" src="https://github.com/user-attachments/assets/32153328-0f5f-4fac-8299-4037b0e454f1" />
](schimbare_automat_status_carte.png)
*Vizualizarea în fișierul Carti.csv a statusului 0 sau 1.*

### Afișare lista cărților din bibliotecă
![<img width="1111" height="716" alt="lista_carti" src="https://github.com/user-attachments/assets/b602561d-aed3-40ea-97bc-3723d9227374" />
](lista_carti.png)
*Afișarea în consolă a tuturor cărților din bibliotecă.*

### Afișare lista membrilor
![<img width="520" height="676" alt="lista_persoane" src="https://github.com/user-attachments/assets/d718bf7a-fdce-4e89-af7b-e30bff1906f8" />](lista_persoane.png)
*Afișarea în consolă a tuturor membrilor înscriși în bibliotecă.*



---

## 🛠️ Detalii Tehnice
* **Limbaj:** C++ (Standard 11/14/17).
* **Gestiune Memorie:** `std::unique_ptr` și containere STL (`std::vector`).
* **Format Date:** Comma-Separated Values (CSV).
* **Structura:** Arhitectură modulară (fișiere `.h` și `.cpp` separate).
