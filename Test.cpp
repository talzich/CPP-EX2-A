// 
// AUTHORS: Tal Zichlinsky
//
// This test file is made to test the Board class and it's methods

#include "doctest.h"
#include "Board.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;
using namespace ariel;
using ariel::Direction;

const int NUM_OF_TESTS = 5*6 + 4*2; // = 38 tests.

const unsigned int ROWS = 100, COLS = 100;
const vector<string> INPUTS {"Tal", "Zichlinsky", "Horizontal", "Vertical"};


TEST_CASE("Test read() on an empty Board:") {

    srand((unsigned)time(NULL));

    Board empty_board;

    Direction dir = Direction::Horizontal;

    unsigned int random_length;

    for(unsigned int i = 0; i < ROWS/2; i++) {
        for(unsigned int j = 0; j < COLS/2; j++) {

            // Switch direction every iteration
            if(dir == Direction::Horizontal) { 

                // Reading vertically. 
                dir = Direction::Vertical;  
                random_length = ((uint)rand()%((uint)(ROWS-i))+1);
            } else {
                // Reading Horizontally.
                dir = Direction::Horizontal;
                random_length = ((uint)rand()%((uint)(COLS-j))+1);
            }

            cout << i << ", " << j << endl;
            cout << "rand length = " << random_length << endl;
            string expected_out(random_length, '_');
            CHECK(empty_board.read(i, j, dir, random_length) == expected_out);            
        }
    }
}

TEST_CASE("Test post") {

    

    Board board;
    Direction direction = Direction::Horizontal;
    srand((unsigned)time(NULL));

    // Testing if message that was posted last is the one to return 
    for(uint i = 0; i < INPUTS.size(); i++) {
        direction = i%2 == 0 ? Direction::Horizontal : Direction::Vertical;
        CHECK_NOTHROW(board.post(i, 0, direction, INPUTS.at(i)));

        CHECK(INPUTS.at(i) == board.read(i, 0, direction, INPUTS.at(i).size()));
    }

    string message = "zich";
    CHECK_NOTHROW(board.post(0,0, direction, message));
    CHECK(board.read(0,0, direction, message.size()) == message);

    direction = Direction::Vertical;
    CHECK_NOTHROW(board.post(0, message.size()-1, direction, "bbbb"));

    direction = Direction::Horizontal;
    CHECK(board.read(0,0, direction, message.size()) != message);
    CHECK(board.read(0,0, direction, message.size()) == "aaab");
}