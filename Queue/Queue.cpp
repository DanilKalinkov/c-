#include <iostream>
using namespace std;
struct  Node {
	Node* next;
	Node* priv;
	int data;
};
class Queue {
public:
	Queue() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void push(int data) {
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = nullptr;
		newnode->priv = tail;

		if (isEmpty()) {
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		count++;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Queue is Etmpy";
		}
		else {
			Node* temp = head;
			head = head->next;
			if (head != nullptr) {
				head->priv = nullptr;
			}
			delete temp;
			count--;
		}
	}
	int front() {
		if (isEmpty()) {
			cout << "Queue is Etmpy";
			return -1;
		}
		else {
			return head->data;
		}
	}
	int back() {
		if (isEmpty()) {
			cout << "Queue is Etmpy";
			return -1;
		}
		else {
			return tail->data;
		}
	}
	bool isEmpty() {
		return head == nullptr;
	}
	int size() {
		return count;
	}
private:
	int count;
	Node* head;
	Node* tail;

};
int main() {
	Queue Q;
	for (int i = 50; i > 0; i--) {
		Q.push(i);
	}
	int j = 0;
	int arr[50];

	//for (int i = 0; i < 50; i++) {
	//	arr[i]=Q.front();
	//}




	while (!Q.isEmpty()) {
		arr[j] = Q.front();
		cout << Q.front() << " ";
		Q.pop();
		j = j + 1;
	}
	for (int i = 0; i < 50; i++) {
		cout << arr[i] << " ";
	}


}