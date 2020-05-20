//
//  frame.cpp
//  tvc
//
//  Created by Nikita Makarin on 19.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "frame.hpp"

const string br_begin{"{"};
const string br_end{"}"};

void Frame::create()
{
    Frame::set_size();
}

void Frame::set_size()
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    width = size.ws_col;
    height = size.ws_row;
}

void Frame::print_empty_cell(int row, int col)
{
    
}

void Frame::print_string(int row, int col, const string val)
{
//    const int start_position{Frame::get_start_position(row, col)};

    vector<string> emoji_match{};
    long emoji_count{0};
    
    long text_size{0};
    long string_size{0};
    long emoji_size{0};

    
    Frame::parse_string_by_emoji(emoji_match, emoji_count, val);

    emoji_size = emoji_count + (br_begin + br_end).size() * emoji_count;
    
    text_size = val.size() - emoji_match[0].size();
    string_size = emoji_size + text_size;
    
    std::cout << string_size << std::endl << val.size();
}

int Frame::get_start_position(int row, int col)
{
    return row * width - (width - col);
}

void Frame::parse_string_by_emoji(vector<string> &emoji_match, long &emoji_count, const string val)
{
    const std::regex exp("\\" + br_begin + ".*\\" + br_end);
    std::smatch match;
    string::const_iterator searchStart( val.cbegin() );
    while ( regex_search( searchStart, val.cend(), match, exp ) )
    {
        string found_emoji{match[0]};
        emoji_match.push_back(found_emoji);
        searchStart = match.suffix().first;
        emoji_count = std::count(found_emoji.begin(), found_emoji.end(), '{');;
    }
}
