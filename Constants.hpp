#pragma once

namespace Constants {
    constexpr int MAX_PLAYERS = 4;
    constexpr double PI = 3.14159265359;
}

/// @brief Constants for use with std::out or other console print functions.
namespace Console {
    // Red console color
    constexpr char* C_RED    = "\033[31m";
    // Blue console color
    constexpr char* C_BLUE   = "\033[34m";
    // Reset console color
    constexpr char* C_RESET  = "\033[0m";
    // Green console color
    constexpr char* C_GREEN  = "\033[32m";
    // Yellow console color
    constexpr char* C_YELLOW = "\033[33m";
}