#pragma once

#include <atomic>
#include <mutex>
#include <iostream>

class ProgressBar {
public:
    void set_progress(float value);
    void set_bar_width(size_t width);
private:
    std::mutex mutex;
    float progress{0.0f};
    size_t bar_width{60};
    std::string fill{"#"}, remainder{" "}, status_text{""};
};