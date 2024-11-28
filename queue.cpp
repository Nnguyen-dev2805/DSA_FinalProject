#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include<algorithm>
using namespace std;
template <typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node(T value) : data(value), next(nullptr) {}
	};
	Node *front;
	Node *back;

public:
	Queue() : front(nullptr), back(nullptr) {}
	~Queue()
	{
		while (!isEmpty())
			dequeue();
	}
	// add a element to the back of queue
	void enqueue(T value)
	{
		Node *temp = new Node(value);
		if (isEmpty())
		{
			front = back = temp;
		}
		else
		{
			back->next = temp;
			back = temp;
		}
	}
	// remove and return the front element of queue
	T dequeue()
	{
		if (isEmpty())
			throw out_of_range("Queue is empty");
		Node *temp = front;
		T value = front->data;
		front = front->next;
		delete (temp);
		if (front == nullptr)
			back = nullptr;
		return value;
	}
	//Get value at top
	T peek()
	{
		if (isEmpty())
			throw out_of_range("Queue is empty");
		T value = front->data;
		return value;
	}
	// check empty
	bool isEmpty() const
	{
		return (this->front == nullptr);
	}
};
template <typename T>
void BFS(T start, const unordered_map<T, vector<T>> &graph)
{
	set<T> visited;
	Queue<T> queue;
	queue.enqueue(start);
	visited.insert(start);
	while (!queue.isEmpty())
	{
		T top = queue.dequeue();
		cout << top << " ";
		for (T neighbor : graph.at(top))
		{
			if (visited.find(neighbor) == visited.end())
			{
				queue.enqueue(neighbor);
				visited.insert(neighbor);
			}
		}
	}
}

// Function to read a graph
template <typename T>
unordered_map<T, vector<T>> readGraph(T m)
{
	unordered_map<T, vector<T>> graph;
	cout << "Enter " << m << " edges (u v): \n";
	for (T i = 0; i < m; i++)
	{
		T u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(auto &pair : graph)
	{
		sort(pair.second.begin(), pair.second.end());
	}
	return graph;
}
int main()
{
	int ok = 1;
	do
	{
		int n, m;
		cout << "Enter the number of edges : ";
		cin >> m;
		if (m <= 0)
		{
			cout << "The graph has no edges. Please enter a valid graph.\n";
			continue;
		}
		unordered_map<int, vector<int>> graph;
		graph = readGraph(m);
		int ok1 = 1;
		do
		{
			// chon dinh bat dau
			int start;
			cout << "Select the starting vertex: ";
			cin >> start;
			if (graph.find(start) == graph.end())
			{
				cout << "Invalid vertex. Please select a valid starting vertex.\n";
				continue;
			}
			cout << "RESULT: \n";
			BFS(start, graph);
			cout << "\nIf you want to bfs with other vertex enter 1, else enter 0: ";
			cin >> ok1;
		} while (ok1 != 0);
		cout << "If you want to continue with other graph enter 1, else enter 0: ";
		cin >> ok;
		if (ok != 0)
			cout << endl
				 << string(40, '-') << endl
				 << endl;
	} while (ok != 0);
	cout << "Thank you.";
	return 0;
}
