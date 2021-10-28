#include "Plate.h"

//унарные
Plate& operator++(Plate& plate) {
	plate.arr = new_size(plate.size, plate.size + 1, plate.arr);
	plate[plate.size].x = 0;
	plate[plate.size].y = 0;
	plate[plate.size].type = 0;
	plate[plate.size].number = INT_MAX;
	plate.size++;
	return plate;
}

Plate operator++(Plate& plate, int i) {
	Plate old(plate.size, &plate[0]);
	plate.arr = new_size(plate.size, plate.size + 1, plate.arr);
	plate[plate.size].x = 0;
	plate[plate.size].y = 0;
	plate[plate.size].type = 0;
	plate[plate.size].number = INT_MAX;
	plate.size++;
	return old;
}

Plate& operator--(Plate& plate) {
	if (plate.size - 1 < 0)
		throw std::exception("The plate is already empty\n");
	plate.arr = new_size(plate.size, plate.size - 1, plate.arr);
	plate.size--;
	return plate;
}

Plate operator--(Plate& plate, int i) {
	if (plate.size - 1 < 0)
		throw std::exception("The plate is already empty\n");
	Plate old(plate.size, &plate[0]);
	plate.arr = new_size(plate.size, plate.size - 1, plate.arr);
	plate.size--;
	return old;
}

//бинарные
Plate* operator+(const Plate& left, const Plate& right) {
	Plate* plate = new Plate;//новая плата
	plate->arr = new_size(0, left.size + right.size, plate->arr);
	for (int i = 0; i < left.getSize(); i++) {//добавляем контакты первого аргумента
		plate->getArr()[plate->size].x = left[i].x;
		plate->getArr()[plate->size].y = left[i].y;
		plate->getArr()[plate->size].type = left[i].type;
		plate->getArr()[plate->size].number = left[i].number;
		plate->size++;
	}
	for (int i = 0; i < right.getSize(); i++) {//добавляем контакты второго аргумента
		plate->getArr()[plate->size].x = right[i].x;
		plate->getArr()[plate->size].y = right[i].y;
		plate->getArr()[plate->size].type = right[i].type;
		plate->getArr()[plate->size].number = right[i].number;
		plate->size++;
	}
	return plate;
}

Plate& operator+=(Plate& left, const int right) {
	left.arr = new_size(left.size, left.size + right, left.arr);
	for (int i = 0; i < right; i++) {
		left[left.size].x = 0;
		left[left.size].y = 0;
		left[left.size].type = 0;
		left[left.size].number = INT_MAX;
		left.size++;
	}
	return left;
}

Plate& operator-=(Plate& left, const int right) {
	if (left.size - right < 0)//если нет места для всех элементов
		throw std::exception("Not enough elements\n");
	left.arr = new_size(left.size, left.size - right, left.arr);
	left.size--;
	return left;
}

bool operator!=(const Plate& left, const Plate& right) {
	return left.getSize() != right.getSize();
}

bool operator==(const Plate& left, const Plate& right) {
	return left.getSize() == right.getSize();
}

bool operator==(const Contact& left, const Contact& right) {
	//возможна связь
	if (left.number != INT_MAX && right.number != INT_MAX && left.type != right.type)
		return true;
	//нет связи
	return false;
}

bool operator<(const Plate& left, const Plate& right) {
	return left.getSize() < right.getSize();
}

bool operator<=(const Plate& left, const Plate& right) {
	return left.getSize() <= right.getSize();
}

bool operator>(const Plate& left, const Plate& right) {
	return left.getSize() > right.getSize();
}

bool operator>=(const Plate& left, const Plate& right) {
	return left.getSize() >= right.getSize();
}

Plate& Plate::operator=(const Plate& right) {//левой плате присваивается размер и массив контактов правой
	if (this == &right) {//проверка на самоприсваивание
		return *this;
	}
	delete[] this->arr;
	try {
		this->arr = new Contact[right.size];
	}
	catch (std::bad_alloc& ba) {
		std::cerr << ba.what() << std::endl;
	}
	this->size = right.size;
	Contact* ptr_arr1 = right.arr;
	Contact* ptr_arr2 = this->arr;
	Contact* arr_end = ptr_arr1 + size;
	for (; ptr_arr1 != arr_end; ++ptr_arr1, ++ptr_arr2) {
		ptr_arr2->x = ptr_arr1->x;
		ptr_arr2->y = ptr_arr1->y;
		ptr_arr2->type = ptr_arr1->type;
		ptr_arr2->number = ptr_arr1->number;
	}
	return *this;
}

Plate& Plate::operator=(Plate&& right) {
	this->size = right.size;
	arr = right.arr;
	right.arr = nullptr;
	return *this;
}

Contact& Plate::operator[] (int index) {//возвращает элемент массива
	if (index > this->size || index < 0)
		throw std::exception("Incorrect index");
	return arr[index];
}
const Contact& Plate::operator[] (int index) const {//возвращает элемент массива
	if (index > this->size || index < 0)
		throw std::exception("Incorrect index");
	return arr[index];
}

//ввод вывод

std::ostream& operator<<(std::ostream& out, const Plate& plate) {
	for (int i = 0; i < plate.size; i++) {
		out << i << plate.arr[i].type << plate.arr[i].x << plate.arr[i].y;
		if (plate.arr[i].number != INT_MAX) {
			if (plate.arr[i].type == 1)//выводится номер связанного элемента
				out << plate.arr[i].number;
			else
				out << plate.arr[i].number;
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Plate& plate) {
	int x, y, type;
	in >> x >> y;
	do {//ожидание корректного ввода типа
		in >> type;
	} while (type != 0 && type != 1);
	plate.arr = new_size(plate.size, plate.size + 1, plate.arr);
	plate.arr[plate.size].x = x;
	plate.arr[plate.size].y = y;
	plate.arr[plate.size].type = type;
	plate.arr[plate.size].number = INT_MAX;
	plate.size++;
	return in;
}

