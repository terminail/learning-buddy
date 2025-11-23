#ifndef FUNCTION_EXERCISES_H
#define FUNCTION_EXERCISES_H

#include <string>
#include <vector>
#include <iostream>

namespace cpp_primer {

// ========== 基础类型和变量练习 ==========

/**
 * @brief 计算两个整数的和
 * @param a 第一个整数
 * @param b 第二个整数
 * @return 两个整数的和
 */
int add_integers(int a, int b);

/**
 * @brief 检查数字是否为偶数
 * @param num 要检查的数字
 * @return 如果是偶数返回true，否则返回false
 */
bool is_even(int num);

/**
 * @brief 将华氏温度转换为摄氏温度
 * @param fahrenheit 华氏温度
 * @return 摄氏温度
 */
double fahrenheit_to_celsius(double fahrenheit);

/**
 * @brief 计算整数的阶乘
 * @param n 要计算阶乘的整数
 * @return n的阶乘
 */
int factorial(int n);

// ========== 字符串和数组练习 ==========

/**
 * @brief 反转字符串
 * @param str 要反转的字符串
 * @return 反转后的字符串
 */
std::string reverse_string(const std::string& str);

/**
 * @brief 统计字符串中元音字母的数量
 * @param str 要统计的字符串
 * @return 元音字母的数量
 */
int count_vowels(const std::string& str);

/**
 * @brief 查找数组中的最大值
 * @param arr 整数数组
 * @param size 数组大小
 * @return 数组中的最大值
 */
int find_max(const int arr[], int size);

/**
 * @brief 计算数组元素的平均值
 * @param arr 整数数组
 * @param size 数组大小
 * @return 数组元素的平均值
 */
double calculate_average(const int arr[], int size);

// ========== 控制流练习 ==========

/**
 * @brief 判断年份是否为闰年
 * @param year 年份
 * @return 如果是闰年返回true，否则返回false
 */
bool is_leap_year(int year);

/**
 * @brief 判断数字是否为质数
 * @param num 要检查的数字
 * @return 如果是质数返回true，否则返回false
 */
bool is_prime(int num);

/**
 * @brief 打印乘法表
 * @param n 乘法表的大小
 */
void print_multiplication_table(int n);

/**
 * @brief 计算斐波那契数列的第n项
 * @param n 斐波那契数列的项数
 * @return 第n项的值
 */
int fibonacci(int n);

// ========== 函数重载练习 ==========

/**
 * @brief 计算两个整数的最大值
 * @param a 第一个整数
 * @param b 第二个整数
 * @return 两个整数中的最大值
 */
int max_value(int a, int b);

/**
 * @brief 计算两个浮点数的最大值
 * @param a 第一个浮点数
 * @param b 第二个浮点数
 * @return 两个浮点数中的最大值
 */
double max_value(double a, double b);

/**
 * @brief 计算三个整数的最大值
 * @param a 第一个整数
 * @param b 第二个整数
 * @param c 第三个整数
 * @return 三个整数中的最大值
 */
int max_value(int a, int b, int c);

} // namespace cpp_primer

#endif // FUNCTION_EXERCISES_H