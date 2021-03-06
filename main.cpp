// CS341 - Homework 4
//
// Author: Brian Horner
// Edit History:
// 4/22/2022 - Initial Version


// --- Standard Library Includes ---
#include <iostream>
#include <string>
// --- User Built Includes ---
#include "Node.h"
#include "LinkedList.h"

void nameSort(std::string &, std::string &);
int stringComparison(std::string &, std::string &);
void stringSortTest(std::string [], int);


int main() {
    LinkedList linkedList;
    std::string name;
    std::cout << "Enter the names you wish to have for your list." <<std::endl;
    std::cout << "Enter your eof keybind for end of input." <<std::endl;
    std::cout << "An updated list is entered after each entry." <<std::endl;
    std::cout << "Entry: ";
    while (!std::cin.eof()&&std::cin.good()){
        std::cin>>name;
        linkedList.sortList(name);
        linkedList.printList();
        std::cout << "\n\nContinue to enter the names you wish to have for "
                     "your "
                     "list."<<std::endl;
        std::cout << "Enter your eof keybind for end of input." <<std::endl;
        std::cout << "Entry: ";

    }

    return 0;
}


void stringSortTest(std::string input [], int size){
    // Bubble sort for strings -- Testing purposes only
    for (int i=0; i<size; i++){
        for (int j= i+1; j<size; j++){
            if(input[i]> input[j]){
                std::string temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    for (int i=0; i <size; i++){
        std::cout <<input[i] <<std::endl;
    }
}





void nameSort (std::string &firstString, std::string &secondString){
// Function to sort the names in a linked list
int bounds = stringComparison(firstString, secondString);
for (int i{0}; i < bounds; i++){
    if(tolower(firstString[i]) < tolower(secondString[i])){
        std::cout << firstString;
        break;
    }else if (tolower(firstString[i]) == tolower(secondString[i])){
        continue;
    }else{
        std::cout <<secondString;
        break;
    }
}

}


int stringComparison(std::string &firstString, std::string &secondString){
// Function to return bounds for comparing strings
    bool firstGreater = (firstString.length() >= secondString.length());
    if (firstGreater){
        return static_cast<int>(firstString.length());

    }else{
        return static_cast<int>(secondString.length());
    }
}