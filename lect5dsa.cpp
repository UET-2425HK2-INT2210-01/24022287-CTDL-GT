#include<iostream>
using namespace std;
struct Node{
    int value;//giá trị của nút
    Node*firstChild; //con đầu tiên
    Node*nextSibling;//ae kế tiếp
    Node(int val):value(val),firstChild(nullptr),nextSibling(nullptr){} //khởi tạo giá trị đầu tiên cho value,các node trỏ đến nullptr
};
class Tree {
private:
    Node*root; //gốc
    Node*findNode(Node*node,int value){//tìm node
        if(!node) return nullptr; //nếu node trỏ đến null trả lại nullptr
        if(node->value==value) return node; //nếu giá trị của node =value trả về node
        Node*found=findNode(node->firstChild,value);
        return found ? found : findNode(node->nextSilbling,value); //nếu bằng thì return found còn ko tìm trong các ae kế tiếp
    }
    // Tìm chiều cao
    ỉn TreeHeight(Node*node){
        if(!node) return -1; //nếu node là nullptr trả về -1
        int chidHeight=TreeHeight(node->firstChid); //chiều cao của con đầu tiên
        int sillingHeght=TreeHeight(node->nextSibling);//chiều cao của con kế tiếp
        return max(childHeight,siblingHeight)+1; //chọn giá trị lớn hơn và cộng thêm 1
    }
    // duyệt theo preOrder
    void preOrder(Node*node){
        if(!node) return;
        cout<<node->value<<" ";
         preorder(node->firstChild);
        preorder(node->nextSibling);
    }
    // duyệt theo postOrder
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->firstChild);
        cout << node->value << " ";
        postorder(node->nextSibling);
    }
    bool isBinaryTree(Node*node){ //kiểm tra xem có phải cây nhị phân ko
        if(!node) return true;
        int count=0;
        for(Node*child=node->firstChild,child,child=nextSibling) count++;//vòng lặp từ con đầu tiên đến hết
        if(count>2) return false; //nếu count>2 trả lạo false
        return isBinaryTree(node->firstChild) && isBinaryTree(node->nextSibling);
    }
    //duyệt theo inOrder
    void inOrder(Node*node){
        if(!node) return;
        Node*first=node->firstChild;
        Node*second;
        if(first){
            second=first->nextsibling;
        }else{
            second=nullptr;
        }
        inorder(first);
        cout << node->value << " ";
        inorder(second);
    }
    public:
    Tree() : root(nullptr) {}
     //thêm 1 cạnh vào cây
    void addEdge(int u, int v) {
        if (!root) root = new Node(u);
        Node* parent = findNode(root, u);
        if (!parent) return;
        Node* child = new Node(v);
        if (!parent->firstChild) parent->firstChild = child;
        else {
            Node* sibling = parent->firstChild;
            while (sibling->nextSibling) sibling = sibling->nextSibling;
            sibling->nextSibling = child;
        }
    }
     //gọi các hàm có sãn để tính toán bài toán
    void solve() {
        cout << treeHeight(root) << endl;
        preorder(root); cout << endl;
        postorder(root); cout << endl;
        if (isBinaryTree(root)) inorder(root);
        else cout << "NOT BINARY TREE";
        cout << endl;
    }
};

int main() {
    int N, M, u, v;
    cin >> N >> M;
    Tree tree;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    tree.solve();
    return 0;
}
