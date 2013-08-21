#include "stdafx.h"
#include <string>
#include <memory>
#include "Money.h"

Money::Money(int amount, std::string currency/*= "???"*/)
{
   this->m_amount = amount;
   this->m_currency = currency;
}

Money Money::times(int multiplier)
{
   return Money(m_amount * multiplier, m_currency);
}

bool Money::equals(const Money& money) const
{
  
   return m_amount == money.m_amount 
            && this->currency() == money.currency();
      
}


bool operator==(const Money& lhs, const Money& rhs) {
   return lhs.equals(rhs);
}

bool operator!=(const Money& lhs, const Money& rhs) {
   return !lhs.equals(rhs);
}

Money Money::dollar(int amount)
{
   return Money(amount, "USD");
}

Money Money::franc(int amount)
{
   return Money(amount, "CHF");
}

std::string Money::currency() const
{ 
   return m_currency;
}

//endfile: money.cpp