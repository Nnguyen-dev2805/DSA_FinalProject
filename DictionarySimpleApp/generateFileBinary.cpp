// Generate File Binary

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void convertTxtToBinary(const string &inputFile, const string &outputFile)
{
    ifstream inFile(inputFile);
    ofstream outFile(outputFile, ios::binary);

    string line;
    while (getline(inFile, line))
    {
        size_t pos = line.find(' ');
        if (pos == string::npos)
        {
            continue;
        }
        string word = line.substr(0, pos);
        string def = line.substr(pos + 1);

        auto writeStringToFile = [&outFile](string s)
        {
            size_t len = s.size();
            // mục đích chuyển đổi con trỏ len từ kiểu size_t* sang kiểu
            // const char*. Hàm reinterpret_cast cho phép chúng ta thay đổi con trỏ mà
            // không thay đổi giá trị thực tế của biến
            // việc chuyển đổi này là cần thiết vì hàm write yêu cầu
            // con trỏ đến kiểu char (mỗi ký tự trong file nhị phân được lưu dưới dạng byte)
            outFile.write(reinterpret_cast<const char *>(&len), sizeof(len));

            // chuyển chuỗi về dạng mảng kí tự rồi ghi len kí tự vào không ghi kí tự NULL
            outFile.write(s.c_str(), len);
        };
        writeStringToFile(word);
        writeStringToFile(def);
    }
    inFile.close();
    outFile.close();
}

int main()
{
    convertTxtToBinary("InputFile/EnglishDictionary.txt", "EnglishDictionary.dat");
    return 0;
}