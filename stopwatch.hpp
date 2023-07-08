// Design inspired by the stopwatch class here 
// https://github.com/ManWithABike/Stopwatch

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>
#include <cstdint>

class Stopwatch {
 private:
    std::chrono::time_point<std::chrono::steady_clock> startTime {};
 public:
    Stopwatch() : startTime {std::chrono::steady_clock::now()} {}

    void start() {
        startTime = std::chrono::steady_clock::now();
    }

    template <typename unit = std::chrono::milliseconds>
    int64_t elapsed() const {
        std::chrono::time_point endTime = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<unit>
                            (endTime - startTime).count();
    }

    using nanoseconds = std::chrono::nanoseconds;
    using microseconds = std::chrono::microseconds;
    using milliseconds = std::chrono::milliseconds;
    using seconds = std::chrono::seconds;
};

#endif      // STOPWATCH_HPP
