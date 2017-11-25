#define  CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <Signal.hpp>
TEST_CASE("connection blocked"){
    Ktb::Tools::Signal<> sig;
    int value=0;
    auto conn =sig.connect([&](){++value;});
    sig();
    REQUIRE(value == 1);
    conn.block();
    sig();
    REQUIRE(value ==1);

}
TEST_CASE("Signal blocked"){
    Ktb::Tools::Signal<> sig;
    int value=0;
    auto conn =sig.connect([&](){++value;});
    sig();
    REQUIRE(value == 1);
    sig.block();
    sig();
    REQUIRE(value ==1);

}


TEST_CASE("connection unblocked"){
    Ktb::Tools::Signal<> sig;
    int value=0;
    auto conn =sig.connect([&](){++value;});
    sig();
    conn.block();
    sig();
    conn.unBlock();
    sig();
    REQUIRE(value ==2);

}
TEST_CASE("Signal unblocked"){
    Ktb::Tools::Signal<> sig;
    int value=0;
    auto conn =sig.connect([&](){++value;});
    sig();
    sig.block();
    sig();
	sig.unBlock();
    sig();
    REQUIRE(value ==2);

}
