//AmirHoshen
#include "doctest.h"
#include "FamilyTree.hpp"

TEST_CASE("relation case test") {
    family::Tree T ("Yosef");
    T.addFather("Yosef", "Yaakov")
            .addMother("Yosef", "Rachel")
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah")
            .addMother("Rivka", "Sisra");

    
    CHECK( T.relation("Yosef") == "me" );
    CHECK( T.relation("Yaakov") == "father" );
    CHECK( T.relation("Rachel") == "mother" );
    CHECK( T.relation("Isaac") == "grandfather" );
    CHECK( T.relation("Rivka") == "grandmother" );
    CHECK( T.relation("Sisra") == "great-grandmother");
    CHECK( T.relation("Terah") == "great-great-grandfather");
    CHECK( T.find("great-great-grandfather") == "Terah"); //should be Terah.
    CHECK( T.find("father") == "Yaakov"); //should be Yaakov.
    CHECK( T.find("great-great-grandfather") == "Terah");
    CHECK( T.find("grandmother") == "Rivka");
    CHECK( T.find("grandfather") == "Isaac");
    CHECK( T.find("mother") == "Rachel");
    CHECK( T.find("father") == "Yaakov");
    CHECK_THROWS( T.find(" ") == "");

    T.remove("Avraham");
    //Avraham and Terah should be deleted from tree

    CHECK( T.relation("Avraham") == "unrelated");

    T.addMother("Isaac", "Mali");
    T.addMother("Mali", "Hagar");
    T.addFather("Mali", "Ben");

    CHECK( T.relation("Ben") == "great-great-grandfather");
    CHECK( T.relation("Hagar") == "great-great-grandmother");
    CHECK( T.relation("Mali") == "great-grandmother");
    CHECK( T.find("great-great-grandfather") == "Ben");
    CHECK( T.find("great-great-grandmother") == "Hagar");
    CHECK( T.find("great-grandmother") == "Mali");
    CHECK( T.find("grandmother") == "Rivka");
    CHECK( T.find("grandfather") == "Isaac");
    CHECK( T.find("father") == "Yaakov");
    CHECK( T.find("mother") == "Rachel");

    T.remove("Rivka"); //both Rivka and Sisra removed from the tree.
    CHECK( T.find("grandmother") == "unrelated");//might be problematic, need to define case.

    //adding tree grandparents great grandparents etc.
    T.addMother("Yaakov", "Gan");
    T.addMother("Rachel", "Hodaya");
    T.addFather("Rachel", "Din");

    CHECK( T.find("grandfather") == "Isaac");//should be also equal to Din.
    CHECK( T.find("grandfather") == "Din");
    CHECK( T.find("grandmother") == "Gan");//should be also equal to Hodaya.
    CHECK( T.find("grandmother") == "Hodaya");
    CHECK( T.relation("Mali") == "great-grandmother");
    CHECK( T.relation("Hodaya") == "grandmother");
    CHECK_THROWS( T.addFather("Yosef", "Baroch"));//Yosef already have a father exception expected.
    CHECK_THROWS( T.addMother("Yosef", "Kim")); //Yosef already have a mother exception expected.

    //adding tree grandparents great grandparents etc.
    T.addMother("Din", "Gila");
    T.addFather("Din", "Dor");
    T.remove("Mali");//Mali Hagar and Ben removed from the tree.
    T.addFather("Dor", "Gil");

    CHECK( T.find("great-grandfather") == "Dor");
    CHECK( T.find("great-grandmother") == "Gila");
    CHECK_THROWS( T.find("great-great-grandmother"));//theres no great great grandmother in this tree.

    //removing left subtree.
    T.remove("Yaakov");//Yaakov Isaac and Gan removed from the tree.
    //Yosef(root) have no father.

    CHECK_THROWS( T.find("father") == "unrelated");

    //adding tree grandparents great grandparents etc.
    T.addFather("Gila", "Moshe");
    T.addMother("Dor", "Rina");
    T.addMother("Gila", "Almagor");
    T.addFather("Moshe", "Ham");

    CHECK( T.relation("Rachel") == "mother");
    CHECK( T.relation("Din") == "grandfather");
    CHECK( T.relation("Hodaya") == "grandmother");
    CHECK( T.relation("Dor") == "great-grandfather");
    CHECK( T.relation("Gila") == "great-grandmother");
    CHECK( T.relation("Gil") == "great-great-grandfather");
    CHECK( T.relation("Rina") == "great-great-grandmother");
    CHECK( T.relation("Moshe") == "great-great-grandfather");
    CHECK( T.relation("Almagor") == "great-great-grandmother");
    CHECK( T.relation("Ham") == "great-great-great-grandfather");
    CHECK( T.find("great-great-great-grandfather") == "Ham");
    CHECK_THROWS( T.find("great-great-great-grandmother") == "unrelated");

    CHECK( T.find("mother") == "Rachel");
    CHECK( T.find("grandfather") == "Din");
    CHECK( T.find("grandmother") == "Hodaya");
    CHECK( T.find("great-grandfather") == "Dor");
    CHECK( T.find("great-grandmother") == "Gila");
    CHECK( T.find("great-great-grandfather") == "Gil");
    CHECK( T.find("great-great-grandmother") == "Rina");
    CHECK( T.find("great-great-grandfather") == "Moshe");
    CHECK( T.find("great-great-grandmother") == "Almagor");
    CHECK( T.find("great-great-great-grandfather") == "Ham");
    CHECK_THROWS( T.find("great-great-great-grandmother") == "unrelated");//should throw an exception.
    CHECK_THROWS ( T.find("great-great-great-great-grandfather") == "unrelated");//should throw an exception.

    //adding tree grandparents great grandparents etc.
    T.addFather("Rina", "Bar");
    T.addMother("Bar", "Kim");
    T.addMother("Hodaya", "Melody");
    T.addFather("Hodaya", "Peter");
    T.addFather("Kim", "Ben");
    T.addFather("Peter", "Paul");

    CHECK( T.relation("Rachel") == "mother");
    CHECK( T.relation("Hodaya") == "grandmother");
    CHECK( T.relation("Din") == "grandfather");
    CHECK( T.relation("Dor") == "great-grandfather");
    CHECK( T.relation("Gila") == "great-grandmother");
    CHECK( T.relation("Peter") == "great-grandfather");
    CHECK( T.relation("Melody") == "great-grandmother");
    CHECK( T.relation("Paul") == "great-great-grandfather");
    CHECK( T.relation("Almagor") == "great-great-grandmother");
    CHECK( T.relation("Moshe") == "great-great-grandfather");
    CHECK( T.relation("Rina") == "great-great-grandmother");
    CHECK( T.relation("Gil") == "great-great-grandfather");
    CHECK( T.relation("Ham") == "great-great-great-grandfather");
    CHECK( T.relation("Bar") == "great-great-great-grandfather");
    CHECK( T.relation("Kim") == "great-great-great-great-grandmother");
    CHECK( T.relation("Ben") == "great-great-great-great-great-grandfather");
    CHECK( T.find("great-great-great-great-great-grandfather") == "Ben");
    CHECK_THROWS( T.find("great-great-great-great-great-grandmother") == "unrelated");
    CHECK( T.find("great-great-great-great-grandmother") == "Kim");
    CHECK( T.find("great-great-great-grandfather") == "Bar");
    CHECK( T.find("great-great-great-grandfather") == "Ham");
    CHECK( T.find("great-great-grandfather") == "Gil");
    CHECK( T.find("great-great-grandmother") == "Rina");
    CHECK( T.find("great-great-grandfather") == "Moshe");
    CHECK( T.find("great-great-grandmother") == "Almagor");
    CHECK( T.find("great-great-grandfather") == "Paul");
    CHECK( T.find("great-grandmother") == "Melody");
    CHECK( T.find("great-grandfather") == "Peter");
    CHECK( T.find("great-grandmother") == "Gila");
    CHECK( T.find("great-grandfather") == "Dor");
    CHECK( T.find("grandfather") == "Din");
    CHECK( T.find("grandmother") == "Hodaya");
    CHECK( T.find("mother") == "Rachel");


    CHECK( T.relation("Gan") == "unrelated");
    CHECK( T.relation("Yaakov") == "unrelated");
    CHECK( T.relation("Mali") == "unrelated");
    CHECK_THROWS( T.find(" ") == "unrelated");//expected exception right here.
    CHECK_THROWS( T.relation(" ") == "unrelated");//expected exception right here.

}
