#pragma once
#include <cmath>
#include <iostream>
#include"NewTasksStudentModel.h"

using TBST = NewTasksStudentModel;
ref class BSTNODE
{
public:
    BSTNODE() {}
    BSTNODE(TBST elem)
    {
        data.setNewStudent(elem);
    }
    TBST data;
    BSTNODE^ p_right;
    BSTNODE^ p_left;
    int leftHeight;
    int rightHeight;
};
ref class BSTree
{
public:
    BSTree();
    ~BSTree();
    void insert(TBST% d);
    bool search(TBST% d);
    bool remove(TBST% d);
    int size();
    BSTNODE^ getRoot();
    TBST findMax();
    TBST findMin();
    int heightOfTree();
    float percentLeaf();
    float percentInterior();

private:

    bool searchHelper(BSTNODE^ p_node, TBST elem);
    bool insertHelper(BSTNODE^% p_node, TBST% elem);
    bool removeHelper(BSTNODE^% p_node, TBST elem);

    bool isBalanced(BSTNODE^ p_node);
    int setHeightHelper(BSTNODE^ p_node);
    void percentLeafHelper(BSTNODE^ p_node);
    void percentInteriorHelper(BSTNODE^ p_node);
    void destructorHelper(BSTNODE^ p_node);

    int numElements;

    int countLeaves;
    int countInterior;

    BSTNODE^ root;
};
BSTree::BSTree()
{
    root;
    numElements = 0;
    countLeaves = 0;
    countInterior = 0;
}

BSTree:: ~BSTree()
{
    destructorHelper(root);
}

void BSTree::destructorHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        destructorHelper(p_node->p_left);
        destructorHelper(p_node->p_right);
        delete p_node;
        numElements--;
    }
}

void BSTree::insert(TBST% elem)
{
    insertHelper(root, elem);
}

bool BSTree::insertHelper(BSTNODE^% p_node, TBST% elem)
{
    bool retVal = false;

    if (p_node == nullptr)
    {
        p_node = gcnew BSTNODE(elem);

        numElements++;

        setHeightHelper(root);
    }
    else
    {
        if (elem <= p_node->data)
        {
            insertHelper(p_node->p_left, elem);
        }
        else
        {
            insertHelper(p_node->p_right, elem);
        }
    }
    return retVal;
}

bool BSTree::search(TBST% elem)
{
    return searchHelper(root, elem);
}

bool BSTree::searchHelper(BSTNODE^ p_node, TBST elem)
{
    if (p_node->data == elem)
    {
        return true;
    }
    else if (p_node->p_right == nullptr && p_node->p_left == nullptr)
    {
        return false;
    }
    else if (p_node->data < elem)
    {
        return searchHelper(p_node->p_right, elem);
    }
    else
    {
        return searchHelper(p_node->p_left, elem);
    }
}

bool BSTree::remove(TBST% elem)
{
    return removeHelper(root, elem);
}

bool BSTree::removeHelper(BSTNODE^% p_node, TBST elem)
{
    bool retVal = false;
    if (p_node != nullptr)
    {
        if (p_node->data == elem)
        {
            retVal = true;
            if (p_node->p_right == nullptr && p_node->p_left == nullptr)
            {
                delete p_node;
                p_node = nullptr;
                numElements--;
            }
            else if (p_node->p_right == nullptr && p_node->p_left != nullptr)
            {
                BSTNODE^ node = p_node;
                p_node = p_node->p_left;
                delete node;
                numElements--;
            }
            else if (p_node->p_left == nullptr && p_node->p_right != nullptr)
            {
                BSTNODE^ node = p_node;
                p_node = p_node->p_right;
                delete node;
                numElements--;
            }
            else
            {
                BSTNODE^ left = p_node->p_left;
                while (left->p_right != nullptr)
                {
                    left = left->p_right;
                }

                p_node->data = left->data;

                removeHelper(p_node->p_left, p_node->data);
            }
            setHeightHelper(root);
        }
        else if (p_node->data <= elem)
        {
            retVal = removeHelper(p_node->p_right, elem);
        }

        else
        {
            retVal = removeHelper(p_node->p_left, elem);
        }
    }

    return retVal;
}

int BSTree::size()
{
    return numElements;
}
inline BSTNODE^ BSTree::getRoot()
{
    return root;
}

int BSTree::setHeightHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        p_node->leftHeight = setHeightHelper(p_node->p_left) + 1;
        p_node->rightHeight = setHeightHelper(p_node->p_right) + 1;

        if (p_node->leftHeight >= p_node->rightHeight)
        {
            return p_node->leftHeight;
        }
        else
        {
            return p_node->rightHeight;
        }
    }
    else
    {
        return -1;
    }
}

bool BSTree::isBalanced(BSTNODE^ p_node)
{
    if (p_node->rightHeight - p_node->leftHeight > 1 || p_node->rightHeight - p_node->leftHeight < -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

float BSTree::percentLeaf()
{
    countInterior = 0;
    countLeaves = 0;

    percentLeafHelper(root);

    return ((float)countLeaves / (float)numElements);
}

void BSTree::percentLeafHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        percentLeafHelper(p_node->p_left);
        if (p_node->p_right == nullptr && p_node->p_left == nullptr)
        {
            countLeaves++;
        }
        percentLeafHelper(p_node->p_right);
    }
}

float BSTree::percentInterior()
{
    countInterior = 0;
    countInterior = 0;

    percentInteriorHelper(root);

    return((float)countInterior / (float)numElements);
}

void BSTree::percentInteriorHelper(BSTNODE^ p_node)
{
    if (p_node != nullptr)
    {
        percentInteriorHelper(p_node->p_left);
        if (!(p_node->p_right == nullptr && p_node->p_left == nullptr))
        {
            countInterior++;
        }
        percentInteriorHelper(p_node->p_right);
    }
}

TBST BSTree::findMax()
{
    BSTNODE^ p_max = root;
    while (p_max->p_right != nullptr)
    {
        p_max = p_max->p_right;
    }

    return p_max->data;
}

TBST BSTree::findMin()
{
    BSTNODE^ p_min = root;
    while (p_min->p_left != nullptr)
    {
        p_min = p_min->p_left;
    }
    return p_min->data;
}

int BSTree::heightOfTree()
{
    if (numElements > 0)
    {
        if (root->rightHeight > root->leftHeight)
        {
            return root->rightHeight + 1;
        }
        else
        {
            return root->leftHeight + 1;
        }
    }
    else
    {
        return 0;
    }
}
