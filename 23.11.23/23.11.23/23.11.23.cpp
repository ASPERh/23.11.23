#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct MoveInformation {
	string FilmName[10];
	string Author[10];
	string Genre[10];

	string symbol;
	string cr;
	string gen;
	int Grade[10];
	int userchoice;
};

void data(MoveInformation& s) {
	string filmname[10] = { "Терминатор", "Подводная братва", "По соображениям совести", "Достать ножи", "Спасти Рядового Райана", "Железный человек", "Джентльмены", "Человек-паук", "Люди Икс", "Зеленая миля" };
	string creator[10] = { "Джеймс Кэмерон", "Люк Бессон", "Стэнли Кубрик", "Райан Джонсон", "Стивен Спилберг", "Джон Фавро", "Гай Ричи", "Сэм Рэйми", "Брайан Сингер", "Фрэнк Дарабонт" };
	string genre[10] = { "фантастика", "боевик", "драма", "триллер", "военный", "фантастика", "криминал", "приключения", "фантастика", "драма" };

	for (int i = 0; i < 10; i++)
	{
		s.FilmName[i] = filmname[i];
		s.Author[i] = creator[i];
		s.Genre[i] = genre[i];
		s.Grade[i] = rand() % 10 + 2;
	}
}

void info(MoveInformation& s) {
	for (int i = 0; i < 10; i++)
	{
		cout << s.FilmName[i] << " " << s.Genre[i] << "  Grade: " << s.Grade[i] << "\n";
		cout << s.Author[i] << "\n\n";
	}
}

void search_system(MoveInformation& s)
{
	cout << "Поисковая система" << "\n";
	cout << "1. По названию" << "\n";
	cout << "2. По автору" << "\n";
	cout << "3. По жанру" << "\n";
	cout << "4. По популярности и оценкам" << "\n";
	cin >> s.userchoice;

	switch (s.userchoice)
	{
	case 1:
	{
		cout << "Введите название: ";
		cin.ignore();
		getline(cin, s.symbol);

		for (int i = 0; i < 10; i++)
		{
			if (s.FilmName[i] == s.symbol)
			{
				cout << s.FilmName[i] << " " << s.Genre[i] << "  Оценка: " << s.Grade[i] << "\n";
				cout << s.Author[i] << "\n\n";
			}
		}
		break;
	}
	case 2:
	{
		cout << "Введите автора: ";
		cin.ignore();
		getline(cin, s.cr);

		for (int i = 0; i < 10; i++)
		{
			if (s.FilmName[i] == s.cr)
			{
				cout << s.Author[i] << " " << s.FilmName[i] << " " << s.Genre[i] << "  Оценка: " << s.Grade[i] << "\n";

			}
		}
		break;
	}
	case 3:
	{
		cout << "Введите жанр: ";
		cin.ignore();
		cin >> s.gen;

		for (int i = 0; i < 10; i++)
		{
			if (s.Genre[i] == s.gen)
			{
				cout << s.Genre[i] << " " << s.FilmName[i] << " " << "  Оценка: " << s.Grade << " " << s.Genre[i] << "\n";
				cout << s.Author[i] << "\n\n";
			}
		}
		break;
	}
	case 4:
	{
		cout << " Самые популярные фильмы: " << "\n";
		for (int i = 0; i < 10; i++)
		{
			if (s.Grade[i] >= 10)
			{
				cout << s.FilmName[i] << " " << s.Genre[i] << "  Оценка: " << s.Grade[i] << "\n";
				cout << s.Author[i] << "\n\n";
			}
		}
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	MoveInformation now;
	data(now);
	info(now);
	search_system(now);
}