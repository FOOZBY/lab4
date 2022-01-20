#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Node
{
	Node* pNext;
	string data;
	string name, faculty, cafedra, group, stud_id, dob, tel_num, email;
	string temparr[8];
	Node(string data = string(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
		int i = 0;
		char* pch = strtok(&data[0], ";");
		while (pch != NULL)                         // пока есть лексемы
		{
			temparr[i] = pch;
			pch = strtok(NULL, ";");
			i++;
		}
		this->name = this->temparr[0];
		this->faculty = this->temparr[1];
		this->cafedra = this->temparr[2];
		this->group = this->temparr[3];
		this->stud_id = this->temparr[4];
		this->dob = this->temparr[5];
		this->tel_num = this->temparr[6];
		this->email = this->temparr[7];
	}
};

struct List
{
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(string data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	string& operator[](int index);

	//добавление элемента в начало списка
	void push_front(string data = "name");

	//добавление элемента в список по указанному индексу
	void insert(string data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

	//отображение списка
	void showlist();

	//сортировка списка
	void sort(string type);

	void show1elem(int index);

private:
	int Size;
	Node* head;
};

List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

void List::pop_front()
{
	Node* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::push_back(string data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}

void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}

string& List::operator[](int index)
{
	int counter = 0;
	if (index < 0)
		index = 0;
	if (index > Size)
		index = Size - 1;
	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

void List::push_front(string data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(string data, int index)
{
	if (index < 1)
		push_front(data);
	else if (index > Size - 1)
		push_back(data);
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		Node* newNode = new Node(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

void List::removeAt(int index)
{
	if (index < 0 || index >= this->GetSize())
	{
		cout << "Not found\n";
		return;
	}
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

void List::pop_back()
{
	removeAt(Size - 1);
}

void List::showlist()
{
	{
		Node* current = head;
		int i = 0;
		while (current != nullptr)
		{
			cout << i << ")\n";
			cout << "Имя: " << setw(35) << current->name << endl;
			cout << "Факультет: " << setw(29) << current->faculty << endl;
			cout << "Кафедра: " << setw(31) << current->cafedra << endl;
			cout << "Группа: " << setw(32) << current->group << endl;
			cout << "Номер студ. билета: " << setw(20) << current->stud_id << endl;
			cout << "Дата рождения: " << setw(25) << current->dob << endl;
			cout << "Телефон: " << setw(31) << current->tel_num << endl;
			cout << "Эл. почта: " << setw(29) << current->email << endl << endl;
			current = current->pNext;
			i++;
		}
	}
	system("pause");
}

void List::sort(string type = "name")
{
	Node* a, * b, * p, * h = NULL;

	for (Node* i = head; i != NULL; ) {
		a = i;
		i = i->pNext;
		b = h;
		p = NULL;
		if (type == "name")//type == name
			for (p = NULL; (b != NULL) && (a->name > b->name); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "faculty")
			for (p = NULL; (b != NULL) && (a->faculty > b->faculty); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "cafedra")
			for (p = NULL; (b != NULL) && (a->cafedra > b->cafedra); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "group")
			for (p = NULL; (b != NULL) && (a->group > b->group); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "stud_id")
			for (p = NULL; (b != NULL) && (a->stud_id > b->stud_id); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "dob")
			for (p = NULL; (b != NULL) && (a->dob > b->dob); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "tel_num")
			for (p = NULL; (b != NULL) && (a->tel_num > b->tel_num); )
			{
				p = b;
				b = b->pNext;
			}
		if (type == "email")
			for (p = NULL; (b != NULL) && (a->email > b->email); )
			{
				p = b;
				b = b->pNext;
			}

		if (p == NULL)
		{
			a->pNext = h;
			h = a;
		}
		else 
		{
			a->pNext = b;
			p->pNext = a;
		}
	}
	if (h != NULL)
		head = h;
}

inline void List::show1elem(int index)
{
	Node* current = head;
	int count = 0;
	if (index < 0 || index > this->GetSize() - 1)
	{
		cout << "Not found\n";
		system("pause");
		return;
	}
	while (current != nullptr)
	{
		if (index == count)
		{
			cout << "Имя: " << setw(35) << current->name << endl;
			cout << "Факультет: " << setw(29) << current->faculty << endl;
			cout << "Кафедра: " << setw(31) << current->cafedra << endl;
			cout << "Группа: " << setw(32) << current->group << endl;
			cout << "Номер студ. билета: " << setw(20) << current->stud_id << endl;
			cout << "Дата рождения: " << setw(25) << current->dob << endl;
			cout << "Телефон: " << setw(31) << current->tel_num << endl;
			cout << "Эл. почта: " << setw(29) << current->email << endl << endl;
			system("pause");
			return;
		}
		count++;
		current = current->pNext;
	}
}

void load_from_file(List& lst)
{
	cout << "Введите название файла или укажите путь к нему: ";
	string prim_file, line, temp;
	while (true)
	{
		getline(cin, prim_file);
		ifstream in;
		in.open(prim_file);
		if (in.is_open())
		{
			while (!in.eof())
			{
				getline(in, line);
				if (line != "")
				{
					lst.push_back(line);
				}
			}
			break;
		}
		else
		{
			cout << "Неправильно указано имя файла или путь к файлу." << endl;
			cout << "Введите заново" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			system("cls");
		}
		cin.seekg(0, ios::end);
		cin.clear();
		in.close();
	}
}

void savetofile(List& lst)
{
	ofstream out;
	string file_name, temp;
	cout << "Ведите назавание файла: ";
	getline(cin, file_name);
	out.open(file_name);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		if (i != lst.GetSize())
			out << lst[i] << "\n";
		else
			out << lst[i];
	}
	out.close();
	cout << "Файл сохранён\n";
	system("pause");
}

string manual_data_input()
{
	string data = "", temp;
	cout << "Введите имя студента\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите название факультета\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите название кафедры\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите номер группы\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите номер студ. билета\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите дату рождения\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите номер телефона\n";
	getline(cin, temp); data += temp += ";";
	cout << "Введите адрес электронной почты\n";
	getline(cin, temp); data += temp += ";";
	return data;
}

void MENU1(List& lst)//добавление элемента в список
{
	string temp;
	cout << "Введите индекс места, куда хотите вставить элемент: ";
	getline(cin, temp);
	lst.insert(manual_data_input(), stoi(temp));
}

void MENU4(List& lst)
{
	string index;
	cout << "Введите индекс элемента, который хотите удалить: ";
	getline(cin, index);
	lst.removeAt(stoi(index));
}

void MENU5(List& lst)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	string name = "Имя\n";
	string faculty = "Факультет\n";
	string cafedra = "Кафедра\n";
	string group = "Группа\n";
	string stud_id = "Студ. билет\n";
	string dob = "Дата рождения\n";
	string tel_num = "Номер телефона\n";
	string email = "Почта\n";
	int k = 0;
	while (true)
	{
		switch (k)
		{
		case 0:
			SetConsoleTextAttribute(handle, 14);
			cout << name;
			SetConsoleTextAttribute(handle, 7);
			cout << faculty;
			cout << cafedra;
			cout << group;
			cout << stud_id;
			cout << dob;
			cout << tel_num;
			cout << email;
			break;
		case 1:
			cout << name;
			SetConsoleTextAttribute(handle, 14);
			cout << faculty;
			SetConsoleTextAttribute(handle, 7);
			cout << cafedra;
			cout << group;
			cout << stud_id;
			cout << dob;
			cout << tel_num;
			cout << email;
			break;
		case 2:
			cout << name;
			cout << faculty;
			SetConsoleTextAttribute(handle, 14);
			cout << cafedra;
			SetConsoleTextAttribute(handle, 7);
			cout << group;
			cout << stud_id;
			cout << dob;
			cout << tel_num;
			cout << email;
			break;
		case 3:
			cout << name;
			cout << faculty;
			cout << cafedra;
			SetConsoleTextAttribute(handle, 14);
			cout << group;
			SetConsoleTextAttribute(handle, 7);
			cout << stud_id;
			cout << dob;
			cout << tel_num;
			cout << email;
			break;
		case 4:
			cout << name;
			cout << faculty;
			cout << cafedra;
			cout << group;
			SetConsoleTextAttribute(handle, 14);
			cout << stud_id;
			SetConsoleTextAttribute(handle, 7);
			cout << dob;
			cout << tel_num;
			cout << email;
			break;
		case 5:
			cout << name;
			cout << faculty;
			cout << cafedra;
			cout << group;
			cout << stud_id;
			SetConsoleTextAttribute(handle, 14);
			cout << dob;
			SetConsoleTextAttribute(handle, 7);
			cout << tel_num;
			cout << email;
			break;
		case 6:
			cout << name;
			cout << faculty;
			cout << cafedra;
			cout << group;
			cout << stud_id;
			cout << dob;
			SetConsoleTextAttribute(handle, 14);
			cout << tel_num;
			SetConsoleTextAttribute(handle, 7);
			cout << email;
			break;
		case 7:
			cout << name;
			cout << faculty;
			cout << cafedra;
			cout << group;
			cout << stud_id;
			cout << dob;
			cout << tel_num;
			SetConsoleTextAttribute(handle, 14);
			cout << email;
			SetConsoleTextAttribute(handle, 7);
			break;
		}
		int f;
		while (true)
		{
			f = _getch();
			if (f == 13)
			{
				system("cls");
				switch (k)
				{
				case 0:
					lst.sort("name");
					break;
				case 1:
					lst.sort("faculty");
					break;
				case 2:
					lst.sort("cafedra");
					break;
				case 3:
					lst.sort("group");
					break;
				case 4:
					lst.sort("stud_id");
					break;
				case 5:
					lst.sort("dob");
					break;
				case 6:
					lst.sort("tel_num");
					break;
				case 7:
					lst.sort("email");
					break;
				}
				break;
			}
			else if (f == 72)
			{
				k--;
				break;
			}
			else if (f == 80)
			{
				k++;
				break;
			}
			else if (f == 27)
				break;
		}
		if (f == 27)
			break;
		if (k < 0)
			k = 7;
		if (k > 7)
			k = 0;
		system("cls");
	}
}

void MENU6(List& lst)
{
	string temp;
	cout << "Введите номер элемента, информацию о котором хотите увидеть: ";
	getline(cin, temp);
	lst.show1elem(stoi(temp));
}

void MENU7(List& lst)
{
	string temp;
	cout << "Введите номер элемента, информацию о котором хотите изменить: ";
	getline(cin, temp);
	cout << "Данные о редактируемом элементе: \n";
	lst.show1elem(stoi(temp));
	lst.removeAt(stoi(temp));
	lst.insert(manual_data_input(), stoi(temp));
}
