#include <Engine/Logger.hpp>
#include <IO/Procedures/PlainText.hpp>
#include <stdio.h>
#include <stdlib.h>

namespace IO {
namespace Procedures {

PlainText::ResultType PlainText::Read(const std::string &filepath) {
  FILE *file;
  file = fopen(filepath.c_str(), "r");
  CORE_ERROR(filepath);
  if (file == nullptr) {
    CORE_ERROR("File not found in PlainText Procedure");
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = (char *)malloc(size);

  fread(buffer, 1, size, file);

  fclose(file);

  std::string content(reinterpret_cast<char *>(buffer), size);

  free(buffer);

  return content;
}

} // namespace Procedures
} // namespace IO