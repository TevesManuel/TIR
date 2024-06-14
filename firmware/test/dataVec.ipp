#include<unity.h>
#include<DataVec.hpp>

void testCorrectlySettingAndGetting()
{
    DataVec<int> registerOfSecuence;
    registerOfSecuence.add(5);
    registerOfSecuence.add(6);
    registerOfSecuence.add(8);
    registerOfSecuence.add(7);
    int data_iter;
    int total_sum = 0;
    while ( registerOfSecuence.iter(&data_iter) )
    {
        total_sum += data_iter;
    }

    Serial.println(registerOfSecuence.length);

    TEST_ASSERT_TRUE(total_sum == 26);
    Serial.println(registerOfSecuence.length);

    TEST_ASSERT_TRUE(registerOfSecuence.length == (u8)4);

    TEST_ASSERT_TRUE(*registerOfSecuence.lastItem() == 7);
}