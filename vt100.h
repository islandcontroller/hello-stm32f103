/*!****************************************************************************
 * @file
 * vt100.h
 *
 * @brief
 * VT100 Escape Sequences
 *
 * @date  13.10.2025
 ******************************************************************************/

#ifndef VT100_H_
#define VT100_H_

/*- Macros -------------------------------------------------------------------*/
// Clear terminal
#define VT100_ERASE_DISPLAY           "\e[2J"

// Reset graphical attributes
#define VT100_RESET_ATTRS             "\e[0m"

// Intensity
#define VT100_INTENSITY_BRIGHT        "\e[1m"
#define VT100_INTENSITY_DIM           "\e[2m"
#define VT100_INTENSITY_NORMAL        "\e[22m"

// Italic
#define VT100_ITALIC                  "\e[3m"
#define VT100_NO_ITALIC               "\e[23m"

// Underline
#define VT100_UNDERLINE               "\e[4m"
#define VT100_UNDERLINE_DOUBLE        "\e[21m"
#define VT100_NO_UNDERLINE            "\e[24m"

// Color inversion
#define VT100_INVERT                  "\e[7m"
#define VT100_NO_INVERT               "\e[27m"

// Strikethrough
#define VT100_STRIKETHROUGH           "\e[9m"
#define VT100_NO_STRIKETHROUGH        "\e[29m"

// FG/BG colours
#define VT100_FGCOL_BLACK             30
#define VT100_FGCOL_RED               31
#define VT100_FGCOL_GREEN             32
#define VT100_FGCOL_YELLOW            33
#define VT100_FGCOL_BLUE              34
#define VT100_FGCOL_MAGENTA           35
#define VT100_FGCOL_CYAN              36
#define VT100_FGCOL_WHITE             37
#define VT100_FGCOL_RESET             39
#define VT100_FGCOL_BRT_BLACK         90
#define VT100_FGCOL_BRT_RED           91
#define VT100_FGCOL_BRT_GREEN         92
#define VT100_FGCOL_BRT_YELLOW        93
#define VT100_FGCOL_BRT_BLUE          94
#define VT100_FGCOL_BRT_MAGENTA       95
#define VT100_FGCOL_BRT_CYAN          96
#define VT100_FGCOL_BRT_WHITE         97
#define VT100_BGCOL_BLACK             40
#define VT100_BGCOL_RED               41
#define VT100_BGCOL_GREEN             42
#define VT100_BGCOL_YELLOW            43
#define VT100_BGCOL_BLUE              44
#define VT100_BGCOL_MAGENTA           45
#define VT100_BGCOL_CYAN              46
#define VT100_BGCOL_WHITE             47
#define VT100_BGCOL_RESET             49
#define VT100_BGCOL_BRT_BLACK         100
#define VT100_BGCOL_BRT_RED           101
#define VT100_BGCOL_BRT_GREEN         102
#define VT100_BGCOL_BRT_YELLOW        103
#define VT100_BGCOL_BRT_BLUE          104
#define VT100_BGCOL_BRT_MAGENTA       105
#define VT100_BGCOL_BRT_CYAN          106
#define VT100_BGCOL_BRT_WHITE         107
#define VT100_SET_COLOR(col)          "\e[" __XSTRING(col) "m"

#endif // VT100_H_
