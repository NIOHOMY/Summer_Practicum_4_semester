#pragma once
#include<iostream>
#include"NewTasksStudentModel.h"

using std::cout; using std::cin; using std::max;
//------------------------------------------------------------------------------------
//	AVL - сбалансир бин дерево поиска
//------------------------------------------------------------------------------------
using AVLTInfo = NewTasksStudentModel;
ref class AVLTreeNode
{
public:
    AVLTInfo key;
    int height;
    AVLTreeNode^ leftChild;
    AVLTreeNode^ rightChild;
    AVLTreeNode(AVLTInfo tempKey)
    {
        height = 0;
        key = tempKey;
        /*leftChild = nullptr;
        rightChild = nullptr;*/
    }
};

ref class AVLTree
{
private:

    AVLTreeNode^ root;

    AVLTreeNode^ Search(AVLTInfo, AVLTreeNode^);
    AVLTreeNode^ LeftRotate(AVLTreeNode^);
    AVLTreeNode^ LeftAndRightRotate(AVLTreeNode^);
    AVLTreeNode^ RightRotate(AVLTreeNode^);
    AVLTreeNode^ RightAndLeftRotate(AVLTreeNode^);

    int GetHeight(AVLTreeNode^);

    AVLTreeNode^ Insert(AVLTInfo, AVLTreeNode^);
    AVLTreeNode^ Delete(bool%, AVLTInfo, AVLTreeNode^);
public:
    AVLTree();
    AVLTreeNode^ getRoot();
    void Insert(AVLTInfo);
    bool Search(AVLTInfo);
    bool Delete(AVLTInfo);
    bool Updata(AVLTInfo, AVLTInfo);
};

//------------------------------------------------------------------------------------

AVLTree::AVLTree()
{
    root = nullptr;
}

// текущая высота ноды

int AVLTree::GetHeight(AVLTreeNode^ tempNode)
{
    return nullptr == tempNode ? -1 : tempNode->height;
}

inline AVLTreeNode^ AVLTree::getRoot()
{
    return root;
}

// вернём указатель на ноду где есть элемент

AVLTreeNode^ AVLTree::Search(AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return nullptr;
    else if (tempKey == tempNode->key)
        return tempNode;
    else if (tempKey < tempNode->key)
        return Search(tempKey, tempNode->leftChild);
    return Search(tempKey, tempNode->rightChild);
}

bool AVLTree::Search(AVLTInfo tempKey)
{
    if (nullptr == Search(tempKey, root))
        return false;
    return true;
}

//------------------------------------------------------------------------------------
//	возвращается корневая нода текущего поддерева Функция левого малого поворота

AVLTreeNode^ AVLTree::LeftRotate(AVLTreeNode^ tempNode)
{
    AVLTreeNode^ lChildNode = tempNode->rightChild->leftChild, ^ newRoot = tempNode->rightChild;
    tempNode->rightChild->leftChild = tempNode;
    tempNode->rightChild = lChildNode;
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    if (nullptr != tempNode->rightChild)
        tempNode->rightChild->height = max(GetHeight(tempNode->rightChild->leftChild), GetHeight(tempNode->rightChild->rightChild)) + 1;
    return newRoot;
}

// тоже самое для баланса малый поворот направо

AVLTreeNode^ AVLTree::RightRotate(AVLTreeNode^ tempNode)
{
    AVLTreeNode^ rChildNode = tempNode->leftChild->rightChild, ^ newRoot = tempNode->leftChild;
    tempNode->leftChild->rightChild = tempNode;
    tempNode->leftChild = rChildNode;
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    if (nullptr != tempNode->leftChild)
        tempNode->leftChild->height = max(GetHeight(tempNode->leftChild->leftChild), GetHeight(tempNode->leftChild->rightChild)) + 1;
    return newRoot;
}

//	 для баланса сначача налево зачем направо

