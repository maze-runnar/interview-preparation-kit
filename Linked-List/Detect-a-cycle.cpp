/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/


    #include <unordered_set>
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method

    Node *temp=head;

    unordered_set<Node*> ans;

    while(temp!=NULL)
    {
        if(ans.find(temp)!=ans.end())
            return 1;

        ans.insert(temp);
        temp=temp->next;
    }

    return 0;
}

