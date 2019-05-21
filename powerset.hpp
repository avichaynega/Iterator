#include <bitset>
#include <algorithm>
#include <cmath>

namespace itertools
{
template <typename T>
class powerset
{
private:
  T set;
 

public:
  powerset(T start): set(start) 
  {
  }
  int length() const{
   return set.length();
  }
  class iterator
  {
  private:
     T object;
     string string_set;
    int counter = 0;
    int size ;
    string subset;
    
    void to_string() {
       stringstream ss;
       typename T::iterator it  = object.begin();
      for(int i =0;i<size;i++){

      ss << *it;
      ++it;
      }
    ss >> string_set;
    
    }

  public:
    iterator(T obj):object(obj),size(pow(2,obj.length()))
    { 
      to_string();     
    }

    string operator*() 
    {
      if(subset==""){counter++;}
      return "{"+subset+"}"; 
    }
    


    // ++i;
    iterator operator++()
    {
      stringstream ss;
      
      string binary = bitset<20>(counter).to_string(); //to binary
      reverse(binary.begin(),binary.end());
      for (int i=0;i<size;i++){
       
        if(binary[i]=='1'){
          ss << string_set[i];
          ss <<",";
         
        }
      }
      ss>>subset;
      
     subset=subset.substr(0,subset.length()-1);      
      ++counter;
      return *this;
    }

    // // i++;
    // // Usually iterators are passed by value and not by const& as they are small.
    // const iterator operator++(int)
    // {
    //   iterator tmp = *this;
    //  ++it_current;
    //   return tmp;
    // }

    bool operator==(const iterator other) 
    {
      return *this == other;
    }

    bool operator!=(const iterator other)
    {
      

      return counter <=size;
    }
    
  };
  iterator begin() const { return iterator{set};}
  iterator end() const { return iterator{set}; }
};
}; // namespace itertools
