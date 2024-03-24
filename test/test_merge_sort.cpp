#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/MergeSortList.h"

TEST_CASE("Ordenação de numeros inteiros") {
    MergeSortList<int, 9> ordered_list({1, 2, 3, 5, 6, 7, 9});
    MergeSortList<int, 9> list({1, 2, 7, 5, 9, 6, 3});
    list.sort();
    REQUIRE(ordered_list == list);
}