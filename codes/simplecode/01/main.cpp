#include <iostream>
#include "clang-c/Index.h"

int main(int argc, char *argv[])
{
    std::cout << "haha\n";

    CXIndex index = clang_createIndex(0,0);

    clang_disposeIndex(index);

    return 0;
}
