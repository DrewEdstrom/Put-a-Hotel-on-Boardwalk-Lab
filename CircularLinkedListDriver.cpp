#include <iostream>
#include <fstream>
#include "CircularLinkedList.h"

using namespace std;

int main()
{
    //the monopoly board, which is a circular linked list of strings
    CircularLinkedList monopoly_board = CircularLinkedList<string>();
    //the monopoly spaces to be added to the monopoly board
    fstream monopoly_spaces{"monopoly_spaces.txt"};
    //the current space in monopoly_spaces
    string current_space;

    //read the monopoly board space on each line and add it to the board
    while(getline(monopoly_spaces, current_space))
    {
        monopoly_board.push_back(current_space);
    }

    //check of the first element, which should be "Go"
    cout << "\n\n" << monopoly_board.current_node->element;

    //step through the monopoly board and print the space we're on
    for(int i = 0; i < 39; i++)
    {
        monopoly_board.step();
        cout << "\n" << monopoly_board.current_node->element;
    }

    //pass Go once more to ensure list can be continually traversed
    monopoly_board.step();
    cout << "\n" << monopoly_board.current_node->element;

    return 0;
}
