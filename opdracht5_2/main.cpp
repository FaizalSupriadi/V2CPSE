#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "cluster.hpp"

TEST_CASE( "Add values from 1 - 6 with type int "){
   auto a = cluster<int, 6>();

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

TEST_CASE( "Try adding excisting value in array" ){
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