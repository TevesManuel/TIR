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
    TEST_ASSERT_TRUE(total_sum == 26);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main( int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(testCorrectlySettingAndGetting);
    UNITY_END();
}
