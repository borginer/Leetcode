//https://neetcode.io/problems/copy-linked-list-with-random-pointer

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Node {
    public:
    int val;
    Node* next;
    Node* random;
        
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) { return NULL; }
    
    Node* p = head;
    Node* new_head = new Node(head->val);

    vector<Node*> next_ptrs;

    new_head->random = head->random;
    p = head->next;   
    next_ptrs.push_back(head->next);
    head->next = new_head;

    Node* q = new_head;
    
    while(p) {
        q->next = new Node(p->val);
        q = q->next;

        q->random = p->random;

        next_ptrs.push_back(p->next);
        p->next = q;
        p = next_ptrs.back();
    }
    q->next = NULL;

    q = new_head;

    while(q) {
        if (q->random) {
            q->random = q->random->next;
        } else {
            q->random = NULL;
        }
        q = q->next;
    }

    p = head;
    for(int i = 0; i < next_ptrs.size(); i++) {
        p->next = next_ptrs[i];
        p = p->next;
    }

    return new_head;
}

int main() {
    Node a(3);
    Node b(7);
    Node c(4);
    Node d(5);


    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    a.random = NULL;
    b.random = &d;
    c.random = &a;
    d.random = &b;

    Node* copy = copyRandomList(&a);
    Node* p = &a;

    while(copy) {
        cout << "copy: " + std::to_string(copy->val);
        if (copy->random) { cout << " random: " + std::to_string(copy->random->val); }
        cout << endl;
        
        cout << "original: " + std::to_string(copy->val);
        if (p->random) { cout << " random: " + std::to_string(p->random->val); }
        cout <<endl;

        copy = copy->next;
        p = p->next;
    }
}