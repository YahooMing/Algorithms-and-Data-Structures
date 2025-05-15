#include <iostream>

struct node {
	int key;
	node* left;
	node* right;
	node(int x0, node* l=nullptr, node* r=nullptr):key(x0), left(l), right(r){}
};

node* find(node* t,int x) {
	while(t && t->key!=x) t=  x < t->key ? t->left : t->right;
	return t;
}

void insert(node *& t, int x){
	node **t1=&t;
	while(*t1) t1= x < (*t1)->key ? &(*t1)->left: &(*t1)->right;
	*t1=new node(x);
};

void remove(node *&t, int x) {
	node **t1=&t;
	while (*t1 && (*t1)->key!=x) t1= x < (*t1)->key ? &(*t1)->left : &(*t1)->right;
	if(*t1){
		if((*t1)->right && (*t1)->left){
			node **t2=&(*t1)->right;
			while ((*t2)->left)
				t2=&(*t2)->left;
			(*t1)->key=(*t2)->key;
			t1=t2;
		}

		node *son = (*t1)->right ?
					(*t1)->right :
					(*t1)->left;
		delete *t1;
		*t1=son;
	}
}

int min (node* t){
	while(t->left) t=t->left;
	return t->key;
}

int max (node* t){
	while(t->right) t=t->right;
	return t->key;
}

int main() {
	node* root = nullptr;

	int tab[] = {10, 5, 15, 3, 7, 12, 18};
	for (int x : tab) insert(root, x);

	std::cout << "ino order: ";
	inorder(root);
	std::cout << "\n";

	int szukany = 7;
	node* f = find(root, szukany);
	std::cout  << szukany << "\n";

	std::cout << "min: " << min(root) << "\n";
	std::cout << "max: " << max(root) << "\n";

	std::cout << "\n usuwanie \n";
	remove(root, 10);
	std::cout << "inorder ";
	inorder(root); std::cout << "\n";

	std::cout << "\n usuwanie \n";
	remove(root, 3);
	std::cout << " inorder ";
	inorder(root); std::cout << "\n";

	std::cout << "\n usuwanko znowuu\n";
	remove(root, 5);
	std::cout << "inorder ";
	inorder(root); std::cout << "\n";

	return 0;
}