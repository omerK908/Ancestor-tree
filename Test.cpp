#include "doctest.h"
#include "FamilyTree.hpp"

TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}

TEST_CASE("find case test") {

	/*string find(string relation);*/
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.find("me") == "Yosef" );
	CHECK( T.find("father") == "Yaakov" );
	CHECK( T.find("mother") == "Rachel" );
	// CHECK( (T.find("grandfather") == "Isaac") || (T.relation("grandfather") == "saba") );
	// CHECK( (T.relation("grandmother") == "Rivka") || (T.relation("grandmother") == "safta") );
	CHECK( T.find("great-grandfather") == "Avraham" );
	CHECK( T.find("great-great-grandfather") == "Terah" );
}

TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}TEST_CASE("relation case test") {
	family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")

	 .addFather("Rivka", "saba")
	 .addMother("Rivka", "safta")

	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK( T.relation("Yosef") == "me" );
	CHECK( T.relation("Yaakov") == "father" );
	CHECK( T.relation("Rachel") == "mother" );
	CHECK( T.relation("Isaac") == "grandfather" );
	CHECK( T.relation("Rivka") == "grandmother" );
	CHECK( T.relation("saba") == "grandfather" );
	CHECK( T.relation("safta") == "grandmother" );
	CHECK( T.relation("Avraham") == "great-grandfather" );
	CHECK( T.relation("Terah") == "great-great-grandfather" );
}