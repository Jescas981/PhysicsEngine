#pragma once
#include <string>

namespace IO {

template <typename T> class FileRead {
public:
  FileRead(std::string filepath) : filepath_{std::move(filepath)} {}

  typename T::ResultType Read() { return T::Read(filepath_); }

private:
  const std::string filepath_;
};

template <typename T> class FileWrite {
public:
  FileWrite(std::string filepath) : filepath_{std::move(filepath)} {}

  void Write() { return T::Write(filepath_); }

private:
  const std::string filepath_;
};

template <typename T> class File : public FileRead<T>, public FileWrite<T> {
public:
  File(std::string filepath) : FileRead<T>(filepath), FileWrite<T>(filepath) {}
};

} // namespace IO