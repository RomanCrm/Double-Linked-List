#include <iostream>
#include <string.h>

using namespace std;


struct Elemen
{
	int data;
	Elemen *next, *prev;
};

class List
{
	Elemen *Head, *tail;
	int count;

public:
	List();
	List(const List&);
	~List();

	int GetCount();
	Elemen * GetElem(int);

	void DeliteAll();
	void Del(int pos = 0);
	void Insert(int pos = 0);
	void AddTail(int n);
	void AddHeard(int n);
	void Print(int pos);
	List& operator = (const List&);
	List& operator + (const List&);

	bool operator == (const List&);

	bool operator != (const List&);

	bool operator <= (const List&);

	bool operator >= (const List&);

	bool operator < (const List&);

	bool operator > (const List&);

	List& operator - ();
};

List::List()
{
	Head = tail = NULL;
	count = 0;
}

List::List(const List & lis)
{
	Head = tail = NULL;
	count = 0;

	Elemen* temp = lis.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DeliteAll();
}

int List::GetCount()
{
	return count;
}

Elemen * List::GetElem(int pos)
{
	Elemen* elem = Head;

	if (pos<1 || pos>count)
	{
		cout << "ERROR";
		return NULL;
	}

	int i = 0;

	while (i < pos && elem != 0)
	{
		elem = elem->next;
		i++;
	}

	if (elem == 0)
	{
		return NULL;
	}
	else
	{
		return elem;
	}
}

void List::DeliteAll()
{
	while (count != 0)
	{
		Del(1);
	}
}

void List::Del(int pos)
{

	if (pos == 0)
	{
		cout << "ENTER NEW POSITION";
		cin >> pos;
	}

	if (pos < 1 || pos > count)
	{
		cout << "ERROR";
		return;
	}

	int i = 1;

	Elemen* temp = Head;


	while (i<pos)
	{
		temp = temp->next;
		i++;
	}

	Elemen* Tailtemp = temp->prev;
	Elemen* Headtemp = temp->next;


	if (Tailtemp != 0 && count != 1)
	{
		Tailtemp->next = Head;
	}



	if (Headtemp != 0 && count != 1)
	{
		Headtemp->prev = tail;
	}



	if (pos == 1)
	{
		Head = Tailtemp;
	}



	if (pos == count)
	{
		tail = Head;
	}


	delete temp;

	count++;


}

void List::Insert(int pos) //ввод значений
{
	if (pos = 0)
	{
		cout << "¬ведите позицию-->";
		cin >> pos;
	}

	if (pos < 1 || pos > count + 1)
	{
		cout << "ERROR";
		return;
	}

	if (pos == count + 1)
	{
		int data;
		cout << "¬ведите новое значение";
		cin >> data;

		AddTail(data);
		return;
	}
	else
	{
		if (pos == 1)
		{
			int data;
			cout << "¬ведите новое значение";
			cin >> data;

			AddHeard(data);
			return;
		}
	}
	int i = 0;

	Elemen* node = Head;
	while (i < pos)
	{
		node = node->next;
		i++;
	}

	Elemen* Prev = node->prev;

	Elemen*tempNode = new Elemen();

	cout << "¬ведите значение";
	cin >> tempNode->data;

	if (Prev != 0 && count != 1)
	{
		Prev->next = tempNode;
	}
	tempNode->next = node;
	tempNode->prev = Prev;
	node->prev = tempNode;
	count++;
}

void List::AddTail(int n) //добавл€ет последний елемент.
{
	Elemen *temp = new Elemen;

	temp->next = 0;
	temp->data = n;
	temp->prev = tail;

	if (tail != 0)
	{
		tail->next = temp;
	}

	if (count == 0)
	{
		Head = tail = temp;
	}
	else
	{
		tail = temp;
	}

	count++;
}

void List::AddHeard(int n)
{
	Elemen* elemn = new Elemen;

	elemn->prev = 0;
	elemn->next = Head;
	elemn->data = n;

	if (Head != 0)
	{
		Head->prev = elemn;
	}
	if (count != 0)
	{
		Head = tail = elemn;
	}
	else
	{
		Head = elemn;
	}

	count++;
}

void List::Print(int pos)
{
	if (pos < 1 || pos > count)
	{
		cout << "ERROR";
		return;
	}

	Elemen* elem;
	if (pos <= count / 2)
	{
		elem = Head;
		int i = 1;

		while (i<pos)
		{
			elem = elem->next;
			i++;

		}

	}
	else
	{
		elem = tail;
		int i = 1;

		while (i<pos)
		{
			elem = elem->prev;
			i++;
		}


	}
	cout << "POSITION ELEMENT " << pos;

	cout << elem->next << endl;
}

bool List::operator==(const List &l)
{
	if (*this == l)
	{
		return true;
	}

	return false;
}

bool List::operator!=(const List &l)
{
	if (*this != l)
	{
		return true;
	}

	return false;
}

bool List::operator<=(const List & l)
{
	if (count < l.count)
	{
		return true;
	}

	if (*this == l)
	{
		return true;
	}

	return false;
}

bool List::operator>=(const List &l)
{
	if (count > l.count)
	{
		return true;
	}

	if (*this == l)
	{
		return true;
	}
	return false;
}

bool List::operator<(const List & l)
{
	if (count < l.count)
	{
		return true;
	}

	return false;
}

bool List::operator>(const List &l)
{
	if (count > l.count)
	{
		return true;
	}

	return false;
}

List & List::operator-()
{
	Elemen * elem = Head;
	List ls;

	while (elem != 0)
	{
		ls.AddHeard(elem->data);
	}
	return ls;
}

List & List::operator=(const List & l)
{
	if (this == &l)
	{
		return *this;
	}


	this->~List();

	Elemen* el = l.Head;

	while (el != 0)
	{
		AddTail(el->data);
		el = el->next;
	}

	return *this;

}

List & List::operator+(const List &)
{
	List templist(*this);
	

	Elemen* elemn = Head;
	while (elemn != 0)
	{
		templist.AddTail(elemn->data);
		elemn = elemn->next;
	}
	return  templist;
}


void main()
{

}