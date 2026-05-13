//
// Created by Babin on 3/18/2026.
//

#ifndef LABORATOIRE6_PARSER_H
#define LABORATOIRE6_PARSER_H
#include <iostream>

class Parser {
public:
    virtual void parse(std::istream& in) = 0;
};


#endif //LABORATOIRE6_PARSER_H