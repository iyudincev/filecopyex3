#pragma once

#include <vector>

#include "StringParent.h"

class StringVector : public StringParent
{
public:
  StringVector() {}
  virtual ~StringVector() {}

  virtual void Clear() { data.clear(); }
  virtual const String & operator[](size_t i) const { return data[i]; }
  virtual void AddString(const String & v) { data.push_back(v); }
  virtual size_t Count() const { return data.size(); }
  intptr_t Find(const String & v, intptr_t start = 0) const
  {
    for (size_t i = start; i < Count(); ++i)
    {
      if (data[i].cmp(v) == 0)
        return i;
    }
    return -1;
  }

private:
  std::vector<String> data;
};

