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
            cout << "������ ��������!" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        cout << "������ �������!" << endl;
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
            cout << "������ ������!" << endl;
            return;
        }
        cout << endl << "----�������� ������------" << endl;
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
            cout << "������ ������!" << endl;
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
                cout << "������� ������� ��������" << endl;
                break;
            }
            temp = temp->next;
        }

    }

    void remove(int index) {
        if (head == NULL) {
            cout << "������ ������!" << endl;
            return;
        }
        if (index < 1) {
            cout << "������������ ������!" << endl;
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
                cout << "������� �������� �� ������� " << index << endl;
                break;

            }
            temp = temp->next;
        }
    }

    void removeFront() {
        if (head == NULL) {
            cout << "������ ������!" << endl;
            return;
        }
        if (length() == 1) {
            head = NULL;
            cout << "������ ������� ��������" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        cout << "������ ������� ��������" << endl;
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
            cout << "������ ������!" << endl;
            return NULL;
        }
        if (index < 0) {
            cout << "������������ ������!" << endl;
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
        cout << "������ ��:" << endl;
        cout << "1: ������ �������" << endl;
        cout << "2: �������� �������" << endl;
        cout << "3: �������� �� �������" << endl;
        cout << "4: ������� ���� ������" << endl;
        cout << "5: ������� ������ ������� ��������" << endl;
        cout << "6: ������ ������" << endl;
        cout << "7: ������� �� �������" << endl;
        cout << "8: �����" << endl;
        cin >> ch;
        cout << "====================================" << endl;
        switch (ch)
        {
        case 1:
            cout << "������ ������� ��� ��������:" << endl;
            cin >> item;
            list->add(item);
            break;
        case 2:
            list->remove();
            break;
        case 3:
            cout << "������ ������:" << endl;
            cin >> index;
            list->remove(index);
            break;
        case 4:
            list->displayAll();
            cout << endl;
            break;
        case 5:
            cout << "������, ������ �������� �������: ";
            cin >> index;
            list->print_amount(index);
        case 6:
            list->reverse();
            cout << endl;
            break;
        case 7:
            cout << "������ ������:" << endl;
            cin >> index;
            cout << "������� �� ������� " << index << ": " << list->get(index) << endl;
            break;
        case 8:
            quit = true;
            break;
        default:
            cout << "������������ ����" << endl;
            break;
        }
    } while (!quit);
}

int main() {
    system("chcp 1251");
    LinkedList<int> intlist;
    LinkedList<double> dlist;
    LinkedList<string> stringlist;

    cout << "�������� ������ � ������������ �������" << endl;
    input(&intlist);
    cout << "�������� ������ � ������ �������" << endl;
    input(&dlist);
    cout << "�������� ������ � ������� ������" << endl;

    input(&stringlist);
    return 0;
}