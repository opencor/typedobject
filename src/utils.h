#ifndef TYPED_OBJECT_UTILS_H
#define TYPED_OBJECT_UTILS_H

#include "rdf.h"
#include "rdfdefs.h"

#include <boost/date_time/posix_time/posix_time.hpp> // _types.hpp>

#include <stdexcept>
#include <string>


namespace utils {

  class TimeException : public std::range_error {
   public:
    TimeException(const std::string &reason)
     : std::range_error(reason) { }
    } ;

  class Datetime {
   public:
    Datetime() { }
    Datetime(const std::string &dt) ;
    Datetime(const rdf::Node &node) ;
    std::string to_string(void) const ;
    rdf::Literal to_literal(void) ;
   private:
    boost::posix_time::ptime m_time ;
    } ;

  class Duration {
   public:
    Duration() { }
    Duration(const std::string &dt, const bool strict=false) ;
    Duration(const rdf::Node &node) ;
    std::string to_string(void) const ;
    rdf::Literal to_literal(void) ;
   private:
    boost::posix_time::time_duration m_duration ;
    static const char *scan_decimal(const char *s, long *number, long *fraction, long *places,
                                    const char terminator) ;
    static const char *scan_integer(const char *s, long *result, const char terminator) ;
    } ;

  } ;

#endif
