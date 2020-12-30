#include <iostream>
#include "lib/LZW.h"

using namespace std;

int main(int argc, char **argv) 
{
    if (argc > 1)
    {
        if (argv[1][0] == 'c' && argc > 3) 
        {
            compress(argv[2], argv[3]);
        } 
        else if (argv[1][0] == 'd' && argc > 3) 
        {
            decompress(argv[2], argv[3]);
        } 
        else if (argv[1][0] == 'h') 
        {
            cout << "Compression:" << endl;
            cout << "lzw c <input> <output>" << endl;
            cout << "Decompression:" << endl;
            cout << "lzw d <input> <output>" << endl;
        } 
        else 
        {
            cout << "Error. Usage: lzw h" << endl;
        }
    } 
    else 
    {
        cout << "Error. Usage: lzw h" << endl;
    }
    
    return 0;
}
