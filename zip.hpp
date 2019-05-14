#include <iostream>
#include <typeinfo>
#include <cassert>

namespace itertools
{
template <typename T,typename Y>
class zip
{
  T *start;
  Y *last;
  public:

  zip(T  s, Y  l): start(&s), last(&l){}

  // uint size;
public:
  class const_iterator
  {
  private:
    T *current, *first, *last ; 
    public: 
    const_iterator(T *c, T *f, T *l) : current(c), first(f), last(l) {}
    const T &operator*() const
    {
      assert(current >= first && current < last);
      return *current;
    }
    const_iterator operator++() //prefix
    {
      current++;
      return *this;
    }
    bool operator!=(const_iterator &other) const
    {
      assert(first == other.first);
      assert(last == other.last);
      return (current != other.current);
    }
  
  };
int* begin(){return nullptr;};
int * end(){return nullptr;};
}; // namespace itertools
}
; // namespace itertools