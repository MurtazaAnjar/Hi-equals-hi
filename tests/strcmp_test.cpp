#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/strcmp.hpp"

TEST_CASE( "it works" ) {
    REQUIRE( strcmp("String one","String one") == 0);
    REQUIRE( strcmp("String one","String two") == -1);
    REQUIRE( strcmp("String two","String one") == 1);
    REQUIRE( strcmp_case_insensitive("String one","string one") == 0);
    REQUIRE( strcmp_case_insensitive("String one","string two") == -1);
    REQUIRE( strcmp_case_insensitive("String two","string one") == 1);
}
