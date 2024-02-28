#ifndef ENGINE_FILESYSTEM_FILE_H
#define ENGINE_FILESYSTEM_FILE_H

#include <string>

namespace engine::filesystem
{
    class File
    {
        private:
            std::string filename;

        public:
            File(const std::string& _filename);
            ~File();

    };
}

#endif