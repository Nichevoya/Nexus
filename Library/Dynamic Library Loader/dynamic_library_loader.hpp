#ifndef DYNAMIC_LIBRARY_LOADER_HPP_
#define DYNAMIC_LIBRARY_LOADER_HPP_

#include <dlfcn.h>
#include "ressource.hpp"

class static_library_loader {
    public:
        static_library_loader(const static_library_loader &) = delete;
        explicit static_library_loader();
        ~static_library_loader();

            //? Open Dynamic Library File (File.so)
            void *open_file(std::string const &);

            //? Load Opened File Into Memory & Access Its Entry Point
        template <typename T>
        T load_file(std::string const &entryPoint) const
        {
            return (T)dlsym(_handler, entryPoint.c_str()); //? entryPoint Represent The Needed Entry Point
        }

        //? Close Loaded File
        int close_file() const;

        //? Log Error From Last _handler Instance
        char *error_logs() const;

    protected:
    private:
        void *_handler = nullptr;
};

template <class T>
class type_allocator {
    public:
        typedef std::unique_ptr<T> (*unique_type_ptr)();
        typedef std::shared_ptr<T> (*shared_type_ptr)();
};

class dynamic_library_loader {
    //? Entry Point Must Be Set From Your Side Using The extern C Linkage
    public:
        //? dynamic_library_loader Types For Dynamic Library Loader
        dynamic_library_loader(const dynamic_library_loader &) = delete;
        explicit dynamic_library_loader() {}
        ~dynamic_library_loader() {}

        template <typename T>
        using unique_type_ptr = typename type_allocator<T>::unique_type_ptr;

        template <typename T>
        auto load_unique(const std::string &file, const std::string &entry_point)
        {
            _libraryInstance.open_file(file);
            unique_type_ptr<T> ptr = _libraryInstance.load_file<unique_type_ptr<T>>(entry_point);
            return ptr();
        }

        template <typename T>
        using shared_type_ptr = typename type_allocator<T>::shared_type_ptr;

        template <typename T>
        auto load_shared(const std::string &file, const std::string &entry_point)
        {
            _libraryInstance.open_file(file);
            shared_type_ptr<T> ptr = _libraryInstance.load_file<shared_type_ptr<T>>(entry_point);
            return ptr();
        }

        void free(void) const { _libraryInstance.close_file(); }

    private:
        static_library_loader _libraryInstance;
};

/**
 * @brief Create an entry point of type T, you must declare the extern "C" once T has been defined.
 * Exemple : #define "name" extern "C" std::unique_ptr<T> entryPoint().
 * @tparam T
 * @return std::unique_ptr<T>
 */
template <typename T>
std::unique_ptr<T> entry_point()
{
    std::unique_ptr<T> instance = std::make_unique<T>();
    return instance;
}

#endif /* !DYNAMIC_LIBRARY_LOADER_HPP_ */
