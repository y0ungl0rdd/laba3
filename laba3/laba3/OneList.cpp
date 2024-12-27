#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Element {
	Type element;
	Element<Type>* NextEl;
	Element(Type el) :element(el), NextEl(nullptr) {}
};

template<typename Type>
class OneList {
	Element<Type>* first_element;
	Element<Type>* last_element;
	int counter_elements;
public:
	OneList() :first_element(nullptr), last_element(nullptr) {}

	OneList(OneList& p) {
		first_element = p.first_element;
		last_element = p.last_element;
		counter_elements = 0;
	}

	void push_back(Type el) {
		Element<Type>* Pointer = new Element<Type>(el);
		if (first_element == nullptr) {
			first_element = Pointer;
			last_element = Pointer;
		}
		else {
			last_element->NextEl = Pointer;
			last_element = Pointer;
		}
		counter_elements++;
	}

	void push_front(Type el) {
		Element<Type>* Pointer = new Element<Type>(el);
		if (first_element == nullptr) {
			first_element = Pointer;
			last_element = Pointer;
		}
		else {
			Pointer->NextEl = first_element;
			first_element = Pointer;
		}
		counter_elements++;
	}

	Element<Type>* back() {
		return last_element;
	}

	Element<Type>* front() {
		return first_element;
	}

	int size() {
		return counter_elements;
	}

	bool empty() {
		if (first_element == nullptr) {
			return 1;
		}
		else return 0;
	}

	void insert(int position, Type el) {
		if (position == 0) {
			push_front(el);
		}
		else {
			if (position == size()) {
				push_back(el);
			}
			else {
				Element<Type>* newEl = new Element<Type>(el);
				Element<Type>* point = first_element;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
			}
		}
		counter_elements++;
	}

	void pop_back() {
		if (last_element == nullptr) throw "Error";
		Element<Type>* point = first_element;
		if (point->NextEl != nullptr) {
			while (point->NextEl->NextEl != nullptr) {
				point = point->NextEl;
			}
		}
		point->NextEl = nullptr;
		delete last_element;
		last_element = point;
		counter_elements--;
	}

	void pop_front() {
		if (first_element == nullptr) throw "Error";
		Element<Type>* point = first_element->NextEl;
		delete first_element;
		first_element = point;
		counter_elements--;
	}

	void remove(Type DeleteEL) {
		if (last_element == nullptr) throw "Error";
		Element<Type>* point = first_element;
		Element<Type>* lastPoint = first_element;
		while (point->NextEl != nullptr) {
			if (point->element == DeleteEL) {
				if (point == first_element) {
					pop_front();
					point = first_element;
					lastPoint = first_element;
				}
				else {
					lastPoint->NextEl = point->NextEl;
					Element<Type>* TimePoint = point;
					point = point->NextEl;
					delete TimePoint;
				}
				counter_elements--;
			}
			else
			{
				lastPoint = point;
				point = point->NextEl;
			}

		}
		if (DeleteEL == last_element->element) pop_back();
	}

	Type& operator [] (int id) {
		if (first_element == nullptr) {
			throw "Error";
		}
		else
		{
			Element<Type>* point = first_element;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) throw "Error";
			}
			return point->element;
		}
	}
};