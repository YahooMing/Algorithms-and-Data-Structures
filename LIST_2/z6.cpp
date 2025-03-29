#include <iostream>
#include <vector>

struct node {
    int value;
    node* next;
    node(int v, node* n = nullptr) : value(v), next(n) {}
};

//a
node* append(node* a, node* b){
    if (!a) return b;
    if (!b) return a;

    node* temp = a;
    while ( temp->next ){
        temp = temp->next;
    }
    
    temp->next = b;
    return a;
}
//b
//komentarze są dla mojego rozumowania jak coś :)
void filter(node* &L, bool (*f)(int)){
    node* temp = new node(0,L);
    node* curr = temp;
    while ( curr->next){
        if ( !f(curr->next->value) ){ //sprawdzam czy val zgadza sie
            node* del = curr->next;
            curr->next = curr->next->next; // i++

            delete del;
        } else {
            curr = curr->next; // i++
        }
    }       
    L = temp->next;
    delete temp;
}

bool fun(int x) {
    return x % 2 == 0;
}

//c 
void insert_after_smaller(node*& L, int x) {
    node* ret = new node(x);
    if ( !L || L->value >= x ){
        ret->next = L;
        L = ret;
        return;
    }

    node* curr = L;
    while ( curr->next && curr->next->value < x ) {
        curr = curr->next;
    }

    ret->next = curr -> next;
    curr->next = ret;
}

//e
node* merge(node* a, node* b){
    if (!a) return b;
    if (!b) return a;
    if (a->value < b->value){
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

//d
std::vector<node*> ascending_fragments(node* L){
    std::vector<node*> frags;
    while (L){
        node* start = L;
        while (L->next && L->value <= L->next->value){
            L = L->next;
        }
        node* next = L->next;
        L->next = nullptr; //koniec podciagu
        frags.push_back(start);
        L = next;
    }
    return frags;

}


void print_list(node* L) {
    while (L) {
        std::cout << L->value << " -> ";
        L = L->next;
    }
    std::cout << "nullptr" << std::endl;
}


int main() {
    node* a = new node(1, new node(3, new node(5, nullptr)));
    node* b = new node(2, new node(4, new node(6, nullptr)));

    std::cout << "lista a: "; print_list(a);
    std::cout << "lista b: "; print_list(b);

    node* combined = append(a, b);
    std::cout << "append: "; print_list(combined);

    filter(combined, fun);
    std::cout << "filter: "; print_list(combined);

    insert_after_smaller(combined, 8);
    std::cout << "insert_after_smaller: "; print_list(combined);

    node* sorted_a = new node(1, new node(4, new node(7, nullptr)));
    node* sorted_b = new node(2, new node(5, new node(8, nullptr)));

    node* merged_list = merge(sorted_a, sorted_b);
    std::cout << "merge: "; print_list(merged_list);

    node* frag_list = new node(1, new node(2, new node(1, new node(3, nullptr))));
    std::vector<node*> fragments = ascending_fragments(frag_list);
    std::cout << "Fragmenty rosnące: \n";
    for (auto frag : fragments) {
        print_list(frag);
    }

    return 0;
}