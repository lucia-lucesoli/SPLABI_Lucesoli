#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node
{
	void *pElement;
	struct Node *pNextNode;
} typedef Node;

struct LinkedList
{
	Node *pFirstNode;
	int size;
} typedef LinkedList;

#endif /* LINKEDLIST_H_ */

LinkedList *ll_newLinkedList(void);
int ll_len(LinkedList *this);
int ll_add(LinkedList *this, void *pElement);
void *ll_get(LinkedList *this, int index);
int ll_set(LinkedList *this, int index, void *pElement);
int ll_remove(LinkedList *this, int index);
int ll_clear(LinkedList *this);
int ll_deleteLinkedlist(LinkedList *this);
int ll_indexOf(LinkedList *this, void *pElement);
int ll_isEmpty(LinkedList *this);
int ll_push(LinkedList *this, int index, void *pElement);
void *ll_pop(LinkedList *this, int index); //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList *this, void *pElement);
int ll_containsAll(LinkedList *this, LinkedList *this2);
LinkedList *ll_subList(LinkedList *this, int from, int to);
LinkedList *ll_clone(LinkedList *this);
int ll_sort(LinkedList *this, int (*pFunc)(void *, void *), int order);

LinkedList *ll_filter(LinkedList *this, int (*pFunc)(void *));
LinkedList *ll_filter_autor(LinkedList *this, int (*pFunc)(void *, char *), char *autor);
LinkedList *ll_map(LinkedList *this, int (*pFunc)(void *));
