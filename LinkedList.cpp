//Thayná Gomes da Silva TIA:32092229
#include "LinkedList.h"

LinkedList* Create() {
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
	// O(1)
	// Justificativa: É constante, cada instrução pode valer uma unidade de tempo, não precisa percorrer a lista.
}

void Destroy(LinkedList* list) {

	Clear(list);
	delete list;
	// O(n)
	// Justificativa: É linear, pois chama a função clear, que é linear por percorer a lista inteira no pior caso.
}

void Insert(LinkedList* list, int pos, std::string elem) {

	Node* n = new Node;

	n->name = elem;
	n->id = pos;
	n->previous = n->next;
	n->next = GetHead(list);

	if (IsEmpty(list)) {
		list->tail = n;
		list->head = n;
	}

	else if (list->count == 1) {
		list->head->next = n;
		list->head->previous = n;
		n->previous = list->head;
		n->next = list->head;
	}
	else {
		list->head->previous = n;
		n->next = list->head;
		n->previous = list->tail;
		list->tail->next = n;
	}

	list->head = n;

	++list->count;
	// O(1)
	// Justificativa: como não existe uma busca no vetor, a busca é constante, os elementos não se "movem" e as funções que são
	// chamadas, são constantes também.
}

void Append(LinkedList* list, int pos, std::string elem) {
	Node* n = new Node;

	n->name = elem;
	n->id = pos;

	if (IsEmpty(list))
	{
		list->head = n;
		list->tail = n;
	}
	else
	{
		n->previous = list->tail;
		list->tail->next = n;
		list->tail = n;
		list->head->previous = n;
	}
	n->next = list->head;
	++list->count;
	// O(1)
}	// Justificativa: como não existe uma busca no vetor, a busca é constante, os elementos não se "movem", função IsEmpty também
	// é constante.

bool InsertBefore(LinkedList* list, int beforeId, int id, std::string elem) {
	Node* n = new Node;
	Node* aux = list->head;

	if (!IsEmpty(list) && beforeId != NULL) {
		for (int i = 0; i < list->count; i++) {
			if (aux->id == beforeId) {
				n->next = aux;
				n->previous = aux->previous;
				aux->previous->next = n;
				aux->previous = n;
				n->id = id;
				n->name = elem;
				break;
			}

			aux = aux->next;
		}
		if (aux->id != beforeId) {
			return false;
		}
		++list->count;
		return true;
	}
	else {
		return false;
	}
	// O(n)
	// Justificativa: É linear, pois precisa percorrer a lista usando o node aux para acessar determinada posição do id, no pior caso,
	// percorre toda a lista, desse modo, sendo n o tamanho da lista, ele percorre n posições, logo será O(n).
}

bool InsertAfter(LinkedList* list, int afterId, int id, std::string elem) {
	Node* n = new Node;
	Node* aux = list->head;
	
	if (!IsEmpty(list) && afterId != NULL) {
		for (int i = 0; i < list->count; i++) {
			if (aux->id == afterId) {
				n->next = aux->next;
				n->previous = aux;
				aux->next->previous = n;
				aux->next = n;
				n->id = id;
				n->name = elem;
				break;
			}
			aux = aux->next;
		}
		if (aux->id != afterId) {
			return false;
		}
		++list->count;
		return true;
	}
	else {
		return false;
	}
	// O(n)
	// Justificativa: É linear, pois precisa percorrer a lista usando o node aux para acessar determinada posição do id, no pior caso,
	// pode percorrer a lista inteira, desse modo, sendo n o tamanho da lista, ele percorre n posições, logo será O(n). .
}

Node* RemoveHead(LinkedList* list) {

	Node* toRemove = list->head;
	if ((list->head) == (list->tail)) {
		list->head = nullptr;
		list->tail = nullptr;
	}
	else {
		list->head = list->head->next;
	}
	--list->count;

	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
	// O(1)
	// Justificativa: É constante, pois não precisa percorrer a lista, pode acessar o elemento sem movimentar os outros.
}

Node* RemoveTail(LinkedList* list)
{
	if ((list->head) == (list->tail))
	{

		return RemoveHead(list);
	}

	Node* toRemove = list->head;
	Node* previous = nullptr;
	while (toRemove != (list->tail))
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	previous->next = nullptr;
	list->tail = previous;
	--list->count;

	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
	// O(1)
	// Justificativa: É constante, pois não precisa percorrer a lista, pode acessar o elemento sem movimentar os outros, função RemoveHead
	// também é constante.
}

Node* RemoveNode(LinkedList* list, int value) {

	Node* toRemove = list->head;
	for (int i = 0; i < list->count; i++) {
		if (toRemove->id == value) {
			break;
		}
		toRemove = toRemove->next;
	}
	if (toRemove->id != value) return nullptr;
	if (toRemove == list->head) return RemoveHead(list);
	if (toRemove == list->tail) return RemoveTail(list);
	else {
		toRemove->previous->next = toRemove->next;
		toRemove->next->previous = toRemove->previous;
		--list->count;
		toRemove->previous = nullptr;
		toRemove->next = nullptr;
		return toRemove;
	}
	// O(n)
	// Justificativa: É linear, precisa percorrer a lista para remover o node conforme o id, no pior caso, pode percorrer a lista toda.
	
}

Node* GetHead(LinkedList* list) {
	return list->head;
	// O(1)
	// Justificativa: É constante, não precisa percorrer a lista, apenas retornar o elemento que está em head, sem movimentar outros elementos.
}

Node* GetTail(LinkedList* list) {
	return list->tail;
	// O(1)
	// Justificativa: É constante, não precisa percorrer a lista, apenas retornar o elemento que está em tail, sem movimentar outros elementos.
}

Node* GetNode(LinkedList* list, int  value) {

	Node* toRemove = list->head;
	while (toRemove != nullptr) {
		if (toRemove->id == value) return toRemove;
		toRemove = toRemove->next;
	}
	return nullptr;
	// O(n)
	// Justificativa: É linear, precisa percorrer a lista para encontrar o node que deseja remover, no pior caso, percorre a lista toda.
}

int Count(const LinkedList* list) {
	return list->count;
	// O(1)
	// Justificativa: É constante, não precisa percorrer a lista, apenas retornar o valor de count.
}

bool IsEmpty(const LinkedList* list) {
	return list->count == 0;
	//O(1)
	// Justificativa: É constante, não precisa percorrer a lista, apenas verificar se o valor de count é igual a 0 e retornar.
}

void Clear(LinkedList* list) {
	Node* toRemove = list->head;
	Node* next = nullptr;
	for (int i = 0; i < list->count; i++) {
		next = toRemove->next;
		delete toRemove;
		toRemove = next;
	}
	list->head = nullptr;
	list->tail = nullptr;
	list->count = 0;
	// O(n)
	// Justificativa: É linear, precisa percorrer toda a lista para limpar elemento por elemento se a fila estiver cheia, ou seja,
	// pior caso, e envolve movimentação desses elementos.
}

void DestroyNode(Node* node) {
	delete node;
	node = nullptr;
	// O(1)
	// Justificativa: É constante, não precisa percorrer a lista, e não envolve movimentação dos elementos da lista.
}
