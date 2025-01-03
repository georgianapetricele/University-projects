
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     STRING = 259,
     CHAR = 260,
     READ = 261,
     PRINT = 262,
     IF = 263,
     ELSE = 264,
     FOR = 265,
     WHILE = 266,
     RETURN = 267,
     START = 268,
     ARRAY = 269,
     plus = 270,
     minus = 271,
     mul = 272,
     division = 273,
     mod = 274,
     lessOrEqual = 275,
     moreOrEqual = 276,
     less = 277,
     more = 278,
     equal = 279,
     different = 280,
     eq = 281,
     leftCurlyBracket = 282,
     rightCurlyBracket = 283,
     leftRoundBracket = 284,
     rightRoundBracket = 285,
     leftBracket = 286,
     rightBracket = 287,
     colon = 288,
     semicolon = 289,
     comma = 290,
     apostrophe = 291,
     quote = 292,
     IDENTIFIER = 293,
     NUMBER_CONST = 294,
     STRING_CONST = 295,
     CHAR_CONST = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

