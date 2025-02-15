/***************************************************************************************[Main.cc]
 Glucose -- Copyright (c) 2009-2014, Gilles Audemard, Laurent Simon
                                CRIL - Univ. Artois, France
                                LRI  - Univ. Paris Sud, France (2009-2013)
                                Labri - Univ. Bordeaux, France

 Syrup (Glucose Parallel) -- Copyright (c) 2013-2014, Gilles Audemard, Laurent Simon
                                CRIL - Univ. Artois, France
                                Labri - Univ. Bordeaux, France

Glucose sources are based on MiniSat (see below MiniSat copyrights). Permissions and copyrights of
Glucose (sources until 2013, Glucose 3.0, single core) are exactly the same as Minisat on which it
is based on. (see below).

Glucose-Syrup sources are based on another copyright. Permissions and copyrights for the parallel
version of Glucose-Syrup (the "Software") are granted, free of charge, to deal with the Software
without restriction, including the rights to use, copy, modify, merge, publish, distribute,
sublicence, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

- The above and below copyrights notices and this permission notice shall be included in all
copies or substantial portions of the Software;
- The parallel version of Glucose (all files modified since Glucose 3.0 releases, 2013) cannot
be used in any competitive event (sat competitions/evaluations) without the express permission of
the authors (Gilles Audemard / Laurent Simon). This is also the case for any competitive event
using Glucose Parallel as an embedded SAT engine (single core or not).


--------------- Original Minisat Copyrights

Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
Copyright (c) 2007-2010, Niklas Sorensson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **************************************************************************************************/

#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <zlib.h>
#include <sys/resource.h>

#include "utils/System.h"
#include "utils/ParseUtils.h"
#include "utils/Options.h"
#include "core/Dimacs.h"
#include "simp/SimpSolver.h"

#include "../simp/datastructures/TupleFactory.h"
#include "../simp/utils/ConstantsManager.h"
#include "../simp/solver/Generator.h"
#include "../simp/solver/InstanceExpansion.h"
#include "../simp/solver/ModelExpansion.h"
#include "../simp/solver/Propagator.h"
#include "../simp/solver/AuxMapHandler.h"
#include "../simp/solver/SatProgramBuilder.h"
#include "../simp/utils/SharedFunctions.h"
#include "../simp/solver/WeakInitializer.h"

#include <fstream>
#include <stdlib.h>

using namespace Glucose;

//=================================================================================================

