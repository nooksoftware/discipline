
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>


namespace impl {
    struct color {
        std::string reset = "\033[0m";
        std::string normal_black = "\033[0;30m";
        std::string bold_black = "\033[1;30m";
        std::string italic_black = "\033[3;30m";
        std::string bold_italic_black = "\033[1;3;30m";

        std::string normal_red = "\033[0;31m";
        std::string bold_red = "\033[1;31m";
        std::string italic_red = "\033[3;31m";
        std::string bold_italic_red = "\033[1;3;31m";

        std::string normal_green = "\033[0;32m";
        std::string bold_green = "\033[1;32m";
        std::string italic_green = "\033[3;32m";
        std::string bold_italic_green = "\033[1;3;32m";

        std::string normal_yellow = "\033[0;33m";
        std::string bold_yellow = "\033[1;33m";
        std::string italic_yellow = "\033[3;33m";
        std::string bold_italic_yellow = "\033[1;3;33m";

        std::string normal_blue = "\033[0;34m";
        std::string bold_blue = "\033[1;34m";
        std::string italic_blue = "\033[3;34m";
        std::string bold_italic_blue = "\033[1;3;34m";

        std::string normal_magenta = "\033[0;35m";
        std::string bold_magenta = "\033[1;35m";
        std::string italic_magenta = "\033[3;35m";
        std::string bold_italic_magenta = "\033[1;3;35m";

        std::string normal_cyan = "\033[0;36m";
        std::string bold_cyan = "\033[1;36m";
        std::string italic_cyan = "\033[3;36m";
        std::string bold_italic_cyan = "\033[1;3;36m";

        std::string normal_white = "\033[0;37m";
        std::string bold_white = "\033[1;37m";
        std::string italic_white = "\033[3;37m";
        std::string bold_italic_white = "\033[1;3;37m";
    };
    enum Color {
        RESET = 0,

        NORMAL_BLACK,
        BOLD_BLACK,
        ITALIC_BLACK,
        BOLD_ITALIC_BLACK,

        NORMAL_RED,
        BOLD_RED,
        ITALIC_RED,
        BOLD_ITALIC_RED,

        NORMAL_GREEN,
        BOLD_GREEN,
        ITALIC_GREEN,
        BOLD_ITALIC_GREEN,

        NORMAL_YELLOW,
        BOLD_YELLOW,
        ITALIC_YELLOW,
        BOLD_ITALIC_YELLOW,

        NORMAL_BLUE,
        BOLD_BLUE,
        ITALIC_BLUE,
        BOLD_ITALIC_BLUE,

        NORMAL_MAGENTA,
        BOLD_MAGENTA,
        ITALIC_MAGENTA,
        BOLD_ITALIC_MAGENTA,

        NORMAL_CYAN,
        BOLD_CYAN,
        ITALIC_CYAN,
        BOLD_ITALIC_CYAN,

        NORMAL_WHITE,
        BOLD_WHITE,
        ITALIC_WHITE,
        BOLD_ITALIC_WHITE
    };
    inline std::string colorString(const Color& color) {
        std::string s = "";
        if (color == RESET) {
            s = "\033[0m";
        } else if (color == NORMAL_BLACK) {
            s = "\033[0;30m";
        } else if (color == BOLD_BLACK) {
            s = "\033[1;30m";
        } else if (color == ITALIC_BLACK) {
            s = "\033[3;30m";
        } else if (color == BOLD_ITALIC_BLACK) {
            s = "\033[1;3;30m";
        } else if (color == NORMAL_RED) {
            s = "\033[0;31m";
        } else if (color == BOLD_RED) {
            s = "\033[1;31m";
        } else if (color == ITALIC_RED) {
            s = "\033[3;31m";
        } else if (color == BOLD_ITALIC_RED) {
            s = "\033[1;3;31m";
        } else if (color == NORMAL_GREEN) {
            s = "\033[0;32m";
        } else if (color == BOLD_GREEN) {
            s = "\033[1;32m";
        } else if (color == ITALIC_GREEN) {
            s = "\033[3;32m";
        } else if (color == BOLD_ITALIC_GREEN) {
            s = "\033[1;3;32m";
        } else if (color == NORMAL_YELLOW) {
            s = "\033[0;33m";
        } else if (color == BOLD_YELLOW) {
            s = "\033[1;33m";
        } else if (color == ITALIC_YELLOW) {
            s = "\033[3;33m";
        } else if (color == BOLD_ITALIC_YELLOW) {
            s = "\033[1;3;33m";
        } else if (color == NORMAL_BLUE) {
            s = "\033[0;34m";
        } else if (color == BOLD_BLUE) {
            s = "\033[1;34m";
        } else if (color == ITALIC_BLUE) {
            s = "\033[3;34m";
        } else if (color == BOLD_ITALIC_BLUE) {
            s = "\033[1;3;34m";
        } else if (color == NORMAL_MAGENTA) {
            s = "\033[0;35m";
        } else if (color == BOLD_MAGENTA) {
            s = "\033[1;35m";
        } else if (color == ITALIC_MAGENTA) {
            s = "\033[3;35m";
        } else if (color == BOLD_ITALIC_MAGENTA) {
            s = "\033[1;3;35m";
        } else if (color == NORMAL_CYAN) {
            s = "\033[0;36m";
        } else if (color == BOLD_CYAN) {
            s = "\033[1;36m";
        } else if (color == ITALIC_CYAN) {
            s = "\033[3;36m";
        } else if (color == BOLD_ITALIC_CYAN) {
            s = "\033[1;3;36m";
        } else if (color == NORMAL_WHITE) {
            s = "\033[0;37m";
        } else if (color == BOLD_WHITE) {
            s = "\033[1;37m";
        } else if (color == ITALIC_WHITE) {
            s = "\033[3;37m";
        } else if (color == BOLD_ITALIC_WHITE) {
            s = "\033[1;3;37m";
        }
        return s;
    }
    class Item {
    public:
        Item() = delete;
        Item(const std::string& id) : id(id) {}

