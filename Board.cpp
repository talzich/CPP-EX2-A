//
// AUTHOURS: Tal Zichlinsky
// This file will be used to build a message board class, as described in this assignments README document (https://github.com/cpp-exercises/messageboard-a)

#include "Board.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{   
    // Default and minimal size for a message board
    const int DEFAULT_SIZE = 1000;
    const int MIN_SIZE = 1;
    
    // Default constructor
    Board::Board(){
        this->rows = DEFAULT_SIZE;
        this->cols = DEFAULT_SIZE;
    }

    // Constructor
    Board::Board(unsigned int rows, unsigned int cols){   
        
        if(rows < MIN_SIZE){
            throw invalid_argument("Invalid input: " + to_string(rows));
        }

        if(cols < MIN_SIZE){
            throw invalid_argument("Invalid input: " + to_string(cols));
        }

        this->rows = rows;
        this->cols = cols;
    }
    
    // Destructor
    Board::~Board(){}

    // This method will get row, column, direction and a message as parameters and posts the message in the 
    // appropriate location and diraction in this message board
    int Board::post(unsigned int row, unsigned int col, Direction dir, string msg){
        return 0;
    }

    // This method get row, column, direction and length of a message as parameters and returns the message in the 
    // appropriate location and diraction in this message board
    string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int len){
        return " ";
    }

    // This message will print out the entire message board
    void Board::show(){}

}
