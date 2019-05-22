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
  int size =0;
  int counter =0;
    bool on_off = false;

  public:
    iterator(T1 first_be, T2 second_be) : first_begin(first_be), second_begin(second_be),
                                          first_data(first_begin.begin()), second_data(second_begin.begin())
    {
      length();
    }
    void length(){
      for (;first_data != first_begin.end();++first_data){
        size++;
      }
      first_data = first_begin.begin();
    }
    
    string operator*()
    {
      if(counter == 0){
        counter++;
      }
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
      counter++;
      ++first_data;
      ++second_data;
      return *this;
    }

        // i++;
        // Usually iterators are passed by value and not by const& as they are small.
        iterator operator++(int)
        {
           counter++;
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
           return  counter<=size;
        }
  };
  iterator begin() const { return iterator{first, second}; }
  iterator end() const
  { return iterator{first, second};}
};
}; // namespace itertools
