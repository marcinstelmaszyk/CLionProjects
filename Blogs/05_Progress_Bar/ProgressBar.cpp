#include "ProgressBar.h"

void ProgressBar::set_progress(float value){
    std::unique_lock lock{mutex};
    progress = value;
}

void ProgressBar::set_bar_width(size_t width) {
    std::unique_lock lock{mutex};
    bar_width = width;
}
