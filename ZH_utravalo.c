// Importálás
#include <stdio.h> // Alapból kell importálni
#include <time.h> // Pszeudo véletlenszám generáláshoz szükséges
#include <string.h> // Stringekkel való műveletekhez
#include <math.h> // Matematikai műveletek => Kerekítés (ceil(double x) -> felfele, floor(double x) -> lefele), hatványozás (pow(double alap, double kitevo)), abszolútérték (abs(double x))
#include <stdlib.h> // Pszeudo véletlenszám generáláshoz (srand(unsigned int seed))
                    // Konvertálás (atoi(char *str) -> int-té, atof(char *str) -> float-tá)

// Makrók
#define MAKRO_NEV 123 // Makró deklarálás, olyan mint a globális változók, csak azokat TILOS használni (vszeg) ZH-ban, de ezt írni fogják
#define VALAMI "asd"  // Ezeknek nem kell megadni a típusát, csak a nevét nagy betűkkel és az értéket amit tárolnak.
#define VALAMI_2 0.5  // Értékük statikus, nem megváltoztatható. Compileoláskor minden helyre ahova beírtad, kicseréli a nevet az értékére.
#define HEIGHT 10
#define WIDTH 10

// Függvény deklarálás
void ValamiFunction1();   // Úgy szeretik ha ide az elejére a függvény szignatúráját beírod, majd a forráskód végére, a main után implementálod.
int ValamiFunction2();    // Figyelj arra hogy változóknak véletlen se legyen ugyanaz a neve mint egy függvénynek! Compile hibát dob különben.
int * ValamiFunction3();  // Így adsz vissza int tömböt, nem valószínű, hogy kell használni, általában voidot kell a változó átadós részben ki van fejtve miért.
char ValamiFunction4();
char * ValamiFunction5(); // Így adsz stringeket vissza, nem valószínű, hogy kell használni, általában voidot kell.

// Változók átadása függvényeknek (fv-nek rövidítem innentől)    -->     Alul példaként deklarálom őket!!
void SimaValtozoPelda(int xd, char prank, float f); // Más fv-ekben újra lehet használni ugyanazt a változó nevet, lokális.
void TombPelda(int xd[], char charTomb[]); // Így adsz a függvényednek egy tömböt
void MatrixPelda(int m1[HEIGHT][WIDTH], char m2[][WIDTH]); // Ilyenkor meg kell adni legalább az "oszlopok" számát, el lehet hagyni a "sorokét"
        // FIGYELJ arra, hogy ha main előtt deklarálsz fv-t akkor mindegyik sor végére kell ';'  !!!
        // FIGYELJ arra, hogy a sima változók értékai vannak csak átadva az adott fv-nek, viszont a tömbök és mátrixok referencia szerint vannak átadva,
        // ami azt jelenti, hogy ha az adott fv-ben megváltoztatod a tömböt/mátrixot, akkor ahol deklaráltad a tömböt/mátrixot megváltozik az is, 
        // míg a sima változók nem változnak meg.


