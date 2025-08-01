#pragma once

namespace C {
    struct State {
        virtual void on_enter() = 0;
        virtual void on_exit() = 0;

        virtual State* update() = 0;
        virtual void render() const = 0;
    };
}