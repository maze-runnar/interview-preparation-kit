#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* new_node=new DoublyLinkedListNode(data);
    if(head==NULL)
    {
        head=new_node;
    }
    else if(head->next==NULL)
    {
        if(head->data>data)
        {
            head->prev=new_node;
            new_node->next=head;
            head=new_node;
        }
        else{
            head->next=new_node;
            new_node->prev=head;
        }
    }
    else{
        DoublyLinkedListNode* temp=head;
        DoublyLinkedListNode* pre_temp=head;
        while(temp->next!=NULL && temp->data<data)
        {
            pre_temp=temp;
            temp=temp->next;
        }
        if(temp->prev==NULL)
        {
            temp->prev=new_node;
            new_node->next=temp;
            head=new_node;
        }
       else if(temp->next==NULL)
        {
            if(temp->data<data)
            {
                temp->next=new_node;
                new_node->prev=temp;
            }
            else
            {
                pre_temp->next=new_node;
                new_node->prev=pre_temp;
                new_node->next=temp;
                temp->prev=new_node;
            }
        }
        else
        {
            pre_temp->next=new_node;
            new_node->prev=pre_temp;
            new_node->next=temp;
            temp->prev=new_node;
        }
    }
    return head;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}

