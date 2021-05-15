#include<iostream>
using namespace std;

template<typename T>class Node {
private:
    T data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node() {
        this->next = NULL;
    }
};

template<typename T>class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() {
        this->head = NULL;
    }

    void add(T item) {
        Node<T>* node = new Node<T>[1];
        node->data = item;
        if (head == NULL) {
            head = node;
            head->next = node;
            cout << "Список створено!" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        cout << "Додано елемент!" << endl;
    }


    int length() {
        if (head == NULL) return 0;
        int len = 1;
        Node<T>* temp = head;
        while (temp->next != head) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void displayAll() {
        if (head == NULL) {
            cout << "Список пустий!" << endl;
            return;
        }
        cout << endl << "----Елементи списку------" << endl;
        Node<T>* temp = head;
        while (true) {
            cout << temp->data << " | ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << endl << "--------------------------" << endl;
    }

    void remove() {
        if (head == NULL) {
            cout << "Список пустий!" << endl;
            return;
        }

        if (length() == 1) {
            head = NULL;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != head) {
            if (temp->next->next == head) {
                temp->next = head;
                cout << "останній елемент видалено" << endl;
                break;
            }
            temp = temp->next;
        }

    }

    void remove(int index) {
        if (head == NULL) {
            cout << "Список пустий!" << endl;
            return;
        }
        if (index < 1) {
            cout << "Недопустимий індекс!" << endl;
            return;
        }
        if (index == 1 || index % length() == 1) {
            removeFront();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < index; i++) {
            if (i = index - 1) {
                temp->next = temp->next->next;
                cout << "Елемент видалено по індексу " << index << endl;
                break;

            }
            temp = temp->next;
        }
    }

    void removeFront() {
        if (head == NULL) {
            cout << "Список пустий!" << endl;
            return;
        }
        if (length() == 1) {
            head = NULL;
            cout << "Перший елемент видалено" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        cout << "Перший елемент видалено" << endl;
    }

    void reverse()
    {
        if (head == NULL)
            return;
        Node<T>* prev = NULL;
        Node<T>* current = head;
        Node<T>* next;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        head = prev;
    }


    T get(int index) {
        if (head == NULL) {
            cout << "Список пустий!" << endl;
            return NULL;
        }
        if (index < 0) {
            cout << "Недопустимий індекс!" << endl;
            return NULL;
        }
        if (index == 0) {
            return head->data;
        }
        int count = 0;
        T res;
        Node<T>* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void print_amount(int amt) {
        Node<T>* temp = head;
        for (int i = 0; i < amt; i++) {
            cout << temp->data << " | ";
            temp = temp->next;
        }
    }
};
template <typename T>
void input(LinkedList<T>* list) {
    int ch, index;
    bool quit = false;
    T item;
    do {
        cout << "====================================" << endl;
        cout << "Оберіть дію:" << endl;
        cout << "1: Додати елемент" << endl;
        cout << "2: Видалити елемент" << endl;
        cout << "3: Видалити по індексу" << endl;
        cout << "4: Вивести весь список" << endl;
        cout << "5: Вивести задану кількість елементів" << endl;
        cout << "6: Реверс списку" << endl;
        cout << "7: Елемент по індексу" << endl;
        cout << "8: вихід" << endl;
        cin >> ch;
        cout << "====================================" << endl;
        switch (ch)
        {
        case 1:
            cout << "Введіть елемент для введення:" << endl;
            cin >> item;
            list->add(item);
            break;
        case 2:
            list->remove();
            break;
        case 3:
            cout << "Введіть індекс:" << endl;
            cin >> index;
            list->remove(index);
            break;
        case 4:
            list->displayAll();
            cout << endl;
            break;
        case 5:
            cout << "Введіть, скільки елементів вивести: ";
            cin >> index;
            list->print_amount(index);
        case 6:
            list->reverse();
            cout << endl;
            break;
        case 7:
            cout << "Введіть індекс:" << endl;
            cin >> index;
            cout << "Елемент по індексу " << index << ": " << list->get(index) << endl;
            break;
        case 8:
            quit = true;
            break;
        default:
            cout << "неправильний вибір" << endl;
            break;
        }
    } while (!quit);
}

int main() {
    system("chcp 1251");
    LinkedList<int> intlist;
    LinkedList<double> dlist;
    LinkedList<string> stringlist;

    cout << "Ведеться робота з цілочисловим списком" << endl;
    input(&intlist);
    cout << "Ведеться робота з дійсним списком" << endl;
    input(&dlist);
    cout << "Ведеться робота з списком стрінгів" << endl;

    input(&stringlist);
    return 0;
}