AVLTreeNode^ AVLTree::LeftAndRightRotate(AVLTreeNode^ tempNode)
{
    tempNode->leftChild = LeftRotate(tempNode->leftChild);
    return RightRotate(tempNode);
}

//	так же для баланса сначала направо потом налево

AVLTreeNode^ AVLTree::RightAndLeftRotate(AVLTreeNode^ tempNode)
{
    tempNode->rightChild = RightRotate(tempNode->rightChild);
    return LeftRotate(tempNode);
}
//------------------------------------------------------------------------------------

// вставка элемента в текущую ноду

AVLTreeNode^ AVLTree::Insert(AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return tempNode = gcnew AVLTreeNode(tempKey);
    else
    {
        /*if (tempKey == tempNode->key)
            return tempNode;
        else */
        if (tempKey <= tempNode->key)
            tempNode->leftChild = Insert(tempKey, tempNode->leftChild);
        else tempNode->rightChild = Insert(tempKey, tempNode->rightChild);
    }
    //tempNode->height=max(GetHeight(tempNode->leftChild),GetHeight(tempNode->rightChild))+1;
    if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
    {
        if (tempKey <= tempNode->leftChild->key)
            tempNode = RightRotate(tempNode);
        else tempNode = LeftAndRightRotate(tempNode);
    }
    else if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
    {
        if (tempKey > tempNode->rightChild->key)
            tempNode = LeftRotate(tempNode);
        else tempNode = RightAndLeftRotate(tempNode);
    }
    tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    return tempNode;
}

void AVLTree::Insert(AVLTInfo tempKey)
{
    root = Insert(tempKey, root);
}

//	удаление

AVLTreeNode^ AVLTree::Delete(bool% isDelSucceed, AVLTInfo tempKey, AVLTreeNode^ tempNode)
{
    if (nullptr == tempNode)
        return nullptr;
    else
    {
        if (tempKey == tempNode->key)
        {
            if (nullptr == tempNode->rightChild)
            {
                AVLTreeNode^ cur = tempNode;
                tempNode = tempNode->leftChild;
                delete cur;
                isDelSucceed = true;
                return tempNode;
            }
            else// идём искать наименьший элемент правого поддерева для замены, а затем удаляем
            {
                AVLTreeNode^ cur = tempNode->rightChild;
                while (cur->leftChild != nullptr)
                    cur = cur->leftChild;
                tempNode->key = cur->key;
                tempNode->rightChild = Delete(isDelSucceed, cur->key, tempNode->rightChild);
            }
        }
        else if (tempKey < tempNode->key)
            tempNode->leftChild = Delete(isDelSucceed, tempKey, tempNode->leftChild);
        else tempNode->rightChild = Delete(isDelSucceed, tempKey, tempNode->rightChild);

        if (-2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))//удаляемый слева
        {
            if (GetHeight(tempNode->rightChild->rightChild) >= GetHeight(tempNode->rightChild->leftChild))
                tempNode = LeftRotate(tempNode);
            else tempNode = RightAndLeftRotate(tempNode);
        }
        else if (2 == GetHeight(tempNode->leftChild) - GetHeight(tempNode->rightChild))
        {
            if (GetHeight(tempNode->leftChild->leftChild) >= GetHeight(tempNode->leftChild->rightChild))
                tempNode = RightRotate(tempNode);
            else tempNode = LeftAndRightRotate(tempNode);
        }
        tempNode->height = max(GetHeight(tempNode->leftChild), GetHeight(tempNode->rightChild)) + 1;
    }
    return tempNode;
}

bool AVLTree::Delete(AVLTInfo tempKey)
{
    bool isDelSucceed = false;
    root = Delete(isDelSucceed, tempKey, root);
    return isDelSucceed;
}

// замена значения

bool AVLTree::Updata(AVLTInfo oldKey, AVLTInfo newKey)
{
    if (Delete(oldKey))
    {
        Insert(newKey);
        return true;
    }
    return false;
}
