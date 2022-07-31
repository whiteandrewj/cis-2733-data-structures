#include <iostream>

using namespace std;

struct node {
 int data;
 struct node* left;
 struct node* right;
};

static int lookup(struct node* node, int target) {
 // 1. Base case == empty tree
 // in that case, the target is not found so return false
 if (node == NULL) {
    return(false);
 } else {
    // 2. see if found here
    if (target == node->data) { 
        return(true);
    } else {
    // 3. otherwise recur down the correct subtree
        if (target < node->data) { return(lookup(node->left, target)); }
        else { return(lookup(node->right, target)); }
    }
 }
}

struct node* newNode(int data) {
 struct node* node = new(struct node); // "new" is like "malloc"
 node->data = data;
 node->left = NULL;
 node->right = NULL;
 return(node);
}

struct node* insert(struct node* node, int data) {
// 1. If the tree is empty, return a new, single node
 if (node == NULL) {
    return(newNode(data));
 } else {
 // 2. Otherwise, recur down the tree
    if (data <= node->data) { 
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
 return(node); // return the (unchanged) node pointer
 }
}

/*------------ Begin Exercises --------------*/

//problem 1a
struct node* build123a() {
    node* element1_1 = newNode(1);
    node* element1_2 = newNode(2);
    node* element1_3 = newNode(3);
    element1_2->left = element1_1;
    element1_2->right = element1_3;
    return element1_2;
}
//problem 1b
struct node* build123b() {
    node* element1_4 = newNode(2);
    element1_4->left = newNode(1);
    element1_4->right = newNode(3);
    return element1_4;
}
//problem 1c
struct node* build123c() {
    //my original solution -- insert(insert(insert(NULL,2),1),3);
    node* element1_5 = NULL;
    element1_5 = insert(element1_5,2);
    element1_5 = insert(element1_5,1);
    element1_5 = insert(element1_5,3);
    return element1_5;
}
//problem #2
int size(struct node* node) {
    /* my original solution. attempted to check if node was empty before recursively calling size()
    int count = 0;
    //base case if tree is empty
    if (node == NULL) { return 0; }
    //add this node to count
    else { count = count + 1; }
    if (node->left != NULL) {
        count = count + size(node->left);
    }
    if (node->right != NULL) {
        count = count + size(node->right);
    }
    return count;
    */

    if (node == NULL) {
        return 0;
    } else {
        return size(node->left) + 1 + size(node->right);    
    }
}
//problem #3
int maxDepth(struct node* node) {
    /*my original solution. am traversing the tree twice instead of storing the result.
    if (node == NULL) {
        return 0;
    } else {
        if (maxDepth(node->left) >= maxDepth(node->right)) {
            return 1 + maxDepth(node->left);
        } else {
            return 1 + maxDepth(node->right);
        }
    }
    */
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        if (leftDepth < rightDepth) {
            return rightDepth + 1;
        } else {
            return leftDepth + 1;
        }
    }
}
//problem 4
/* I solved using recursion rather than while loop, tested in main() */
int minValue(struct node* node) {
    if (node->left == NULL) {
        return node->data;
    } else {
        return minValue(node->left);
    }
}
//problem #5
void printTree(struct node* node) {
    /* first attmpt
    if (node == NULL) { cout << "tree is empty" << endl;}
    if (node->left == NULL) { cout << node->data << " "; }
    else { printTree(node->left); }
    if (node->right != NULL) { printTree(node->right); }
    */
    /*second attempt following hint
    if (node == NULL) { break; }
    printTree(node->left);
    cout << node->data;
    printTree(node->left);
    */
    if (node == NULL) { return; }
    printTree(node->left);
    cout << node->data << " ";
    printTree(node->right);   
}

int main()
{
    node* root = NULL;
    root = insert(root,4);
    root = insert(root,2);   
    root = insert(root,5);
    root = insert(root,1);
    root = insert(root,3);

    cout << "the min value is: " << minValue(root) << endl;

    printTree(root);
    cout << endl;




 
    return 0;
}
