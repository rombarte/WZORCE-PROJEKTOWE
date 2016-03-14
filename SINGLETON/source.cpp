/* Autor: Bartłomiej Romanek          */
/* Tytuł: Wzorzec Singleton           */
/* Licencja: Licencja MIT             */
/* Data modyfikacji: 14.03.2016       */

#include <iostream>

class Singleton {
	public:
		static Singleton & Wykorzystaj() {
			static Singleton Obiekt;
			std::cout << "Operacja: Wykorzystaj" << std::endl;
			return Obiekt;
		}
		void Zarejestruj() {
			std::cout << "Operacja: Zarejestruj" << std::endl;
		}	
	private:
		Singleton() {
			std::cout << "Operacja: Konstruktor" << std::endl;
		}
		~Singleton() {
			std::cout << "Operacja: Destruktor" << std::endl;
		}
};

int main(){
	Singleton::Wykorzystaj();
	Singleton::Wykorzystaj().Zarejestruj();
	Singleton::Wykorzystaj();
}

// Opis kodu: Klasa Singleton pozwala na utworzenie wyłącznie jednego egzemplarza klasy w trakcie działania programu.
// Obiekt ten jest tworzony przy pierwszej próbie użycia.
