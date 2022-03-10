#pragma once
#include "queue.h"

class List_private : private List {
public:
    void Push_Back(int value);
    int& operator[](const int index);
    void Pop_Front();
    void  SearchMax(List_private& obj);
    int  GetSize() { return size; }
    void Copying(List_private& obj);
    void Merge(List_private& obj, List_private& obj2);
};

class List_protected : protected List {
public:
    void Push_Back(int value);
    int& operator[](const int index);
    void Pop_Front();
    void  SearchMax(List_protected& obj);
    int  GetSize() { return size; }
    void Copying(List_protected& obj);
    void Merge(List_protected& obj, List_protected& obj2);
};

class List_public : public List {};