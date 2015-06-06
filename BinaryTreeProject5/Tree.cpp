//
//  Tree.cpp
//  BinaryTreeProject5
//
//  Created by Derrick Fox on 11/28/14.
//  Copyright (c) 2014 Derrick Fox. All rights reserved.
//

#include "Tree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Tree::Tree()
{
    root = NULL;
}

Tree::Book* Tree::createLeaf(string title, string author, int ID, int year)
{
    Book* n = new Book;
    n->title = title;
    n->author = author;
    n->ID = ID;
    n->year = year;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Tree::addLeaf(string title, string author, int ID, int year)
{
    addLeafPrivate(title, author, ID, year, root);
}

void Tree::addLeafPrivate(string title, string author, int ID, int year, Book* ptr)
{
    if (root == NULL)
    {
        root = createLeaf(title, author, ID, year);
    }
    else if (year <= ptr->year)
    {
        if (ptr->left !=NULL)
        {
            addLeafPrivate(title, author, ID, year, ptr->left);
        }
        else
        {
            ptr->left = createLeaf(title, author, ID, year);
        }
    }
    else if (year >= ptr->year)
    {
        if (ptr->right !=NULL)
        {
            addLeafPrivate(title, author, ID, year, ptr->right);
        }
        else
        {
            ptr->right = createLeaf(title, author, ID, year);
        }
    }
    else
    {
        cout << "The year " << year << " has already been added to the tree";
    }
    
}

void Tree::print()
{
    printPrivate(root);
}

void Tree::printPrivate(Book* ptr)
{
    if (root !=NULL) {
        if (ptr->left != NULL)
        {
            printPrivate(ptr->left);
        }
        cout << ptr->year << " ";
        if (ptr->right != NULL)
        {
            printPrivate(ptr->right);
        }
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}

Tree::Book* Tree::returnNode(int year)
{
    return returnNodePrivate(year, root);
}

Tree::Book* Tree::returnNodePrivate(int year, Book* ptr)
{
    if (ptr != NULL)
    {
        if (ptr->year == year)
        {
            return ptr;
        }
        else
        {
            if (year < ptr->year)
            {
                return returnNodePrivate(year, ptr->left);
            }
            else
            {
                return returnNodePrivate(year, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int Tree::returnRootKey()
{
    if (root != NULL)
    {
        return root->year;
    }
    else
    {
        return -1000;
    }
}

void Tree::search(Book* root, int year)
{
    if (root == NULL)
    {
        cout << "NOT found" << endl;
    }
    else if(root->year == year)
    {
        cout << "FOUND: ";
        cout << "That book is called " << root->title << endl;
    }
    else if (year <= root->year)
    {
        search(root->left, year);
    }
    else
        search(root->right, year);
}