// !!!FONTOS!!! Általános tippek:
//  - Kerüld az undefined behaviouroket, mert pontlevonással jár, ez a mondhatni megjósolhatatlan viselkedéseket takarja (pl. túlindexelés, 0-val való osztás, stb.)
//  - Kerüld a globális változókat
//  - Compileoláskor néha használj -W -Wall -Wextra flageket, hogy lássad van-e amire sikít a compiler, lehet lesznek érte pontlevonások, DE
//      NE szánj rá sok időt, CSAK ha kész vagy nem éri meg vele bajlódni!!!
//  - Legyen több mentésed minden esetre ha egyiket elrontod, akkor vissza tudj menni az előzőre + ha már kezd nagyon lejárni az idő + véletlen törlés esetére
//      Ezen mentések közt legyen legalább egy amit le tud compileolni a GCC!!! Különben ZH = 0 pont
//  - Ha szegmentálási hibát dob és barátait akkor érdemes túlindexelésre gondolni, ha nem találod hol hibáztál, akkor a legegyszerűbb main elejéről
//
// VS Codeos shotcutok:
//  - Ctrl + LeftAlt + nyilak(fel/le) => Többszörös kurzorozás, több sorba tudsz ugyanoda írni, kibaszott black magic
//  - Ctrl + Shift + L => Kijelölt szöveg minden előfordulásának kijelölése.
//  - Ctrl + D => Kijelölt szöveg következő előfordulásának kijelölése, ahányszor megnyomod. Ez meg előtti tippel gyorsan lehet replacelni.
//
//// Sok szerencsét, kéz és láb törést, sikeres ZH-t!
int main()
{
    // Változók
    int a = 10;
    float b = 10.123;
    char c = 'a';
    double d = 10.123456789;

    // Pointerek, pointer aritmetikát kihagyom úgysem kell vszeg használni.
    int *p; // Pointer deklarálása, a * azt jelenti, hogy pointer, a p pedig a változó neve, amire mutatni fog.
    p = &a; // A pointer mostmár az 'a' nevű int típusú változóra mutat. Lehet deklaráláshoz is írni, tökre mind1.
    *p = 5; // Értékadás a pointeren keresztül, azaz az 'a' változó értéke 5 lesz.

    char humor[21]; // Stringekhez, ezesetben 20 karaktert illik ide beolvasni, mert a 21. a \0, ami a string végét jelzi.

    int tomb1[10]; // Itt inicializálatlan a tömb, random memória szemetet tartalmaz az összes eleme, ha kérik a feladatban, akkor ciklus(okk)al töltsd fel külön a kért értékkel. 
    float tomb2[3] = {0.5, 1.2, 123.123}; // Így is lehet inicializálni
    int tomb3[10] = {0}; // Itt a lényeg a jobb oldalt van, tömböknél lehet egy elemet megadva inicializálni az összes elemét arra. char, float tömb esetén is működik

    // Kiírások (változókhoz)
    printf("1. Kiiras: %d %f %s %c\n", a, 0.5, "asd", 'a'); // A %d -> int, %f -> float, %s -> string, %c -> char
    char valamiStr[] = "bohocemoji";
    printf("2. Kiiras: %s\n", valamiStr); // Ha char *-od van ami a char[]-re mutat akkor ugyanígy csak odaírod a változó nevét.

    // Beolvasások
    char bekertStr[11];
    fgets(bekertStr, 11, stdin); // Beolvas 10 karaktert, a 11. helyre a '\0'-t teszi, stdin-ről olvas, ez a billentyűzetet jelenti.
    int bekertInt;
    float bekertFloat;
    char bekertChar;
    scanf("%d %f %c", &bekertInt, &bekertFloat, &bekertChar); // A & jelentése, hogy a változó memóriacímére fog beolvasni. !!!!Első whitespace-ig olvas!!!!
    // Példa tőlünk ZH-ból, karakterenkénti beolvasás, amíg nem kap enter-t. Ezzel egy sorba több karaktert is megadhatunk és csak a kért karakterekre futtatja a kódunkat, '\n'-t ignorálja 
    char c;
    while (c != EOF) // End-of-File-ig olvas lehet ezt fogja kérni a feladat, ha End-of-Line kér akkor helyette EOL
    {
        c = getchar(); // Beolvas 1 karaktert
        if (c != 10 && (c == 'a' || c == 's' || c == 'w' || c == 'd')) // Lehet '' jelek közti char összehasonlítani (""-et használva sose hasonlíts össze, arra
        {                                                              // van az strcmp(), lentebb kifejtettem) és lehet ascii kóddal is, btw a 10 az a '\n'.
            printf("Karakter: %c\tAscii kodja:%d", c, c);
        }
    }
    

    // Random szám generálás
    time_t t;
    srand((unsigned) time(&t));
    int randomNum = rand() % 1000; // 0 és 999 között generál egy random számot

    // Stringekkel való műveletek
    char str1[] = "teststring";
    char str2[] = "teststringasd";

    printf("strcmp: %d\n", strcmp(str1, str2)); // Stringek összehasonlítása, ha egyenlőek akkor 0-t ad vissza, ha nem akkor nem 0-t. Ha a 2. string hosszabb, akkor -1-et 
                                                // ad vissza, ha rövidebb akkor 1-et.
    printf("strlen: %d\n", strlen(str1)); // String hosszát adja vissza, a \0-t nem számolja bele.
    printf("strchr: %s\n", strchr(str1, 's')); // Megkeresi az első előfordulását a karakternek a stringben, és visszaadja a karaktertől kezdve a stringet.
    printf("strtok: %s\n", strtok(str1, "s")); // Megadott string alapján (második param) darabolja fel a stringet, és visszaadja az első. Ha a második param NULL, akkor a 
                                               // következő darabot adja vissza. Ahhoz hogy megkapd a kövi darabot, újra kell hívni a fv-t, de már NULL-al "s" helyett.
    printf("strcpy: %s\n", strcpy(str1, str2)); // str1-be bemásolja str2-t, és visszaadja str1-et.

    return 0;
}

void MatrixPelda(int m1[HEIGHT][WIDTH], char m2[][WIDTH])
{
    static int valami = 0; // Első alkalommal amikor megvan hívva az fv, 0-val inicializálódik a valami nevű változó, de utánna minden fv hívásnál a visszatérés pillanatában
    valami++;              // való értékét őrzi meg, és a következő fv hívásnál már az új értékkel fog indulni. pl.: 1. fv hívásnál 0, 2. fv hívásnál 1, 3. fv hívásnál 2, stb.


    return; // Voidnál is kiteheted, de nem kötelező
}
