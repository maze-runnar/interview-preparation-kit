/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>

bool checkBST(Node* node) {
        
 return(isBSTUtil(node, INT_MIN, INT_MAX));
		
	}


 
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) &&
        isBSTUtil(node->right, node->data+1, max); 
}  