        void SetId(const std::string& id) {
            this->id = id;
        }
        inline const std::string& GetID() const {
            return id;
        }
    protected:
        std::string id;
    };
    class Data {
    public:
        typedef std::map<int, Item> _Items;

        Data() {
            Initialize();
        }
        //void LoadItems();
        inline const _Items& GetItems() const {
            return items;
        }
        inline _Items& GetItems() {
            return items;
        }
    protected:
        void Initialize() {

        }

        _Items items;
    } data;

    struct Info {
        std::string custom_configuration_file;
        bool default_configuration_file = true;
    };
    class CMDArguments {
    public:
        CMDArguments(int argc, char* argv[]) {
            Process(argc, argv);
        }
    protected:
        void Process(int argc, char* argv[]) {

        }

    };
    class Loader {
    public:
        Loader() {}

        const Info& InitializeLoaderFromCMDArguments(const CMDArguments& args) {

            return info;
        }
        void LoadDefaultConfigurationFile() {

        }
        void LoadConfigurationFile(const std::string& config_file) {

        }
    protected:
        Info info;
    } loader;
}
/////////////////////////////////////////////
using namespace std;
/////////////////////////////////////////////
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

inline void ColorTest() {
    cout << endl << endl;
    cout << normalDefault() << "normalDefault()" << endl;
    cout << boldDefault() << "boldDefault()" << endl;
    cout << italicDefault() << "italicDefault()" << endl;
    cout << boldItalicDefault() << "boldItalicDefault()" << endl;
    cout << normalBlack() << "normalBlack()" << endl;
    cout << boldBlack() << "boldBlack()" << endl;
    cout << italicBlack() << "italicBlack()" << endl;
    cout << boldItalicBlack() << "boldItalicBlack()" << endl;
    cout << normalRed() << "normalRed()" << endl;
    cout << boldRed() << "boldRed()" << endl;
    cout << italicRed() << "italicRed()" << endl;
    cout << boldItalicRed() << "boldItalicRed()" << endl;
    cout << normalGreen() << "normalGreen()" << endl;
    cout << boldGreen() << "boldGreen()" << endl;
    cout << italicGreen() << "italicGreen()" << endl;
    cout << boldItalicGreen() << "boldItalicGreen()" << endl;
    cout << normalYellow() << "normalYellow()" << endl;
    cout << boldYellow() << "boldYellow()" << endl;
    cout << italicYellow() << "italicYellow()" << endl;
    cout << boldItalicYellow() << "boldItalicYellow()" << endl;
    cout << normalBlue() << "normalBlue()" << endl;
    cout << boldBlue() << "boldBlue()" << endl;
    cout << italicBlue() << "italicBlue()" << endl;
    cout << boldItalicBlue() << "boldItalicBlue()" << endl;
    cout << normalMagenta() << "normalMagenta()" << endl;
    cout << boldMagenta() << "boldMagenta()" << endl;
    cout << italicMagenta() << "italicMagenta()" << endl;
    cout << boldItalicMagenta() << "boldItalicMagenta()" << endl;
    cout << normalCyan() << "normalCyan()" << endl;
    cout << boldCyan() << "boldCyan()" << endl;
    cout << italicCyan() << "italicCyan()" << endl;
    cout << boldItalicCyan() << "boldItalicCyan()" << endl;
    cout << normalWhite() << "normalWhite()" << endl;
    cout << boldWhite() << "boldWhite()" << endl;
    cout << italicWhite() << "italicWhite()" << endl;
    cout << boldItalicWhite() << "boldItalicWhite()" << endl;
}
/////////////////////////////////////////////
int main(int argc, char* argv[]) {
    //Process command arguments
    
    impl::CMDArguments args(argc, argv);
    const impl::Info& info = impl::loader.InitializeLoaderFromCMDArguments(args);

    if (info.default_configuration_file) {
        impl::loader.LoadDefaultConfigurationFile();
    } else {
        impl::loader.LoadConfigurationFile(info.custom_configuration_file);
    }

    cout << normalDefault() << "Discipline Program \n";
    cout << "Build " << boldDefault() << "0001" << normalDefault() << ", by " << boldDefault() << "Dawid Jakubowski";
    cout << colorReset() << std::endl;
    cout << "---------------------------------------\n";


    return 0;
}
/////////////////////////////////////////////
/////////////////////////////////////////////
