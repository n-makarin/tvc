//
//  frame.cpp
//  tvc
//
//  Created by Nikita Makarin on 19.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "frame.hpp"

const string emoji_begin{"{"};
const string emoji_end{"}"};
const string empty_cell{"-"};

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

void Frame::print()
{
    std::cout << std::endl << content << std::endl;
}

void Frame::fill_with_empty_cells()
{
    Frame::fill_content_with_empty_cells(width * height);
    Frame::format_content_by_rows();
}

void Frame::format_content_by_rows()
{
    for (int i{1}; i < height; i++) {
        content.replace(width * i, 1, "\n");
    }
}

void Frame::print_string(int row, int col, const string val)
{
    const int start_position{Frame::get_start_position(row, col)};
    const long string_size{Frame::get_printing_string_size(val)};
    Frame::fill_content_with_empty_cells(start_position);
    const string parsed_val{Frame::remove_emoji_braces(val)};
    content.replace(start_position, string_size, parsed_val);
}


void Frame::fill_content_with_empty_cells(const int start_position)
{
    if (content.size() >= start_position) {
        return;
    }
    string cocal_content = content;
    long content_size = content.size();
    for (long i{content_size}; i < start_position; i++) {
        cocal_content.append(empty_cell);
    }
    content = cocal_content;
}

int Frame::get_start_position(int row, int col)
{
    return (row + 1) * width - (width - col - 1);
}

void Frame::parse_string_by_emoji(string &found_emoji, long &emoji_count,
                                  const string val)
{
    const std::regex exp("\\" + emoji_begin + ".*\\" + emoji_end);
    vector<string> emoji_match{};
    std::smatch match;
    string::const_iterator searchStart( val.cbegin() );
    while ( regex_search( searchStart, val.cend(), match, exp ) )
    {
        found_emoji = match[0];
        emoji_match.push_back(found_emoji);
        searchStart = match.suffix().first;
        emoji_count = std::count(found_emoji.begin(), found_emoji.end(), '{');;
    }
}

long Frame::get_printing_string_size(string val)
{
    string found_emoji;
    long emoji_count{0};
    Frame::parse_string_by_emoji(found_emoji, emoji_count, val);
    long text_size{0};
    long emoji_size{0};
    emoji_size = emoji_count + (emoji_begin + emoji_end).size() * emoji_count;
    text_size = val.size() - found_emoji.size();
    return emoji_size + text_size;
}

string Frame::remove_emoji_braces(string val)
{
    string local_val;
    for (int i{0}; i < val.size(); i++) {
        if (val[i] != emoji_begin[0] && val[i] != emoji_end[0]) {

            local_val.push_back(val[i]);
        }
    }
    return local_val;
}
