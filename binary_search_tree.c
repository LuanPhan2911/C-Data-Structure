#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node Node;
typedef struct Node* Tree;
void makenullTree(Tree* t){
	(*t)=NULL;
}
int emptyTree(Tree t){
	return t==NULL;
}
Tree leftChild(Tree t){
	if(t!=NULL){
		return t->Left;
	}
	return NULL;
}
Tree createNode(KeyType data){
	Tree t;
	makenullTree(&t);
	t= (Tree)malloc(sizeof(Node));
	t->Key= data;
	t->Left=NULL;
	t->Right=NULL;
}
Tree rightChild(Tree t){
	if(t!=NULL){
		return t->Right;
	}
	return NULL;
}
void insertNode(KeyType key, Tree *t){
	if((*t)==NULL){
		Tree n=(Tree)malloc(sizeof(Node));
		n->Key= key;
		n->Left=NULL;
		n->Right=NULL;
		*t =n;
	}else{
		if((*t)->Key < key){
			insertNode(key, &(*t)->Right);
		}
		if((*t)->Key >key){
			insertNode(key, &(*t)->Left);
		}
	}
}
Tree search(KeyType key, Tree t){
	if(t==NULL){
		return NULL;
	}
	if(t->Key==key){
		return t;
	}
	if(t->Key< key){
		return search(key, rightChild(t));
	}
	if(t->Key>key){
		return search(key, leftChild(t));
	}
}
void preOrder(Tree t){
	if(t!=NULL){
		printf("%d ", t->Key);
		preOrder(leftChild(t));
		preOrder(rightChild(t));
	}
}
void inOrder(Tree t){
	if(t!=NULL){
		inOrder(leftChild(t));
		printf("%d ", t->Key);
		inOrder(rightChild(t));
	}
}
void deleteNode(KeyType key, Tree *t){
	if((*t)!=NULL){
		if(key < (*t)->Key){
			deleteNode(key, &(*t)->Left);
		}else if(key>(*t)->Key){
			deleteNode(key, &(*t)->Right);
		}else{
			if((*t)->Left==NULL && (*t)->Right==NULL){
				(*t)=NULL;
			}else if((*t)->Left==NULL){
				(*t)= (*t)->Right;
			}else if((*t)->Right==NULL){
				(*t)= (*t)->Left;
			}else{
				(*t)->Key= deleteMin(&(*t)->Right);
			}
		}
	}
}
KeyType deleteMin(Tree *t){
	KeyType k;
	if((*t)->Left==NULL){
		k= (*t)->Key;
		(*t)= (*t)->Right;
		return k;
	}else{
		return deleteMin(&(*t)->Left);
	}
}
KeyType deleteMax(Tree *t){
	KeyType k;
	if((*t)->Right==NULL){
		k= (*t)->Key;
		(*t)= (*t)->Left;
		return k;
	}else{
		return deleteMax(&(*t)->Right);
	}
}
int number_nodes(Tree t){
	if(t==NULL){
		return 0;
	}else{
		return number_nodes(t->Left)+ number_nodes(t->Right)+1;
	}
}
