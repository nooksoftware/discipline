
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>


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

namespace impl {
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
