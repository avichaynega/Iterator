#include <sstream>
namespace itertools
{

template <typename T1, typename T2>

class zip
{
private:
  T1 first;
  T2 second;
  using V1 = decltype(*first.begin());
  using V2 = decltype(*second.begin());

public:
  zip(const T1 first, const T2 second) : first(first), second(second)
  {
    static_assert(
        std::is_same<V1, V2>,
        "The two arguments of 'chain' must have the same value type!");
  }
 int length() const{
   return first.length();
 }
  class iterator
  {
  private:
    T1 first_begin;
    typename T1::iterator first_data;
    T2 second_begin;
    typename T2::iterator second_data;

    bool on_off = false;

  public:
    iterator(T1 first_be, T2 second_be) : first_begin(first_be), second_begin(second_be),
                                          first_data(first_begin.begin()), second_data(second_begin.begin())
    {
    }

    string operator*()
    {
      stringstream ss;
      string res = "";
      ss << *first_data;
      ss << ",";
      ss << *second_data;
      ss >> res;
      return res;
    }

    //++i;
    iterator operator++()
    {
      ++first_data;
      ++second_data;
      return *this;
    }

        // i++;
        // Usually iterators are passed by value and not by const& as they are small.
        iterator operator++(int)
        {
          
          iterator tmp = *this;
          ++*this;
          return tmp;
        }

        bool operator==(iterator other) 
        {
          
          return **this == *other;
        
        }

        bool operator!=( iterator other) 
        {

           return  !(*this==other);
        }
  };
  iterator begin() const { return iterator{first, second}; }
  iterator end() const
  {

    iterator it{first, second};
    for (size_t i = 0; i < (first.length()); i++)
    {
      ++it;
    }

    return it;
  }
};
}; // namespace itertools
