#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct jatekos {
	string nev;
	int gol;
	int ido;
};

int main() {
	setlocale(LC_ALL, "Hungarian");
	srand(time(NULL));

	jatekos csap[12];
	int ossz = 0, jatekos = 0, lottek = 0;

	do {
		cout << "Adja meg a jatekosok szamat (5-12): ";
		cin >> jatekos;

		if (jatekos < 5 || jatekos > 12)
			cout << "Nem megfelelo letszam (5-12)!\n";

	} while (jatekos < 5 || jatekos > 12);

	cin.ignore();

	for (int i = 0; i < jatekos; i++)
	{
		cout << "Adja meg az " << i + 1
			<< ". jatekos nevet: ";

		getline(cin, csap[i].nev);

		csap[i].ido = rand() % 61;

		do {
			cout << "Adja meg a jatekos goljainak szamat: ";
			cin >> csap[i].gol;

			if (csap[i].gol < 0 || csap[i].gol > 5)
				cout << "Nem megfelelo golszam (0-5)!\n";

		} while (csap[i].gol < 0 || csap[i].gol > 5);

		cin.ignore();
	}

	system("cls"); // képernyőtörlés

	cout.setf(ios::left);

	int max = 0;

	for (int i = 0; i < jatekos; i++)
	{
		cout << i + 1 << ". "
			<< setw(25) << csap[i].nev
			<< "\t" << csap[i].ido << " perc\t"
			<< csap[i].gol << " gol\n";

		ossz += csap[i].gol;

		if (csap[i].gol > 0)
			lottek++;

		if (csap[i].ido > csap[max].ido)
			max = i;
	}

	cout << endl;

	cout << "\nAz ossz gol: " << ossz << endl;

	cout << lottek
		<< " jatekos lott golt a merkozesen.\n";

	cout << csap[max].nev
		<< " jatszott a legtobbet, ezalatt "
		<< csap[max].gol << " golt lott.\n";

	cout << "A kovetkezo jatekosok jatszottak legalabb 20 percet:\n";

	for (int i = 0; i < jatekos; i++)
	{
		if (csap[i].ido >= 20)
		{
			cout << csap[i].nev << " - "
				<< csap[i].ido << " perc\n";
		}
	}

	return 0;
}