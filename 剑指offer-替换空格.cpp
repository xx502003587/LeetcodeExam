/*
 * 题目：
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 * 
 * 思路：
 * 该题要求为原地替换，不允许开辟新的空间
 * 于是可以考虑先通过一次遍历来计算空格的个数和除空格之外的其他字符的个数，然后计算新字符串的长度，从末尾开始往前遍历
 * 用两个指针p和q分别指向原始字符串的最后一位和新长度的最后一位，如果p字符为空格，则将q字符往前三位分别设置为0 2 % 直到p遍历完毕
 */

#include <iostream>

using namespace std;

void replaceSpace(char *str,int length) {
        if (str == NULL || length == 0) {
            return;
        }
        int original_length = 0;
        int number_of_space = 0;
        int i = 0;
        while (str[i] != '\0') {
            ++original_length;
            if (str[i] == ' '){
                ++number_of_space;
            }
            ++i;
        }
        
        int new_length = original_length + number_of_space * 2;
        if (new_length > length) {
            return;
        }
        
        int index_of_original = original_length;
        int index_of_new = new_length;
        
        while (index_of_original >= 0 && index_of_new > index_of_original) {
            if (str[index_of_original] == ' ') {
                str[index_of_new --] = '0';
                str[index_of_new --] = '2';
                str[index_of_new --] = '%';
            } else {
                str[index_of_new --] = str[index_of_original];
            }
            --index_of_original;
        }
	}

int main() {
    char* input = "We are happy";
    if (input == NULL) {
        return 0;
    }
    auto ret = replaceSpace(input);
    cout << "原字符串为 " << input << endl;
    cout << "替换后字符串为 " << ret << endl;
    return 0;
}
