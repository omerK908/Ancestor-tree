#include "doctest.h"
#include "FamilyTree.hpp"

TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rachel") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
	
}