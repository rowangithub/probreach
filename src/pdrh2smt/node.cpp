//
// Created by fedor on 02/02/17.
//

#include "node.h"
#include <sstream>
#include <cstring>

node::node()
{

}

node::node(string value)
{
    this->value = value;
}

node::node(string value, vector<node> operands)
{
    this->value = value;
    this->operands = operands;
}

void node::append(node n)
{
    this->operands.push_back(n);
}

void node::append(vector<node> n)
{
    this->operands.insert(this->operands.begin(), n.begin(), n.end());
}

bool node::is_terminal()
{
    return this->operands.empty();
}

bool node::is_empty()
{
    return this->operands.empty() && this->value.empty();
}

string node::to_string_infix()
{
    stringstream s;
    // checking whether n is an operation node
    if(this->operands.size() > 1)
    {
        s << "(";
        for(unsigned long i = 0; i < this->operands.size() - 1; i++)
        {
            s << this->operands.at(i).to_string_infix();
            s << this->value;
        }
        s << this->operands.at(this->operands.size() - 1).to_string_infix() << ")";
    }
    else if(this->operands.size() == 1)
    {
        if(strcmp(this->value.c_str(), "-") == 0)
        {
            s << "(" << this->value << this->operands.front().to_string_infix() << ")";
        }
        else
        {
            s << this->value << "(" << this->operands.front().to_string_infix() << ")";
        }
    }
    else
    {
        s << this->value;
    }
    return s.str();
}

string node::to_string_prefix()
{
    stringstream s;
    // checking whether n is an operation node
    if(!this->is_terminal())
    {
        s << "(" << this->value;
        for(node n : this->operands)
        {
            s << n.to_string_prefix();
        }
        s << ")";
    }
    else
    {
        s  << " " << this->value;
    }
    return s.str();
}