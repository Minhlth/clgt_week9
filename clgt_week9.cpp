#include <iostream>
using namespace std;

struct Node {
    char word[100];
    Node* next;

    Node(const char* w) {
        int i = 0;

        while (w[i] != '\0') {
            word[i] = w[i];
            i++;
        }
        word[i] = '\0';
        next = nullptr;
    }
};

void addWord(Node*& head, const char* word) {
    Node* newNode = new Node(word);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool compareWords(const char* word1, const char* word2) {
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0') {
        if (word1[i] != word2[i]) {
            return false;
        }
        i++;
    }
    return word1[i] == word2[i];
}

const char* findWord(Node* head) {
    int maxCount = 0;
    const char* most = nullptr;

    for (Node* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
        int count = 0;
        for (Node* temp2 = head; temp2 != nullptr; temp2 = temp2->next) {
            if (compareWords(temp1->word, temp2->word)) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            most = temp1->word;
        }
    }
    return most;
}

void remove(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (compareWords(temp->word, temp->next->word)) {
            Node* Delete = temp->next;
            temp->next = temp->next->next;
            delete Delete;
        }
        else {
            temp = temp->next;
        }
    }
}

int countWords(Node* head) {
    int count = 0;
    Node* temp1 = head;
    while (temp1 != nullptr) {
        bool only = true;
        Node* temp2 = head;
        while (temp2 != temp1) {
            if (compareWords(temp1->word, temp2->word)) {
                only = false;
                break;
            }
            temp2 = temp2->next;
        }
        if (only) {
            count++;
        }
        temp1 = temp1->next;
    }
    return count;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addWord(head, "cay");
    addWord(head, "xanh");
    addWord(head, "xanh");
    addWord(head, "thi");
    addWord(head, "la");
    addWord(head, "cung");
    addWord(head, "xinh");

    cout << "Danh sach tu:  ";
    printList(head);

    const char* most = findWord(head);
    cout << "Tu xuat hien nhieu nhat:  " << most << endl;

    remove(head);
    cout << "Danh sach sau khi bo:  ";
    printList(head);

    int Count = countWords(head);
    cout << "So tu con lai: " << Count << endl;

    return 0;
}
