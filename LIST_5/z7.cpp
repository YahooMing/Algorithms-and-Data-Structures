#include <iostream>

// drzewo BST bez wskaźnika na rodzica
struct node {
	int key;
	node* left;
	node* right;
	node(int x0, node* l=nullptr, node* r=nullptr):key(x0), left(l), right(r){}
};

node** find(node* &t,int x){
	if(!t || t->key==x) return &t;

	if(x < t->key) return find(t->left,x);

	else return find(t->right,x);
};

void insert(node *& t, int x){
	if(!t) t=new node(x);

	else insert( x < t->key ? t->left : t->right, x);
};

void inorder(node *t){
	if(t){
		inorder(t->left);
		std::cout<<t->key<<" ";
		inorder(t->right);
	}
};

void prerder(node *t){
	if(t){
		std::cout<<t->key<<" ";
		prerder(t->left);
		prerder(t->right);
	}
};

node** leftmost (node*& t){
	if(t->left) return leftmost (t->left);
    else return &t;
}

void remove(node *&t, int x){
	node **t1=find(t,x);

	if(*t1){
		if((*t1)->right && (*t1)->left) {
		   node ** t2=leftmost((*t1)->right);
		   (*t1)->key=(*t2)->key;
		   t1=t2;
		}

		node *son = (*t1)->right ? (*t1)->right : (*t1)->left;
		delete *t1;
		*t1=son;
	}
}

void postorder(node *t){
	if(t){
		postorder(t->left);
		postorder(t->right);
		std::cout<<t->key<<" ";
	}
};


int count(node* t) {
    if (!t) return 0;
    return 1 + count(t->left) + count(t->right);
}

int height(node* t){
	if(!t) return 0;
	int hL=height(t->left);
	int hR=height(t->right);
	return 1+ (hR > hL ? hR : hL);
}

int main() {
    node* root = nullptr;

    int values[] = {10, 5, 15, 3, 7, 12, 17};
    for (int x : values) {
        insert(root, x);
        std::cout << x << ": inorder: ";
        inorder(root);
        std::cout << "\nliczba wezlow: " << count(root);
        std::cout << "\nwysokosc: " << height(root) << "\n";
    }
    std::cout << "inorder:   "; inorder(root);   std::cout << "\n";
    std::cout << "preorder:  "; prerder(root);   std::cout << "\n";
    std::cout << "postorder: "; postorder(root); std::cout << "\n";

    std::cout << "\n wysokosc: " << height(root) << "\n";
    std::cout << "liczba węzłów:   " << count(root) << "\n";

    int szukany = 7;
    node** found = find(root, szukany);
    std::cout << "\n znaleziono klucz " << szukany << "\n";


    std::cout << "\n usuwanko \n";
    remove(root, 10);
    std::cout << "inorder "; inorder(root); std::cout << "\n";

    std::cout << "\n usuwanie \n";
    remove(root, 3);
    std::cout << "inorder "; inorder(root); std::cout << "\n";

    std::cout << "\n usuwanie \n";
    remove(root, 5);
    std::cout << "inorder "; inorder(root); std::cout << "\n";

    return 0;
}

