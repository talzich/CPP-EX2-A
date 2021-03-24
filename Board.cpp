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
    const int DEFAULT_SIZE = 1000;
    const int MIN_SIZE = 1;
    
    Board::Board(){
        this->rows = DEFAULT_SIZE;
        this->cols = DEFAULT_SIZE;
    }

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
    
    Board::~Board(){}

    int Board::post(unsigned int row, unsigned int col, Direction dir, string msg){
        return 0;
    }

    string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int len){
        return " ";
    }

    void Board::show(){}

}
