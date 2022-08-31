#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int _main()
{
    auto v = std::vector<int>({1, 2, 3, 4, 5});
    auto increase = [](int& x) { x ++; };
    auto output = [](int& x) { printf("%d", x); };   
    auto quick = [](std::vector<int>& v, auto f) {
        std::for_each(v.begin(), v.end(), f);
    };

    quick(v, increase);
    quick(v, output);
}
