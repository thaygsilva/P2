//Thayn� Gomes da Silva TIA:32092229
#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;
void Print(const LinkedList* list)
{
	Node* temp = list->head;

	for (int i = 0; i < list->count; i++) {
		cout << "[" << temp->id << "]" << temp->name << endl;
		temp = temp->next;
	}
	cout << "\n";
}

void PrintListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia! (" << Count(list) << ")\n\n";
	}
	else
	{
		cout << "Lista (" << Count(list) << "): \n";
		Print(list);
	}
}

void PrintListInfoAfterInsertion(const LinkedList* list, bool didInsert)
{
	if (didInsert)
	{
		PrintListInfo(list);
	}
	else
	{
		cout << "N�o foi poss�vel inserir novo n� na lista!\n\n";
	}
}

void PrintListInfoAfterRemoval(const LinkedList* list, Node* node)
{
	if (node != nullptr)
	{
		cout << "N� removido -> id: " << node->id << ", name: " << node->name << "\n\n";
		PrintListInfo(list);
	}
	else
	{
		cout << "N�o foi poss�vel remover o n� da lista!\n\n";
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** ESTRUTURA DE DADOS I - Avalia��o Parcial 2 (P2) ***\n\n";
	LinkedList* list = Create();
	PrintListInfo(list);
	Append(list, 1, "Carol");
	Append(list, 2, "Eric");
	Append(list, 3, "John");
	PrintListInfo(list);
	bool didInsert = InsertAfter(list, 5, 4, "Leo");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = InsertAfter(list, 2, 4, "Leo");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = InsertAfter(list, 2, 5, "Julia");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = InsertBefore(list, 4, 6, "Lisa");
	PrintListInfoAfterInsertion(list, didInsert);
	Node* temp = RemoveNode(list, 99);
	PrintListInfoAfterRemoval(list, temp);
	DestroyNode(temp);

	temp = RemoveNode(list, 2);
	PrintListInfoAfterRemoval(list, temp);
	DestroyNode(temp);

	temp = RemoveHead(list);
	PrintListInfoAfterRemoval(list, temp);
	DestroyNode(temp);

	temp = RemoveTail(list);
	PrintListInfoAfterRemoval(list, temp);
	DestroyNode(temp);

	Clear(list);
	PrintListInfo(list);
	didInsert = InsertAfter(list, 44, 33, "Olga");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = InsertBefore(list, 11, 22, "Thomas");
	PrintListInfoAfterInsertion(list, didInsert);
	Append(list, 44, "Bia");
	PrintListInfo(list);
	didInsert = InsertAfter(list, 44, 55, "Angela");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = InsertBefore(list, 44, 66, "Karen");
	PrintListInfoAfterInsertion(list, didInsert);
	Destroy(list);

	cout << "Fim.\n";
}