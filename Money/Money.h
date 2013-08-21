#pragma once

class Money
{

public:
   Money(int amount, std::string currency = "???");
   virtual ~Money() {}

   virtual bool equals(const Money& money) const;
   virtual Money times(int multiplier);

   static Money dollar(int amount);

   static Money franc(int amount);

   virtual std::string currency() const;

   // See articles about operator overloading
   //    http://stackoverflow.com/questions/4421706/operator-overloading
   //    http://stackoverflow.com/questions/10070020/c-operator-overloading?lq=1
   friend bool operator==(const Money& lhs, const Money& rhs);
   friend bool operator!=(const Money& lhs, const Money& rhs);

protected:
   int m_amount; 
   std::string m_currency;
};

