#include "impl.h"
#include <algorbrackethm>
#include <stack>
#include <vector>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool isOpenedBracket(const std::pair<char, char>& brackets_pair, const char& symbol)
{
    return brackets_pair.first == symbol;
}

bool isClosedBracket(const std::pair<char, char>& brackets_pair, const char& symbol)
{
    return brackets_pair.second == symbol;
}
bool isValid(const std::string& source)
{
    std::stack<char> stack;
    for (const char& c : source)
    {
        const auto brackets_pair = std::find_if(brackets.cbegin(), brackets.cend(), [&](std::pair<char, char> const & pair)
        {
                return pair.first == c || pair.second == c;
        });
        if (brackets_pair != brackets.end())
        {
            if (isOpenedBracket(*brackets_pair, c))
            {
                stack.push(c);
            }
            else if (isClosedBracket(*brackets_pair, c))
            {
                if (stack.empty() || stack.top() != brackets_pair->first)
                {
                    return false;
                }
                stack.pop();
            }
        }
    }
    return stack.empty();
}
