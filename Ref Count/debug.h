#ifdef debug

#define _d(exp)  \
    std::cerr << "\x1b[92mFile " __FILE__ \
              << ", line " << __LINE__ \
              << ", in " << __FUNCTION__ \
              << "\n  \x1b[91m" #exp "\x1b[39m" \
              << std::endl; exp;
#define _e(hint) \
    std::cerr << hint"\x1b[39m " << *use << "\t[\x1b[96m" \
              << ps << "\x1b[39m]\t" \
              "\x1b[97m" << *ps << "\x1b[39m"\
              << std::endl;
#define _ref() _e("\x1b[32mref")
#define _undef() _e("\x1b[33munref")
#define _del() _e("\x1b[31mdelete")

#else

#define _d(exp)  exp;
#define _ref() 
#define _undef() 
#define _del() 
    
#endif

#define _p(...) std::cout << "\x1b[97mOut[" \
        << __FILE__ << ":" << __LINE__ << \
        "]: \x1b[39m"  << __VA_ARGS__ << std::endl;
