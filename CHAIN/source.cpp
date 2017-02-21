/* Autor: Bartłomiej Romanek                  */
/* Tytuł: Wzorzec "Łańcuch odpowiedzialności" */
/* Licencja: Licencja MIT                     */
/* Data modyfikacji: 21.02.2017               */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ekran {
	public:
		int Wyswietl(string & napis) {
			cout << napis << endl;
			return 0;
		}
};

class Plik {
	public:
		int Zapisz(string & napis) {
			ofstream plik("output.txt", ifstream::out);
			if (!plik.good()) {
				return 1;
			}
			plik << napis;
			plik.close();
			return 0;
		}
};

class Lancuch {
	public:
		void Zachowaj(string napis) {
        		preferencja = 0;
        		if (preferencja == 0) {
            			Plik file1;
            			preferencja = file1.Zapisz(napis);
             		}
             		if (preferencja == 1) {
    				Ekran display1;
    				preferencja = display1.Wyswietl(napis);
    			}	
		}
		
	private:
		int preferencja;
};

int main(){
	Lancuch strategy1;
	strategy1.Zachowaj("Bon na 10zl do Tesco: AH4S-C8H5-09NN");
	system("pause");
}

// Opis kodu: Klasa "Łancuch" posiada metodę "Zachowaj", która umożliwia zapis napisu do pliku. Jeżeli to się nie uda, 
// następuje próba wykonania operacji zastępczej: wypisanie napisu na ekran.
