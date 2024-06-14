#include<unity.h>

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

void testSimpleAllocation()
{
    int * a = new int;
    *a = TEST_INITIAL_VALUE_A;
    {
        int b = TEST_TARGET_VALUE_A;
        *a = b;
    }
    TEST_ASSERT_TRUE(*a == TEST_TARGET_VALUE_A);
}

void testComplexAllocation()
{
    Snapshot * data = new Snapshot;
    {
        *data = Snapshot(5, 6);
    }
    TEST_ASSERT_TRUE(data->atTime == 6);
    TEST_ASSERT_TRUE(data->pulseTime == 5);
}

DataVec<int> intVec;


void testSuperComplexAllocation(int variation)
{
    int value1 = 5 * variation;
    int value2 = 3 * variation;
    TEST_ASSERT_TRUE(intVec.lastItem() == nullptr);
    TEST_ASSERT_TRUE(intVec.length == 0);
    intVec.add(value1);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 1);
    TEST_ASSERT_TRUE(*intVec.lastItem() == value1);
    intVec.add(value2);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 2);
    TEST_ASSERT_TRUE(*intVec.lastItem() == value2);
    int * currentItem = new int;
    TEST_ASSERT_TRUE(intVec.iter(currentItem) != nullptr);
    TEST_ASSERT_TRUE(currentItem != nullptr);
    TEST_ASSERT_TRUE(*currentItem == value1);
    TEST_ASSERT_TRUE(intVec.iter(currentItem) != nullptr);
    TEST_ASSERT_TRUE(currentItem != nullptr);
    TEST_ASSERT_TRUE(*currentItem == value2);
    TEST_ASSERT_TRUE(intVec.lastItem() != nullptr);
    TEST_ASSERT_TRUE(intVec.length == 2);
    TEST_ASSERT_TRUE(*intVec.lastItem() == value2);
}

void testFullAllocation()
{
    testSimpleAllocation();
    testComplexAllocation();
    testSuperComplexAllocation(1);
    intVec.clean();
    testSuperComplexAllocation(2);
}

int main( int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(testFullAllocation);
    UNITY_END();
}
