#include <iostream>
using namespace std;

// skrótowo, to idea programu jest taka - najpierw szukamy najd³u¿szego ci¹gu rosn¹cego, a potem malej¹cego, a dziêki odpowiednio napisanym warunkom robimy to w jednym przejœciu pêtli. Dok³adny opis zawarty jest w komentarzach w pêtli
int main() {
    int N = 10; // oczywiœcie tu mo¿e byæ cokolwiek
    int tab[N];
    for(int i=0; i<N; i++) cin >> tab[i];

    int increasing_max_length = 1, decreasing_max_length = 1;
    int current_length = 1; // d³ugoœæ aktualnie rozpatrywanego ci¹gu, bêdziemy jej u¿ywaæ w pêtli
    int current_difference; // ró¿nica aktualnie rozpatrywanego ci¹gu arytmetycznego
    // oczywiœcie obie pêtle mo¿na zrealizowaæ w jednej (trzeba tylko u¿yæ paru dodatkowych zmiennych), ale dla czytelnoœci kodu zapisa³em to w osobnych
    // znajdŸmy najd³u¿szy ci¹g rosn¹cy
    current_difference = -1; // jakakolwiek wartoœæ ujemna, odró¿niamy w ten sposób ci¹g ujemny
    for(int i=1; i<N; i++) {
        if(tab[i] > tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podci¹gu, bo poprzedni siê zakoñczy³ z powodu wyst¹pienia ciagu malej¹cego / dopiero rozpoczêliœmy program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz¹ce nowy ci¹g
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference > 0){ // jeœli podci¹g dalej roœnie o ró¿nicê arytmetyczn¹ oraz ró¿nica ta jest dodatnia
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] > tab[i-1]) { // je¿eli kolejny element ma inn¹ ró¿nicê, ale jest wiêkszy od poprzedniego, to rozpoczynamy nowy ci¹g rosn¹cy
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz¹ce nowy podci¹g
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ci¹g malej¹cy. Jako nastêpnego wywo³amy pierwszego if'a (albo znów tego elsa, je¿eli nastêpny element dalej bêdzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podci¹gu
            current_difference = -1;
        }

        if(current_length > increasing_max_length) increasing_max_length = current_length; // je¿eli aktualna d³ugoœæ jest wiêksza od dotychczasowej maksymalnej, to update'ujemy maksymaln¹
        // poni¿ej cout wypisuje nam krok po kroku co siê dzieje ze zmiennymi w tej pêtli, mo¿esz go sobie odkomentowaæ aby to przeœledziæ. Zwróæ uwagê na to, ¿e wypisuje on aktualne wartoœci po zakoñczeniu danego obiegu pêtli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << increasing_max_length << endl;
    }

    // znajdŸmy najd³u¿szy ci¹g rosn¹cy
    current_difference = 1; // jakakolwiek wartoœæ dodatnia
    current_length = 1;
    for(int i=1; i<N; i++) {
        if(tab[i] < tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podci¹gu, bo poprzedni siê zakoñczy³ z powodu wyst¹pienia ciagu malej¹cego / dopiero rozpoczêliœmy program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz¹ce nowy ci¹g
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference < 0){ // jeœli podci¹g dalej maleje o ró¿nicê arytmetyczn¹ (mówi¹c œciœlej - malejê o jej wartoœæ bezwglêdn¹ jej ró¿nicy) oraz ró¿nica ta jest ujemna
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] < tab[i-1]) { // je¿eli kolejny element ma inn¹ ró¿nicê, ale jest mniejszy od poprzedniego, to rozpoczynamy nowy ci¹g malej¹cy
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz¹ce nowy podci¹g
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ci¹g malej¹cy. Jako nastêpnego wywo³amy pierwszego if'a (albo znów tego elsa, je¿eli nastêpny element dalej bêdzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podci¹gu
            current_difference = 1;
        }

        if(current_length > decreasing_max_length) decreasing_max_length = current_length; // je¿eli aktualna d³ugoœæ jest wiêksza od dotychczasowej maksymalnej, to update'ujemy maksymaln¹
        // poni¿ej cout wypisuje nam krok po kroku co siê dzieje ze zmiennymi w tej pêtli, mo¿esz go sobie odkomentowaæ aby to przeœledziæ. Zwróæ uwagê na to, ¿e wypisuje on aktualne wartoœci po zakoñczeniu danego obiegu pêtli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << decreasing_max_length << endl;
    }

    cout << "increasing_max_length = " << increasing_max_length << ", decreasing_max_length = " << decreasing_max_length << endl;
    cout << increasing_max_length - decreasing_max_length << endl;

    return 0;
}
