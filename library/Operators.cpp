#include "Plate.h"

//унарные
Plate& operator++(Plate& plate) {
	if (plate.size + 1 > Size)
		throw std::exception("Not enough space\n");
	plate.arr[plate.size].x = 0;
	plate.arr[plate.size].y = 0;
	plate.arr[plate.size].type = 0;
	plate.arr[plate.size].number = INT_MAX;
	plate.size++;
	return plate;
}

Plate operator++(Plate& plate, int i) {
	if (plate.size + 1 > Size)
		throw std::exception("Not enough space\n");
	Plate old(plate.size, plate.arr);
	plate.size--;
	return old;
}

Plate& operator--(Plate& plate) {
	if (plate.size - 1 < 0)
		throw std::exception("The plate is already empty\n");
	plate.size--;
	return plate;
}

Plate operator--(Plate& plate, int i) {
	if (plate.size - 1 < 0)
		throw std::exception("The plate is already empty\n");
	Plate old(plate.size, plate.arr);
	plate.size--;
	return plate;
}

//бинарные
Plate* operator+(Plate& left, Plate& right) {
	if (left.size + right.size > Size)//если нет места для всех элементов
		throw std::exception("Not enough space\n");
	Plate* plate = new Plate(left.size, left.arr);//создаем плату с контактами первого аргумента
	for (int i = 0; i < right.size; i++) {//добавляем контакты второго аргумента
		plate->arr[plate->size].x = right.arr[i].x;
		plate->arr[plate->size].y = right.arr[i].y;
		plate->arr[plate->size].type = right.arr[i].type;
		plate->arr[plate->size].number = right.arr[i].number;
		plate->size++;
	}
	return plate;
}

Plate& operator+=(Plate& left, const int right) {
	if (left.size + right > Size)//если нет места для всех элементов
		throw std::exception("Not enough space\n");
	for (int i = 0; i < right; i++) {
		left.arr[left.size].x = 0;
		left.arr[left.size].y = 0;
		left.arr[left.size].type = 0;
		left.arr[left.size].number = INT_MAX;
		left.size++;
	}
	return left;
}

Plate& operator-=(Plate& left, const int right) {
	if (left.size - right < 0)//если нет места для всех элементов
		throw std::exception("Not enough elements\n");
	for (int i = 0; i < right; i++)
		left.size--;
	return left;
}

bool operator!=(const Plate& left, const Plate& right) {
	return left.size != right.size;
}

bool operator==(const Plate& left, const Plate& right) {
	return left.size == right.size;
}

bool operator==(const Contact& left, const Contact& right) {
	//возможна связь
	if (left.number != INT_MAX && right.number != INT_MAX && left.type != right.type)
		return true;
	//нет связи
	return false;
}

bool operator<(const Plate& left, const Plate& right) {
	return left.size < right.size;
}

bool operator<=(const Plate& left, const Plate& right) {
	return left.size <= right.size;
}

bool operator>(const Plate& left, const Plate& right) {
	return left.size > right.size;
}

bool operator>=(const Plate& left, const Plate& right) {
	return left.size >= right.size;
}

//ввод вывод

std::ostream& operator<<(std::ostream& out, const Plate& plate) {
	for (int i = 0; i < plate.size; i++) {
		out << "Number: " << i << "	Type: ";
		if (plate.arr[i].type == 1)
			out << "entrance";
		else
			out << "output";
		out << "	(x,y): " << '(' << plate.arr[i].x << ',' << plate.arr[i].y << ')';
		if (plate.arr[i].number != INT_MAX) {
			out << std::endl;
			if (plate.arr[i].type == 1)
				out << "Related output element: " << plate.arr[i].number;
			else
				out << "Related input element: " << plate.arr[i].number;
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Plate& plate) {
	if(plate.size == Size)
		throw std::exception("Not enough space\n");
	int x, y, type;
	in >> x >> y;
	do {//ожидание корректного ввода типа
		in >> type;
	} while (type != 0 && type != 1);
	plate.arr[plate.size].x = x;
	plate.arr[plate.size].y = y;
	plate.arr[plate.size].type = type;
	plate.arr[plate.size].number = INT_MAX;
	plate.size++;
	return in;
}