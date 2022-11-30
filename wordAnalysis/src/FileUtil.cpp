#include "FileUtil.h"

FileUtil::FileUtil(string fileName) { in = new ifstream(fileName); }
FileUtil::~FileUtil() { delete in; }
char FileUtil::getNextChar() { return in->get(); }
char FileUtil::peekNextChar() { return in->peek(); }
bool FileUtil::hasNextChar() { return in->peek() != ios::traits_type::eof(); }