static const char *_certified = "CORE -- CERTIFIED UNSAT";
void test_backward_propagation(std::vector<AggregatePropagator> &propagators)
{
    // Glucose::vec<Glucose::Lit> empty;
    // {
    //     for(int j = 1; j<=3; j++){
    //         TupleLight* agg_set_1_j_1 = TupleFactory::getInstance().find({1,j,1}, AuxMapHandler::getInstance().get_aggr_set0());
    //         agg_set_1_j_1->setStatus(True);
    //         propagators[0].propagate(NULL,empty,agg_set_1_j_1->getId());
    //     }
    //     int count = 9;
    //     for(int i = 1; i<=3; i++){
    //         for(int j = 1; j<=3; j++){
    //             TupleLight* agg_set_i_j_1 = TupleFactory::getInstance().find({i,j,2}, AuxMapHandler::getInstance().get_aggr_set0());
    //             agg_set_i_j_1->setStatus(False);
    //             propagators[1].propagate(NULL,empty,-agg_set_i_j_1->getId());
    //             count--;
    //             if(count < 5){
    //                 break;
    //             }
    //         }
    //         if(count < 5){
    //             break;
    //         }
    //     }
    // }
}
void test_support_propagation(std::vector<AggregatePropagator> &propagators)
{
    // Glucose::vec<Glucose::Lit> empty;

    // TupleLight* aggId_1_2 = TupleFactory::getInstance().find({1,2}, AuxMapHandler::getInstance().get_aggr_id0());
    // aggId_1_2->setStatus(True);
    // propagators[0].propagate(NULL,empty,aggId_1_2->getId());
    // int count = 9;
    // for(int i = 1; i<=3; i++){
    //     for(int j = 1; j<=3; j++){
    //         TupleLight* agg_set_i_j_1 = TupleFactory::getInstance().find({i,j,1}, AuxMapHandler::getInstance().get_aggr_set0());
    //         agg_set_i_j_1->setStatus(False);
    //         propagators[0].propagate(NULL,empty,-agg_set_i_j_1->getId());
    //         count--;
    //         if(count < 4){
    //             break;
    //         }
    //     }
    //     if(count < 4){
    //         break;
    //     }
    // }
    // TupleLight* aggId_2_4 = TupleFactory::getInstance().find({2,4}, AuxMapHandler::getInstance().get_aggr_id0());
    // aggId_2_4->setStatus(False);
    // propagators[1].propagate(NULL,empty,-aggId_2_4->getId());
    // count = 0;
    // for(int i = 1; i<=3; i++){
    //     for(int j = 1; j<=3; j++){
    //         TupleLight* agg_set_1_j_1 = TupleFactory::getInstance().find({i,j,2}, AuxMapHandler::getInstance().get_aggr_set0());
    //         agg_set_1_j_1->setStatus(True);
    //         propagators[1].propagate(NULL,empty,agg_set_1_j_1->getId());
    //         count++;
    //         if(count > 3){
    //             break;
    //         }
    //     }
    //     if(count > 3){
    //         break;
    //     }
    // }
}
void test_propagators(std::vector<AggregatePropagator> &propagators)
{
    Glucose::vec<Glucose::Lit> empty;
    for (unsigned i = 0; i < propagators.size(); i++)
    {
        std::cout << "Propagator " << i << std::endl;
        propagators[i].printCurrentStatus();
    }
    // test_backward_propagation(propagators);
    test_support_propagation(propagators);
}
void printStats(Solver &solver)
{
    double cpu_time = cpuTime();
    double mem_used = 0; // memUsedPeak();
    printf("c restarts              : %" PRIu64 " (%" PRIu64 " conflicts in avg)\n", solver.starts, (solver.starts > 0 ? solver.conflicts / solver.starts : 0));
    printf("c blocked restarts      : %" PRIu64 " (multiple: %" PRIu64 ") \n", solver.stats[nbstopsrestarts], solver.stats[nbstopsrestartssame]);
    printf("c last block at restart : %" PRIu64 "\n", solver.stats[lastblockatrestart]);
    printf("c nb ReduceDB           : %" PRIu64 "\n", solver.stats[nbReduceDB]);
    printf("c nb removed Clauses    : %" PRIu64 "\n", solver.stats[nbRemovedClauses]);
    printf("c average learnt size   : %" PRIu64 "\n", solver.conflicts == 0 ? 0 : solver.stats[sumSizes] / solver.conflicts);
    printf("c nb learnts DL2        : %" PRIu64 "\n", solver.stats[nbDL2]);
    printf("c nb learnts size 2     : %" PRIu64 "\n", solver.stats[nbBin]);
    printf("c nb learnts size 1     : %" PRIu64 "\n", solver.stats[nbUn]);
    if (solver.chanseokStrategy)
        printf("c nb permanent learnts  : %" PRIu64 "\n", solver.stats[nbPermanentLearnts]);

    printf("c conflicts             : %-12" PRIu64 "   (%.0f /sec)\n", solver.conflicts, solver.conflicts / cpu_time);
    printf("c decisions             : %-12" PRIu64 "   (%4.2f %% random) (%.0f /sec)\n", solver.decisions, (float)solver.stats[rnd_decisions] * 100 / (float)solver.decisions, solver.decisions / cpu_time);
    printf("c propagations          : %-12" PRIu64 "   (%.0f /sec)\n", solver.propagations, solver.propagations / cpu_time);
    //    printf("c conflict literals     : %-12" PRIu64"   (%4.2f %% deleted)\n", solver.stats[tot_literals], (solver.stats[max_literals] - solver.stats[tot_literals])*100 / (double)solver.stats[max_literals]);
    //    printf("c Average resolutions   : %-12" PRIu64"   (%.0f seen ones)\n",solver.stats[sumRes]/solver.conflicts,((double)solver.stats[sumResSeen])/solver.conflicts);
    printf("c nb reduced Clauses    : %" PRIu64 "\n", solver.stats[nbReducedClauses]);
    printf("c LCM                   : %" PRIu64 " / %" PRIu64 " \n", solver.stats[lcmreduced], solver.stats[lcmtested]);
    if (mem_used != 0)
        printf("Memory used           : %.2f MB\n", mem_used);
    printf("c CPU time              : %g s\n", cpu_time);
}

