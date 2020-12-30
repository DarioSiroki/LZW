#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include <limits.h>

void compress(char *input, char *output)
{
    // Check for input file existence.
    if (!std::filesystem::exists(input))
    {
        std::cout << "File '" << input << "' does not exist." << std::endl;
        return;
    }

    // Create input and output file handles.
    std::ifstream ifs(input);
    std::ofstream ofs(output, std::ios::binary);
    // Create a dictionary for codes.
    std::unordered_map<std::string, short> codes;

    char c;
    std::string s;
    short code = -1;

    // Populate the dictionary with ASCII codes.
    while (code++ < 254)
    {
        codes[std::string(1, (char)code)] = code;
    }

    while (ifs.read((char *)&c, sizeof(char)))
    {
        s += c;
        if (codes.count(s) == 0)
        {
            if (code <= SHRT_MAX)
                codes[s] = code++;
            s.erase(s.size() - 1);
            ofs.write((char *)&codes[s], sizeof(short));
            s = c;
        }
    }
    if (s.size())
        ofs.write((char *)&codes[s], sizeof(short));
}

void decompress(char *input, char *output)
{
    // Check for input file existence.
    if (!std::filesystem::exists(input))
    {
        std::cout << "File '" << input << "' does not exist." << std::endl;
        return;
    }

    // Create input and output file handles.
    std::ifstream ifs(input, std::ios::binary);
    std::ofstream ofs(output);

    // Create a dictionary for codes.
    std::unordered_map<int, std::string> codes;
    short nc = -1; // nc = next code

    // Populate the dictionary with ASCII codes.
    while (nc++ < 254)
    {
        codes[nc] = std::string(1, nc);
    }

    std::string ps; // ps = previous string
    short cc;       // cc = current code
    while (ifs.read((char *)&cc, sizeof(short)))
    {
        if (codes.count(cc) == 0)
            codes[cc] = ps + ps[0];
        ofs << codes[cc];
        if (ps.size() && nc <= SHRT_MAX)
            codes[nc++] = ps + codes[cc][0];
        ps = codes[cc];
    }
}