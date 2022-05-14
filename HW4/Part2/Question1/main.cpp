//main.cpp
#include <iostream>
#include <BinaryTree.h>


int main(){
    BinaryTree<char> binary_tree_a("binary_tree_a");
    BinaryTree<char> binary_tree_b("binary_tree_b");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(binary_tree_a.IsEmpty()){
        std::cout<<"binary_tree_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"binary_tree_a.IsEmpty() = false"<<std::endl;
    }

    if(binary_tree_b.IsEmpty()){
        std::cout<<"binary_tree_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"binary_tree_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Set1() & Display1() Test--------------"<<std::endl;
    std::cout<<"> Set1(binary_tree_a)"<<std::endl;
    std::cout<<"> Display1(binary_tree_a)"<<std::endl;
    Set1(binary_tree_a);
    Display1(binary_tree_a);

    std::cout<<std::endl;
    std::cout<<"------------Set2() & Display2() Test--------------"<<std::endl;
    std::cout<<"> Set2(binary_tree_b)"<<std::endl;
    std::cout<<"> Display2(binary_tree_b)"<<std::endl;
    Set2(binary_tree_b);
    Display2(binary_tree_b);

    std::cout<<std::endl;
    std::cout<<"------------RootData() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.RootData() = "<<binary_tree_a.RootData()<<std::endl;
    std::cout<<"> binary_tree_b.RootData() = "<<binary_tree_b.RootData()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Inorder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.Inorder() = "<<std::endl;
    binary_tree_a.Inorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.Inorder() = "<<std::endl;
    binary_tree_b.Inorder();

    std::cout<<std::endl;
    std::cout<<"------------NorecInorder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.NorecInorder() = "<<std::endl;
    binary_tree_a.NorecInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.NorecInorder() = "<<std::endl;
    binary_tree_b.NorecInorder();

    std::cout<<std::endl;
    std::cout<<"------------NoStackInorder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.NoStackInorder() = "<<std::endl;
    binary_tree_a.NoStackInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.NoStackInorder() = "<<std::endl;
    binary_tree_b.NoStackInorder();

    std::cout<<std::endl;
    std::cout<<"------------Preorder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.Preorder() = "<<std::endl;
    binary_tree_a.Preorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.Preorder() = "<<std::endl;
    binary_tree_b.Preorder();

    std::cout<<std::endl;
    std::cout<<"------------Postorder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.Postorder() = "<<std::endl;
    binary_tree_a.Postorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.Postorder() = "<<std::endl;
    binary_tree_b.Postorder();

    std::cout<<std::endl;
    std::cout<<"------------LevelOrder() Test--------------"<<std::endl;
    std::cout<<"> binary_tree_a.LevelOrder() = "<<std::endl;
    binary_tree_a.LevelOrder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_b.LevelOrder() = "<<std::endl;
    binary_tree_b.LevelOrder();

    std::cout<<std::endl;
    std::cout<<"------------BinaryTree(bt1, item, bt2) Test--------------"<<std::endl;
    std::cout<<"> char item = 'Z'"<<std::endl;
    char item = 'Z';
    std::cout<<"> BinaryTree<char> binary_tree_c(binary_tree_a, item, binary_tree_b);"<<std::endl;;
    BinaryTree<char> binary_tree_c(binary_tree_a, item, binary_tree_b);
    binary_tree_c.SetName("binary_tree_c");
    std::cout<<"> binary_tree_c.Inorder();"<<std::endl;
    binary_tree_c.Inorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c.NorecInorder() = "<<std::endl;
    binary_tree_c.NorecInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c.NoStackInorder() = "<<std::endl;
    binary_tree_c.NoStackInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c.Preorder();"<<std::endl;
    binary_tree_c.Preorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c.Postorder();"<<std::endl;
    binary_tree_c.Postorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c.LevelOrder();"<<std::endl;
    binary_tree_c.LevelOrder();

    std::cout<<std::endl;
    std::cout<<"------------LeftSubtree() Test--------------"<<std::endl;
    BinaryTree<char> binary_tree_c_left("binary_tree_c_left");
     if(binary_tree_c_left.IsEmpty()){
        std::cout<<"binary_tree_c_left.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"binary_tree_c_left.IsEmpty() = false"<<std::endl;
    }

    std::cout<<"> binary_tree_c_left = binary_tree_c.LeftSubtree();"<<std::endl;
    binary_tree_c_left = binary_tree_c.LeftSubtree();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.Inorder();"<<std::endl;
    binary_tree_c_left.Inorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.NorecInorder() = "<<std::endl;
    binary_tree_c_left.NorecInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.NoStackInorder() = "<<std::endl;
    binary_tree_c_left.NoStackInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.Preorder();"<<std::endl;
    binary_tree_c_left.Preorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.Postorder();"<<std::endl;
    binary_tree_c_left.Postorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_left.LevelOrder();"<<std::endl;
    binary_tree_c_left.LevelOrder();

    std::cout<<std::endl;
    std::cout<<"------------RightSubtree() Test--------------"<<std::endl;
    BinaryTree<char> binary_tree_c_right("binary_tree_c_right");
     if(binary_tree_c_right.IsEmpty()){
        std::cout<<"binary_tree_c_right.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"binary_tree_c_right.IsEmpty() = false"<<std::endl;
    }

    std::cout<<"> binary_tree_c_right = binary_tree_c.RightSubtree();"<<std::endl;
    binary_tree_c_right = binary_tree_c.RightSubtree();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.Inorder();"<<std::endl;
    binary_tree_c_right.Inorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.NorecInorder() = "<<std::endl;
    binary_tree_c_right.NorecInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.NoStackInorder() = "<<std::endl;
    binary_tree_c_right.NoStackInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.Preorder();"<<std::endl;
    binary_tree_c_right.Preorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.Postorder();"<<std::endl;
    binary_tree_c_right.Postorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_c_right.LevelOrder();"<<std::endl;
    binary_tree_c_right.LevelOrder();


    std::cout<<std::endl;
    std::cout<<"------------Copy Constructor() Test--------------"<<std::endl;
    std::cout<<"> BinaryTree<char> binary_tree_d(binary_tree_c);"<<std::endl;
    BinaryTree<char> binary_tree_d(binary_tree_c);
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.Inorder();"<<std::endl;
    binary_tree_d.Inorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.NorecInorder() = "<<std::endl;
    binary_tree_d.NorecInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.NoStackInorder() = "<<std::endl;
    binary_tree_d.NoStackInorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.Preorder();"<<std::endl;
    binary_tree_d.Preorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.Postorder();"<<std::endl;
    binary_tree_d.Postorder();
    std::cout<<std::endl;
    std::cout<<"> binary_tree_d.LevelOrder();"<<std::endl;
    binary_tree_d.LevelOrder();

    std::cout<<std::endl;
    std::cout<<"------------operator==() Test--------------"<<std::endl;
    if(binary_tree_a == binary_tree_c_left){
        std::cout<<"binary_tree_a == binary_tree_c_left is true"<<std::endl;
    }else{
        std::cout<<"binary_tree_a == binary_tree_c_left is false"<<std::endl;
    }

    if(binary_tree_b == binary_tree_c_right){
        std::cout<<"binary_tree_b == binary_tree_c_right is true"<<std::endl;
    }else{
        std::cout<<"binary_tree_b == binary_tree_c_right is false"<<std::endl;
    }

    if(binary_tree_d == binary_tree_c){
        std::cout<<"binary_tree_d == binary_tree_c is true"<<std::endl;
    }else{
        std::cout<<"binary_tree_d == binary_tree_c is false"<<std::endl;
    }

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