static Solver *solver;
// Terminate by notifying the solver and back out gracefully. This is mainly to have a test-case
// for this feature of the Solver as it may take longer than an immediate call to '_exit()'.
static void SIGINT_interrupt(int signum) { solver->interrupt(); }

// Note that '_exit()' rather than 'exit()' has to be used. The reason is that 'exit()' calls
// destructors and may cause deadlocks if a malloc/free function happens to be running (these
// functions are guarded by locks for multithreaded use).
static void SIGINT_exit(int signum)
{
    printf("\n");
    printf("*** INTERRUPTED ***\n");
    if (solver->verbosity > 0)
    {
        printStats(*solver);
        printf("\n");
        printf("*** INTERRUPTED ***\n");
    }
    _exit(1);
}

//=================================================================================================
// Main:
int parseTuple(const std::string &literalString, std::vector<std::pair<std::string, std::vector<std::string>>> &parsedTuple, std::set<std::string> &alphanumericConstants)
{
    std::vector<std::string> terms;
    std::string predicateName;
    unsigned i = 0;
    for (i = 0; i < literalString.size(); i++)
    {
        if (literalString[i] == '(')
        {
            predicateName = literalString.substr(0, i);
            break;
        }
        if (i == literalString.size() - 1)
        {
            predicateName = literalString.substr(0);
        }
    }
    for (; i < literalString.size(); i++)
    {
        char c = literalString[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '-')
        {
            int start = i;
            int openBrackets = 0;
            while ((c != ' ' && c != ',' && c != ')') || openBrackets > 0)
            {
                if (c == '(')
                {
                    openBrackets++;
                }
                else if (c == ')')
                {
                    openBrackets--;
                }
                i++;
                c = literalString[i];
            }
            std::string term = literalString.substr(start, i - start);
            if (!isInteger(term))
                alphanumericConstants.insert(term);
            terms.push_back(term);
            // terms.push_back(ConstantsManager::getInstance().mapConstant(literalString.substr(start, i - start)));
        }
    }
    parsedTuple.push_back(std::make_pair(predicateName, terms));
    // TupleLight* tuple=TupleFactory::getInstance().addNewInternalTuple(terms, AuxMapHandler::getInstance().getPredicateId(predicateName));

    // const auto& insertResult = tuple->setStatus(True);
    // if(insertResult.second){
    //     TupleFactory::getInstance().removeFromCollisionsList(tuple->getId());
    //     AuxMapHandler::getInstance().insertTrue(insertResult);
    //     return tuple->getId();
    // }
    return -1;
}
int parseTupleUndef(const std::string &literalString)
{
    std::vector<int> terms;
    std::string predicateName;
    unsigned i = 0;
    for (i = 0; i < literalString.size(); i++)
    {
        if (literalString[i] == '(')
        {
            predicateName = literalString.substr(0, i);
            break;
        }
        if (i == literalString.size() - 1)
        {
            predicateName = literalString.substr(0);
        }
    }
    for (; i < literalString.size(); i++)
    {
        char c = literalString[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '-')
        {
            int start = i;
            int openBrackets = 0;
            while ((c != ' ' && c != ',' && c != ')') || openBrackets > 0)
            {
                if (c == '(')
                {
                    openBrackets++;
                }
                else if (c == ')')
                {
                    openBrackets--;
                }
                i++;
                c = literalString[i];
            }
            terms.push_back(ConstantsManager::getInstance().mapConstant(literalString.substr(start, i - start)));
        }
    }
    //    TupleLight* tuple=TupleFactory::getInstance().findNoSet(terms, AuxMapHandler::getInstance().getPredicateId(predicateName));
    TupleLight *tuple = TupleFactory::getInstance().find(terms, AuxMapHandler::getInstance().getPredicateId(predicateName));
    return tuple != NULL ? tuple->getId() : -1;
}
void read_model_constraints(std::string filename, std::vector<std::vector<int>> &constraints)
{
    std::ifstream inputFile(filename);
    string line;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            unsigned start = 0;
            std::vector<int> literals;
            for (unsigned i = 0; i < line.size(); i++)
            {
                if (line[i] == ' ')
                {
                    int tupleId = parseTupleUndef(line[start] == '-' ? line.substr(start + 1, i - start) : line.substr(start, i - start));
                    // std::cout << "reading "<<(line[start] == '-' ? line.substr(start+1,i-start) : line.substr(start,i-start))<<" "<<tupleId<<std::endl;
                    if (tupleId > 0)
                    {
                        literals.push_back(line[start] == '-' ? -tupleId : tupleId);
                    }
                    start = i + 1;
                }
            }
            constraints.push_back(literals);
        }
        inputFile.close();
    }
    else
        cout << "Unable to open file" << std::endl;
}
void read_asp(Solver *solver, std::string filename, std::vector<unsigned> &facts)
{
    std::ifstream inputFile(filename);
    std::vector<std::pair<std::string, std::vector<std::string>>> parsedTuples;
    std::set<std::string> alphanumericConstants;
    string line;
    bool warning = false;
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            unsigned start = 0;
            bool skip = false;
            for (unsigned i = 0; i < line.size(); i++)
            {
                if (line[i] == '%')
                {
                    if (!warning)
                        std::cout << "WARNING: found comment in " << filename << std::endl;
                    warning = true;
                    std::cout << "Ignored line " << line.substr(i, line.size() - i) << std::endl;
                    break;
                }
                if (line[i] == '.')
                {
                    skip = true;
                    int tupleId = parseTuple(line.substr(start, i - start), parsedTuples, alphanumericConstants);
                    if (tupleId > 0)
                    {
                        facts.push_back(tupleId);
                    }
                    start = i + 1;
                }
                else if (skip)
                {
                    if (line[i] < 'a' || line[i] > 'z')
                    {
                        start = i + 1;
                    }
                    else
                    {
                        skip = false;
                    }
                }
            }
        }
        inputFile.close();
    }
    else
        cout << "Unable to open file" << std::endl;
    for (const std::string &constant : alphanumericConstants)
    {
        ConstantsManager::getInstance().mapConstant(constant);
    }
    for (auto &parsedTuple : parsedTuples)
    {
        std::vector<int> terms;
        for (std::string &term : parsedTuple.second)
        {
            terms.push_back(ConstantsManager::getInstance().mapConstant(term));
        }
        TupleLight *tuple = TupleFactory::getInstance().addNewInternalTuple(terms, AuxMapHandler::getInstance().getPredicateId(parsedTuple.first));

        const auto &insertResult = tuple->setStatus(True);
        if (insertResult.second)
        {
            TupleFactory::getInstance().removeFromCollisionsList(tuple->getId());
            AuxMapHandler::getInstance().initTuple(tuple);
            AuxMapHandler::getInstance().insertTrue(insertResult);
            facts.push_back(tuple->getId());
        }
    }
}

