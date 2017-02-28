/* Autor: Bartłomiej Romanek      */
/* Tytuł: Wzorzec "Strategia"     */
/* Licencja: Licencja MIT         */
/* Data modyfikacji: 28.02.2017   */

<?php

	class Ekran {
		public function Wyswietl($napis) {
			echo $napis . "\n";
		}
	};

	class Plik {
		public function Zapisz($napis) {
			$plik = fopen('output.txt', 'w');
			fwrite($plik, $napis);
			fclose($plik);
		}
	};

	class Strategia {
		public function Zachowaj($napis) {
			if ($this->preferencja == "ekran") {
				$display1 = new Ekran();
				$display1->Wyswietl($napis);
			}
			else if ($this->preferencja == "plik") {
				$file1 = new Plik();
				$file1->Zapisz($napis);
			}
			else {
				echo "Nie ustawiono strategii! \n";
			}	
		}
		public function Ustaw($opcja) {
			$this->preferencja = $opcja;
		}
		private $preferencja;
	};

	$strategy1 = new Strategia();
	$strategy1->Zachowaj("Bon na 10zl do Tesco: AH4S-C8H5-09NN");
	$strategy1->Ustaw("ekran");
	$strategy1->Zachowaj("Bon na 20zl do Tesco: AH4S-C8H5-09NN");
	$strategy1->Ustaw("plik");
	$strategy1->Zachowaj("Bon na 50zl do Tesco: AH4S-C8H5-09NN");

?>

// Opis kodu: Klasa "Strategia" posiada metodę "Zachowaj", która umożliwia przechowywanie napisu. W zależności od wybranej strategii 
// przez użytkownika (którą wybiera za pomocą metody "Ustaw"), zapis napisu wykonywany jest albo na ekran, albo do pliku.
