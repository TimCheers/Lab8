#include <iostream>
#include<string>
using namespace std;

struct Student
{
	void Show()
	{
		cout << famil << name << endl << adres << endl << dat1 <<"."<< dat2 << "." << dat3 << endl << reiting << endl;
	}
	string name, adres, famil;
	int dat1, dat2, dat3, reiting;
};


void CorNumb(Student*& st, int N, int k)
{
	system("chcp 1251>nul");
	int  dat01 = -1, dat02 = -1, dat03 = -1, reiting1 = -1;
	for (int i = k; i < N; i++)
	{
		cout << "Введите ФИО:\t";
		cin >> st[i].famil; getline(cin, st[i].name);
		cout << "Введите адрес:\t";
		getline(cin, st[i].adres);
		cout << "Введите дату рождения:\n";
		while ((dat01 <= 0 || dat01 >= 30) && (dat02 <= 0 || dat02 >= 12) && (dat03 <= 0 || dat03 < 1950))
		{
			cout << "День:\t"; cin >> dat01;
			cout << "Месяц:\t"; cin >> dat02;
			cout << "Год:\t"; cin >> dat03;
			if ((dat01 <= 0 || dat01 > 30) && (dat02 <= 0 || dat02 >= 12) && (dat03 <= 0 || dat03 < 1950))
			{
				cout << "Введены некоректные данные! Введите дату рождения заново!" << endl;
			}
			st[i].dat1 = dat01;
			st[i].dat2 = dat02;
			st[i].dat3 = dat03;
		}
		while (st[i].reiting < 0)
		{
			cout << "Введите рейтинг:\t";
			cin >> reiting1;
			if (reiting1 < 0)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			st[i].reiting = reiting1;
		}
		dat01 = -1;
		dat02 = -1;
		dat03 = -1;
		reiting1 = -1;
	}
}
void CorNumb2(Student*& st2, int N, int k)
{
	system("chcp 1251>nul");
	int  dat01 = -1, dat02 = -1, dat03 = -1, reiting1 = -1;
	for (int i = k; i < N; i++)
	{
		cout << "Введите ФИО:\t";
		cin >> st2[i].famil; getline(cin, st2[i].name);
		cout << "Введите адрес:\t";
		getline(cin, st2[i].adres);
		cout << "Введите дату рождения:\n";
		while ((dat01 <= 0 || dat01 >= 30) && (dat02 <= 0 || dat02 >= 12) && (dat03 <= 0 || dat03 < 1950))
		{
			cout << "День:\t"; cin >> dat01;
			cout << "Месяц:\t"; cin >> dat02;
			cout << "Год:\t"; cin >> dat03;
			if ((dat01 <= 0 || dat01 > 30) && (dat02 <= 0 || dat02 >= 12) && (dat03 <= 0 || dat03 < 1950))
			{
				cout << "Введены некоректные данные! Введите дату рождения заново!" << endl;
			}
			st2[i].dat1 = dat01;
			st2[i].dat2 = dat02;
			st2[i].dat3 = dat03;
		}
		while (st2[i].reiting < 0)
		{
			cout << "Введите рейтинг:\t";
			cin >> reiting1;
			if (reiting1 < 0)
			{
				cout << "Введены некоректные данные!" << endl;
			}
			st2[i].reiting = reiting1;
		}
		dat01 = -1;
		dat02 = -1;
		dat03 = -1;
		reiting1 = -1;
	}
}
int main()
{
	system("chcp 1251>nul");
	int N = -1;
	while (N <= 0)
	{
		cout << "Введите количество студентов";
		cin >> N;
	}
	Student* st = new Student[N];
	CorNumb(st, N, 0);
	/////////////////////////УДАЛЕНИЕ///////////////////////////////////
	for (int i = 0; i < N; i++)
	{
		int f = 0;
		bool day = 0, month = 0, ear = 0;
		for (int j = i+1; j < N; j++)
		{
			if (st[i].dat1==st[j].dat1)
			{
				day = true;
			}
			if (st[i].dat2 == st[j].dat2)
			{
				month = true;
			}
			if (st[i].dat3 == st[j].dat3)
			{
				ear = true;
			}
			if (day==true && month==true && ear==true)
			{
				f++;
				for (int l = j; l < N-1; l++)
				{
					st[l].dat1 = st[l + 1].dat1;
					st[l].dat2 = st[l + 1].dat2;
					st[l].dat3 = st[l + 1].dat3;
					st[l].adres = st[l + 1].adres;
					st[l].famil = st[l + 1].famil;
					st[l].name = st[l + 1].name;
					st[l].reiting = st[l + 1].reiting;
				}
				N--;
			}
		}
		if (f>0)
		{
			for (int l = i; l < N-1; l++)
			{
				st[l].dat1 = st[l + 1].dat1;
				st[l].dat2 = st[l + 1].dat2;
				st[l].dat3 = st[l + 1].dat3;
				st[l].adres = st[l + 1].adres;
				st[l].famil = st[l + 1].famil;
				st[l].name = st[l + 1].name;
				st[l].reiting = st[l + 1].reiting;
			}
			N--;
		}
	}

	////////////////////////////ДОБАВЛЕНИЕ///////////////////////////////////////
	string Sname;
	cout << "Введите фамилию нужную";
	cin >> Sname;
	Student *st2=new Student[N+1];
	Student Obj;
	cout << "Введите параметры нвого чела" << endl;
	for (int i = 0; i < N; i++)
	{
		if (st[i].famil==Sname)
		{
			for (int j = 0; j < i; j++)
			{
				st2[j].dat1 = st[j].dat1;
				st2[j].dat2 = st[j].dat2;
				st2[j].dat3 = st[j].dat3;
				st2[j].adres = st[j].adres;
				st2[j].famil = st[j].famil;
				st2[j].name = st[j].name;
				st2[j].reiting = st[j].reiting;
			}
			CorNumb2(st2, i+1, i);
			for (int j = i+1; j < N+1; j++)
			{
				st2[j] = st[j - 1];
			}
			i = N;
		}
	}
	///////////////////////////////////////////////////////////////////////////////

	
	cout << endl << endl;
	for (int i = 0; i < N+1; i++)
	{
		st2[i].Show();
	}
	return 0;
}
