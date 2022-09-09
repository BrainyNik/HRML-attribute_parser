#include "attribute_parser.cpp"

using namespace attributeparser;

// using namespace Hi;

int main()
{

    // Hi::main();
    std::map<std::string, std::string> m;
    /*  n = number of tags to be parsed
    q = number of queries to be parsed */
    int n, q;
    std::cin >> n >> q;
    // ignoring the newline character at the end of first line
    std::cin.ignore();
    m = attribute_parser(n,q);

    return 0;
}