#include "file_reader.h"

FileReader::FileReader(const std::string &fileName) :
        fileStream(fileName) {
}

FileReader::FileReader(const FileReader &reader) {
    CopyFrom(reader);
}

FileReader::FileReader(FileReader &&reader) noexcept {
    MoveFrom(std::move(reader));
}

FileReader &FileReader::operator=(const FileReader &reader) {
    CopyFrom(reader);
    return *this;
}

FileReader &FileReader::operator=(FileReader &&reader) noexcept {
    MoveFrom(std::move(reader));
    return *this;
}

std::string FileReader::ReadLine() {
    std::string line;
    if (std::getline(fileStream, line)) {
        return line;
    }
    return std::string("");
}

void FileReader::CopyFrom(const FileReader &reader) {
    // TODO
}

void FileReader::MoveFrom(FileReader &&reader) noexcept {
    // TODO
}