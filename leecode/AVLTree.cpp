
/*
*This is a library to build an AVL tree.
*The properity of AVL tree is height balance, i.e., |height(left) - height(right)| <= 1.
*/
#include "printlib.h"
#include "tree.h"

constexpr int C_LEAFHEIGHT = 0;
constexpr int C_NULLHEIGHT = -1;
constexpr int C_MAXSKEW = 2;

#define GETLHEIGHT(node) (node->lchild) ? (node->lchild->height) : C_NULLHEIGHT
#define GETRHEIGHT(node) (node->rchild) ? (node->rchild->height) : C_NULLHEIGHT
#define INSERTNODE(pa,node) (pa->val > node->val) ? (pa->lchild = node) : (pa->rchild = node)

Node* createImbalanceTree(const std::string_view& direction);
Node* adjImbalance(Node* pivot);
Node* updateTreeHeight(Node* newpivot);

Node* insert(Node* node, Node* root)
{
    if(!root){
        root = node;
        return root;
    }

    Node* prev = nullptr;
    Node* tmp = root;
    while(tmp){
        if((node->val) == (tmp->val)) break;
        if((node->val) > (tmp->val)){
            prev = tmp;
            tmp = tmp->rchild;
        }else{ //node->val < tmp->val
            prev = tmp;
            tmp = tmp->lchild;
        }
    }

    if(!tmp){
        //(prev->val > node->val) ? (prev->lchild = node) : (prev->rchild = node);
        INSERTNODE(prev,node);
        node->pa = prev;
        node->height = 0;
    }

    //update height and adjust
    Node* imbalanceNode = updateTreeHeight(node);
    while(imbalanceNode){
        Node* pa = imbalanceNode->pa;
        node = adjImbalance(imbalanceNode);
        node->pa = pa;
        if(pa){
            //(imbalanceNode->pa->val > node->val) ? (imbalanceNode->pa->lchild = node) : (imbalanceNode->pa->rchild = node);
            INSERTNODE(pa, node);
        }
        imbalanceNode = updateTreeHeight(node);
    }
    
    if(!node->pa){
        root = node;
    }
    return root;
}

Node* buildAVLTree(const vector<int>& arr){
    Node* root = nullptr;

    for(const auto& val : arr){
        Node* node = new Node;
        node->val = val;
        node->height = 0;
        node->pa = nullptr;
        node->lchild = nullptr;
        node->rchild = nullptr;
        root = insert(node, root);
    }
    return root;
}

/*
*    x                                y  
*   / \     turn left around x       / \
*   A  y    ------------------>     x   C
*     / \                          / \ 
*    B   C                        A   B
*/
//x and y nodes must not be nullptr, A, B, C may be nullpter. So please check A, B, C before using.
Node* leftRotation(Node* pivot){
    Node* root = pivot->rchild;
    root->pa = nullptr;

    pivot->rchild = root->lchild;
    if(root->lchild) root->lchild->pa = pivot;

    root->lchild = pivot;
    // root->pa = pivot->pa;
    // if(pivot->pa){
    //     INSERTNODE(pivot->pa,root);
    // }
    pivot->pa = root;

    //update pivot and root height, A, B, and C 's height not change.
    int plheight = GETLHEIGHT(pivot);
    int prheight = GETRHEIGHT(pivot);
    pivot->height = max(plheight, prheight) + 1;

    int tlheight = GETLHEIGHT(root);
    int trheight = GETRHEIGHT(root);
    root->height = max(tlheight, trheight) + 1;

    return root;
}

