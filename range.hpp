#include <iostream>
#include <typeinfo>

namespace itertools
{
template <typename T>
class range
{

private:
  T start_;
  T stop_;

public:
  range() {}
  range(T start, T stop)
  {

    start_ = start;
    stop_ = stop;
  }

  class iterator
  {

  public:
    T *a_pointer;
    T value;

    iterator(T start)
    {

      value = start;
      // cout<<value<<endl;
      a_pointer = &value;
    }

    T operator*() const
    {

      return value;
    }
    // ++i;

    iterator operator++()
    {
      value++;
      return *a_pointer;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    iterator operator++(int)
    {
      iterator tmp = a_pointer;
      *a_pointer++;
      return tmp;
    }

    bool operator==(const iterator &other) const
    {
      return value == other.value;
    }

    bool operator!=(const iterator &other) const
    {
      return value != other.value;
    }
  };
  iterator begin()
  {

    return iterator{start_};
  }

  iterator end()
  {

    //cout <<  *iterator{stop_} << endl;
    return iterator{stop_};
  }
};
}; // namespace itertools