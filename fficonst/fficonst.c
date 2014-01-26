#include <stdio.h>
#include <stddef.h>

#include <clang-c/Index.h>
#include "visitors.h"

void genConstant(const char* name, size_t value)
{
  printf("\n");
  printf("%s :: Int\n", name);
  printf("%s = %zu\n", name, value);
}

int main(int argc, char** argv)
{
  // CXCursor constants.
  genConstant("sizeOfCXCursor", sizeof(CXCursor));
  genConstant("alignOfCXCursor", 4);  // in C11, could use alignof()
  genConstant("offsetCXCursorKind", offsetof(CXCursor, kind));
  genConstant("offsetCXCursorXData", offsetof(CXCursor, xdata));
  genConstant("offsetCXCursorP1", offsetof(CXCursor, data));
  genConstant("offsetCXCursorP2", offsetof(CXCursor, data) + sizeof(void*));
  genConstant("offsetCXCursorP3", offsetof(CXCursor, data) + 2 * sizeof(void*));

  // ParentedCursor constants.
  genConstant("sizeOfParentedCursor", sizeof(struct ParentedCursor));
  genConstant("alignOfParentedCursor", 4);
  genConstant("offsetParentedCursorParent", offsetof(struct ParentedCursor, parent));
  genConstant("offsetParentedCursorCursor", offsetof(struct ParentedCursor, cursor));

  // Inclusion constants.
  genConstant("sizeOfInclusion", sizeof(struct Inclusion));
  genConstant("alignOfInclusion", 4);
  genConstant("offsetInclusionInclusion", offsetof(struct Inclusion, inclusion));
  genConstant("offsetInclusionLocation", offsetof(struct Inclusion, location));
  genConstant("offsetInclusionIsDirect", offsetof(struct Inclusion, isDirect));

  // SourceLocation constants.
  genConstant("sizeOfCXSourceLocation", sizeof(CXSourceLocation));
  genConstant("alignOfCXSourceLocation", 4);
  genConstant("offsetCXSourceLocationP1", offsetof(CXSourceLocation, ptr_data));
  genConstant("offsetCXSourceLocationP2", offsetof(CXSourceLocation, ptr_data) + sizeof(void*));
  genConstant("offsetCXSourceLocationData", offsetof(CXSourceLocation, int_data));

  return 0;
}
