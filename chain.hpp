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
    int length()
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

    bool is_sec = false;

  public:
    iterator(T1 first_be, T2 second_be) : first_begin(first_be), second_begin(second_be),
                                          first_data(first_begin.begin()), second_data(second_begin.begin())
    {
    }

    decltype(auto) operator*()
    {
      V1 type;
      if (!is_sec)
      {
        type = *first_data;
        return type;
        ;
      }
      type = *second_data;
      return type;
    }

    //++i;
    iterator operator++()
    {
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
      V1 type;
      V1 type2;

      type = *second_data;
      type2 = *other.second_data;
      return type != type2;
    }
  };
  iterator begin() const { return iterator{first, second}; }
  iterator end() const
  {

    iterator it{first, second};
    for (size_t i = 0; i < (first.length() + second.length() + 1); i++)
    {
      ++it;
    }

    return it;
  }
};
}; // namespace itertools
