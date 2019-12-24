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
