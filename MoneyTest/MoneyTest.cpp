#include <memory>
#include "gtest/gtest.h"
#include "Money.h"

TEST(testMoney, testDifferentClassEquality) {
   EXPECT_TRUE(Money(10, "USD").equals(Money::dollar(10)));
   EXPECT_TRUE(Money(10, "CHF").equals(Money::franc(10)));

}

TEST(testMoney, testCurrency) {
   EXPECT_EQ("USD", Money::dollar(1).currency());

   EXPECT_EQ("CHF", Money::franc(1).currency());
}

TEST(testMoney, testMultiplication) {
	Money five = Money::dollar(5);
	EXPECT_EQ( Money::dollar(10), five.times(2) );
   EXPECT_EQ( Money::dollar(15), five.times(3) );
   EXPECT_TRUE(Money::dollar(10).equals(five.times(2)));

   Money fiveFrancs = Money::franc(5);
   EXPECT_EQ(Money::franc(10), fiveFrancs.times(2));
   EXPECT_EQ(Money::franc(15), fiveFrancs.times(3));
   EXPECT_TRUE(Money::franc(15).equals(fiveFrancs.times(3)));
}

TEST(testMoney, testEquality) {
   EXPECT_EQ(Money::dollar(5), Money::dollar(5));
   EXPECT_NE(Money::dollar(5), Money::dollar(6));
   EXPECT_EQ(Money::franc(5), Money::franc(5));
   EXPECT_NE(Money::franc(5), Money::franc(6));

 
   EXPECT_NE(Money::dollar(5), Money::franc(5));
   EXPECT_FALSE(Money::dollar(5).equals(Money::franc(5)));

}


//TEST(testMoney, testTypeID) {
//   Money money(1); 
//   Dollar dollar(2);
//   Franc franc(3);
//
//   EXPECT_NE(typeid(money), typeid(dollar)); //<< typeid(money).name() << " " << typeid(dollar).name();
//   EXPECT_NE(typeid(money), typeid(franc));
//   EXPECT_NE(typeid(dollar), typeid(franc));
//
//   EXPECT_STREQ("class Money", typeid(money).name());
//   EXPECT_STREQ(".?AVMoney@@", typeid(money).raw_name());
//   EXPECT_STREQ("class Dollar", typeid(dollar).name());
//   EXPECT_STREQ("class Franc", typeid(franc).name());
//}

