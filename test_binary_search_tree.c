#include<stdio.h>
#include "binary_search_tree.c"
void readFile(char * fileName, Tree* t){
	FILE * f;
	f=fopen(fileName, "r");
	makenullTree(t);
	int key;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f,"%d", &key);
			if(search(key, *t)==NULL){
				insertNode(key, t);
			}
		}
	}else{
		printf("Mo that bai");
	}
}
int dem=0;
//int dem_so_chan(Tree t ){
//	if(t==NULL){
//		return 0;
//	}
//	if(t->Key%2!=0){
//		dem++;
//	}
//	dem_so_chan(t->Left);
//	dem_so_chan(t->Right);
//	return dem;
//	
//}
//void dem_so_chan(Tree t, int *dem){
//	if(t!=NULL){
//		if(t->Key%2==0){
//			(*dem)++;
//		}
//		dem_so_chan(t->Left);
//		dem_so_chan(t->Right);
//	}
//}
int dem_so_node_la(Tree t){
	if(t==NULL){
		return 0;
	}else{
		if(isLeaf(t)){
			dem++;
		}
		dem_so_node_la(t->Left);
		dem_so_node_la(t->Right);
		return dem;
	}
}
int node_1_con(Tree t){
	if(t==NULL){
		return 0;
	}
	return (t->Left==NULL && t->Right!=NULL)||(t->Left!=NULL && t->Right==NULL);
}
int node_2_con(Tree t){
	if(t==NULL){
		return 0;
	}
	return t->Left!=NULL && t->Right!=NULL;
}
int isLeaf(Tree t){
	if(t==NULL){
		return 0;
	}
	return t->Left==NULL && t->Right==NULL;
}
int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
int heightNode(Tree t){
	if(t==NULL){
		return 0;
	}
	return max(heightNode(t->Left), heightNode(t->Right))+1;
}
void heightEachNode(Tree t){
	if(t!=NULL){
		printf("\n%d -> %d", t->Key, heightNode(t));
		heightEachNode(t->Left);
		heightEachNode(t->Right);
	}
}
//int depthNode(Tree t){
//	// cay sau nhat la bao nhieu
//	if(t==NULL){
//		return 0;
//	}
//	int left= depthNode(t->Left);
//	int right = depthNode(t->Right);
//	return (left >right)? left+1: right+1;
//}
int findDepth(Tree t, Node* n){
	if(t==NULL){
		return 0;
	}
	if(t==n){
		return 1;
	}
	int left =findDepth(t->Left, n);
	if(left!=0){
		return left+1;
	}
	int right=findDepth(t->Right, n);
	if(right!=0){
		return right+1;
	}
	return 0;
}
void findEachDepth(Tree root, Tree t){
	if(t!=NULL){
		printf("\nChieu sau node %d -> %d", t->Key,findDepth(root, t));
		findEachDepth(root, t->Left);
		findEachDepth(root, t->Right);
	}
}
KeyType maxTree(Tree t){
	if(t==NULL){
		return -999;
	}
	KeyType max= t->Key;
	KeyType maxRight =maxTree(t->Right);
	if(max < maxRight){
		max = maxRight;
	}
	return max;
	
}
Tree rightMostNode(Tree t){
	if(t->Right!=NULL){
		return rightMostNode(t->Right);
	}
	return t;
}

Tree tree=NULL;
Tree getPrevious(KeyType x, Tree t){
	if(t==NULL){
		return NULL;
	}
	if(x <= t->Key){
		return getPrevious(x, t->Left);
	}
	Tree temp = getPrevious(x, t->Right);
	return temp!= NULL ? temp: t;
}
Tree getNext(KeyType x,Tree t ){
	if(t==NULL){
		return NULL;
	}
	if(x >= t->Key){
		return getNext(x, t->Right);
	}
	Tree temp = getNext(x, t->Left);
	return temp!=NULL ? temp : t;
}
int countLeafNode(Tree t){
	if(t==NULL){
		return 0;
	}
	int res=0;
	if(isLeaf(t)){
		res =1;
	}
	res+= countLeafNode(t->Left)+ countLeafNode(t->Right);
	return res;
}
int main(){
	char * fileName ="test_binary_search_tree.txt";
	Tree t;
	readFile(fileName, &t);
	inOrder(t);
	printf("\nSo node la %d", dem_so_node_la(t));
	printf("\nSo node la %d", countLeafNode(t));
//	printf("\nChieu cao cua node goc %d", heightNode(t));
//	heightEachNode(t);
//	printf("\nChieu sau node %d", findDepth(t, t));
//	findEachDepth(t, t);
//	Tree next =getNext(565, t);
//	if(next!=NULL){
//		printf("\nNext value %d->%d",565 ,next->Key);
//	}
//	Tree previous = getPrevious(2, t);
//	if(previous!=NULL){
//		printf("\nPrevious value %d->%d ", 2, previous->Key);
//	}


return 0;
}

