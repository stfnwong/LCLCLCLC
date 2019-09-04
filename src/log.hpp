/*
 * LOG
 * Logging stuff
 *
 */

#ifndef __LC_LOG_HPP
#define __LC_LOG_HPP

#ifdef LC_DEBUG 

#define lc_log(x) do { \
    {std::cerr << "[" << __func__ << ":" << __LINE__ << "] " << x << std::endl; }\
} while (0)

#else

#define lc_log(x) do {} while(0)
#endif /*LC_DEBUG*/



#endif /*__LC_LOG_HPP*/
