#pragma once

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <fstream>
#include <utility>

namespace C {
namespace Log {
    inline std::ofstream log_file("log.txt");

    inline void init() {
        if (!log_file) {
            std::cerr << "FATAL :: unable to open log file: 'log.txt'" << std::endl;
            exit(1);
        }
    }

    inline void close() {
        log_file << "EOF";
        log_file.close();
    }

    // helper function for the main logging functions below
    template <typename ...Args>
    inline void _log(const char* prefix, const char* str, Args&&... args) {
        if constexpr (sizeof...(args) > 0) {
            log_file << prefix << std::vformat(str, std::make_format_args(args...)) << std::endl;
        } else {
            log_file << prefix << str << std::endl;
        }
        log_file.flush();
    }

    template <typename ...Args>
    inline void info(const char* str, Args&&... args) {
        _log("INFO :: ", str, std::forward<Args>(args)...);
    }

    template <typename ...Args>
    inline void debug(const char* str, Args&&... args) {
        _log("DEBUG :: ", str, std::forward<Args>(args)...);
    }

    template <typename ...Args>
    inline void waring(const char* str, Args&&... args) {
        _log("WARNING :: ", str, std::forward<Args>(args)...);
    }

    template <typename ...Args>
   inline void error(const char* str, Args&&... args) {
       _log("ERROR :: ", str, std::forward<Args>(args)...);
    }

    template <typename ...Args>
    [[noreturn]] inline void fatal(const char* str, Args&&... args) {
        _log("FATAL :: ", str, std::forward<Args>(args)...);
        log_file.close();
        exit(1);
    }
}
}