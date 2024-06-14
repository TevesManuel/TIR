#include<unity.h>
#include<DataVec.hpp>
#include<Snapshot.hpp>
#include<Arduino.h>

void testCorrectlySettingAndGettingTime()
{
    DataVec<Snapshot> recordedTime;
    unsigned long time_0 = 5;
    unsigned long duration_0 = 3;
    TEST_ASSERT(recordedTime.lastItem() == nullptr);
    recordedTime.add(Snapshot(duration_0, time_0));
    recordedTime.add(Snapshot(duration_0*2, time_0*2));
    TEST_ASSERT(recordedTime.length == 2);
    TEST_ASSERT(recordedTime.lastItem()->atTime == time_0);
    TEST_ASSERT(recordedTime.lastItem()->pulseTime == duration_0);
    // TEST_ASSERT(recordedTime.length == 2);
    // TEST_ASSERT(recordedTime.lastItem()->atTime == time_0*2);
    // TEST_ASSERT(recordedTime.lastItem()->pulseTime == duration_0*2);
}
