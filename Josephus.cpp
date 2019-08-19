#include<iostream>
using namespace std;

template <class T>
struct Node //for stocking the information of players
{
	T info;
	Node *next;
};

template <class T>
class Josephus
{
	Node<T> *head = new Node<T>;
public:
	Josephus(int num = 1, int interval = 1)//initialise
	{
		Node<T> *current, *end;
		current = end = head;
		current->info = 0;
		int pos = 0;
		while (pos < num) //constructing a circle
		{
			if (pos == 0)
				head = current;
			else
				end->next = current;
			end = current;
			current = new Node<T>;
			current->info = pos + 1;
			pos++;
		}
		end->next = head;
		delete current;
		cout << "The initial Josephus is: ";
		print(head);//print the initial circle
		int times = 1;
		while (head != head->next)
		{
			head = play(head, interval);//play once
			cout << "Play " << times << " time(s), Josephus is ";
			times++;
			print(head);//print a result after one play
		}
		cout << "The winner is " << head->info << endl;//winner
	}
	~Josephus()
	{
		Node<T> *current, *next;
		current = next = head->next;
		while (next != head)
		{
			next = next->next;
			delete current;
			current = next;
		}
		delete head;
	}
	Node<T> *play(Node<T> *h, int interval) //play once, delete one player
	{
		Node<T> *current, *parent;
		current = parent = h;
		int count = 0;
		while (count < interval)
		{
			parent = current;
			current = current->next;
			count++;
		}
		parent->next = current->next;
		delete current;
		return parent->next;
	}
	void print(Node<T>*h) //print the Josephus circle
	{
		Node<T> *current;
		current = h;
		while (current->next != h)
		{
			cout << current->info << " ";
			current = current->next;
		}
		cout << current->info << endl;
	}
};

int main()
{
	Josephus<int> js(31, 5);  //initialise
	system("pause");
	return 0;
}