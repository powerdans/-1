#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include<math.h>
#include <vector>
#include <string>




using namespace std;


class Snack
{
private:
	string name_snack;
public:
	Snack()
	{
		this->name_snack = "�������";
	
	}
	Snack(string name_snack)
	{
		this->name_snack = name_snack;
	}
};

class SnackSlot
{
private:
	
	short number_seats;
	Snack** storage;
	short num;


public:
	SnackSlot()
	{
		num = 0;
		this->number_seats = 10;
		storage = new Snack * [number_seats];
	}
	SnackSlot(short number_seats)
	{
		num = 0;
		this->number_seats = number_seats;
		storage = new Snack * [this->number_seats];
	}
	void addSnack(Snack *addSnack)
	{
		if (num == number_seats)
		{
			return;
		}
		this->storage[num] = addSnack;
		num += 1;
	}
	~SnackSlot()
	{
		delete [] storage ;
	}
	
};
class VendingMachine
{
private:
	short slotCount;
	SnackSlot** storage;
	short num;

public:
	VendingMachine()
	{
		num = 0;
		this->slotCount = 10;
		storage = new SnackSlot * [slotCount];
	}
	VendingMachine(short slotCount)
	{
		num = 0;

		this->slotCount=slotCount;
		storage =new SnackSlot* [this->slotCount];
	}
	void addSlot(SnackSlot* addSlot)
	{
		if (num == slotCount)
		{
			return;
		}
		this->storage[num] = addSlot;
		num += 1;
	}
	
	~VendingMachine()
	{
		delete[] storage;
	}
	short getEmptySlotsCount()
	{
		return slotCount - num;
	}

};




int main() 
{
	Snack* bounty = new Snack("Bounty");
	Snack* snickers = new Snack("Snickers");
	SnackSlot* slot = new SnackSlot(10/*���������� ����������, ������� ���������� � ����*/);
	slot->addSnack(bounty); //��������� �������� � ����
	slot->addSnack(snickers);
	short slotCount=10;
	VendingMachine* machine = new VendingMachine(slotCount /*���������� ������ ��� ������*/);
	machine->addSlot(slot); // �������� ����  � �������

	cout << machine->getEmptySlotsCount(); // ������ �������� ���������� ������ ������ ��� ������
	delete machine;
	delete slot;
	delete snickers;
	delete bounty;
}