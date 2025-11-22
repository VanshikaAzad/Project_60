#ifndef PROJECT_60_FUNCTION_H
#define PROJECT_60_FUNCTION_H

// function.h
// Utility function declarations and small constexpr algorithms
// Suitable for inclusion in small projects or demos.
//
// Note: Header-only implementations where reasonable.

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <functional>
#include <limits>

namespace project60 {

// Constrain to integral types
template <typename T>
using EnableIfIntegral = std::enable_if_t<std::is_integral_v<T>, T>;

// Compute gcd using Euclid's algorithm (handles zeros)
template <typename T>
constexpr EnableIfIntegral<T> gcd(EnableIfIntegral<T> a, EnableIfIntegral<T> b) noexcept {
    if (a < 0) a = static_cast<T>(-a);
    if (b < 0) b = static_cast<T>(-b);
    while (b != 0) {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Compute lcm; returns 0 if either argument is zero
template <typename T>
constexpr EnableIfIntegral<T> lcm(EnableIfIntegral<T> a, EnableIfIntegral<T> b) noexcept {
    if (a == 0 || b == 0) return static_cast<T>(0);
    T g = gcd(a, b);
    // Avoid overflow by dividing first
    return (a / g) * b;
}

// constexpr factorial for small positive integers (0! = 1)
template <typename T>
constexpr std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, std::uint64_t>
factorial(T n) {
    if (n <= 1) return 1;
    std::uint64_t result = 1;
    for (T i = 2; i <= n; ++i) result *= static_cast<std::uint64_t>(i);
    return result;
}

// Fast integer power: base^exp (exp must be non-negative)
template <typename T>
constexpr T ipow(T base, std::size_t exp) {
    static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "ipow requires numeric type");
    T result = static_cast<T>(1);
    while (exp) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

// Simple primality check (trial division). Not optimized for very large numbers.
template <typename T>
constexpr bool is_prime(T n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (T d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

// Clamp helper (C++17-compatible)
template <typename T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi) {
    return (v < lo) ? lo : (hi < v) ? hi : v;
}

// Apply a callable to each element of an array-like container (small convenience wrapper)
template <typename Container, typename Func>
inline void for_each(Container& c, Func&& f) {
    for (auto& elem : c) f(elem);
}

// Convert sign of integral value to -1, 0, 1
template <typename T>
constexpr int sign(EnableIfIntegral<T> value) noexcept {
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

} // namespace project60

#endif // PROJECT_60_FUNCTION_H