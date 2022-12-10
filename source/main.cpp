/**
 * @file main.cpp
 * @author Halit Cetin (halitcetin@live.com)
 * @brief Internal map example project
 * @version 0.1
 * @date 04-12-2022
 *
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include "interval_map.cpp"

void REQUIRE(bool status);
void TEST_CASE_1(void);
void TEST_CASE_2(void);
void TEST_CASE_3(void);
void TEST_CASE_4(void);
void TEST_CASE_5(void);
void TEST_CASE_6(void);
void TEST_CASE_7(void);
void TEST_CASE_8(void);
void TEST_CASE_9(void);
void TEST_CASE_10(void);
void TEST_CASE_11(void);
void TEST_CASE_12(void);
void TEST_CASE_13(void);
void TEST_CASE_14(void);
void TEST_CASE_15(void);
void TEST_CASE_16(void);
void TEST_CASE_17(void);
void TEST_CASE_18(void);
void TEST_CASE_19(void);

/**
 * @brief Enterance point of the program
 *
 * @return int Program succes value
 */
int main(void)
{
    TEST_CASE_1();
    TEST_CASE_2();
    TEST_CASE_3();
    TEST_CASE_4();
    TEST_CASE_5();
    TEST_CASE_6();
    TEST_CASE_7();
    TEST_CASE_8();
    TEST_CASE_9();
    TEST_CASE_10();
    TEST_CASE_11();
    TEST_CASE_12();
    TEST_CASE_13();
    TEST_CASE_14();
    TEST_CASE_15();
    TEST_CASE_16();
    TEST_CASE_17();
    TEST_CASE_18();
    TEST_CASE_19();
    return 0;
}

void REQUIRE(bool status)
{
    if (status == true)
    {
        std::cout << "PASSED" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }
}

void TEST_CASE_1(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 10, 'B');
    REQUIRE(m[0] == 'A');
    for (int i = 1; i < 10; i++)
    {
        REQUIRE(m[i] == 'B');
    }
    REQUIRE(m[10] == 'A');
}

void TEST_CASE_2(void)
{
    interval_map<int, char> m('A');
    m.assign(3, 3, 'B');
    REQUIRE(m.m_map.count(3) == 0);

    m.assign(3, 2, 'B');
    REQUIRE(m.m_map.count(2) == 0);
    REQUIRE(m.m_map.count(3) == 0);
}

void TEST_CASE_3(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 3, 'B');
    m.assign(6, 8, 'C');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'A');
    REQUIRE(m[4] == 'A');
    REQUIRE(m[5] == 'A');
    REQUIRE(m[6] == 'C');
    REQUIRE(m[7] == 'C');
    REQUIRE(m[8] == 'A');
}

void TEST_CASE_4(void)
{
    interval_map<int, char> m('A');
    m.assign(std::numeric_limits<int>::lowest(), 10000, 'B');
    REQUIRE(m[0] == 'B');
    REQUIRE(m[9999] == 'B');
    REQUIRE(m[10000] == 'A');
}

void TEST_CASE_5(void)
{
    interval_map<int, char> m('A');
    m.assign(std::numeric_limits<int>::lowest(), 10, 'B');
    m.assign(10, 20, 'B');
    REQUIRE(m[0] == 'B');
    REQUIRE(m[10] == 'B');
    REQUIRE(m[19] == 'B');
    REQUIRE(m[20] == 'A');
}

void TEST_CASE_6(void)
{
    interval_map<float, char> m('A');
    m.assign(1.f, 5.f, 'B');
    REQUIRE(m[0.f] == 'A');
    REQUIRE(m[.999999999f] == 'B');
    REQUIRE(m[1.f] == 'B');
    REQUIRE(m[4.999f] == 'B');
    REQUIRE(m[5.f] == 'A');
}

void TEST_CASE_7(void)
{
    interval_map<int, char> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 6, 'C');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'C');
    REQUIRE(m[2] == 'C');
    REQUIRE(m[3] == 'C');
    REQUIRE(m[4] == 'C');
    REQUIRE(m[5] == 'C');
    REQUIRE(m[6] == 'A');
}

void TEST_CASE_8(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 6, 'C');
    m.assign(3, 5, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'C');
    REQUIRE(m[2] == 'C');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'C');
    REQUIRE(m[6] == 'A');
}

void TEST_CASE_9(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'C');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'C');
    REQUIRE(m[4] == 'C');
    REQUIRE(m[5] == 'C');
    REQUIRE(m[6] == 'A');
}

void TEST_CASE_10(void)
{
    interval_map<int, char> m('A');
    m.assign(3, 6, 'C');
    m.assign(1, 5, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'C');
    REQUIRE(m[6] == 'A');
}

void TEST_CASE_11(void)
{
    interval_map<int, char> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 4, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_12(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'B');
    REQUIRE(m[6] == 'A');
}

void TEST_CASE_13(void)
{
    interval_map<int, char> m('A');
    m.assign(2, 3, 'B');
    m.assign(1, 5, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_14(void)
{
    interval_map<int, char> m('A');
    m.assign(2, 5, 'B');
    m.assign(5, 8, 'C');
    m.assign(4, 5, 'A');
}

void TEST_CASE_15(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(2, 3, 'B');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'B');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_16(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(4, 6, 'A');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'B');
    REQUIRE(m[2] == 'B');
    REQUIRE(m[3] == 'B');
    REQUIRE(m[4] == 'A');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_17(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(1, 5, 'A');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'A');
    REQUIRE(m[2] == 'A');
    REQUIRE(m[3] == 'A');
    REQUIRE(m[4] == 'A');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_18(void)
{
    interval_map<int, char> m('A');
    m.assign(1, 5, 'B');
    m.assign(0, 7, 'A');
    REQUIRE(m[0] == 'A');
    REQUIRE(m[1] == 'A');
    REQUIRE(m[2] == 'A');
    REQUIRE(m[3] == 'A');
    REQUIRE(m[4] == 'A');
    REQUIRE(m[5] == 'A');
}

void TEST_CASE_19(void)
{
    interval_map<int, char> m('A');
    m.assign(3, 6, 'B');
    m.assign(2, 5, 'C');
    m.assign(4, 7, 'A');

    REQUIRE(m[1] == 'A');
    REQUIRE(m[2] == 'C');
    REQUIRE(m[3] == 'C');
    REQUIRE(m[4] == 'A');
    REQUIRE(m[5] == 'A');
    REQUIRE(m[6] == 'A');
    REQUIRE(m[7] == 'A');
}