#include <iostream>
#include <string>
#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;
//convert container to string
template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	return ostr.str();
}
int main()
{
	badkan::TestCase testcase;
	int grade = 0; //Inits the grade.
	int signal = setjmp(badkan::longjmp_buffer);
	if(signal == 0)
	{
		int check=22;

		testcase.setname("------Range tests-------");
		for (int i: range(22,29)){
		testcase.CHECK_EQUAL(i,check++);
		}

		check=2;
		testcase.setname("------Chain tests-------");
		for (int i: chain(range(2,8),range(2,5))){
		testcase.CHECK_EQUAL(check++,i);
		if(check==7)check=2;
		}
		
		string ch = iterable_to_string( zip(range(5,8), string("abc"))); //5,a 6,b 7,c
		string t="";
		testcase.setname("------zip tests-------");
		for (int i: zip(range(5,8), string("abc"))){
			t=t+to_string(i);
		}
		testcase.CHECK_EQUAL(ch,t);

		ch = iterable_to_string( product(range(15,17), string("tc"))); 
		t="";
		testcase.setname("------product tests-------");
		for (int i: product(range(15,17), string("tc"))){
			t=t+to_string(i);
		}
		testcase.CHECK_EQUAL(ch,t);

		ch = iterable_to_string( powerset(range(-9,-6))); //{-9,-8,-7}
		t="";
		testcase.setname("------powerset tests-------");
		for (int i: powerset(range(-9,-6))){
			t=t+to_string(i);
		}
		testcase.CHECK_EQUAL(ch,t);
    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
