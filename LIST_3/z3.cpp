#include <iostream>

// do podpunktu a
template <typename T>
class stack_arr{
    private:
        static const int max_size = 1000; //przykładowa pojemność
        T tab[max_size];
        int top = 0;
    public:
        void push(T x){
            if (top >= max_size){
                std::cout << "Stack overflow xd" << std::endl;
                return;
            }
            tab[top] = x;
            top ++;
        };

        T pop(){
            if (top <= 0){
                std::cout << "Stack za malutki jest wykracza poniżej 0" << std::endl;
                return T(); //czemu musze zwracać obiekt domyślny a nie moge nic
            }
            top--;
            return tab[top]; //rozumiem że mam zwrócić element który usuwam
        };

        bool isEmpty(){
            if (top == 0){
                return true;
            }
            return false;
        };

        void seeout(){
            std::cout << "Elementy stacku: ";
            for (int i = 0; i<top; i++){
                std::cout << tab[i] << " ";
            }
            std::cout << std::endl;
        }
};


template <typename T>
class stack_node{
    private:
        struct node{
            T key;
            node* next = nullptr;
            node(T k, node* n = nullptr) : key(k), next(n) {}
        };
        node *L = nullptr;
    public:
        void push(T x){
            L = new node(x, L);
        };

        T pop(){
            if ( L == nullptr ){
                return T();
            }
            node *temp = L;
            L = L->next;
            T ret = temp->key;
            delete temp;
            return ret;
        };

        bool isEmpty(){
            if (L == nullptr ) return true;
            return false;
        }

        void seeout(){
            std::cout << "Elementy stacku: ";
            for (node *p = L; p != nullptr; p=p->next){
                std::cout << p->key << " ";
            }
            std::cout << std::endl;
        }

        ~stack_node() {
            node* p = L;
            while (p != nullptr) {
                node* temp = p;
                p = p->next;
                delete temp;
            }
        }

};

int main(){
    // stack_arr<int> tab;
    // tab.pop();
    // tab.push(4);
    // tab.seeout();
    // tab.pop();
    // tab.seeout();
    // tab.push(8);
    // tab.push(88);
    // tab.seeout();

    stack_node<int> nod;
    nod.push(5);
    nod.push(10);
    nod.seeout();
    nod.pop();
    nod.seeout();

    return 0;
}