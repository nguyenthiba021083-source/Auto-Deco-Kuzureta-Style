#pragma once

enum class ThemeType {
    Kuzureta,
    City,
    Crystal,
    Night
};

class ThemeSystem {
public:
    static ThemeType currentTheme;
};
