
namespace itertools
{

template <typename A,typename B,typename T> 
class chain
{
 
private:
  static A _a;
  static B _b;
  static T _c;
  

public:
  chain() {}
  chain(A a, B b)
  {
     _a = a;
     _b = b;
     _c= nullptr;
  }

  class iterator
  {

  public:
    
  T *value;

    iterator()
    {
      value=_a.begin();
    }

    
    iterator operator*() 
    {
      return *value ;
    }

    iterator &operator++() 
    {
      if (value==_a.end()){
        value == *_b.begin();
        return;
      }
      if (typeid(value)==typeid("ss")){
        value++;
      }
      if (typeid(value)==typeid(6)){
          *value++;
      }
      
      return *value;
    }

    iterator operator++(int) 
    {
      auto ret = *this;
      ++*this;
      return ret;
    }

    bool operator!=( iterator &other) 
    {

      return *this!= *other ;
    }

    bool operator==( iterator &other) 
    {
      return *this == other;
    }
  };
    iterator begin()
  {
     return iterator{};
   
  }
    iterator end()
  {
      return _b.end();
  }
};
}; // namespace itertools