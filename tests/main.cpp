/*
 * main.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: asm
 */
#include <iostream>
#include "../headers/data-structures.hpp"

using namespace std;

typedef WrapperDataStr::SingleLinkedList<int> SingleLinkedList;

int main(){
    SingleLinkedList list = SingleLinkedList();

    list.Push(1);
    cout << list.ToString() << "\n";
    return 0;
}



