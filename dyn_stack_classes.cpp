#include <iostream>
#include <conio.h>


struct node_t {
	node_t() {
		prev = nullptr;
	}
	int value;
	node_t* prev;
};


class stack {
private:
	node_t* top;
	bool is_empty();
public:
	stack() {
		top = nullptr;
	};
	~stack() {
		//TODO
		while (!is_empty()) {
			delete top;
		}
	};

	void push(int);
	int* pop();
	void read();
	void reverse();
	int size;
};


void stack::push(int value) {
    node_t* tmp = new node_t();
    tmp->value = value;
    tmp->prev = top;
    top = tmp;

	size++;
}


int* stack::pop() {
    if (!is_empty()) {
        int* tmp_val = new int(top->value);
        node_t* tmp_top = top;
        top = top->prev;

		size--;

        delete tmp_top;
        return tmp_val;
    }
    return nullptr;
}

bool stack::is_empty() {
	return top == nullptr;
}

void stack::read(){
	while (!is_empty())
		std::cout << *pop() << std::endl;
	}


void stack::reverse() {
	int *tmp_arr = new int[size];

	int i = 0;
	int tmp = size;
	while (!is_empty()) {
		tmp_arr[i] = *pop();
		i++;
	}
	
	i = 0;
	while (i < tmp) {
		push(tmp_arr[i]);
		i++;
	}
	

	delete [] tmp_arr;
}

int main() {
	// int val;
	stack my_stack;

	for (int i = 0; i < 10; ++i) {
		my_stack.push(i);
	}

	//TODO: read stack content

	my_stack.reverse();

	for (int i = 0; i < 10; ++i) {
		my_stack.read();
	}	

	

	_getch();
	return 0;
}


// API
// Application Programming Interface


