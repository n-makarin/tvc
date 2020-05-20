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
#include <string>
#include <regex>
#include <vector>
#include <algorithm>


using std::string;
using std::vector;

class Frame {
    int width;
    int height;
    string content;
    
public:
    void create();
    void set_size();
    void print_string(int row, int col, const string val);
    
    void print_empty_cell(int row, int col);
    int get_start_position(int row, int col);
    void parse_string_by_emoji(string &found_emoji, long &emoji_count, const string val);
    long get_printing_string_size(string val);
};

#endif /* frame_hpp */
