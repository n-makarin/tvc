//
//  main.cpp
//  tvc
//
//  Created by Nikita Makarin on 17.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "main.hpp"

int main(int argc, const char * argv[]) {
    print_frame();
    return 0;
}

void print_frame()
{
    Frame frame;
    frame.create();
    frame.fill_with_empty_cells();

    frame.print_string(0, 24, "|");

    frame.print_string(1, 24, "|");

    frame.print_string(2, 24, "|");
    frame.print_string(3, 24, "|");
    frame.print_string(4, 24, "|");
    frame.print_string(5, 24, "|");
    frame.print_string(15, 24, "|");
    frame.print_string(20, 24, "|");
//    frame.print_string(20, 30, "привет Тузик");
//    frame.print_string(14, 19, "hello, what's up?");
//    frame.print_string(4, 19, "hmmm, what's wrong?");
//    frame.print_string(5, 19, "hmmm, what's wrong?");
//    frame.print_string(6, 19, "hmmm, what's wrong?");
//    frame.print_string(7, 19, "hmmm {🤨}, what's wrong?");
    
//    frame.print_string(8, 9, "it's work!!");
    frame.print();
}
