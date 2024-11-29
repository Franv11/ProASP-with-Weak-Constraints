#ifndef WEAKINITCOMPILER_H
#define WEAKINITCOMPILER_H
#include "../language/Program.h"
#include "DataStructureCompiler.h"
#include "../utils/Indentation.h"
#include "../utils/SharedFunctions.h"

class WeakInitCompiler
{
public:
    WeakInitCompiler(const std::set<std::string> &rewrittenWeak, const std::string &execPath, DataStructureCompiler *mapCompiler) : weak(rewrittenWeak), executablePath(execPath), auxMapCompiler(mapCompiler) {}

    void compile();

    void buildAuxMapHandler();
    void buildComponentGenerator();

private:
    std::set<std::string> weak;
    DataStructureCompiler *auxMapCompiler;

    std::string executablePath;
};
#endif