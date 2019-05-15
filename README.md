### authors: Avichay (Avtai) Nega, Omer Hadida, Oren Zauda
# Iterator
this repository contain data structors with comlexity of o(1).

## range
range is structor with two parameters, start and end, which represent
the starting point and the end point of the structor. 
for instance: range (3,6) means 3 4 5

## chain
chain is structor with two ranges or strings. its goal is to chain two parts into one.
for instance: chain(range(1,3),string("ah")) means 12ah

## zip
zip is constructor with two parameters, ranges or string. its goal is to zip
the two parts into one. for instance: zip(range(1,3),string("ah")) means
1a 2h

## product
product is structor which make cartesian product of two parts.
for instance: product(range(1,3),string("ah")) means 1,a 1,h 2,a 2,h

## powerset
represent all sub groups of container-like

## Run example in bash :
  ### for demo run:
  
    make demo && ./demo
     
  ### for test run:
     
     make test && ./test
## our mentor
[Erel Segal-Halevi](https://github.com/erelsgl/ariel-cpp-5779)
