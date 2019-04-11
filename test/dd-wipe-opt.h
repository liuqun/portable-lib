/*
 * Automatically generated by ../tools/mkgetopt.py [v1.0.2]
 * Input file: dd-wipe-opt.in
 *
 * DO NOT EDIT THIS FILE!
 *
 * Make all changes in dd-wipe-opt.in.
 */
#ifndef ___DD_WIPE_OPT_H_680883707___
#define ___DD_WIPE_OPT_H_680883707___ 1

/* ANSI/ISO headerfile that defines exact width types */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Struct containing parsed options.
 *
 * There are two kinds of elements here:
 *    a) members with a one-to-one mapping to option specification in
 *       the input file. These will be set to parsed command line
 *       values.
 *
 *    b) Boolean flags whose names match the member names above but,
 *       with the added suffix of "_present". These are set to true iff a
 *       command line option was used. These boolean flags can be used
 *       to know when something has a "default" value vs. something set
 *       by command line parsing.
 *
 *  Lastly, the two members 'argv_inputs' and 'argv_count' hold the
 *  remaining arguments and count respectively.
 */
struct opt_option
{
    /* Points to remaining/unconsumed command line arguments.
     * These are unconsumed either because:
     *   1. The argument parsing was explicitly stopped by use of
     *      the "--" command line option.
     *   2. There are no more options (starting with "-" or "--")
     */
    char * const * argv_inputs;

    /*
     * Contains a count of remaining command line arguments in
     * 'argv_inputs' above.
     */
    int     argv_count;

    int help;
    int ncpu;
    int iopause;
    uint64_t iosize;
    int wipes;
    int verbose;


    /*
     * Boolean flags to denote if any of above vars were recognized
     * during command line processing
     */
    char help_present;
    char ncpu_present;
    char iopause_present;
    char iosize_present;
    char wipes_present;
    char verbose_present;

};
typedef struct opt_option opt_option;



/** Command line parser function
 *
 *  @input argv Array of command line options (obtained via main())
 *              argv[0] is assumed to contain the invoking program
 *              name and will be skipped.
 *  @input argc Count of number of items in the 'argv' array above.
 *
 *  @output opt Pointer to an instance of the option struct defined
 *              above. Upon successful parsing of the command line
 *              options, the appropriate member variables of this
 *              struct will be hold the option values and associated
 *              arguments.
 *
 *  @return 0   if successful
 *         >0   if options were unrecognized or arguments were
 *              incorrect or missing
 */
extern int opt_parse(opt_option * opt, int argc, char * const *argv);


/** Callback function to obtain the version information
 *
 *  The user of this library must supply an implementation of this
 *  function. The generated 'main_opt_parse()' will call this function to
 *  display program version information - when the command line
 *  option "--version" is recognized.
 *
 *  @return string This constant string must contain the version
 *                 number of the invoking program.
 */
extern const char * opt_version(void);


/**
 * User supplied external callback for providing program usage.
 * This function must return a string that can be printed on console.
 */
extern const char* opt_usage(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ___DD_WIPE_OPT_H_680883707___ */

/* EOF */
