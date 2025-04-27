#include <iostream>

// do podpunktu a
template <typename T>
class queue_arr{
    private:
        static const int max_size = 1000; //przykładowa pojemność
        T tab[max_size];
        int start = 0;
        int top = 0;
    public:

        void enqueue(T x){
            if (top >= max_size){
                std::cout << "Too large man" << std::endl;
                return;
            }
            tab[top] = x;
            top++;
        };

        T dequeue(){
            if ( start >= top ){
                std::cout << "Too small man" << std::endl;
                return T();
            }
            T ret = tab[start];
            start ++;
            return ret;
        }

        bool isEmpty(){
            if (top == start){
                return true;
            }
            return false;
        };

        void seeout() {
            std::cout << "Elementy kolejki: ";
            for (int i = start; i < top; i++) {
                std::cout << tab[i] << " ";
            }
            std::cout << std::endl;
        }
};


template <typename T>
class queue_node{
    private:
        struct node{
            T key;
            node* next = nullptr;
            node(T k, node* n = nullptr) : key(k), next(n) {}
        };
        node *start = nullptr;
        node *top = nullptr;
    public:

        void enqueue(T x){
            node* p = new node(x);
            if (top) top->next = p;
            else start = p;
            top = p;
        };

        T dequeue() {
            if (isEmpty()) {
                std::cout << "Queue is empty" << std::endl;
                return T();
            }
            node* temp = start;
            T ret = temp->key;
            start= start->next;

            if ( !start ) top = nullptr;
            delete temp;

            return ret;
        }

        bool isEmpty() {
            return start == nullptr;
        }

        void seeout() {
            std::cout << "Elementy kolejki: ";
            for (node* p = start; p != nullptr; p = p->next) {
                std::cout << p->key << " ";
            }
            std::cout << std::endl;
        }

        ~queue_node() {
            while (start != nullptr) {
                node* temp = start;
                start = start->next;
                delete temp;
            }
        }
};

int main(){
    queue_arr<int> tab;
    tab.dequeue();
    tab.enqueue(4);
    tab.seeout();
    tab.dequeue();
    tab.seeout();
    tab.enqueue(8);
    tab.enqueue(88);
    tab.seeout();

    queue_node<int> nod;
    nod.enqueue(5);
    nod.enqueue(10);
    nod.seeout();
    nod.dequeue();
    nod.seeout();

    return 0;
}