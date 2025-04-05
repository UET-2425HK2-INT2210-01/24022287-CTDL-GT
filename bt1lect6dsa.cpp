#include<iostream>
using namespace std;
struct Node{
     int data; //Lưu giá trị của nút
    Node*right;  // trỏ đến phải
    Node*left;   // trỏ đến trái
    Node(int val): data(val),left(nullptr),right(nullptr) {} // khởi tạo giá trị của 1 node,các con trỏ trỏ đến nullptr
};
class BST{
public:
    Node*root;
    BST():root(nulllptr) {}
    Node*insert(Node*node,int value){
        if(!node) return new Node(value); //Nếu node->nullptr tạo node mới(value)
        if(val<node->data)
            node->left=insert(node->left,value); //tìm bên trái để chèn thêm
        else
            node->right=insert(node->right,value); //ngược lại
        return node;
    }
    Node*findMin(Node*node){
        while(node && node->left) //Nếu node và node->left !=nullptr
            node=node->left;  //duyệt tiếp
        return node;//lưu node nhỏ nhất
    }
    Node* remove(Node*node,int val){
      if(!node) return nullptr; //nếu cây rỗng trả về nullptr
      if(val<node->data){
        node->left=remove(node->left,val); //xóa bên trái
      }else if{
          node->right=remove(node->right,val);//ngược lại
      }else{ //val==node->data
          if(node->right==nullptr){ //nếu node cha đến con phải bằng null
            Node*temp=Node->left; //tạo node temp
            delete node;//xóa node
            return temp;//lưu node temp
          }
          if (!node->left) { //ngược lại
                Node* temp = node->right;
                delete node;
                return temp;
            }
            //nếu có đủ cả 2 con
            Node*temp=findMin(node->right);//tìm node bên phải nhỏ nhất
            Node->data=temp->data; //thay thế
            node->right=remove(node->right,temp->data);//xóa nút đó
      }
    }
    void inorder(Node* node) { // duyệt theo inorder
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};
int main() {
    BST tree; //tạo đối tượng tree
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; //tạo mảng
    for (int val : values)
        tree.root = tree.insert(tree.root, val); //chèn các phần tử trên vào cây

    cout << "BST sau khi chèn: ";
    tree.inorder(tree.root);
    cout << endl;

    int insertValues[] = {14, 0, 35};
    for (int val : insertValues)
        tree.root = tree.insert(tree.root, val);//chèn thêm vào cây

    cout << "BST sau khi được thêm vào: ";
    tree.inorder(tree.root);
    cout << endl;

    int deleteValues[] = {6, 13, 35};
    for (int val : deleteValues)
        tree.root = tree.remove(tree.root, val);//xóa khỏi cây

    cout << "BST sau khi xóa: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}


