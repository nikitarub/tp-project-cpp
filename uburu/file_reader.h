#ifndef UBURU_FILE_READER_H
#define UBURU_FILE_READER_H

#include <string>
#include <fstream>

class FileReader {
    public:
        FileReader() = delete;
        explicit FileReader(const std::string& fileName);
        FileReader(const FileReader& reader);
        FileReader(FileReader&& reader) noexcept;

        virtual ~FileReader() noexcept = default;

        FileReader& operator =(const FileReader& reader);
        FileReader& operator =(FileReader&& reader) noexcept;

        std::string ReadLine();

    private:
        std::ifstream fileStream;

        void CopyFrom(const FileReader& reader);
        void MoveFrom(FileReader&& reader) noexcept;
};

#endif //UBURU_FILE_READER_H
