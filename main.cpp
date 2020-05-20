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
//    frame.print_string(2, 2, "h");
    frame.print_string(2, 2, "hello {🙂}{🤓}{😎}, what's up?");
//    frame.print_string(2, 2, "🙂🤨🧐🤓😎d");
}
