
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>

namespace impl {
    class Console {
    public:

    protected:

    };
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
        Loader();

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

    impl::Console console;
    

    return 0;
}
/////////////////////////////////////////////
/////////////////////////////////////////////
