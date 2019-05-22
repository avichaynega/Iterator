namespace itertools
{

template <typename T1, typename T2>

class chain
{
private:
  T1 first;
  T2 second;
  using V1 = decltype(*first.begin());

public:
  chain(const T1 first, const T2 second) : first(first), second(second)
  {
    using V1 = const decltype(*first.begin()) &;
    using V2 = const decltype(*second.begin()) &;
  }
  int length () const
  {
    return first.length() + second.length();
  }

  class iterator
  {
  private:
    T1 first_begin;
    typename T1::iterator first_data;
    T2 second_begin;
    typename T2::iterator second_data;
  
  int counter=0;
    bool is_sec = false;

  public:
  int size = 0;
    iterator(T1 first_be, T2 second_be) : first_begin(first_be), second_begin(second_be),
                                          first_data(first_begin.begin()), second_data(second_begin.begin())
    {
      length();
    }

    void length(){
      for (;first_data != first_begin.end();++first_data){
        size++;
      }
      for (;second_data != second_begin.end();++second_data){
        size++;
      }
      first_data = first_begin.begin();
      second_data = second_begin.begin();

    }
    decltype(auto) operator*()
    {
      if(counter == 0){
        counter++;
      }
      auto type =*first_data;
      if (!is_sec)
      {
        type = *first_data;
        return type;
        
      }
      type = *second_data;
      return type;
    }

    //++i;
    iterator operator++()
    {
       counter++;
      if (*first_data == (*first_begin.end() - 1) && !is_sec)
      {
        is_sec = true;
        return *this;
      }

      if (is_sec)
      {
        ++second_data;
      }
      else
      {
        ++first_data;
      }
      return *this;
    }

    // i++;
    // Usually iterators are passed by value and not by const& as they are small.
    const iterator operator++(int)
    {
      
      if (*first_data == (*first_begin.end() - 1) && !is_sec)
      {
        is_sec = true;
        iterator tmp = *this;
        ++*this;
        return tmp;
      }

      if (is_sec)
      {
        ++second_data;
      }
      else
      {
        ++first_data;
      }

      return *this;
    }

    bool operator==(const iterator &other) const
    {
      return !(this != other);
    }

    bool operator!=(const iterator other) const
    {
      
      return counter<=size;
    }
  };
  iterator begin() const { return iterator{first, second}; }
  iterator end() const
  {
return iterator{first, second};
  }
};
}; // namespace itertools
