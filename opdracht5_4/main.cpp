#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "cluster.hpp"

TEST_CASE( "Add values 1 to 10" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   std::stringstream s;
   s << a;
   REQUIRE( s.str() == "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, " );    
}

TEST_CASE( "Add values from 1 - 6 with type double "){
   auto a = cluster<double, 6>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   std::stringstream s;
   s << a;
   REQUIRE( s.str() == "1, 2, 3, 4, 5, 6, " );    
}
TEST_CASE( "Add values from 1 - 6 with type float "){
   auto a = cluster<float, 6>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   std::stringstream s;
   s << a;
   REQUIRE( s.str() == "1, 2, 3, 4, 5, 6, " );    
}

TEST_CASE( "Try adding existing value in array" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 6; ++i){
      a.add(i);
   }

   a.add(5);

   std::stringstream s;
   s << a;

   REQUIRE( s.str() == "1, 2, 3, 4, 5, 0, 0, 0, 0, 0, " );
}

TEST_CASE( "Make array fuller than it is" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   a.add(11);

   std::stringstream s;
   s << a;

   REQUIRE( s.str() == "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, " );
}

TEST_CASE( "Delete a value" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   a.remove(5);

   std::stringstream s;
   s << a;
   REQUIRE( s.str() == "1, 2, 3, 4, 6, 7, 8, 9, 10, 0, " );  
}

TEST_CASE( "Delete a value that is not in the array" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 7; ++i){
      a.add(i);
   }

   a.remove(8);

   std::stringstream s;
   s << a;
   REQUIRE( s.str() == "1, 2, 3, 4, 5, 6, 0, 0, 0, 0, " );  
}

TEST_CASE( "Check if a value is in the array" ){
   auto a = cluster<int, 10>();

   for (int i = 1; i < 11; ++i){
      a.add(i);
   }

   bool b = a.contains(4);


   REQUIRE(b == 1);
}

TEST_CASE( "Check if a char value is in the array" ){
   auto a = cluster<char, 14>();

   for (int i = 70; i < 85; ++i){
      a.add(char(i));
   }

   bool b = a.contains('G');


   REQUIRE(b == 1);
}

TEST_CASE( "Check for the biggest value in the array" ){
   auto a = cluster<int, 10>();

   a.add(23);
   a.add(54);
   a.add(20);
   a.add(29);
   a.add(3);
   a.add(1);
   a.add(47);
   a.add(2);
   a.add(1);
   a.add(32);

   int b = a.maximum();


   REQUIRE(b == 54);
}

TEST_CASE( "Check for the biggest char in the array" ){
   auto a = cluster<char, 3>();

   a.add('q');
   a.add('c');
   a.add('p');

   int b = a.maximum();


   REQUIRE(b == 'q');
}

TEST_CASE( "Check for the biggest char array in the array" ){
   auto a = cluster<std::array<char, 3>, 3>();

   a.add({'a', 'b', 'c'});
   a.add({'h', 'h', 'h'});
   a.add({'s', 'a', 'd'});
   a.add({'z', 'z', 'z'});
   a.remove({'z', 'z', 'z'});

   std::stringstream s;
   for(const auto & element : a.maximum()){
      s << element;
   }
   REQUIRE( s.str() == "sad" ); 
}