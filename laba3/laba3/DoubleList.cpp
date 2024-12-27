#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct Element2 {
	Type element;
	Element2<Type>* NextEl;
	Element2<Type>* PreviosEl;
	Element2(Type el) :element(el), NextEl(nullptr), PreviosEl(nullptr) {}
};

template<typename Type>
class DoubleList {
	Element2<Type>* first_element;
	Element2<Type>* last_element;
	int counter_elements = 0;
public:
	DoubleList() :first_element(nullptr), last_element(nullptr) {}

	void push_back(Type el) {
		Element2<Type>* Pointer = new Element2<Type>(el);
		if (first_element == nullptr) {
			first_element = Pointer;
			last_element = Pointer;
			counter_elements++;
		}
		else {
			last_element->NextEl = Pointer;
			Pointer->PreviosEl = last_element;
			last_element = Pointer;
			counter_elements++;
		}
	}

	void push_front(Type el) {
		Element2<Type>* Pointer = new Element2<Type>(el);
		if (first_element == nullptr) {
			first_element = Pointer;
			last_element = Pointer;
			counter_elements++;
		}
		else {
			Pointer->NextEl = first_element;
			first_element = Pointer;
			counter_elements++;
		}

	}

	Element2<Type>* back() {
		return last_element;
	}

	Element2<Type>* front() {
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
		if (position < counter_elements) {
			if (position == 0) {
				push_front(el);
			}
			else
			{
				Element2<Type>* newEl = new Element2<Type>(el);
				Element2<Type>* point = first_element;
				int countElements = 1;
				while (countElements != position) {
					countElements++;
					point = point->NextEl;
				}
				newEl->NextEl = point->NextEl;
				point->NextEl = newEl;
				counter_elements++;
			}
		}
		else
		{
			if (position == size()) {
				push_back(el);
			}
			else
			{
				Element2<Type>* newEl = new Element2<Type>(el);
				Element2<Type>* point = last_element;
				int countElements = size();
				while (countElements != position) {
					countElements--;
					point = point->PreviosEl;
				}
				newEl->PreviosEl = point->PreviosEl;
				point->PreviosEl = newEl;
				counter_elements++;
			}
		}
	}

	void pop_back() {
		Element2<Type>* DelEl = last_element;
		last_element->PreviosEl->NextEl = nullptr;
		last_element = last_element->PreviosEl;
		delete DelEl;
		counter_elements--;
	}

	void pop_front() {
		Element2<Type>* DelEl = first_element;
		first_element->NextEl->PreviosEl = nullptr;
		first_element = first_element->NextEl;
		counter_elements--;
		delete DelEl;
	}

	Type& operator [] (int id) {
		if (first_element == nullptr) {
			std::cout << "MissingEl";
		}
		else
		{
			Element2<Type>* point = first_element;
			for (int i = 0; i < id; i++) {
				point = point->NextEl;
				if (point == nullptr) {
					std::cout << "MissingEl";
				}
			}
			return point->element;
		}
	}

	void remove(Type data) {
		if (last_element != nullptr) {

			int current_element_index = 0;
			Element2<Type>* element_ = new Element2<Type>(data);
			Element2<Type>* current_element = first_element;

			if (current_element->element == data) {
				pop_front();
			}
			else {
				for (int i = 0; i < counter_elements; i++) {
					while (current_element->NextEl != nullptr) {
						if (current_element->NextEl->element == element_->element) {
							if (current_element_index + 2 == counter_elements) {
								pop_back();
								break;
							}
							Element2<Type>* elemDel = current_element->NextEl;
							current_element->NextEl = elemDel->NextEl;
							delete elemDel;
							counter_elements--;
							break;

						}

						current_element = current_element->NextEl;
						current_element_index++;
					}
				}
			}
		}
		else {
			throw "List size Error";
		}
	}
};