//
//  frame.hpp
//  tvc
//
//  Created by Nikita Makarin on 19.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#ifndef frame_hpp
#define frame_hpp

#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

class Frame {
    int width;
    int height;
    
public:
    void create();
    void set_size();
    void print_empty_space();
};

#endif /* frame_hpp */
