#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

template<typename T, typename C>
T get_lust_iterator(C& container, T& lust_it)
{
    for (int j = 1; j < container.size(); ++j)
        ++lust_it;

    return lust_it;
}