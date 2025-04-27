// parse_chars.cpp
#include <cstdint>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <chrono>

int main(int argc, char* argv[])
{
    const char* fname = (argc > 1) ? argv[1] : "data.txt";
    std::ifstream in(fname, std::ios::binary);
    if (!in) { std::cerr << "Cannot open " << fname << '\n'; return 1; }

    std::uint64_t a=0,b=0,c=0,d=0,e=0, other=0;
    char ch;

    auto start_time = std::chrono::high_resolution_clock::now();


    while (in.get(ch)) {
        switch (ch) {
            case 'A': ++a; break;
            case 'B': ++b; break;
            case 'C': ++c; break;
            case 'D': ++d; break;
            case 'E': ++e; break;
            default : ++other;
        }
    }

       // End timing
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << elapsed_time.count() << " seconds\n";

    std::cout << "A:" << a << "  B:" << b << "  C:" << c
              << "  D:" << d << "  E:" << e << "  other:" << other << '\n';

    return 0;
}
