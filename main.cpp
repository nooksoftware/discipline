
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <ncurses.h>

inline std::string normalDefault() {return  "\033[0m";}
inline std::string boldDefault() {return  "\033[1m";}
inline std::string italicDefault() {return  "\033[3m";}
inline std::string boldItalicDefault() {return "\033[1;3m";}
inline std::string colorReset() {return "\033[0m";}
inline std::string normalBlack() {return "\033[0;30m";}
inline std::string boldBlack() {return "\033[1;30m";}
inline std::string italicBlack() {return "\033[3;30m";}
inline std::string boldItalicBlack() {return "\033[1;3;30m";}
inline std::string normalRed() {return "\033[0;31m";}
inline std::string boldRed() {return "\033[1;31m";}
inline std::string italicRed() {return "\033[3;31m";}
inline std::string boldItalicRed() {return "\033[1;3;31m";}
inline std::string normalGreen() {return "\033[0;32m";}
inline std::string boldGreen() {return "\033[1;32m";}
inline std::string italicGreen() {return "\033[3;32m";}
inline std::string boldItalicGreen() {return "\033[1;3;32m";}
inline std::string normalYellow() {return "\033[0;33m";}
inline std::string boldYellow() {return "\033[1;33m";}
inline std::string italicYellow() {return "\033[3;33m";}
inline std::string boldItalicYellow() {return "\033[1;3;33m";}
inline std::string normalBlue() {return "\033[0;34m";}
inline std::string boldBlue() {return "\033[1;34m";}
inline std::string italicBlue() {return "\033[3;34m";}
inline std::string boldItalicBlue() {return "\033[1;3;34m";}
inline std::string normalMagenta() {return "\033[0;35m";}
inline std::string boldMagenta() {return "\033[1;35m";}
inline std::string italicMagenta() {return "\033[3;35m";}
inline std::string boldItalicMagenta() {return "\033[1;3;35m";}
inline std::string normalCyan() {return "\033[0;36m";}
inline std::string boldCyan() {return "\033[1;36m";}
inline std::string italicCyan() {return "\033[3;36m";}
inline std::string boldItalicCyan() {return "\033[1;3;36m";}
inline std::string normalWhite() {return "\033[0;37m";}
inline std::string boldWhite() {return "\033[1;37m";}
inline std::string italicWhite() {return "\033[3;37m";}
inline std::string boldItalicWhite() {return "\033[1;3;37m";}

/////////////////////////////////////
namespace globals {
    std::map<std::string, std::list<std::string>> _flagArgs;
    std::list<std::string> _args;
    char* _menuOptionsStr[3];
    bool _isRunning = false;
    int _rows = 3;
    int _selected = 0;
    bool _exitOnThisFrame = false;

    enum SelectedChoice {
        PROGRAM = 0,
        SETTINGS,
        MENU
    };
    SelectedChoice _selectedChoice = SelectedChoice::MENU;
};
/////////////////////////////////////
inline bool _hasFlag(const std::string& a) {
    return (
        globals::_flagArgs.find(a) != globals::_flagArgs.end()
        || globals::_flagArgs.find("-" + a) != globals::_flagArgs.end()
        || globals::_flagArgs.find("--" + a) != globals::_flagArgs.end()   
    );
}
/////////////////////////////////////
inline bool _isFlag(const std::string& a) {
    if (a.find("-") == std::string::npos || a.find("--") == std::string::npos) {
        return true;
    }
    return false;
}
/////////////////////////////////////
inline std::list<std::string> _flagArgs(int i, int argc, char* argv[]) {
    std::string flag_arg = argv[i];
    std::list<std::string> flagArgs;
    bool verify = _isFlag(flag_arg);
    if (verify) {
        bool end = false;
        for (int i2 = i; i2 < argc || end; ++i2) {
            std::string a = argv[i2];
            if (_isFlag(a)) {
                if (flag_arg.compare(a) == 0) {
                    //this is not the next flag
                } else {
                    end = true;
                }
            } else {
                flagArgs.emplace_back(a);
            }            
        }
    }
    return flagArgs;
}
/////////////////////////////////////
int _processArgs(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if (_isFlag(arg)) {
            std::list<std::string> args = _flagArgs(i, argc, argv);
            auto insert_pair = globals::_flagArgs.insert(
                std::make_pair(
                    arg,
                    args
                )
            );

        }
        globals::_args.emplace_back(arg);
    }
}

void _unitTests() {

}
void _initialize() {
    
    if (_hasFlag("ut")) {
        _unitTests();
    } else {
        globals::_menuOptionsStr[0] = (char*)"Program";
        globals::_menuOptionsStr[1] = (char*)"Settings";
        globals::_menuOptionsStr[2] = (char*)"Exit";
        
        initscr();
        start_color();
        keypad(stdscr, TRUE);
        noecho();
        refresh();
        init_pair(0, COLOR_BLACK, COLOR_BLUE);
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        globals::_isRunning = true;
    }
}
inline bool _isMenuRowSelected(int row) {
    if (globals::_selectedChoice == globals::SelectedChoice::MENU) {
        if (globals::_selected == row) return true;
        return false;
    }
    return false;
}
void _selectProgram() {
    globals::_selectedChoice = globals::SelectedChoice::PROGRAM;
}
void _selectSettings() {
    globals::_selectedChoice = globals::SelectedChoice::SETTINGS;
}
void _exit() {
    globals::_exitOnThisFrame = true;
}
inline void _select(int row) {
    if (row == 0) { //program
        _selectProgram();
    } else if (row == 1) { //settings 
        _selectSettings();
    } else if (row == 2) { //exit
        _exit();
    }
}
void _start() {
    while (globals::_isRunning) {
        for (int row = 0; row < globals::_rows; ++row) {
            if (_isMenuRowSelected(row)) {
                attron(COLOR_PAIR(1));
                mvprintw(row, 1, globals::_menuOptionsStr[row]);
                attroff(COLOR_PAIR(1));
            } else {
                attron(COLOR_PAIR(2));
                mvprintw(row, 1, globals::_menuOptionsStr[row]);
                attroff(COLOR_PAIR(2));
            }
        }
        char ch = getch();
        if (ch == 's') {
            globals::_selected++;
            if (globals::_selected == 3) globals::_selected = 0;
        } else if (ch == 'w') {
            globals::_selected--;
            if (globals::_selected == -1) globals::_selected = 2;
        } else if (ch == 10 || ch == 13) {
            _select(globals::_selected);
        }
        if (globals::_exitOnThisFrame) {
            globals::_isRunning = false;
        }
    }

}
void _release() {
    endwin();

}
/////////////////////////////////////
int main(int argc, char* argv[]) {
    _processArgs(argc, argv);

    _initialize();
    _start();
    _release();

    return 0;
}