int main(int argc, char **argv)
{
    try
    {
        // printf("c\nc This is glucose 4.2.1 --  based on MiniSAT (Many thanks to MiniSAT team)\nc\n");
        printf("c\nc This is ProASP solver --  based on glucose 4.2.1 (Many thanks to Glucose team)\nc\n");

        // Set the temporary bound for the weak
        /*int bound;
        std::cout << "Enter an integer: ";
        while (!(std::cin >> bound))
        {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // cout << "You entered: " << bound << endl;*/

        setUsageHelp("c USAGE: %s [options] <input-file> <result-output-file>\n\n  where input may be either in plain or gzipped DIMACS.\n");

#if defined(__linux__)
        fpu_control_t oldcw, newcw;
        _FPU_GETCW(oldcw);
        newcw = (oldcw & ~_FPU_EXTENDED) | _FPU_DOUBLE;
        _FPU_SETCW(newcw);
// printf("c WARNING: for repeatability, setting FPU to use double precision\n");
#endif
        // Extra options:
        //
        IntOption verb("MAIN", "verb", "Verbosity level (0=silent, 1=some, 2=more).", 1, IntRange(0, 2));
        BoolOption mod("MAIN", "model", "show model.", false);
        IntOption vv("MAIN", "vv", "Verbosity every vv conflicts", 10000, IntRange(1, INT32_MAX));
        BoolOption pre("MAIN", "pre", "Completely turn on/off any preprocessing.", true);
        StringOption dimacs("MAIN", "dimacs", "If given, stop after preprocessing and write the result to this file.");
        IntOption cpu_lim("MAIN", "cpu-lim", "Limit on CPU time allowed in seconds.\n", INT32_MAX, IntRange(0, INT32_MAX));
        IntOption mem_lim("MAIN", "mem-lim", "Limit on memory usage in megabytes.\n", INT32_MAX, IntRange(0, INT32_MAX));
        //       BoolOption opt_incremental ("MAIN","incremental", "Use incremental SAT solving",false);

        BoolOption opt_certified(_certified, "certified", "Certified UNSAT using DRUP format", false);
        StringOption opt_certified_file(_certified, "certified-output", "Certified UNSAT output file", "NULL");
        BoolOption opt_vbyte(_certified, "vbyte", "Emit proof in variable-byte encoding", false);

        parseOptions(argc, argv, true);

        SimpSolver S;

        double initial_time = cpuTime();

        S.parsing = 1;
        S.use_simplification = pre;

        // if (!pre) S.eliminate(true);

        S.verbosity = verb;
        S.verbEveryConflicts = vv;
        S.showModel = mod;

        S.certifiedUNSAT = opt_certified;
        S.vbyte = opt_vbyte;
        if (S.certifiedUNSAT)
        {
            if (!strcmp(opt_certified_file, "NULL"))
            {
                S.vbyte = false; // Cannot write binary to stdout
                S.certifiedOutput = fopen("/dev/stdout", "wb");
                if (S.verbosity >= 1)
                    printf("c\nc Write unsat proof on stdout using text format\nc\n");
            }
            else
                S.certifiedOutput = fopen(opt_certified_file, "wb");
            const char *name = opt_certified_file;
            if (S.verbosity >= 1)
                printf("c\nc Write unsat proof on %s using %s format\nc\n", name, S.vbyte ? "binary" : "text");
        }
        solver = &S;
        // Use signal handlers that forcibly quit until the solver will be able to respond to
        // interrupts:
        signal(SIGINT, SIGINT_exit);
        signal(SIGXCPU, SIGINT_exit);

        // Set limit on CPU-time:
        if (cpu_lim != INT32_MAX)
        {
            rlimit rl;
            getrlimit(RLIMIT_CPU, &rl);
            if (rl.rlim_max == RLIM_INFINITY || (rlim_t)cpu_lim < rl.rlim_max)
            {
                rl.rlim_cur = cpu_lim;
                if (setrlimit(RLIMIT_CPU, &rl) == -1)
                    printf("c WARNING! Could not set resource limit: CPU-time.\n");
            }
        }

        // Set limit on virtual memory:
        if (mem_lim != INT32_MAX)
        {
            rlim_t new_mem_lim = (rlim_t)mem_lim * 1024 * 1024;
            rlimit rl;
            getrlimit(RLIMIT_AS, &rl);
            if (rl.rlim_max == RLIM_INFINITY || new_mem_lim < rl.rlim_max)
            {
                rl.rlim_cur = new_mem_lim;
                if (setrlimit(RLIMIT_AS, &rl) == -1)
                    printf("c WARNING! Could not set resource limit: Virtual memory.\n");
            }
        }

        if (argc == 1)
            printf("c Reading from standard input... Use '--help' for help.\n");
        gzFile in = (argc == 1) ? gzdopen(0, "rb") : gzopen(argv[1], "rb");
        if (in == NULL)
            printf("ERROR! Could not open file: %s\n", argc == 1 ? "<stdin>" : argv[1]), exit(1);

        if (S.verbosity > 0)
        {
            printf("c ========================================[ Problem Statistics ]===========================================\n");
            printf("c |                                                                                                       |\n");
        }

        FILE *res = (argc >= 3) ? fopen(argv[argc - 1], "wb") : NULL;
        if (false /* !ASP */)
        {

            parse_DIMACS(in, S);
            gzclose(in);
        }
        else
        {
            vec<Lit> lits;
            while (0 >= solver->nVars())
                solver->newVar();
            lits.push(mkLit(0));
            solver->addClause_(lits);
            std::vector<unsigned> facts;
            read_asp(solver, argv[argc - 1], facts);
            int lastFact = TupleFactory::getInstance().size();
            InstanceExpansion::getInstance().generate(&S);

            int lastExpandedFact = TupleFactory::getInstance().size();
            // std::cout << "%%%%%%%%%%%%%%%%%%% Instance Expansion %%%%%%%%%%%%%%%%%%%"<<std::endl;
            for (int id = lastFact; id < lastExpandedFact; id++)
            {
                // AuxMapHandler::getInstance().printTuple(TupleFactory::getInstance().getTupleFromInternalID(id));
                // std::cout << std::endl;
                facts.push_back(id);
            }
            // std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<std::endl;
            TupleFactory::getInstance().storeFactSize();
            TupleFactory::getInstance().initClauseGen();
            TupleFactory::getInstance().initConstraintGen();
            std::vector<int> falseAtoms;
            Generator::getInstance().generate(&S, falseAtoms);

            for (AggregatePropagator *prop : Generator::getInstance().collectAggregatePropagators())
            {
                // prop->printCurrentStatus();
                Propagator::getInstance().addPropagator(prop);
            }
            // std::vector<AggregatePropagator> propagators;
            // test_propagators(propagators);

            // Initialifze the weak and add to the propagator
            WeakInitializer::getInstance().initialize();
            Propagator::getInstance().addPropagator(WeakInitializer::getInstance().getWeakPropagator());

            Propagator::getInstance().attachWatchers();
            for (unsigned id : facts)
            {
#ifdef DEBUG_PROP
                std::cout << "Adding facts in glucose " << id << std::endl;
#endif
                while (id >= S.nVars())
                {
                    S.setFrozen(S.newVar(), true);
                }
                lits.clear();
                lits.push(mkLit(id));
                solver->addClause_(lits);
                Propagator::getInstance().updateSumForTrueLitGroundAggregate(id);
                // std::cout << "Addeded "<<var(mkLit(id))<<" at level "<<solver->getLiteralLevel(var(mkLit(id)))<<std::endl;
                if (!solver->okay())
                    break;
            }

            while (!falseAtoms.empty())
            {
                int id = falseAtoms.back();
                falseAtoms.pop_back();
#ifdef DEBUG_PROP
                std::cout << "Adding false atoms in glucose -" << id << std::endl;
#endif
                Propagator::getInstance().updateSumForTrueLitGroundAggregate(-id);
                lits.clear();
                lits.push(mkLit(id, true));
                solver->addClause_(lits);
                if (!solver->okay())
                    break;
            }
            std::vector<std::vector<int>> constraints;
            // read_model_constraints("constraints.lp",constraints);
            // std::cout << "Found "<<constraints.size()<<" constraints"<<std::endl;
            for (std::vector<int> constraint : constraints)
            {
                lits.clear();
                for (int literal : constraint)
                {
                    bool negated = literal < 0;
                    lits.push(mkLit(negated ? -literal : literal, !negated));
                    std::cout << -literal << " ";
                }
                std::cout << "0" << std::endl;
                solver->addClause_(lits);
                if (!solver->okay())
                    break;
            }
            Propagator::getInstance().activate();
            if (S.okay())
                Propagator::getInstance().propagateAtLevel0(&S, lits);
            if (S.okay())
            {
                SatProgramBuilder::getInstance().computeCompletion(&S);

                // std::cout << "Exiting ..."<<std::endl;
                // exit(180);
                // std::cout << "p cnf "<<TupleFactory::getInstance().size()-1<<" " << S.nClauses()+facts.size()<<std::endl;
                /*for(int i=1;i<TupleFactory::getInstance().size(); i++){
                    std::cout << "c "<<i<<" ";
                    AuxMapHandler::getInstance().printTuple(TupleFactory::getInstance().getTupleFromInternalID(i));
                    std::cout << std::endl;
                }*/
                // // S.printGeneratedClauses();
                // for(unsigned id : facts){
                //     std::cout << id << " 0"<<std::endl;
                // }
                // for(int id : falseAtoms)
                //     std::cout << -id << " 0"<<std::endl;
                // std::cout << "End cnf"<<std::endl;
                TupleFactory::getInstance().destroyClauses();
                TupleFactory::getInstance().destroyConstraints();
                // std::cout << "Found "<<S.nVars()<<" glucose variables"<<std::endl;
                int lastVar = TupleFactory::getInstance().getLastId();
                // std::cout << "Generated "<<lastVar<<" symbols"<<std::endl;
            }
        }
        if (S.verbosity > 0)
        {
            printf("c |  Number of variables:  %12d                                                                   |\n", S.nVars());
            printf("c |  Number of clauses:    %12d                                                                   |\n", S.nClauses());
        }

        double parsed_time = cpuTime();
        if (S.verbosity > 0)
        {
            printf("c |  Parse time:           %12.2f s                                                                 |\n", parsed_time - initial_time);
            printf("c |                                                                                                       |\n");
        }

        // Change to signal-handlers that will only notify the solver and allow it to terminate
        // voluntarily:
        signal(SIGINT, SIGINT_interrupt);
        signal(SIGXCPU, SIGINT_interrupt);

        S.parsing = 0;
        if (pre /* && !S.isIncremental()*/)
        {
            printf("c | Preprocesing is fully done\n");
            S.eliminate(true);
            double simplified_time = cpuTime();
            if (S.verbosity > 0)
            {
                printf("c |  Simplification time:  %12.2f s                                                                 |\n", simplified_time - parsed_time);
            }
        }
        printf("c |                                                                                                       |\n");
        if (!S.okay())
        {
            if (S.certifiedUNSAT)
                fprintf(S.certifiedOutput, "0\n"), fclose(S.certifiedOutput);
            if (res != NULL)
                fprintf(res, "UNSAT\n"), fclose(res);
            if (S.verbosity > 0)
            {
                printf("c =========================================================================================================\n");
                printf("Solved by simplification\n");
                printStats(S);
                printf("\n");
            }
            printf("s UNSATISFIABLE\n");
            exit(20);
        }

        if (dimacs)
        {
            std::cout << "dimacs if" << std::endl;
            if (S.verbosity > 0)
                printf("c =======================================[ Writing DIMACS ]===============================================\n");
            S.toDimacs((const char *)dimacs);
            if (S.verbosity > 0)
                printStats(S);
            exit(0);
        }
        else
        {
            // std::cout << "no dimacs"<<std::endl;
        }
        Generator::getInstance().destroyRemapping();
        // TupleFactory::getInstance().printUsedMemory();
        // printAuxMapMem();
        // analyzePenalty();
        std::cout << "Start solving" << std::endl;
        vec<Lit> dummy;
        // Start Point
        lbool ret = S.solveLimited(dummy);

        if (S.verbosity > 0)
        {
            printStats(S);
            printf("\n");
        }
        printf(ret == l_True ? "s SATISFIABLE\n" : ret == l_False ? "s UNSATISFIABLE\n"
                                                                  : "s INDETERMINATE\n");
        int exit_code = ret == l_True ? 10 : ret == l_False ? 20
                                                            : 180;

        if (res != NULL)
        {
            if (ret == l_True)
            {
                printf("SAT\n");
                for (int i = 0; i < S.nVars(); i++)
                    if (S.model[i] != l_Undef)
                        fprintf(res, "%s%s%d", (i == 0) ? "" : " ", (S.model[i] == l_True) ? "" : "-", i + 1);
                fprintf(res, " 0\n");
            }
            else
            {
                if (ret == l_False)
                {
                    fprintf(res, "UNSAT\n");
                }
            }
            fclose(res);
        }
        else
        {
            if (S.showModel && ret == l_True)
            {
                if (false /*asp mode on*/)
                {
                    // model print has been anticipated in solve method
                    for (unsigned id = 1; id < TupleFactory::getInstance().size(); id++)
                    {
                        TupleLight *t = TupleFactory::getInstance().getTupleFromInternalID(id);
                        if (t != NULL && t->isTrue())
                            AuxMapHandler::getInstance().printTuple(t);
                    }
                }
                else
                {
                    printf("v ");
                    for (int i = 0; i < S.nVars(); i++)
                        if (S.model[i] != l_Undef)
                            printf("%s%s%d", (i == 0) ? "" : " ", (S.model[i] == l_True) ? "" : "-", i + 1);
                    printf(" 0\n");
                }
            }
        }

        exit(exit_code);
#ifdef NDEBUG
        exit(ret == l_True ? 10 : ret == l_False ? 20
                                                 : 0); // (faster than "return", which will invoke the destructor for 'Solver')
#else
        return (ret == l_True ? 10 : ret == l_False ? 20
                                                    : 0);
#endif
    }
    catch (OutOfMemoryException &)
    {
        printf("c =========================================================================================================\n");
        printf("INDETERMINATE\n");
        exit(0);
    }
}
