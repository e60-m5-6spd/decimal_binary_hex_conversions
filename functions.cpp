#include "main.h"

std::string decimalToBinary(int n){
    std::string binary;

    while(n > 0){
        int remainder = n % 2; // 
        binary += std::to_string(remainder);
        n /= 2;
    }
    // reverse the binary string
    std::reverse(binary.begin(), binary.end()); 
    return binary;
}

std::string decimalToHex(int n){
    std::string binary = decimalToBinary(n);
    int lengthBinary = binary.length(), i = 0;
    std::string hex;

    std::map<std::string, char> hexEquivalents = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };// dictionary for hex equivalents

    // adding extra bits to the front
    if(lengthBinary % 4 != 0){
        int extraBits = 4 - (lengthBinary % 4);
        std::string extra;
        for(i=0; i<extraBits; i++){
            extra += '0';
        }
        binary = extra + binary;
    }

    for(i=0; i<lengthBinary; i+=4){
        std::string fourBits = binary.substr(i, 4);
        auto it = hexEquivalents.find(fourBits);
        hex += it->second;
    }

    return hex;

}
