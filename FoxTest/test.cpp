#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(FoxTest, constructor) {
    {  
        Seconds s;
        ASSERT_EQ(s.seconds(), 0);
    }

    {   Seconds* s = new Seconds;
    ASSERT_EQ(s->seconds(), 0);
    delete s; }

    {   Seconds* s = new Seconds(5);
    ASSERT_EQ(s->seconds(), 5);
    delete s; }

    {   Seconds s(0);
    ASSERT_EQ(s.seconds(), 0);   }

    {   Seconds s(42);
    ASSERT_EQ(s.seconds(), 42);  }

    {   Seconds s(59);
    ASSERT_EQ(s.seconds(), 59);  }

    // ќжидать искоючение: Seconds s(60) должен бросить исключение типа SecondsException
    ASSERT_THROW(Seconds s(60), SecondsException);

    ASSERT_THROW(Seconds s(100), SecondsException);

    ASSERT_THROW(Seconds s(-1), SecondsException);

    ASSERT_THROW(Seconds s(-100), SecondsException);
}