/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ICL_H_INCLUDED
# define YY_YY_ICL_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 30 "../vendor/ieee/ICL.y" /* yacc.c:1909  */

 
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif
 

#line 53 "ICL.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ACCESSLINK = 258,
    ACCESSTOGETHER = 259,
    ACTIVEPOLARITY = 260,
    ACTIVESIGNALS = 261,
    ADDRESSPORT = 262,
    ADDRESSVALUE = 263,
    ALIAS = 264,
    ALLOWBROADCASTONSCANINTERFACE = 265,
    AND = 266,
    ATTRIBUTE = 267,
    BSDLENTITIY = 268,
    CAPTUREENPORT = 269,
    CAPTURESOURCE = 270,
    CHAIN = 271,
    CLOCKMUX = 272,
    CLOCKPORT = 273,
    COLON = 274,
    COMMA = 275,
    DATAINPORT = 276,
    DATAMUX = 277,
    DATAOUTPORT = 278,
    DATAREGISTER = 279,
    DEFAULTLOADVALUE = 280,
    DIFFERENTIALINVOF = 281,
    DOLLAR = 282,
    DOT = 283,
    DOUBLE_COLON = 284,
    D_SUBST = 285,
    ENABLE = 286,
    ENUM = 287,
    EQUAL = 288,
    FALLING = 289,
    FREQDIVIDER = 290,
    FREQMULTIPLIER = 291,
    IAPPLYENDSTATE = 292,
    INPUTPORT = 293,
    INSTANCE = 294,
    LAUNCHEDGE = 295,
    LEFT_BRACE = 296,
    LEFT_BRACKET = 297,
    LEFT_PAREN = 298,
    LOCALPARAMETER = 299,
    LOGICSIGNAL = 300,
    LOGIC_AND = 301,
    LOGIC_EQUAL = 302,
    LOGIC_OR = 303,
    MINUS = 304,
    MODULE = 305,
    MSEC = 306,
    NAMESPACE = 307,
    NOT_EQUAL = 308,
    NSEC = 309,
    OF = 310,
    ONE = 311,
    ONEHOTDATAGROUP = 312,
    ONEHOTSCANGROUP = 313,
    PARAMETER = 314,
    PERCENT = 315,
    PERIOD = 316,
    PIPE = 317,
    PLUS = 318,
    PORT = 319,
    POS_INT = 320,
    PSEC = 321,
    READCALLBACK = 322,
    READDATASOURCE = 323,
    READENPORT = 324,
    REFENUM = 325,
    RESETPORT = 326,
    RESETVALUE = 327,
    RIGHT_BRACE = 328,
    RIGHT_BRACKET = 329,
    RIGHT_PAREN = 330,
    RISING = 331,
    R_SUBST = 332,
    SCALAR_ID = 333,
    SCANINPORT = 334,
    SCANINSOURCE = 335,
    SCANINTERFACE = 336,
    SCANMUX = 337,
    SCANOUTPORT = 338,
    SCANREGISTER = 339,
    SEC = 340,
    SELECTEDBY = 341,
    SELECTPORT = 342,
    SEMICOLON = 343,
    SHIFTENPORT = 344,
    SLASH = 345,
    SOURCE = 346,
    STAR = 347,
    STD_1149_1_2001 = 348,
    STD_1149_1_2013 = 349,
    STRING = 350,
    TCKPORT = 351,
    TILDE = 352,
    LOGIC_NOT = 353,
    TMSPORT = 354,
    TOCAPTUREENPORT = 355,
    TOCLOCKPORT = 356,
    TOIRSELECTPORT = 357,
    TORESETPORT = 358,
    TOSELECTPORT = 359,
    TOSHIFTENPORT = 360,
    TOTCKPORT = 361,
    TOTMSPORT = 362,
    TOTRSTPORT = 363,
    TOUPDATEENPORT = 364,
    TRSTPORT = 365,
    UNSIZED_BIN_NUM = 366,
    UNSIZED_DEC_NUM = 367,
    UNSIZED_HEX_NUM = 368,
    UPDATEENPORT = 369,
    USEC = 370,
    USENAMESPACE = 371,
    WRITECALLBACK = 372,
    WRITEDATASOURCE = 373,
    WRITEENPORT = 374,
    WRITEENSOURCE = 375,
    XOR = 376,
    ZERO = 377
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_ICL_H_INCLUDED  */
