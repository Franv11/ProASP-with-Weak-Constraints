#include "WeakInitCompiler.h"

void WeakInitCompiler::compile()
{
    buildAuxMapHandler();
    buildComponentGenerator();
}

void WeakInitCompiler::buildAuxMapHandler()
{
    for (std::string headWeak : weak)
    {
        auxMapCompiler->addAuxMap(headWeak, {});
    }
}

void WeakInitCompiler::buildComponentGenerator()
{

    Indentation ind(0);
    std::string className = "WeakInitializer";
    std::string executorPath = executablePath + "/../../glucose-4.2.1/sources/simp/generators/" + className + ".cc";
    std::ofstream outfile(executorPath);
    if (!outfile.is_open())
    {
        std::cout << "Error unable to open " + className + " file " << executorPath << std::endl;
        exit(180);
    }

    outfile << ind << "#include \"../solver/" + className + ".h\"\n";
    outfile << ind << "#include <vector>\n";
    outfile << ind << "#include <string>\n";
    outfile << ind << "#include \"../datastructures/TupleFactory.h\"\n";
    outfile << ind << "#include \"../datastructures/AuxiliaryMapSmart.h\"\n";
    outfile << ind << "#include \"../solver/AuxMapHandler.h\"\n";
    outfile << ind << "\n";
    outfile << ind << "WeakInitializer::WeakInitializer() {\n";
    outfile << ++ind << "weakPropagator = new WeakPropagator();\n";
    outfile << --ind << "}\n";
    outfile << ind << "\n";
    outfile << ind << "void " + className + "::" + "initialize() {\n";
    outfile << ind << "\n";

    ++ind;
    std::string structType = "std::vector<int>*";
    for (auto head : weak)
    {
        outfile << ind << "{\n";

        outfile << ++ind << structType << " tuplesU = &AuxMapHandler::getInstance().get_u" << head << "_()->getValuesVec({});\n";
        outfile << ind << structType << " tuplesF = &AuxMapHandler::getInstance().get_f" << head << "_()->getValuesVec({});\n";
        outfile << ind << structType << " tuplesP = &AuxMapHandler::getInstance().get_p" << head << "_()->getValuesVec({});\n";

        outfile << ind << "for(auto i = tuplesP->begin(); i != tuplesU->end(); i++) {\n";
        outfile << ++ind << "if(i == tuplesP->end()) i=tuplesF->begin();\n";
        outfile << ind << "if(i == tuplesF->end()) i=tuplesU->begin();\n";
        outfile << ind << "if(i == tuplesU->end()) break;\n";
        outfile << ind << "int id = *i;\n";

        outfile << ind << "Tuple* tuple = TupleFactory::getInstance().getTupleFromInternalID(id);\n";
        outfile << ind << "weakPropagator->addWeightedLiteral(tuple, tuple->getContent()[0]);\n";

        outfile << --ind << "}\n";

        outfile << --ind << "}\n";
    }
    outfile << --ind << "}\n";

    outfile.close();
}
