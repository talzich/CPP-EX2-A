//
// AUTHOURS: Tal Zichlinsky
// 
// Header file for class Board

#include "Direction.hpp"
#include <string>

namespace ariel{

    class Board{
        
        unsigned int rows, cols;

        public:
            // Constructors
            Board();
            Board(unsigned int rows, unsigned int cols);

            // Destructor
            ~Board();

            // This method will get row, column, direction and a message as parameters and posts the message in the 
            // appropriate location and diraction in this message board
            int post(unsigned int row, unsigned int col, Direction dir, std::string msg);

            // This method get row, column, direction and length of a message as parameters and returns the message in the 
            // appropriate location and diraction in this message board
            std::string read(unsigned int row, unsigned int col, Direction dir, unsigned int len);

            // This message will print out the entire message board
            void show();

            // Returns number of rows and columns of this board
            int get_rows();
            int get_cols();

            

    };
}