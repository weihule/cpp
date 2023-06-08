#include "global_file.h"

vector<string> string_split(const string& str, char delim) {
    // stringstream将字符串转换为输入流ss，然后使用std::getline函数从输入流中逐个读取分隔符分隔的子字符串
    stringstream ss(str);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}
