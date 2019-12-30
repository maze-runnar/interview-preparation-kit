/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
boolean checkBST(Node root, int minValue, int maxValue) {
    if (root == null) {
        return true;
    }
    
    if (root.data < minValue || root.data > maxValue) {
        return false;
    }
    
    return (    checkBST(root.left, minValue, root.data - 1) 
            &&  checkBST(root.right, root.data + 1, maxValue)
            );
}
    
boolean checkBST(Node root) {
    return checkBST(root, 0, 10000);
}
