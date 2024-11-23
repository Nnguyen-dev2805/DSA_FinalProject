// Test File Binary

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("EnglishDictionary.dat", std::ios::binary);
    
    if (!inFile) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    char buffer[10];
    inFile.read(buffer, 10);
    
    for (int i = 0; i < 10; i++) {
        std::cout << "Byte " << i << ": " << (int)(unsigned char)buffer[i] << std::endl;
    }

    inFile.close();
    return 0;
}
