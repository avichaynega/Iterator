namespace itertools
{
template <typename T>
class range
{
private:
  T _start;
  T _stop;

public:
  range(T start, T stop)
  {
    _start = start;
    _stop = stop;
  }
  int length() const{
   return  (_stop-_start);
  }
  class iterator
  {
  private:
    T _it;
    T it_current;

  public:
    iterator(T pointer)
    {
       it_current = pointer;
      _it = pointer ;    
    }
    T operator*() const
    {
      return it_current;
    }

    // ++i;
    iterator operator++()
    {
      ++(it_current);
      return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const iterator operator++(int)
    {
      iterator tmp = *this;
     ++it_current;
      return tmp;
    }

    bool operator==(const iterator &other) const
    {
      return it_current == other.it_current;
    }

    bool operator!=(const iterator &other) const
    {
      return it_current != other.it_current;
    }
    
  };
  iterator begin() const { return iterator{_start};}
  iterator end() const { return iterator{_stop}; }
};
}; // namespace itertools
