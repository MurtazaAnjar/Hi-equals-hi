#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/strcmp.hpp"

TEST_CASE( "it works" ) {
    REQUIRE( strcmp("String one","String one") == 0);
    REQUIRE( strcmp("String one","String two") == -1);
    REQUIRE( strcmp("String two","String one") == 1);

    REQUIRE( strcmp_case_insensitive("String one","string two") == -1);
    REQUIRE( strcmp_case_insensitive("String one","string one") == 0);
    REQUIRE( strcmp_case_insensitive("String two","string one") == 1);

    REQUIRE( strcmp_case_insensitive("my cool string","mycoolstring", true) == 0);
    REQUIRE( strcmp_case_insensitive("My Cool String","MyCoolString", true) == 0);
    REQUIRE( strcmp_case_insensitive("My Cool String","mycoolstring", true) == 0);
    REQUIRE( strcmp_case_insensitive("My Cool String ","mycoolstring", true) == 0);
    REQUIRE( strcmp_case_insensitive(" My Cool String","mycoolstring", true) == 0);
    REQUIRE( strcmp_case_insensitive("Another string","mycoolstring", true) == -1);

    REQUIRE( strcmp_case_insensitive("ABCDEF","abczEF", false, 3) == 0);
    REQUIRE( strcmp_case_insensitive("ABCDEF","abczEF", false, 4) == -1);
    REQUIRE( strcmp_case_insensitive("ABCDEF","abczEF", false, 5) == -1);
    REQUIRE( strcmp_case_insensitive("Short","Shorter", false, 6) == 0);
    REQUIRE( strcmp_case_insensitive("abc","efg", false, 0) == 0);
    REQUIRE( strcmp_case_insensitive("abc","abd", false, -5) == -1);
    REQUIRE( strcmp_case_insensitive("abc","abd", false, 0) == 0);
    REQUIRE( strcmp_case_insensitive("A B C","abcde", false, 2) == -1);
    REQUIRE( strcmp_case_insensitive("A B C","abcde", true, 2) == 0);

    REQUIRE( strcmp_case_insensitive("2","50") == -1);
    REQUIRE( strcmp_case_insensitive("2","10") == -1);
    REQUIRE( strcmp_case_insensitive("20","5") == 1);
    REQUIRE( strcmp_case_insensitive("20","1") == 1);
    REQUIRE( strcmp_case_insensitive("100","100") == 0);
    REQUIRE( strcmp_case_insensitive("2 Some String","50 Some String") == -1);
    REQUIRE( strcmp_case_insensitive("2 Some String","10 Some String") == -1);
    REQUIRE( strcmp_case_insensitive("20 Some String","5 Some String") == 1);
    REQUIRE( strcmp_case_insensitive("20 Some String","1 Some String") == 1);
    REQUIRE( strcmp_case_insensitive("100 Some String","100 Some String") == 0);
}