/*
*    x                                y  
*   / \     turn right around y      / \
*   A  y    <------------------     x   C
*     / \                          / \ 
*    B   C                        A   B
*/
//x and y nodes must not be nullptr, A, B, C may be nullpter. So please check A, B, C before using.
Node* rightRotation(Node* pivot){
    Node* root = pivot->lchild;
    root->pa == nullptr;

    pivot->lchild = root->rchild;
    if(root->rchild) root->rchild->pa = pivot;

    root->rchild = pivot;
    // root->pa = pivot->pa;
    // if(pivot->pa){
    //     INSERTNODE(pivot->pa,root);
    // }
    pivot->pa = root;

    //update pivot and root height, A, B, and C 's height not change.
    int plheight = GETLHEIGHT(pivot);
    int prheight = GETRHEIGHT(pivot);
    pivot->height = max(plheight, prheight) + 1;

    int tlheight = GETLHEIGHT(root);
    int trheight = GETRHEIGHT(root);
    root->height = max(tlheight, trheight) + 1;

    return root;
}

string_view judegImbalanceType(Node* imbalanceNode){
    int lHeight = GETLHEIGHT(imbalanceNode);
    int rHeight = GETRHEIGHT(imbalanceNode);
    int llHeight = (imbalanceNode->lchild) ? ( (imbalanceNode->lchild->lchild) ? (imbalanceNode->lchild->lchild->height) : C_NULLHEIGHT) : C_NULLHEIGHT;
    int lrHeight = (imbalanceNode->lchild) ? ( (imbalanceNode->lchild->rchild) ? (imbalanceNode->lchild->rchild->height) : C_NULLHEIGHT) : C_NULLHEIGHT;
    int rlHeight = (imbalanceNode->rchild) ? ( (imbalanceNode->rchild->lchild) ? (imbalanceNode->rchild->lchild->height) : C_NULLHEIGHT) : C_NULLHEIGHT;
    int rrHeight = (imbalanceNode->rchild) ? ( (imbalanceNode->rchild->rchild) ? (imbalanceNode->rchild->rchild->height) : C_NULLHEIGHT) : C_NULLHEIGHT;

    string_view imbalanceType = ((lHeight - rHeight) > 0) ? ( (llHeight - lrHeight) > 0 ? "LL" : "LR" ) : ( (rlHeight - rrHeight) > 0 ? "RL" : "RR" );
    
    return imbalanceType;
}

Node* adjLLImblance(Node* pivot){
    return rightRotation(pivot);
}

Node* adjRRImblance(Node* pivot){
    return leftRotation(pivot);
}

Node* adjLRImblance(Node* pivot){
    //turn left around the pivot->lchild
    Node* lchild = leftRotation(pivot->lchild);

    //relink the pivot->lchild
    pivot->lchild = lchild;
    lchild->pa = pivot;

    //turn right around the pivot
    Node* root = rightRotation(pivot);
    return root;
}

Node* adjRLImblance(Node* pivot){
    //turn right around the pivot->rchild
    Node* rchild = rightRotation(pivot->rchild);

    //relink the pivot->rchild
    pivot->rchild = rchild;
    rchild->pa = pivot;

    //turn left around the pivot
    Node* root = leftRotation(pivot);
    return root;
} 

Node* adjImbalance(Node* pivot){
    string_view imbalanceType = judegImbalanceType(pivot);
    Node* root = nullptr;
    if(imbalanceType == "LL"){
        root = adjLLImblance(pivot);
    }
    if(imbalanceType == "LR"){
        root = adjLRImblance(pivot);
    }
    if(imbalanceType == "RL"){
        root = adjRLImblance(pivot);
    }
    if(imbalanceType == "RR"){
        root = adjRRImblance(pivot);
    }
    return root;
}

//updating the height from the newpivot, while computing the skew.
//once occuring imbalance, return the node. 
Node* updateTreeHeight(Node* newnode){
    Node* imbalanceNode = nullptr;
    Node* tmp = newnode;

    while(tmp){
        int lHeight = GETLHEIGHT(tmp);
        int rHeight = GETRHEIGHT(tmp);

        //judeg imblance
        if(abs(lHeight - rHeight) >= C_MAXSKEW){
            imbalanceNode = tmp;
            break;
        }
        tmp->height = max(lHeight, rHeight) + 1;
        tmp = tmp->pa;
    }

    return imbalanceNode;
}

void testLeftRotation(){
    //creat a RR imbalance
    Node* root = createImbalanceTree("RR");
    cout << "tree before left rotation\n";
    printTree(root);

    root = leftRotation(root);
    cout << "tree after left rotation" << endl;
    printTree(root);
}

