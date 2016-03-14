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
