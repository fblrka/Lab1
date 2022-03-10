#include "queue1.h"
#include <iostream>
using namespace std;

void List_protected::Push_Back(int value) { return List::Push_Back(value); }
int& List_protected::operator[](const int index) { return List::operator[](index); }
void List_protected::Pop_Front() { return List::Pop_Front(); }
void  List_protected::SearchMax(List_protected& obj) { }
void List_protected::Copying(List_protected& obj) { return List::Copying(obj); }
void List_protected::Merge(List_protected& obj, List_protected& obj2) { return List::Merge(obj, obj2); }


void List_private::Push_Back(int value) { return List::Push_Back(value); }
int& List_private::operator[](const int index) { return List::operator[](index); }
void List_private::Pop_Front() { return List::Pop_Front(); }
void List_private::SearchMax(List_private&obj) { }
void List_private::Copying(List_private& obj) { return List::Copying(obj); }
void List_private::Merge(List_private& obj, List_private& obj2) { return List::Merge(obj, obj2); }

