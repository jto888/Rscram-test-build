C:\\Rpack\>build Rscram

 

C:\\Rpack\>R CMD INSTALL --build Rscram

\* installing to library 'C:/Users/Dad/Documents/R/win-library/3.2'

\* installing \*source\* package 'Rscram' ...

\*\* libs

 

\*\*\* arch - i386

g++ -m32 -std=c++0x -I"C:/PROGRA\~1/R/R-32\~1.4/include" -DNDEBUG   
-I"C:/Users/D

ad/Documents/R/win-library/3.2/Rcpp/include" -I"C:/Program Files/R/R-3.2.4/libra

ry/RcppArmadillo/include" -I"C:/Users/Dad/Documents/R/win-library/3.2/BH/include

" -I"d:/RCompile/r-compiling/local/local323/include"     -O2 -Wall  -mtune=core2

 -c element.cc -o element.o

In file included from element.cc:21:0:

element.h:121:1: error: expected unqualified-id before 'using'

element.h:199:1: error: expected unqualified-id before 'using'

element.h:226:16: sorry, unimplemented: non-static data member initializers

element.h:226:16: error: ISO C++ forbids in-class initialization of non-const
static member 'mark_'

In file included from element.cc:25:0:

error.h:40:11: error: function 'virtual scram::Error::\~Error()' defaulted on
its

 first declaration must not have an exception-specification

error.h:40:31: error: 'virtual scram::Error::\~Error()' declared virtual cannot
be defaulted in the class body

error.h:43:28: error: expected ';' at end of member declaration

error.h:43:37: error: 'override' does not name a type

error.h:65:16: error: 'scram::Error::Error' names constructor

error.h:70:16: error: 'scram::Error::Error' names constructor

error.h:75:26: error: 'scram::ValidationError::ValidationError' names
constructor

error.h:80:26: error: 'scram::ValidationError::ValidationError' names
constructor

error.h:85:26: error: 'scram::ValidationError::ValidationError' names
constructor

error.h:90:16: error: 'scram::Error::Error' names constructor

error.h:96:16: error: 'scram::Error::Error' names constructor

error.h:103:16: error: 'scram::Error::Error' names constructor

error.h:111:16: error: 'scram::Error::Error' names constructor

element.cc: In constructor 'scram::mef::Element::Element(std::string, bool)':

element.cc:34:55: error: no matching function for call to
'scram::LogicError::LogicError(const char [32])'

element.cc:34:55: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from 'const char [32]'
to 'const scram::LogicError&'

element.cc:36:59: error: no matching function for call to
'scram::InvalidArgument::InvalidArgument(const char[31])'

element.cc:36:59: note: candidate is:

error.h:95:8: note: scram::InvalidArgument::InvalidArgument(const
scram::InvalidArgument&)

error.h:95:8: note:   no known conversion for argument 1 from 'const char [31]'

to 'const scram::InvalidArgument&'

element.cc: In member function 'void scram::mef::Element::label(std::string)':

element.cc:41:60: error: no matching function for call to
'scram::LogicError::LogicError(std::basic_string\<char\>)'

element.cc:41:60: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from
'std::basic_string\<char\>' to 'const scram::LogicError&'

element.cc:43:51: error: no matching function for call to
'scram::LogicError::LogicError(const char [28])'

element.cc:43:51: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from 'const char [28]'

 to 'const scram::LogicError&'

element.cc: In member function 'void
scram::mef::Element::AddAttribute(scram::mef::Attribute)':

element.cc:52:38: error: no matching function for call to
'scram::DuplicateArgumentError::DuplicateArgumentError(std::basic_string\<char\>)'

element.cc:52:38: note: candidate is:

error.h:79:8: note: scram::DuplicateArgumentError::DuplicateArgumentError(const

scram::DuplicateArgumentError&)

error.h:79:8: note:   no known conversion for argument 1 from 'std::basic_string

\<char\>' to 'const scram::DuplicateArgumentError&'

element.cc: In member function 'const scram::mef::Attribute& scram::mef::Element

::GetAttribute(const string&) const':

element.cc:68:64: error: no matching function for call to
'scram::LogicError::LogicError(std::basic_string\<char\>)'

element.cc:68:64: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from
'std::basic_string\<char\>' to 'const scram::LogicError&'

element.cc: In constructor 'scram::mef::Role::Role(scram::mef::RoleSpecifier,
std::string)':

element.cc:78:70: error: no matching function for call to
'scram::InvalidArgument::InvalidArgument(const char[42])'

element.cc:78:70: note: candidate is:

error.h:95:8: note: scram::InvalidArgument::InvalidArgument(const
scram::InvalidArgument&)

error.h:95:8: note:   no known conversion for argument 1 from 'const char [42]'
to 'const scram::InvalidArgument&'

element.cc: In constructor 'scram::mef::Id::Id(const scram::mef::Element&, const

 scram::mef::Role&)':

element.cc:87:52: error: no matching function for call to
'scram::LogicError::LogicError(const char [29])'

element.cc:87:52: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from 'const char [29]'

 to 'const scram::LogicError&'

element.cc:89:69: error: no matching function for call to
'scram::LogicError::LogicError(const char [46])'

element.cc:89:69: note: candidate is:

error.h:102:8: note: scram::LogicError::LogicError(const scram::LogicError&)

error.h:102:8: note:   no known conversion for argument 1 from 'const char [46]'

 to 'const scram::LogicError&'

make: \*\*\* [element.o] Error 1

Warning: running command 'make -f "C:/PROGRA\~1/R/R-32\~1.4/etc/i386/Makeconf"
-f

"C:/PROGRA\~1/R/R-32\~1.4/share/make/winshlib.mk" CXX='\$(CXX1X) \$(CXX1XSTD)'
CXXFL

AGS='\$(CXX1XFLAGS)' CXXPICFLAGS='\$(CXX1XPICFLAGS)'
SHLIB_LDFLAGS='\$(SHLIB_CXX1XL

DFLAGS)' SHLIB_LD='\$(SHLIB_CXX1XLD)' SHLIB="Rscram.dll" OBJECTS="element.o
error

.o"' had status 2

ERROR: compilation failed for package 'Rscram'

\* removing 'C:/Users/Dad/Documents/R/win-library/3.2/Rscram'

 

C:\\Rpack\>\^V
