#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void DeleteNodes(Node*& head, int value) {
    Node** curr = &head;
    while (*curr) {
        if ((*curr)->data == value) {
            Node* temp = *curr;
            *curr = (*curr)->next;
            delete temp;
        } else {
            curr = &((*curr)->next);
        }
    }
}

void PrintList(const Node* head) {
    const Node* curr = head;
    while (curr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);

    std::cout << "Original list: ";
    PrintList(head);

    DeleteNodes(head, 2);
    std::cout << "After deleting nodes with value 2: ";
    PrintList(head);

    DeleteNodes(head, 1);
    std::cout << "After deleting nodes with value 1: ";
    PrintList(head);

    return 0;
}
