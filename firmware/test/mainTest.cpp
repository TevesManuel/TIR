#include<unity.h>

#include "./dataVec.ipp"
#include "./timeRegistration.ipp"

#include <Arduino.h>

#include <Snapshot.hpp>
#include <DataVec.hpp>


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

#define TEST_INITIAL_VALUE_A 5
#define TEST_TARGET_VALUE_A 4

void testAllocation()
{
    int * a;
    *a = TEST_INITIAL_VALUE_A;
    {
        int b = TEST_TARGET_VALUE_A;
        *a = b;
    }
    TEST_ASSERT_TRUE(*a == TEST_TARGET_VALUE_A);
    Snapshot * data;
    {
        *data = Snapshot(5, 6);
    }
    TEST_ASSERT_TRUE(data->atTime == 6);
    TEST_ASSERT_TRUE(data->pulseTime == 5);
    DataVec<int> intVec;
    TEST_ASSERT_TRUE(intVec.lastItem() == nullptr);
    TEST_ASSERT_TRUE(intVec.length == 0);
    intVec.add(5);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 1);
    TEST_ASSERT_TRUE(*intVec.lastItem() == 5);
    intVec.add(3);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 2);
    TEST_ASSERT_TRUE(*intVec.lastItem() == 3);
    int * currentItem;
    TEST_ASSERT_TRUE(intVec.iter(currentItem) != nullptr);
    TEST_ASSERT_TRUE(currentItem != nullptr);
    TEST_ASSERT_TRUE(*currentItem == 5);
    TEST_ASSERT_TRUE(intVec.iter(currentItem) != nullptr);
    TEST_ASSERT_TRUE(currentItem != nullptr);
    TEST_ASSERT_TRUE(*currentItem == 3);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 2);
    TEST_ASSERT_TRUE(*intVec.lastItem() == 3);
}

int main( int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(testAllocation);
    // RUN_TEST(testCorrectlySettingAndGetting);
    // RUN_TEST(testCorrectlySettingAndGettingTime);
    UNITY_END();
}
