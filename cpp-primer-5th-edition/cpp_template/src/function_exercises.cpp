#include "function_exercises.h"
#include <stdexcept>
#include <algorithm>

namespace cpp_primer {

// ========== 基础类型和变量练习 ==========

int add_integers(int a, int b) {
    // TODO: 实现两个整数的加法
    // 返回a和b的和
}

bool is_even(int num) {
    // TODO: 检查数字是否为偶数
    // 使用取模运算符%来判断
}

double fahrenheit_to_celsius(double fahrenheit) {
    // TODO: 实现华氏温度到摄氏温度的转换
    // 转换公式: C = (F - 32) * 5/9
}

int factorial(int n) {
    // TODO: 计算n的阶乘
    // 注意处理n=0和n=1的情况
    // 使用循环或递归实现
}

// ========== 字符串和数组练习 ==========

std::string reverse_string(const std::string& str) {
    // TODO: 反转字符串
    // 可以使用循环或标准库函数
}

int count_vowels(const std::string& str) {
    // TODO: 统计元音字母数量
    // 元音字母包括: a, e, i, o, u (大小写都要考虑)
}

int find_max(const int arr[], int size) {
    // TODO: 查找数组中的最大值
    // 注意处理空数组的情况
}

double calculate_average(const int arr[], int size) {
    // TODO: 计算数组元素的平均值
    // 注意处理除零错误
}

// ========== 控制流练习 ==========

bool is_leap_year(int year) {
    // TODO: 判断是否为闰年
    // 闰年规则: 能被4整除但不能被100整除，或者能被400整除
}

bool is_prime(int num) {
    // TODO: 判断数字是否为质数
    // 质数是大于1的自然数，且只能被1和自身整除
}

void print_multiplication_table(int n) {
    // TODO: 打印n×n的乘法表
    // 使用嵌套循环实现
}

int fibonacci(int n) {
    // TODO: 计算斐波那契数列的第n项
    // 斐波那契数列: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
}

// ========== 函数重载练习 ==========

int max_value(int a, int b) {
    // TODO: 返回两个整数中的较大值
}

double max_value(double a, double b) {
    // TODO: 返回两个浮点数中的较大值
}

int max_value(int a, int b, int c) {
    // TODO: 返回三个整数中的最大值
    // 可以调用两个参数的max_value函数
}

} // namespace cpp_primer