
// Generated from icl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  iclLexer : public antlr4::Lexer {
public:
  enum {
    ACCESSLINK = 1, ACCESSTOGETHER = 2, ACTIVEPOLARITY = 3, ACTIVESIGNALS = 4, 
    ADDRESSPORT = 5, ADDRESSVALUE = 6, ALIAS = 7, ALLOWBROADCASTONSCANINTERFACE = 8, 
    UNSIZED_BIN_NUM = 9, UNSIZED_DEC_NUM = 10, UNSIZED_HEX_NUM = 11, AND = 12, 
    ATTRIBUTE = 13, BSDLENTITIY = 14, CAPTUREENPORT = 15, CAPTURESOURCE = 16, 
    CHAIN = 17, CLOCKMUX = 18, CLOCKPORT = 19, COLON = 20, COMMA = 21, DATAINPORT = 22, 
    DATAMUX = 23, DATAOUTPORT = 24, DATAREGISTER = 25, DEFAULTLOADVALUE = 26, 
    DIFFERENTIALINVOF = 27, DOLLAR = 28, DOT = 29, DOUBLE_COLON = 30, D_SUBST = 31, 
    ENABLE = 32, ENUM = 33, EQUAL = 34, FALLING = 35, FREQDIVIDER = 36, 
    FREQMULTIPLIER = 37, IAPPLYENDSTATE = 38, INPUTPORT = 39, INSTANCE = 40, 
    LAUNCHEDGE = 41, LEFT_BRACE = 42, LEFT_BRACKET = 43, LEFT_PAREN = 44, 
    LOCALPARAMETER = 45, LOGICSIGNAL = 46, LOGIC_AND = 47, LOGIC_EQUAL = 48, 
    LOGIC_OR = 49, MINUS = 50, MODULE = 51, MSEC = 52, NAMESPACE = 53, NOT_EQUAL = 54, 
    NSEC = 55, OF = 56, ZERO = 57, ONE = 58, ONEHOTDATAGROUP = 59, ONEHOTSCANGROUP = 60, 
    PARAMETER = 61, PERCENT = 62, PERIOD = 63, PIPE = 64, PLUS = 65, PORT = 66, 
    POS_INT = 67, PSEC = 68, READCALLBACK = 69, READDATASOURCE = 70, READENPORT = 71, 
    REFENUM = 72, RESETPORT = 73, RESETVALUE = 74, RIGHT_BRACE = 75, RIGHT_BRACKET = 76, 
    RIGHT_PAREN = 77, RISING = 78, R_SUBST = 79, SCANINPORT = 80, SCANINSOURCE = 81, 
    SCANINTERFACE = 82, SCANMUX = 83, SCANOUTPORT = 84, SCANREGISTER = 85, 
    SEC = 86, SELECTEDBY = 87, SELECTPORT = 88, SEMICOLON = 89, SHIFTENPORT = 90, 
    SLASH = 91, SOURCE = 92, STAR = 93, STD_1149_1_2001 = 94, STD_1149_1_2013 = 95, 
    STRING = 96, TCKPORT = 97, TILDE = 98, LOGIC_NOT = 99, TMSPORT = 100, 
    TOCAPTUREENPORT = 101, TOCLOCKPORT = 102, TOIRSELECTPORT = 103, TORESETPORT = 104, 
    TOSELECTPORT = 105, TOSHIFTENPORT = 106, TOTCKPORT = 107, TOTMSPORT = 108, 
    TOTRSTPORT = 109, TOUPDATEENPORT = 110, TRSTPORT = 111, UPDATEENPORT = 112, 
    USEC = 113, USENAMESPACE = 114, WRITECALLBACK = 115, WRITEDATASOURCE = 116, 
    WRITEENPORT = 117, WRITEENSOURCE = 118, SCALAR_ID = 119, XOR = 120, 
    SPACE = 121, ML_COMMENT = 122, SL_COMMENT = 123
  };

  iclLexer(antlr4::CharStream *input);
  ~iclLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

