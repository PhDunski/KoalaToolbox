#define  CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <Signal.hpp>
#include <TestingStructs.hpp>
TEST_CASE("Multiple static functions No param"){
     Ktb::Tools::Signal<> sig;
    auto conn1 = sig.connect(&Ktb::Testing::StaticStruct::addOne);
    auto conn2 = sig.connect(&Ktb::Testing::StaticStruct::removeOne);
    REQUIRE(StaticStruct::value == 0);
    for(int i=1; i<=4; ++i){
        sig();
        REQUIRE(StaticStruct::value == 0);
    }

}

TEST_CASE("Multiple Static functions param"){
     Ktb::Tools::Signal<int> sig;
    auto conn1 = sig.connect(&Ktb::Testing::StaticStruct::add);
    auto conn2 = sig.connect(&Ktb::Testing::StaticStruct::remove);
    REQUIRE(StaticStruct::value == 0);
    for(int i=1; i<=4; ++i){
        sig(i);
        REQUIRE(StaticStruct::value == 0);
    }
}
TEST_CASE("Multiple member functions no param"){
    Ktb::Testing::NoStatic s;
    Ktb::Tools::Signal<> sig;
    auto conn1 = sig.connect([&](){s.addOne();});
    auto conn2 = sig.connect([&](){s.removeOne();});
    for(int i = 1; i<=4; ++i){
        sig();
        REQUIRE(s.value == 0);
    }
}
TEST_CASE("Multiple member functions param"){
NoStatic s;
    Ktb::Tools::Signal<int> sig;
    auto conn1 = sig.connect([&](int i){s.add(i);});
    auto conn2 = sig.connect([&](int i){s.remove(i);});
    for(int i = 1; i<=4; ++i){
        sig(i);
        REQUIRE(s.value == 0);
    }
}
TEST_CASE("Multiple free functions no param"){
     Ktb::Tools::Signal<> sig;
     auto conn1=sig.connect(&addOne);
     auto conn2=sig.connect(&removeOne);
    for(int i = 1; i<=4; ++i){
        sig();
        REQUIRE(externValue== 0);
    }
}

TEST_CASE("Multiple free functions param"){
     Ktb::Tools::Signal<int> sig;
     auto conn1=sig.connect(&addValue);
     auto conn2=sig.connect(&removeValue);
    for(int i = 1; i<=4; ++i){
        sig(i);
        REQUIRE(externValue== 0);
    }
}
TEST_CASE("Slot combinaison 1"){
     Ktb::Tools::Signal<> sig;
     Ktb::Testing::StaticStruct::value = 0;
     Ktb::Testing::externValue = 0;
     NoStatic s;
     auto conn1 = sig.connect(&Ktb::Testing::StaticStruct::addOne);
     auto conn2 = sig.connect([&](){s.addOne();});
     auto conn3 = sig.connect(&addOne);
     for(int i = 1; i<=4;++i){
        sig();
        REQUIRE(externValue == i);
        REQUIRE(StaticStruct::value == i);
        REQUIRE(s.value == i);
     }
}

TEST_CASE("Slot combinaison 2"){
     Ktb::Tools::Signal<int> sig;
     Ktb::Testing::StaticStruct::value = 0;
     externValue = 0;
     NoStatic s;
     auto conn1 = sig.connect(Ktb::Testing::StaticStruct::add);
     auto conn2 = sig.connect([&](int i){s.add(i);});
     auto conn3 = sig.connect(addValue);
     int total{0};
     for(int i = 1; i<=4;++i){
        total+= i;
        sig(i);
        REQUIRE(externValue == total);
        REQUIRE(StaticStruct::value == total);
        REQUIRE(s.value == total);
     }

}
