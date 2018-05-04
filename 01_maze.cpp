#include <iostream>
#include <fstream>

using namespace std;

#define 0_AS_ASCII 0x30
#define 9_AS_ASCII 0x39

bool is_integer(char ch)
{
    if (ch >= 0_AS_ASCII && ch <= 9_AS_ASCII)
        return true;
    else
        return false;
}

bool is_separator(char ch)
{
    if (ch == '!' || ch == '\n')
        return true;
    else
        return false;
}

int charToInt(char ch)
{
    return (ch-0_AS_ASCII);
}

int main()
{
    ifstream myfile("input.txt");
    
    if (!myfile.is_open()) {
        cout << "[ERROR] file open error" << endl;
        return -1;
    }
    
    char ch;
    char maze_ch = '\0';
    int count = 0;
    
    while (!myfile.eof()) {
        myfile.get(ch);
        
        if (!is_integer(ch) && !is_separator(ch)) {
            // 'T' 'X' 'b'
            if (count > 0) {
                for (int i = 0; i < count; i++) {
                    if (ch == 'b') cout << ' '; // blank for b
                    else           cout << ch;
                }
                count = 0;
            }
            else {
                maze_ch = ch;
            }
        }
        else if (is_integer(ch)) {
            count += charToInt(ch);
        }
        else if (is_separator(ch)) {
            cout << endl;
        }
    }
    
    myfile.close();
    
    return 0;
}