void testRightRotation(){
    //creat a RR imbalance
    Node* root = createImbalanceTree("LL");

    cout << "tree before right rotation\n";
    printTree(root);
    root = rightRotation(root);
    cout << "tree after right rotation\n";
    printTree(root);
}

void testAdjLRImbalance(){
    //creat a LR imbalance tree
    Node* root = createImbalanceTree("LR");

    cout << "tree before adjustment\n";
    printTree(root);
    cout << "pa of node 2 is " << root->lchild->pa->val << endl;

    root = adjLRImblance(root);
    cout << "tree after adjustment\n";
    printTree(root);
    cout << "pa of node 2 is " << root->lchild->pa->val << endl;
}

void testJudgeImbalanceType(){
    Node* root = createImbalanceTree("RR");
    cout << "The imbalanceType is: RR, " << "The judeg answer is: " << judegImbalanceType(root) << endl;

    root = createImbalanceTree("LL");
    cout << "The imbalanceType is: LL, " << "The judeg answer is: " << judegImbalanceType(root) << endl;

    root = createImbalanceTree("RL");
    cout << "The imbalanceType is: RL, " << "The judeg answer is: " << judegImbalanceType(root) << endl;

    root = createImbalanceTree("LR");
    cout << "The imbalanceType is: LR, " << "The judeg answer is: " << judegImbalanceType(root) << endl;
}

void testUpdateHeight(){
    Node* root = createImbalanceTree("RR");
    Node* pivot = updateTreeHeight(root);
    cout << "the minimum imbalance tree: \n";
    printTree(pivot);
    if(pivot){
        Node* newroot = adjImbalance(pivot);
        cout << "after adjusting, the tree:\n";
        printTree(newroot);
        cout << "after adjusting, the updateHeight should return nullptr.\n";
        cout << "after adjusting, the updateHeight return value is nullptr? " << std::boolalpha << (updateTreeHeight(newroot) == nullptr) << endl; 
    }
} 

void testInsert(){
    Node* root = nullptr;
    for(int i = 1 ; i <= 11; i++){
        Node* node = new Node;
        node->val = i;
        node->height = 0;
        node->pa = nullptr;
        node->lchild = nullptr;
        node->rchild = nullptr;
        root = insert(node, root);
    }
    cout << "the AVL tree after inseration: \n";
    printTree(root);
}

void testBuild(){
    const vector<int> tree = { 1,2,3,9,8,7,6};
    Node* root = buildAVLTree(tree);
    printTree(root);
}

int main(){

    #ifdef __TESTRR__
    testLeftRotation();
    #endif

    #ifdef __TESTLL__
    testRightRotation();
    #endif

    #ifdef __TESTLR__
    testAdjLRImbalance();
    #endif

    #ifdef __TESTTYPE__
    testJudgeImbalanceType();
    #endif

    #ifdef __TESTHEI__
    testUpdateHeight();
    #endif

    #ifdef __TESTIN__
    testInsert();
    #endif

    #ifdef __TESTBI__
    testBuild();
    #endif

    return 0;
}

Node* createImbalanceTree(const std::string_view& direction){
    //creat a RR imbalance
    Node* root = new Node;
    Node* child1 = new Node;
    Node* child2 = new Node; 

    root->val = 1;
    child1->val = 2;
    child2->val = 3;

    root->height = 0;
    child1->height = 0;
    child2->height = 0;

    root->pa = nullptr;
    root->rchild = (direction[0] == 'R') ? child1 : nullptr;
    root->lchild = (direction[0] == 'L') ? child1 : nullptr;
    root->height += 1;

    child1->pa = root;
    child1->rchild = (direction[1] == 'R') ? child2 : nullptr;
    child1->lchild = (direction[1] == 'L') ? child2 : nullptr;
    child1->height += 1;
    root->height += 1;

    child2->pa = child1;
    child2->rchild = nullptr;
    child2->lchild = nullptr;
    
    return root;
}