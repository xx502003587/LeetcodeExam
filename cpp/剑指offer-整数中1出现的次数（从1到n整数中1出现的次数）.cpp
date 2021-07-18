/*
 * 题意：
 * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
 * ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
 *
 * 思路：
 * 1. 遍历从1到n的所有数，每个数从个位开始判断是否为1，累加计数，时间复杂度O(nlogn)(log以10为底)
 * 2. 根据规律解题，时间复杂度O(logn)(log以10为底)
 * 如n=514的情况
 * 2.1 考虑个位：令weight等于个位的数字，round等于高位的数，即weight=4 round=51
 * 从1到n，每增加1，weight就会加1，当weight加到9时，再加1又会回到0重新开始。
 * 那么weight从0-9的这种周期会出现多少次呢？这取决于n的高位是多少，在从1增长到n的过程中，514的个位从0-9变化了51次，记为round。
 * 每一轮变化中，1在个位出现一次，所以一共出现了51次。 
 * 再来看weight的值。weight为1，大于0，说明第51轮变化是从0-1，1又出现了1次。
 * 记1出现的次数为count，所以 count = round+1 = 51 + 1 = 52
 * 如果此时weight为0（n=510），说明第52轮到0就停止了，那么： count = round = 51
 * 
 * 2.2 考虑十位：令weight等于十位的数字，round等于高位的数，即weight=1 round=5
 * 对于10位来说，其0-9周期的出现次数与个位的统计方式是相同的。
 * 不同点在于：从1到n，每增加10，十位的weight才会增加1
 * 所以，一轮0-9周期内，1会出现10次。即round*10，一共出现了50次。 
 * 再来看weight的值。当此时weight为1，等于1，那么第6轮中1出现了多少次呢？
 * 这与个位数的值有关，个位数为k，第6轮中1就出现了k+1次(0-k)。
 * 记个位数为former，则： count = round*10 + former + 1= 5*10 + 4 + 1 = 55
 * 如果此时weight的值等于0（n=504），说明第6轮到0就停止了，那么： count = round*10 = 5*10 = 50
 * 
 * 2.3 考虑百位：令weight等于百位的数字，round等于高位的数，即weight=5 round=0
 * 从1到n，每增加100，百位的weight才会增加1
 * 所以，一轮0-9周期内，1会出现100次，即round*100，一共出现了0次
 * 再来看weight的值。weight为5，大于1，说明第1轮变化是从0-5，1又出现了100次，所以：count = round*100 + 100 = 100
 * 
 * 累加起来总的出现次数为 count = 52 + 55 + 100 = 207
 */

#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n) {
    if (n <= 1) {
        return n;
    }
    int count = 0;
    int round = n;
    int base = 1;
    int weight = 0;
    while (round > 0) {
        // 取到最低位的数字
        weight = round % 10;
        // 1在最低位一共出现了 round / 10 * base 次
        round /= 10;
        count += round * base;
        // 如果当前位是1，则当前位出现的次数应该是低位数+1，如：14的十位1出现的次数是4+1=5次，即10,11,12,13,14
        if (weight == 1) {
            count += (n%base) + 1;
        } 
        // 如果当前位大于1，则表明在该位为1的次数都要加上，即base次
        else if (weight > 1) {
            count += base;
        }
        base *= 10;
    }
    return count;
}

int main() {
    int n = 514; // 207
    auto ret = NumberOf1Between1AndN_Solution(n);
    cout << ret << endl;
    return 0;
}
