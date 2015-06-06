//
//  Tree.h
//  BinaryTreeProject5
//
//  Created by Derrick Fox on 11/28/14.
//  Copyright (c) 2014 Derrick Fox. All rights reserved.
//

#ifndef __BinaryTreeProject5__Tree__
#define __BinaryTreeProject5__Tree__

#include <stdio.h>
#include <string>

class Tree
{
private:
    struct Book
    {
        std::string title;
        std::string author;
        int ID;
        int year;
        Book* left;
        Book* right;
    };
    void addLeafPrivate(std::string title, std::string author, int ID, int year, Book* ptr);
    void printPrivate(Book* ptr);
    Book* returnNodePrivate(int year, Book* ptr);
    
public:
    Tree();
    Book* root;
    Book* createLeaf(std::string title, std::string author, int ID, int year);
    void addLeaf(std::string title, std::string author, int ID, int year);
    void print();
    Book* returnNode(int year);
    int returnRootKey();
    void search(Book* book, int year);
};


#endif /* defined(__BinaryTreeProject5__Tree__) */
