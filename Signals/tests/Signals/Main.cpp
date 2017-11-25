#define  CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <Signal.hpp>
#include <TestingStructs.hpp>
TEST_CASE("FreeFunction Signal"){
	Ktb::Tools::Signal<> sig;
    auto conn=sig.connect(addOne);
	for(int i=1;i<=4;++i){
        sig();
        REQUIRE(externValue == i);
    }
}

TEST_CASE("No param static function"){
    Ktb::Tools::Signal<> sig;
    auto conn = sig.connect(&StaticStruct::addOne);
    REQUIRE(StaticStruct::value == 0);
    for(int i=1; i<=4; ++i){
        sig();
        REQUIRE(StaticStruct::value == i);
    }
}

TEST_CASE("Param static function"){
    Ktb::Testing::StaticStruct::value = 0;
    Ktb::Tools::Signal<int> sig;
    auto conn = sig.connect(&StaticStruct::add);
    int total{0};
    for(int i = 1; i<=4; ++i){
        total+=i;
        sig(i);
        REQUIRE(StaticStruct::value == total);
    }
}
TEST_CASE("No param lamda"){
	Ktb::Tools::Signal<> sig;
	int value{0};
    auto conn = sig.connect([&](){++value;});
    for(int i = 1; i<=4; ++i){
        sig();
        REQUIRE(value == i);
    }
}
TEST_CASE("Param lambda"){
    Ktb::Tools::Signal<int> sig;
    int value{0};
    auto conn = sig.connect([&](int i){value+=i;});
    int total{0};
    for(int i = 1; i<=4; ++i){
        total+=i;
        sig(i);
        REQUIRE(value == total);
    }
}
TEST_CASE("Member function no param"){
    Ktb::Testing::NoStatic s;
    Signals::Signal<> sig;
    auto conn = sig.connect([&](){s.addOne();});
    for(int i = 1; i<=4; ++i){
        sig();
        REQUIRE(s.value == i);
    }
}
TEST_CASE("Member function param"){

    Ktb::Testing::NoStatic s;
    Ktb::Tools::Signal<int> sig;
    auto conn = sig.connect([&](int i){s.add(i);});
    int total=0;
    for(int i = 1; i<=4; ++i){
        sig(i);
        total+=i;
        REQUIRE(s.value == total);
    }
}
