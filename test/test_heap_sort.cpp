#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/HeapSortList.h"

TEST_CASE("Ordenação de numeros inteiros") {
    HeapSortList<int, 9> ordered_list({1, 2, 3, 5, 6, 7});
    HeapSortList<int, 9> list({1, 2, 7, 5, 6, 3});
    list.sort();
    REQUIRE(ordered_list == list);
}