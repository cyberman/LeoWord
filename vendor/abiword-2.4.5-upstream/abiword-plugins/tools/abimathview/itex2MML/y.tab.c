/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse itex2MML_yyparse
#define yylex   itex2MML_yylex
#define yyerror itex2MML_yyerror
#define yylval  itex2MML_yylval
#define yychar  itex2MML_yychar
#define yydebug itex2MML_yydebug
#define yynerrs itex2MML_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TEXOVER = 258,
     CHAR = 259,
     STARTMATH = 260,
     STARTDMATH = 261,
     ENDMATH = 262,
     MI = 263,
     MIB = 264,
     MN = 265,
     MO = 266,
     SUP = 267,
     SUB = 268,
     MROWOPEN = 269,
     MROWCLOSE = 270,
     LEFT = 271,
     RIGHT = 272,
     BIG = 273,
     BBIG = 274,
     BIGG = 275,
     BBIGG = 276,
     BIGL = 277,
     BBIGL = 278,
     BIGGL = 279,
     BBIGGL = 280,
     FRAC = 281,
     TFRAC = 282,
     MATHOP = 283,
     MOP = 284,
     MOL = 285,
     MOF = 286,
     PERIODDELIM = 287,
     OTHERDELIM = 288,
     LEFTDELIM = 289,
     RIGHTDELIM = 290,
     MOS = 291,
     MOB = 292,
     SQRT = 293,
     ROOT = 294,
     BINOM = 295,
     UNDER = 296,
     OVER = 297,
     OVERBRACE = 298,
     UNDERBRACE = 299,
     UNDEROVER = 300,
     TENSOR = 301,
     MULTI = 302,
     ARRAY = 303,
     COLSEP = 304,
     ROWSEP = 305,
     ARRAYOPTS = 306,
     COLLAYOUT = 307,
     COLALIGN = 308,
     ROWALIGN = 309,
     ALIGN = 310,
     EQROWS = 311,
     EQCOLS = 312,
     ROWLINES = 313,
     COLLINES = 314,
     FRAME = 315,
     PADDING = 316,
     ATTRLIST = 317,
     ITALICS = 318,
     BOLD = 319,
     RM = 320,
     BB = 321,
     ST = 322,
     END = 323,
     BBLOWERCHAR = 324,
     BBUPPERCHAR = 325,
     CALCHAR = 326,
     FRAKCHAR = 327,
     CAL = 328,
     FRAK = 329,
     ROWOPTS = 330,
     TEXTSIZE = 331,
     SCSIZE = 332,
     SCSCSIZE = 333,
     DISPLAY = 334,
     TEXTSTY = 335,
     TEXTBOX = 336,
     TEXTSTRING = 337,
     CELLOPTS = 338,
     ROWSPAN = 339,
     COLSPAN = 340,
     THINSPACE = 341,
     MEDSPACE = 342,
     THICKSPACE = 343,
     QUAD = 344,
     QQUAD = 345,
     NEGSPACE = 346,
     PHANTOM = 347,
     HREF = 348,
     UNKNOWNCHAR = 349,
     EMPTYMROW = 350,
     STATLINE = 351,
     TOGGLE = 352,
     FGHIGHLIGHT = 353,
     BGHIGHLIGHT = 354,
     SPACE = 355,
     INTONE = 356,
     INTTWO = 357,
     INTTHREE = 358,
     BAR = 359,
     WIDEBAR = 360,
     VEC = 361,
     WIDEVEC = 362,
     HAT = 363,
     WIDEHAT = 364,
     CHECK = 365,
     WIDECHECK = 366,
     TILDE = 367,
     WIDETILDE = 368,
     DOT = 369,
     DDOT = 370,
     UNARYMINUS = 371,
     UNARYPLUS = 372,
     BEGINENV = 373,
     ENDENV = 374,
     MATRIX = 375,
     PMATRIX = 376,
     BMATRIX = 377,
     BBMATRIX = 378,
     VMATRIX = 379,
     VVMATRIX = 380,
     SMALLMATRIX = 381,
     CASES = 382,
     ALIGNED = 383,
     SUBSTACK = 384,
     PMOD = 385,
     RMCHAR = 386,
     COLOR = 387,
     BGCOLOR = 388
   };
#endif
/* Tokens.  */
#define TEXOVER 258
#define CHAR 259
#define STARTMATH 260
#define STARTDMATH 261
#define ENDMATH 262
#define MI 263
#define MIB 264
#define MN 265
#define MO 266
#define SUP 267
#define SUB 268
#define MROWOPEN 269
#define MROWCLOSE 270
#define LEFT 271
#define RIGHT 272
#define BIG 273
#define BBIG 274
#define BIGG 275
#define BBIGG 276
#define BIGL 277
#define BBIGL 278
#define BIGGL 279
#define BBIGGL 280
#define FRAC 281
#define TFRAC 282
#define MATHOP 283
#define MOP 284
#define MOL 285
#define MOF 286
#define PERIODDELIM 287
#define OTHERDELIM 288
#define LEFTDELIM 289
#define RIGHTDELIM 290
#define MOS 291
#define MOB 292
#define SQRT 293
#define ROOT 294
#define BINOM 295
#define UNDER 296
#define OVER 297
#define OVERBRACE 298
#define UNDERBRACE 299
#define UNDEROVER 300
#define TENSOR 301
#define MULTI 302
#define ARRAY 303
#define COLSEP 304
#define ROWSEP 305
#define ARRAYOPTS 306
#define COLLAYOUT 307
#define COLALIGN 308
#define ROWALIGN 309
#define ALIGN 310
#define EQROWS 311
#define EQCOLS 312
#define ROWLINES 313
#define COLLINES 314
#define FRAME 315
#define PADDING 316
#define ATTRLIST 317
#define ITALICS 318
#define BOLD 319
#define RM 320
#define BB 321
#define ST 322
#define END 323
#define BBLOWERCHAR 324
#define BBUPPERCHAR 325
#define CALCHAR 326
#define FRAKCHAR 327
#define CAL 328
#define FRAK 329
#define ROWOPTS 330
#define TEXTSIZE 331
#define SCSIZE 332
#define SCSCSIZE 333
#define DISPLAY 334
#define TEXTSTY 335
#define TEXTBOX 336
#define TEXTSTRING 337
#define CELLOPTS 338
#define ROWSPAN 339
#define COLSPAN 340
#define THINSPACE 341
#define MEDSPACE 342
#define THICKSPACE 343
#define QUAD 344
#define QQUAD 345
#define NEGSPACE 346
#define PHANTOM 347
#define HREF 348
#define UNKNOWNCHAR 349
#define EMPTYMROW 350
#define STATLINE 351
#define TOGGLE 352
#define FGHIGHLIGHT 353
#define BGHIGHLIGHT 354
#define SPACE 355
#define INTONE 356
#define INTTWO 357
#define INTTHREE 358
#define BAR 359
#define WIDEBAR 360
#define VEC 361
#define WIDEVEC 362
#define HAT 363
#define WIDEHAT 364
#define CHECK 365
#define WIDECHECK 366
#define TILDE 367
#define WIDETILDE 368
#define DOT 369
#define DDOT 370
#define UNARYMINUS 371
#define UNARYPLUS 372
#define BEGINENV 373
#define ENDENV 374
#define MATRIX 375
#define PMATRIX 376
#define BMATRIX 377
#define BBMATRIX 378
#define VMATRIX 379
#define VVMATRIX 380
#define SMALLMATRIX 381
#define CASES 382
#define ALIGNED 383
#define SUBSTACK 384
#define PMOD 385
#define RMCHAR 386
#define COLOR 387
#define BGCOLOR 388




/* Copy the first part of user declarations.  */
#line 5 "itex2MML.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "itex2MML.h"

#define YYSTYPE char *
#define YYPARSE_PARAM_TYPE char **
#define YYPARSE_PARAM ret_str

#define yytext itex2MML_yytext

 extern int yylex ();

 extern char * yytext;

 static void itex2MML_default_error (const char * msg)
   {
     if (msg)
       fprintf(stderr, "Line: %d Error: %s\n", itex2MML_lineno, msg);
   }

 void (*itex2MML_error) (const char * msg) = itex2MML_default_error;

 static void yyerror (char * s)
   {
     char * msg = itex2MML_copy3 (s, " at token ", yytext);
     if (itex2MML_error)
       (*itex2MML_error) (msg);
     itex2MML_free_string (msg);
   }

 /* Note: If length is 0, then buffer is treated like a string; otherwise only length bytes are written.
  */
 static void itex2MML_default_write (const char * buffer, unsigned long length)
   {
     if (buffer)
       {
	 if (length)
	   fwrite (buffer, 1, length, stdout);
	 else
	   fputs (buffer, stdout);
       }
   }

 void (*itex2MML_write) (const char * buffer, unsigned long length) = itex2MML_default_write;

 static void itex2MML_default_write_mathml (const char * mathml)
   {
     if (itex2MML_write)
       (*itex2MML_write) (mathml, 0);
   }

 void (*itex2MML_write_mathml) (const char * mathml) = itex2MML_default_write_mathml;

 char * itex2MML_empty_string = "";

 /* Create a copy of a string, adding space for extra chars
  */
 char * itex2MML_copy_string_extra (const char * str, unsigned extra)
   {
     char * copy = malloc(extra + (str ? strlen (str) : 0) + 1);
     if (copy)
       {
	 if (str)
	   strcpy(copy, str);
	 else
	   copy[0] = 0;
       }
     return copy ? copy : itex2MML_empty_string;
   }

 /* Create a copy of a string, appending two strings
  */
 char * itex2MML_copy3 (const char * first, const char * second, const char * third)
   {
     int  first_length =  first ? strlen( first) : 0;
     int second_length = second ? strlen(second) : 0;
     int  third_length =  third ? strlen( third) : 0;

     char * copy = malloc(first_length + second_length + third_length + 1);

     if (copy)
       {
	 if (first)
	   strcpy(copy, first);
	 else
	   copy[0] = 0;

	 if (second) strcat(copy, second);
	 if ( third) strcat(copy,  third);
       }
     return copy ? copy : itex2MML_empty_string;
   }

 /* Create a copy of a string, appending a second string
  */
 char * itex2MML_copy2 (const char * first, const char * second)
   {
     return itex2MML_copy3(first, second, 0);
   }

 /* Create a copy of a string
  */
 char * itex2MML_copy_string (const char * str)
   {
     return itex2MML_copy3(str, 0, 0);
   }

 /* Create a copy of a string, escaping unsafe characters for XML
  */
 char * itex2MML_copy_escaped (const char * str)
   {
     unsigned long length = 0;

     const char * ptr1 = str;

     char * ptr2 = 0;
     char * copy = 0;

     if ( str == 0) return itex2MML_empty_string;
     if (*str == 0) return itex2MML_empty_string;

     while (*ptr1)
       {
	 switch (*ptr1)
	   {
	   case '<':  /* &lt;   */
	   case '>':  /* &gt;   */
	     length += 4;
	     break;
	   case '&':  /* &amp;  */
	     length += 5;
	     break;
	   case '\'': /* &apos; */
	   case '"':  /* &quot; */
	   case '-':  /* &#x2d; */
	     length += 6;
	     break;
	   default:
	     length += 1;
	     break;
	   }
	 ++ptr1;
       }

     copy = malloc (length + 1);

     if (copy)
       {
	 ptr1 = str;
	 ptr2 = copy;

	 while (*ptr1)
	   {
	     switch (*ptr1)
	       {
	       case '<':
		 strcpy (ptr2, "&lt;");
		 ptr2 += 4;
		 break;
	       case '>':
		 strcpy (ptr2, "&gt;");
		 ptr2 += 4;
		 break;
	       case '&':  /* &amp;  */
		 strcpy (ptr2, "&amp;");
		 ptr2 += 5;
		 break;
	       case '\'': /* &apos; */
		 strcpy (ptr2, "&apos;");
		 ptr2 += 6;
		 break;
	       case '"':  /* &quot; */
		 strcpy (ptr2, "&quot;");
		 ptr2 += 6;
		 break;
	       case '-':  /* &#x2d; */
		 strcpy (ptr2, "&#x2d;");
		 ptr2 += 6;
		 break;
	       default:
		 *ptr2++ = *ptr1;
		 break;
	       }
	     ++ptr1;
	   }
	 *ptr2 = 0;
       }
     return copy ? copy : itex2MML_empty_string;
   }

 void itex2MML_free_string (char * str)
   {
     if (str && str != itex2MML_empty_string)
       free(str);
   }



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 571 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  161
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2503

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  134
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  102
/* YYNRULES -- Number of rules. */
#define YYNRULES  267
/* YYNRULES -- Number of states. */
#define YYNSTATES  464

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   388

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    13,    16,    18,
      21,    24,    28,    32,    34,    37,    43,    47,    53,    57,
      63,    67,    73,    77,    83,    89,    93,    97,   100,   103,
     105,   107,   109,   111,   113,   115,   117,   119,   121,   123,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   167,   169,   171,   173,   175,   177,   179,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   217,   221,   225,   227,   229,
     231,   233,   236,   239,   242,   245,   248,   251,   254,   257,
     260,   263,   266,   269,   272,   275,   278,   281,   284,   285,
     291,   294,   297,   300,   303,   306,   309,   312,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   348,   351,   353,   364,   368,
     372,   376,   380,   384,   388,   391,   394,   397,   400,   403,
     406,   409,   412,   417,   419,   422,   427,   429,   432,   434,
     436,   441,   443,   446,   448,   453,   455,   458,   460,   462,
     464,   466,   468,   470,   472,   475,   479,   485,   489,   498,
     505,   512,   514,   517,   522,   525,   528,   532,   536,   540,
     543,   549,   555,   559,   562,   565,   568,   571,   574,   577,
     580,   583,   586,   589,   592,   595,   598,   601,   604,   608,
     612,   616,   621,   627,   633,   639,   645,   651,   657,   663,
     669,   675,   680,   685,   694,   696,   699,   701,   703,   705,
     707,   709,   711,   713,   715,   717,   719,   722,   725,   728,
     731,   734,   737,   740,   743,   746,   749,   751,   755,   757,
     759,   761,   765,   771,   773,   776,   778,   780,   781,   783,
     789,   791,   794,   796,   798,   800,   802,   805
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     135,     0,    -1,   136,    -1,    -1,   137,    -1,   138,    -1,
     136,   137,    -1,   136,   138,    -1,     4,    -1,     5,     7,
      -1,     6,     7,    -1,     5,   139,     7,    -1,     6,   139,
       7,    -1,   140,    -1,   139,   140,    -1,   152,    13,   141,
      12,   141,    -1,   152,    13,   141,    -1,   152,    12,   141,
      13,   141,    -1,   152,    12,   141,    -1,   150,    13,   141,
      12,   141,    -1,   150,    13,   141,    -1,   150,    12,   141,
      13,   141,    -1,   150,    12,   141,    -1,   141,    13,   141,
      12,   141,    -1,   141,    12,   141,    13,   141,    -1,   141,
      13,   141,    -1,   141,    12,   141,    -1,    13,   141,    -1,
      12,   141,    -1,   141,    -1,   212,    -1,   147,    -1,   148,
      -1,   150,    -1,   149,    -1,   151,    -1,   153,    -1,   188,
      -1,   189,    -1,   192,    -1,   195,    -1,   205,    -1,   206,
      -1,   207,    -1,   208,    -1,   198,    -1,   199,    -1,   204,
      -1,   200,    -1,   201,    -1,   203,    -1,   202,    -1,   197,
      -1,   196,    -1,   209,    -1,   154,    -1,   162,    -1,   163,
      -1,   164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,
      -1,   169,    -1,   170,    -1,   171,    -1,   174,    -1,   177,
      -1,   155,    -1,   161,    -1,   180,    -1,   181,    -1,   182,
      -1,   183,    -1,   184,    -1,   185,    -1,   186,    -1,   187,
      -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,
      -1,   194,    -1,    14,   141,    15,    -1,    14,   139,    15,
      -1,   142,   139,   143,    -1,   210,    -1,   211,    -1,   193,
      -1,   146,    -1,    16,    34,    -1,    16,    33,    -1,    16,
      32,    -1,    17,    35,    -1,    17,    33,    -1,    17,    32,
      -1,    18,    34,    -1,    18,    35,    -1,    18,    33,    -1,
      19,    34,    -1,    19,    35,    -1,    19,    33,    -1,    20,
      34,    -1,    20,    35,    -1,    20,    33,    -1,    21,    34,
      -1,    21,    35,    -1,    -1,    21,    33,   145,    22,    34,
      -1,    22,    33,    -1,    23,    34,    -1,    23,    33,    -1,
      24,    34,    -1,    24,    33,    -1,    25,    34,    -1,    25,
      33,    -1,    94,    -1,   116,    -1,   117,    -1,     8,    -1,
       9,    -1,    10,    -1,    37,    -1,   152,    -1,   144,    -1,
      11,    -1,    30,    -1,    35,    -1,    34,    -1,    33,    -1,
      31,    -1,    32,    -1,    36,    -1,    29,    -1,    28,    82,
      -1,    95,    -1,   100,    67,   101,    68,    67,   102,    68,
      67,   103,    68,    -1,    96,    82,   141,    -1,    97,   141,
     141,    -1,    98,    62,   141,    -1,    99,    62,   141,    -1,
     132,    62,   139,    -1,   133,    62,   139,    -1,    81,    82,
      -1,    79,   141,    -1,    80,   141,    -1,    76,   141,    -1,
      77,   141,    -1,    78,   141,    -1,    63,   141,    -1,    64,
     141,    -1,    65,    67,   170,    68,    -1,   131,    -1,   170,
     131,    -1,    66,    67,   172,    68,    -1,   173,    -1,   172,
     173,    -1,    69,    -1,    70,    -1,    74,    67,   175,    68,
      -1,   176,    -1,   175,   176,    -1,    72,    -1,    73,    67,
     178,    68,    -1,   179,    -1,   178,   179,    -1,    71,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,    92,   141,    -1,    93,    82,   141,    -1,    46,
     141,    14,   190,    15,    -1,    46,   141,   190,    -1,    47,
      14,   190,    15,   141,    14,   190,    15,    -1,    47,    14,
     190,    15,   141,    95,    -1,    47,    95,   141,    14,   190,
      15,    -1,   191,    -1,   190,   191,    -1,    13,   141,    12,
     141,    -1,    13,   141,    -1,    12,   141,    -1,    13,    12,
     141,    -1,    26,   141,   141,    -1,    27,   141,   141,    -1,
     130,   141,    -1,    14,   139,     3,   139,    15,    -1,   142,
     139,     3,   139,   143,    -1,    40,   141,   141,    -1,    44,
     141,    -1,    43,   141,    -1,   104,   141,    -1,   105,   141,
      -1,   106,   141,    -1,   107,   141,    -1,   114,   141,    -1,
     115,   141,    -1,   112,   141,    -1,   113,   141,    -1,   110,
     141,    -1,   111,   141,    -1,   108,   141,    -1,   109,   141,
      -1,    38,   141,    -1,    39,   141,   141,    -1,    41,   141,
     141,    -1,    42,   141,   141,    -1,    45,   141,   141,   141,
      -1,   118,   120,   225,   119,   120,    -1,   118,   121,   225,
     119,   121,    -1,   118,   122,   225,   119,   122,    -1,   118,
     124,   225,   119,   124,    -1,   118,   123,   225,   119,   123,
      -1,   118,   125,   225,   119,   125,    -1,   118,   126,   225,
     119,   126,    -1,   118,   127,   225,   119,   127,    -1,   118,
     128,   225,   119,   128,    -1,   129,    14,   225,    15,    -1,
      48,    14,   225,    15,    -1,    48,    14,    51,    14,   213,
      15,   225,    15,    -1,   214,    -1,   213,   214,    -1,   215,
      -1,   216,    -1,   217,    -1,   218,    -1,   219,    -1,   220,
      -1,   221,    -1,   222,    -1,   223,    -1,   224,    -1,    52,
      62,    -1,    53,    62,    -1,    54,    62,    -1,    55,    62,
      -1,    56,    62,    -1,    57,    62,    -1,    58,    62,    -1,
      59,    62,    -1,    60,    62,    -1,    61,    62,    -1,   226,
      -1,   225,    50,   226,    -1,   227,    -1,   228,    -1,   231,
      -1,   227,    49,   231,    -1,    75,    14,   229,    15,   227,
      -1,   230,    -1,   229,   230,    -1,   216,    -1,   217,    -1,
      -1,   139,    -1,    83,    14,   232,    15,   139,    -1,   233,
      -1,   232,   233,    -1,   216,    -1,   217,    -1,   234,    -1,
     235,    -1,    84,    62,    -1,    85,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   211,   211,   214,   215,   216,   217,   218,   220,   222,
     223,   224,   237,   251,   255,   261,   280,   294,   313,   327,
     346,   360,   379,   393,   403,   413,   420,   427,   431,   435,
     440,   441,   442,   443,   444,   448,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   504,   508,   516,   517,   518,
     519,   521,   526,   531,   537,   541,   545,   550,   555,   559,
     563,   568,   572,   576,   581,   585,   589,   594,   598,   598,
     607,   612,   617,   622,   627,   632,   637,   643,   647,   651,
     655,   657,   663,   665,   671,   672,   673,   678,   683,   687,
     692,   696,   700,   704,   709,   714,   720,   724,   735,   743,
     751,   759,   767,   774,   782,   787,   792,   797,   802,   807,
     812,   817,   822,   827,   831,   837,   842,   846,   852,   856,
     861,   866,   870,   876,   881,   886,   890,   896,   901,   905,
     909,   913,   917,   921,   925,   930,   938,   945,   953,   963,
     972,   980,   984,   990,   995,   999,  1003,  1008,  1015,  1023,
    1028,  1035,  1049,  1057,  1062,  1067,  1071,  1076,  1080,  1085,
    1090,  1095,  1099,  1104,  1108,  1113,  1117,  1122,  1127,  1135,
    1143,  1151,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1197,  1202,  1206,  1214,  1218,  1224,  1228,  1232,  1236,
    1240,  1244,  1248,  1252,  1256,  1260,  1265,  1270,  1275,  1280,
    1285,  1290,  1295,  1300,  1305,  1310,  1317,  1321,  1327,  1331,
    1336,  1340,  1346,  1354,  1358,  1364,  1368,  1373,  1376,  1380,
    1388,  1392,  1398,  1402,  1406,  1410,  1415,  1420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXOVER", "CHAR", "STARTMATH",
  "STARTDMATH", "ENDMATH", "MI", "MIB", "MN", "MO", "SUP", "SUB",
  "MROWOPEN", "MROWCLOSE", "LEFT", "RIGHT", "BIG", "BBIG", "BIGG", "BBIGG",
  "BIGL", "BBIGL", "BIGGL", "BBIGGL", "FRAC", "TFRAC", "MATHOP", "MOP",
  "MOL", "MOF", "PERIODDELIM", "OTHERDELIM", "LEFTDELIM", "RIGHTDELIM",
  "MOS", "MOB", "SQRT", "ROOT", "BINOM", "UNDER", "OVER", "OVERBRACE",
  "UNDERBRACE", "UNDEROVER", "TENSOR", "MULTI", "ARRAY", "COLSEP",
  "ROWSEP", "ARRAYOPTS", "COLLAYOUT", "COLALIGN", "ROWALIGN", "ALIGN",
  "EQROWS", "EQCOLS", "ROWLINES", "COLLINES", "FRAME", "PADDING",
  "ATTRLIST", "ITALICS", "BOLD", "RM", "BB", "ST", "END", "BBLOWERCHAR",
  "BBUPPERCHAR", "CALCHAR", "FRAKCHAR", "CAL", "FRAK", "ROWOPTS",
  "TEXTSIZE", "SCSIZE", "SCSCSIZE", "DISPLAY", "TEXTSTY", "TEXTBOX",
  "TEXTSTRING", "CELLOPTS", "ROWSPAN", "COLSPAN", "THINSPACE", "MEDSPACE",
  "THICKSPACE", "QUAD", "QQUAD", "NEGSPACE", "PHANTOM", "HREF",
  "UNKNOWNCHAR", "EMPTYMROW", "STATLINE", "TOGGLE", "FGHIGHLIGHT",
  "BGHIGHLIGHT", "SPACE", "INTONE", "INTTWO", "INTTHREE", "BAR", "WIDEBAR",
  "VEC", "WIDEVEC", "HAT", "WIDEHAT", "CHECK", "WIDECHECK", "TILDE",
  "WIDETILDE", "DOT", "DDOT", "UNARYMINUS", "UNARYPLUS", "BEGINENV",
  "ENDENV", "MATRIX", "PMATRIX", "BMATRIX", "BBMATRIX", "VMATRIX",
  "VVMATRIX", "SMALLMATRIX", "CASES", "ALIGNED", "SUBSTACK", "PMOD",
  "RMCHAR", "COLOR", "BGCOLOR", "$accept", "doc", "xmlmmlTermList", "char",
  "expression", "compoundTermList", "compoundTerm", "closedTerm", "left",
  "right", "bigdelim", "@1", "unrecognized", "unaryminus", "unaryplus",
  "mi", "mib", "mn", "mob", "mo", "emptymrow", "space", "statusline",
  "toggle", "fghighlight", "bghighlight", "color", "textstring",
  "displaystyle", "textstyle", "textsize", "scriptsize",
  "scriptscriptsize", "italics", "bold", "roman", "rmchars", "bbold",
  "bbletters", "bbletter", "frak", "frakletters", "frakletter", "cal",
  "calletters", "calletter", "thinspace", "medspace", "thickspace", "quad",
  "qquad", "negspace", "phantom", "href", "tensor", "multi", "subsupList",
  "subsupTerm", "mfrac", "pmod", "texover", "binom", "munderbrace",
  "moverbrace", "bar", "vec", "dot", "ddot", "tilde", "check", "hat",
  "msqrt", "mroot", "munder", "mover", "munderover", "mathenv", "substack",
  "array", "arrayopts", "anarrayopt", "collayout", "colalign", "rowalign",
  "align", "eqrows", "eqcols", "rowlines", "collines", "frame", "padding",
  "tableRowList", "tableRow", "simpleTableRow", "optsTableRow", "rowopts",
  "arowopt", "tableCell", "cellopts", "acellopt", "rowspan", "colspan", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   134,   135,   136,   136,   136,   136,   136,   137,   138,
     138,   138,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   142,   143,   143,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   144,
     144,   144,   144,   144,   144,   144,   144,   146,   147,   148,
     149,   150,   151,   152,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   154,   155,   156,   157,
     158,   159,   160,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   170,   171,   172,   172,   173,   173,
     174,   175,   175,   176,   177,   178,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   188,   189,   189,
     189,   190,   190,   191,   191,   191,   191,   192,   192,   193,
     194,   194,   195,   196,   197,   198,   198,   199,   199,   200,
     201,   202,   202,   203,   203,   204,   204,   205,   206,   207,
     208,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   211,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   225,   226,   226,
     227,   227,   228,   229,   229,   230,   230,   231,   231,   231,
     232,   232,   233,   233,   233,   233,   234,   235
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     1,     1,     2,     2,     1,     2,
       2,     3,     3,     1,     2,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     5,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     5,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,    10,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     2,     4,     1,     2,     1,     1,
       4,     1,     2,     1,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     5,     3,     8,     6,
       6,     1,     2,     4,     2,     2,     3,     3,     3,     2,
       5,     5,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     4,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     4,     4,     8,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     5,     1,     2,     1,     1,     0,     1,     5,
       1,     2,     1,     1,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       3,     8,     0,     0,     0,     2,     4,     5,     9,   120,
     121,   122,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   127,
     131,   132,   130,   129,   128,   133,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   169,   170,   171,   172,   173,     0,     0,   117,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,     0,
       0,     0,   153,     0,     0,     0,    13,    29,     0,   125,
      90,    31,    32,    34,    33,    35,   124,    36,    55,    68,
      78,    79,    80,    81,    82,    69,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    70,    71,
      72,    73,    74,    75,    76,    77,    37,    38,    39,    89,
      83,    40,    53,    52,    45,    46,    48,    49,    51,    50,
      47,    41,    42,    43,    44,    54,    87,    88,    30,    10,
       0,     1,     6,     7,    28,    33,   124,    27,     0,    29,
      93,    92,    91,    99,    97,    98,   102,   100,   101,   105,
     103,   104,   108,   106,   107,   110,   112,   111,   114,   113,
     116,   115,     0,     0,   135,   207,     0,     0,     0,     0,
     194,   193,     0,     0,     0,     0,   257,   150,   151,     0,
       0,     0,     0,   147,   148,   149,   145,   146,   144,   174,
       0,     0,     0,     0,     0,     0,   195,   196,   197,   198,
     205,   206,   203,   204,   201,   202,   199,   200,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   189,     0,
       0,    11,    14,     0,     0,     0,     0,     0,     0,     0,
     154,    12,     0,    85,    84,     0,   187,   188,   208,   192,
     209,   210,     0,     0,     0,     0,   177,   181,     0,     0,
       0,     0,     0,   258,     0,   246,   248,   249,   250,     0,
     158,   159,     0,   156,   167,     0,   165,   163,     0,   161,
     175,   138,   139,   140,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,    26,    25,
       0,     0,    86,    22,    20,    18,    16,     0,     0,   211,
     185,     0,   184,     0,   182,     0,     0,     0,     0,     0,
     222,   257,   257,   152,   155,   157,   164,   166,   160,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,    96,    95,    94,     0,     0,     0,
       0,   190,   109,   186,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     255,   256,     0,   253,     0,     0,   262,   263,     0,   260,
     264,   265,   247,   251,     0,   212,   213,   214,   216,   215,
     217,   218,   219,   220,    24,    23,   191,    21,    19,    17,
      15,   183,     0,   179,   180,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   257,   225,   257,   254,   266,
     267,     0,   261,     0,     0,     0,   252,   259,     0,   178,
     223,     0,     0,   137
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     4,     5,     6,     7,   283,    96,    97,    98,   322,
      99,   265,   100,   101,   102,   103,   165,   105,   166,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   292,   293,
     126,   298,   299,   127,   295,   296,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   276,   277,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   284,   285,   286,   287,   402,   403,   288,   408,   409,
     410,   411
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -328
static const short int yypact[] =
{
     120,  -328,   981,  1108,    36,   120,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  2370,  2370,  2118,    97,    99,   126,   129,
     134,    21,   143,   145,   147,  2370,  2370,    13,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  2370,  2370,  2370,
    2370,  2370,  2370,  2370,  2370,  2370,    -7,    50,  2370,  2370,
       6,    17,    30,    55,  2370,  2370,  2370,  2370,  2370,    53,
    -328,  -328,  -328,  -328,  -328,  -328,  2370,    75,  -328,  -328,
      83,  2370,     5,    65,   132,  2370,  2370,  2370,  2370,  2370,
    2370,  2370,  2370,  2370,  2370,  2370,  2370,  -328,  -328,    28,
      85,  2370,  -328,   130,   138,  1235,  -328,   171,  2118,  -328,
    -328,  -328,  -328,  -328,   174,  -328,   176,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,    70,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    1362,  -328,  -328,  -328,  -328,  -328,  -328,  -328,   723,    31,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  2370,  2370,  -328,  -328,  2370,  2370,  2370,  2370,
    -328,  -328,  2370,   158,   178,  2370,  1488,  -328,  -328,    71,
     125,   135,   124,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    2370,  2370,  2370,  2370,  2370,   102,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  1614,  1614,
    1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,  -328,  2118,
    2118,  -328,  -328,  2370,  2370,   854,  2370,  2370,  2370,  2370,
    -328,  -328,  2118,  -328,  -328,   183,  -328,  -328,  -328,  -328,
    -328,  -328,  2370,  2370,  2244,   178,   178,  -328,    38,   193,
     194,   195,   196,  2118,    24,  -328,   162,  -328,  -328,   -39,
    -328,  -328,   105,  -328,  -328,    -9,  -328,  -328,   -27,  -328,
    -328,  -328,  -328,  -328,  -328,   146,   -41,   -36,   -34,   -18,
     -17,   -16,   -15,   -13,   -12,    27,  2118,  2118,   199,   201,
    2118,    33,  -328,   202,   204,   205,   207,  1740,   186,  -328,
    -328,  2370,   209,    45,  -328,  2370,   178,    86,   144,     2,
    -328,  1614,  1866,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
     150,   107,   101,   103,   109,   104,   110,   100,   119,   127,
    -328,  2370,  2370,  1992,  -328,  -328,  -328,  2370,  2370,  2370,
    2370,  -328,  -328,  -328,  2370,  -328,    -6,    57,   167,   168,
     172,   190,   192,   197,   211,   214,   215,   216,    56,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,    37,  -328,   217,   220,  -328,  -328,    -5,  -328,
    -328,  -328,  -328,  -328,   154,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,   178,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  1614,  -328,  1866,  -328,  -328,
    -328,  2118,  -328,   189,   106,    32,   162,  2118,   191,  -328,
    -328,   180,   218,  -328
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -328,  -328,  -328,   256,   283,     0,   -32,   355,  -328,   -74,
    -328,  -328,  -328,  -328,  -328,  -328,    -2,  -328,    25,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,    81,  -328,  -328,    -1,
    -328,  -328,    -4,  -328,  -328,    -3,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -199,  -272,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
     -95,  -328,  -327,  -308,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -221,   -45,  -150,  -328,  -328,  -104,   -43,  -328,  -108,
    -328,  -328
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     104,   104,    95,   160,   334,   278,   334,   204,   432,   341,
     451,   400,   406,   104,   341,   168,   341,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   106,   106,   343,
     401,   407,   341,   341,   341,   341,   161,   341,   341,   340,
     106,   348,   360,   253,   254,   297,   264,   460,   379,   380,
     273,   274,   447,   335,   185,   379,   380,   273,   274,   346,
     375,   334,   294,   252,   206,   364,   365,   223,   366,   273,
     274,   445,   434,   209,   341,   400,   333,   341,   351,   404,
     405,   406,   341,   352,   210,   353,   404,   405,   205,   433,
     379,   380,   260,   104,   401,   194,   104,   211,   255,   247,
     407,   354,   355,   356,   357,   334,   358,   359,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   273,   274,
     106,   459,   212,   106,     1,     2,     3,   224,   252,   170,
     171,   172,   173,   174,   175,   218,   252,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   220,   104,   176,
     177,   178,   179,   180,   181,   221,   104,   182,   183,   184,
     273,   274,   275,   344,   290,   291,   186,   187,   188,   189,
     190,   191,   334,   253,   254,   106,   256,   257,   258,   259,
     273,   274,   249,   106,   290,   291,   297,   379,   380,   225,
     250,   260,    92,   305,   104,   328,   294,   336,   337,   338,
     339,   342,   361,   362,   350,   367,   368,   414,   369,   370,
     372,   374,   416,   252,   455,   417,   421,   415,   419,   435,
     436,   106,   418,   454,   437,   420,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   422,   104,   104,   316,
     317,   252,   438,   104,   439,   423,   453,   458,   461,   440,
     104,   162,   327,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   441,   106,   106,   442,   443,   444,   449,
     106,   104,   450,   462,   252,   252,   463,   106,   163,   426,
     289,   345,   347,   446,   349,   252,   412,   456,   448,   413,
     452,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,     0,   104,   104,     0,     0,   104,     0,
     363,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,   104,
     104,   106,   106,     0,     0,   106,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,   106,   106,   164,   167,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,   207,   208,     0,     0,     0,     0,   213,
     214,   215,   216,   217,     0,     0,     0,     0,     0,     0,
       0,   219,     0,     0,     0,   252,   222,     0,     0,     0,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   104,     0,   104,   248,     0,     0,   104,
       0,   457,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,   106,     0,     0,     0,   106,     0,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,     0,
       0,   268,   269,   270,   271,     0,     0,   272,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,   301,   302,   303,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,   319,
       0,   323,   324,   325,   326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,   330,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,     0,     0,     0,
     376,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   424,   425,     0,     0,
       0,     0,   427,   428,   429,   430,   262,     0,     0,   431,
       0,     9,    10,    11,    12,    13,    14,    15,   263,    16,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,    52,    53,     0,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,   320,     0,     0,
       0,     0,     9,    10,    11,    12,    13,    14,    15,     0,
      16,   321,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,    52,    53,     0,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,    52,    53,     0,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,   159,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,    52,    53,     0,    54,    55,    56,    57,    58,    59,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,   251,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,     0,     0,     0,     0,     0,     0,    52,    53,
       0,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,   261,
       9,    10,    11,    12,    13,    14,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    52,    53,     0,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,    52,    53,   281,    54,    55,    56,    57,    58,    59,
       0,   282,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,     9,    10,    11,    12,    13,    14,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,    52,    53,   281,
      54,    55,    56,    57,    58,    59,     0,   282,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,     9,    10,
      11,    12,    13,    14,    15,   371,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,     0,     0,     0,
       0,     0,     0,    52,    53,     0,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,     9,    10,    11,    12,    13,    14,
      15,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,     0,     0,     0,     0,     0,     0,    52,
      53,     0,    54,    55,    56,    57,    58,    59,     0,   282,
       0,     0,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
       9,    10,    11,    12,    13,    14,    15,     0,    16,   321,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    52,    53,     0,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,    52,    53,     0,    54,    55,    56,    57,    58,    59,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,     9,    10,    11,    12,   331,     0,    15,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,    52,    53,     0,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,     9,    10,
      11,    12,     0,     0,    15,     0,    16,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,     0,     0,     0,
       0,     0,     0,    52,    53,     0,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94
};

static const short int yycheck[] =
{
       2,     3,     2,     3,   276,   204,   278,    14,    14,    50,
      15,   338,   339,    15,    50,    15,    50,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     2,     3,    68,
     338,   339,    50,    50,    50,    50,     0,    50,    50,    15,
      15,    68,    15,    12,    13,    72,    15,    15,    53,    54,
      12,    13,    15,    15,    33,    53,    54,    12,    13,    68,
      15,   333,    71,    95,    14,    32,    33,    62,    35,    12,
      13,    15,    15,    67,    50,   402,   275,    50,   119,    84,
      85,   408,    50,   119,    67,   119,    84,    85,    95,    95,
      53,    54,   131,    95,   402,    82,    98,    67,    98,    14,
     408,   119,   119,   119,   119,   377,   119,   119,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    12,    13,
      95,    15,    67,    98,     4,     5,     6,    62,   160,    32,
      33,    34,    33,    34,    35,    82,   168,   336,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    82,   160,    33,
      34,    35,    33,    34,    35,    82,   168,    33,    34,    35,
      12,    13,    14,    68,    69,    70,    33,    34,    33,    34,
      33,    34,   454,    12,    13,   160,    12,    13,    12,    13,
      12,    13,    62,   168,    69,    70,    72,    53,    54,    67,
      62,   131,   131,   101,   206,    22,    71,    14,    14,    14,
      14,    49,    13,    12,    68,    13,    12,    67,    13,    12,
      34,    12,   121,   255,   445,   122,   126,   120,   124,    62,
      62,   206,   123,   432,    62,   125,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   127,   249,   250,   249,
     250,   283,    62,   255,    62,   128,   102,    68,    67,    62,
     262,     5,   262,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    62,   249,   250,    62,    62,    62,    62,
     255,   283,    62,   103,   316,   317,    68,   262,     5,   363,
     209,   292,   295,   388,   298,   327,   341,   447,   402,   342,
     408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,    -1,
      -1,    -1,    -1,    -1,   316,   317,    -1,    -1,   320,    -1,
     320,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,
      -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
     342,   316,   317,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   363,    -1,    -1,    -1,    -1,   341,   342,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,   457,    71,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,   445,    -1,   447,    91,    -1,    -1,   451,
      -1,   451,    -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     445,    -1,   447,    -1,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,   196,   197,   198,   199,    -1,    -1,   202,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   361,   362,    -1,    -1,
      -1,    -1,   367,   368,   369,   370,     3,    -1,    -1,   374,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,     3,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,     8,     9,    10,    11,    12,    -1,    14,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,     8,     9,
      10,    11,    -1,    -1,    14,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     4,     5,     6,   135,   136,   137,   138,     7,     8,
       9,    10,    11,    12,    13,    14,    16,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    63,    64,
      65,    66,    73,    74,    76,    77,    78,    79,    80,    81,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     129,   130,   131,   132,   133,   139,   140,   141,   142,   144,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   174,   177,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     7,
     139,     0,   137,   138,   141,   150,   152,   141,   139,   141,
      32,    33,    34,    33,    34,    35,    33,    34,    35,    33,
      34,    35,    33,    34,    35,    33,    33,    34,    33,    34,
      33,    34,   141,   141,    82,   141,   141,   141,   141,   141,
     141,   141,   141,   141,    14,    95,    14,   141,   141,    67,
      67,    67,    67,   141,   141,   141,   141,   141,    82,   141,
      82,    82,   141,    62,    62,    67,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    14,   141,    62,
      62,     7,   140,    12,    13,   139,    12,    13,    12,    13,
     131,     7,     3,    15,    15,   145,   141,   141,   141,   141,
     141,   141,   141,    12,    13,    14,   190,   191,   190,   141,
      51,    75,    83,   139,   225,   226,   227,   228,   231,   170,
      69,    70,   172,   173,    71,   178,   179,    72,   175,   176,
     141,   141,   141,   141,   141,   101,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   139,   139,   141,   141,
       3,    17,   143,   141,   141,   141,   141,   139,    22,   141,
     141,    12,   141,   190,   191,    15,    14,    14,    14,    14,
      15,    50,    49,    68,    68,   173,    68,   179,    68,   176,
      68,   119,   119,   119,   119,   119,   119,   119,   119,   119,
      15,    13,    12,   139,    32,    33,    35,    13,    12,    13,
      12,    15,    34,   141,    12,    15,   141,   190,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     216,   217,   229,   230,    84,    85,   216,   217,   232,   233,
     234,   235,   226,   231,    67,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   141,   141,   143,   141,   141,   141,
     141,   141,    14,    95,    15,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    15,   214,    15,   230,    62,
      62,    15,   233,   102,   190,   225,   227,   139,    68,    15,
      15,    67,   103,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 211 "itex2MML.y"
    {/* all processing done in body*/}
    break;

  case 3:
#line 214 "itex2MML.y"
    {/* nothing - do nothing*/}
    break;

  case 4:
#line 215 "itex2MML.y"
    {/* proc done in body*/}
    break;

  case 5:
#line 216 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 6:
#line 217 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 7:
#line 218 "itex2MML.y"
    {/* all proc. in body*/}
    break;

  case 8:
#line 220 "itex2MML.y"
    {printf("%s", (yyvsp[0]));}
    break;

  case 9:
#line 222 "itex2MML.y"
    {/* empty math group - ignore*/}
    break;

  case 10:
#line 223 "itex2MML.y"
    {/* ditto */}
    break;

  case 11:
#line 224 "itex2MML.y"
    {
  char ** r = (char **) ret_str;
  char * s = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='inline'>", (yyvsp[-1]), "</math>");
  itex2MML_free_string((yyvsp[-1]));
  if (r) {
    (*r) = (s == itex2MML_empty_string) ? 0 : s;
  }
  else {
    if (itex2MML_write_mathml)
      (*itex2MML_write_mathml) (s);
    itex2MML_free_string(s);
  }
}
    break;

  case 12:
#line 237 "itex2MML.y"
    {
  char ** r = (char **) ret_str;
  char * s = itex2MML_copy3("<math xmlns='http://www.w3.org/1998/Math/MathML' display='block'>", (yyvsp[-1]), "</math>");
  itex2MML_free_string((yyvsp[-1]));
  if (r) {
    (*r) = (s == itex2MML_empty_string) ? 0 : s;
  }
  else {
    if (itex2MML_write_mathml)
      (*itex2MML_write_mathml) (s);
    itex2MML_free_string(s);
  }
}
    break;

  case 13:
#line 251 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 14:
#line 255 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[-1]), (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 15:
#line 261 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 16:
#line 280 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munder>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</munder>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msub>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msub>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 17:
#line 294 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[0]), " ", (yyvsp[-2]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[0]), " ", (yyvsp[-2]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 18:
#line 313 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<mover>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mover>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msup>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msup>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 19:
#line 327 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 20:
#line 346 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munder>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</munder>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msub>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msub>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 21:
#line 360 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<munderover>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[0]), " ", (yyvsp[-2]));
    (yyval) = itex2MML_copy3(s1, s2, "</munderover>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  else {
    char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
    char * s2 = itex2MML_copy3((yyvsp[0]), " ", (yyvsp[-2]));
    (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
    itex2MML_free_string(s1);
    itex2MML_free_string(s2);
  }
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 22:
#line 379 "itex2MML.y"
    {
  if (itex2MML_displaymode == 1) {
    char * s1 = itex2MML_copy3("<mover>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mover>");
    itex2MML_free_string(s1);
  }
  else {
    char * s1 = itex2MML_copy3("<msup>", (yyvsp[-2]), " ");
    (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msup>");
    itex2MML_free_string(s1);
  }
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 23:
#line 393 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
  char * s2 = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
  (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 24:
#line 403 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msubsup>", (yyvsp[-4]), " ");
  char * s2 = itex2MML_copy3((yyvsp[0]), " ", (yyvsp[-2]));
  (yyval) = itex2MML_copy3(s1, s2, "</msubsup>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 25:
#line 413 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msub>", (yyvsp[-2]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msub>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 26:
#line 420 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<msup>", (yyvsp[-2]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</msup>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 27:
#line 427 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msub><mo></mo>", (yyvsp[0]), "</msub>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 28:
#line 431 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msup><mo></mo>", (yyvsp[0]), "</msup>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 29:
#line 435 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 34:
#line 444 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[0]), "</mi>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 35:
#line 448 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mn>", (yyvsp[0]), "</mn>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 84:
#line 500 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 85:
#line 504 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow>", (yyvsp[-1]), "</mrow>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 86:
#line 508 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[-2]), (yyvsp[-1]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 91:
#line 521 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 92:
#line 526 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 93:
#line 531 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 94:
#line 537 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 95:
#line 541 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 96:
#line 545 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 97:
#line 550 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 98:
#line 555 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 99:
#line 559 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 100:
#line 563 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 101:
#line 568 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 102:
#line 572 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 103:
#line 576 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 104:
#line 581 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 105:
#line 585 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 106:
#line 589 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 107:
#line 594 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 108:
#line 598 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 109:
#line 602 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[-3]), "</mo>");
  itex2MML_free_string((yyvsp[-3]));
}
    break;

  case 110:
#line 607 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.2em\" minsize=\"1.2em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 111:
#line 612 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 112:
#line 617 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"1.8em\" minsize=\"1.8em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 113:
#line 622 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 114:
#line 627 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"2.4em\" minsize=\"2.4em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 115:
#line 632 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 116:
#line 637 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo maxsize=\"3em\" minsize=\"3em\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 117:
#line 643 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<merror><mtext>Unknown character</mtext></merror>");
}
    break;

  case 118:
#line 647 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">&minus;</mo>");
}
    break;

  case 119:
#line 651 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mo lspace=\"verythinmathspace\" rspace=\"0em\">+</mo>");
}
    break;

  case 121:
#line 657 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[0]), "</mi>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 123:
#line 665 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"thinmathspace\" rspace=\"thinmathspace\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 126:
#line 673 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 127:
#line 678 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 128:
#line 683 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 129:
#line 687 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 130:
#line 692 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 131:
#line 696 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo stretchy=\"false\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 132:
#line 700 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mo>", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 133:
#line 704 "itex2MML.y"
    {
  itex2MML_rowposn=2;
  (yyval) = itex2MML_copy3("<mo lspace=\"mediummathspace\" rspace=\"mediummathspace\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 134:
#line 709 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 135:
#line 714 "itex2MML.y"
    {
  itex2MML_rowposn = 2;
  (yyval) = itex2MML_copy3("<mo lspace=\"0em\" rspace=\"thinmathspace\">", (yyvsp[0]), "</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 136:
#line 720 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mrow></mrow>");
}
    break;

  case 137:
#line 724 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mspace height=\"", (yyvsp[-7]), "ex\" depth=\"");
  char * s2 = itex2MML_copy3((yyvsp[-4]), "ex\" width=\"", (yyvsp[-1]));
  (yyval) = itex2MML_copy3(s1, s2, "em\"/>");
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[-7]));
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 138:
#line 735 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"statusline\">", (yyvsp[0]), "<mtext>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[-1]), "</mtext></maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 139:
#line 743 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"toggle\" selection=\"2\">", (yyvsp[-1]), " ");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 140:
#line 751 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='color=", (yyvsp[-1]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 141:
#line 759 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<maction actiontype=\"highlight\" other='background=", (yyvsp[-1]), "'>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</maction>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 142:
#line 767 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathcolor=", (yyvsp[-1]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 143:
#line 774 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle mathbackground=", (yyvsp[-1]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 144:
#line 782 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtext>", (yyvsp[0]), "</mtext>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 145:
#line 787 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"true\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 146:
#line 792 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle displaystyle=\"false\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 147:
#line 797 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"0\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 148:
#line 802 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"1\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 149:
#line 807 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 150:
#line 812 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"italic\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 151:
#line 817 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle mathvariant=\"bold\">", (yyvsp[0]), "</mstyle>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 152:
#line 822 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi mathvariant=\"normal\">", (yyvsp[-1]), "</mi>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 153:
#line 827 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 154:
#line 831 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[-1]), (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 155:
#line 837 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[-1]), "</mi>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 156:
#line 842 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 157:
#line 846 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[-1]), (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 158:
#line 852 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 159:
#line 856 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[0]), "opf;");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 160:
#line 861 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[-1]), "</mi>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 161:
#line 866 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 162:
#line 870 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[-1]), (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 163:
#line 876 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[0]), "fr;");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 164:
#line 881 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mi>", (yyvsp[-1]), "</mi>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 165:
#line 886 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 166:
#line 890 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[-1]), (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 167:
#line 896 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("&", (yyvsp[0]), "scr;");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 168:
#line 901 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thinmathspace\"/>");
}
    break;

  case 169:
#line 905 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"mediummathspace\"/>");
}
    break;

  case 170:
#line 909 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"thickmathspace\"/>");
}
    break;

  case 171:
#line 913 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"1em\"/>");
}
    break;

  case 172:
#line 917 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"2em\"/>");
}
    break;

  case 173:
#line 921 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mspace width=\"-0.1667 em\"/>");
}
    break;

  case 174:
#line 925 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mphantom>", (yyvsp[0]), "</mphantom>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 175:
#line 930 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:type=\"simple\" xlink:href=\"", (yyvsp[-1]), "\">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 176:
#line 938 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[-3]), (yyvsp[-1]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 177:
#line 945 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[-1]), (yyvsp[0]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 178:
#line 953 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[-3]), (yyvsp[-1]));
  char * s2 = itex2MML_copy3("<mprescripts />", (yyvsp[-5]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[-5]));
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 179:
#line 963 "itex2MML.y"
    {
  char * s1 = itex2MML_copy2("<mmultiscripts>", (yyvsp[-1]));
  char * s2 = itex2MML_copy3("<mprescripts />", (yyvsp[-3]), "</mmultiscripts>");
  (yyval) = itex2MML_copy2(s1, s2);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 180:
#line 972 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mmultiscripts>", (yyvsp[-3]), (yyvsp[-1]));
  (yyval) = itex2MML_copy2(s1, "</mmultiscripts>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1])); 
}
    break;

  case 181:
#line 980 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 182:
#line 984 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-1]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 183:
#line 990 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 184:
#line 995 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2((yyvsp[0]), " <none />");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 185:
#line 999 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none /> ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 186:
#line 1003 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("<none /> ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 187:
#line 1008 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac>", (yyvsp[-1]), (yyvsp[0]));
  (yyval) = itex2MML_copy2(s1, "</mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 188:
#line 1015 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mstyle displaystyle=\"false\"><mfrac>", (yyvsp[-1]), (yyvsp[0]));
  (yyval) = itex2MML_copy2(s1, "</mfrac></mstyle>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 189:
#line 1023 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3( "<mo lspace=\"mediummathspace\">(</mo><mo rspace=\"thinmathspace\">mod</mo>", (yyvsp[0]), "<mo rspace=\"mediummathspace\">)</mo>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 190:
#line 1028 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac><mrow>", (yyvsp[-3]), "</mrow><mrow>");
  (yyval) = itex2MML_copy3(s1, (yyvsp[-1]), "</mrow></mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 191:
#line 1035 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow>", (yyvsp[-4]), "<mfrac><mrow>");
  char * s2 = itex2MML_copy3((yyvsp[-3]), "</mrow><mrow>", (yyvsp[-1]));
  char * s3 = itex2MML_copy3("</mrow></mfrac>", (yyvsp[0]), "</mrow>");
  (yyval) = itex2MML_copy3(s1, s2, s3);
  itex2MML_free_string(s1);
  itex2MML_free_string(s2);
  itex2MML_free_string(s3);
  itex2MML_free_string((yyvsp[-4]));
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 192:
#line 1049 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mfrac linethickness=\"0\">", (yyvsp[-1]), (yyvsp[0]));
  (yyval) = itex2MML_copy2(s1, "</mfrac>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 193:
#line 1057 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<munder>", (yyvsp[0]), "<mo>&UnderBrace;</mo></munder>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 194:
#line 1062 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&OverBrace;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 195:
#line 1067 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo stretchy=\"false\">&OverBar;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 196:
#line 1071 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&OverBar;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 197:
#line 1076 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo stretchy=\"false\">&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 198:
#line 1080 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&RightVector;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 199:
#line 1085 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&dot;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 200:
#line 1090 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&Dot;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 201:
#line 1095 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo stretchy=\"false\">&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 202:
#line 1099 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&tilde;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 203:
#line 1104 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo stretchy=\"false\">&macr;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 204:
#line 1108 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&macr;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 205:
#line 1113 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo stretchy=\"false\">&#x302;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 206:
#line 1117 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mover>", (yyvsp[0]), "<mo>&#x302;</mo></mover>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 207:
#line 1122 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<msqrt>", (yyvsp[0]), "</msqrt>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 208:
#line 1127 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mroot>", (yyvsp[0]), (yyvsp[-1]));
  (yyval) = itex2MML_copy2(s1, "</mroot>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 209:
#line 1135 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munder>", (yyvsp[0]), (yyvsp[-1]));
  (yyval) = itex2MML_copy2(s1, "</munder>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 210:
#line 1143 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mover>", (yyvsp[0]), (yyvsp[-1]));
  (yyval) = itex2MML_copy2(s1, "</mover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 211:
#line 1151 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<munderover>", (yyvsp[0]), (yyvsp[-2]));
  (yyval) = itex2MML_copy3(s1, (yyvsp[-1]), "</munderover>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 212:
#line 1160 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 213:
#line 1164 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>(</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow><mo>)</mo></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 214:
#line 1168 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>[</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow><mo>]</mo></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 215:
#line 1172 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&VerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow><mo>&VerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 216:
#line 1176 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow><mo>}</mo></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 217:
#line 1180 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>&DoubleVerticalBar;</mo><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow><mo>&DoubleVerticalBar;</mo></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 218:
#line 1184 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mstyle scriptlevel=\"2\"><mrow><mtable rowspacing=\"0.5ex\">", (yyvsp[-2]), "</mtable></mrow></mstyle>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 219:
#line 1188 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mo>{</mo><mrow><mtable columnalign=\"left left\">", (yyvsp[-2]), "</mtable></mrow></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 220:
#line 1192 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"right left\">", (yyvsp[-2]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[-2]));
}
    break;

  case 221:
#line 1197 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable columnalign=\"center\" rowspacing=\"0.5ex\">", (yyvsp[-1]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 222:
#line 1202 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mrow><mtable>", (yyvsp[-1]), "</mtable></mrow>");
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 223:
#line 1206 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mrow><mtable ", (yyvsp[-3]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[-1]), "</mtable></mrow>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-3]));
  itex2MML_free_string((yyvsp[-1]));
}
    break;

  case 224:
#line 1214 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 225:
#line 1218 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-1]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 226:
#line 1224 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 227:
#line 1228 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 228:
#line 1232 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 229:
#line 1236 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 230:
#line 1240 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 231:
#line 1244 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 232:
#line 1248 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 233:
#line 1252 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 234:
#line 1256 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 235:
#line 1260 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 236:
#line 1265 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 237:
#line 1270 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnalign=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 238:
#line 1275 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowalign=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 239:
#line 1280 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("align=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 240:
#line 1285 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalrows=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 241:
#line 1290 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("equalcolumns=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 242:
#line 1295 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowlines=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 243:
#line 1300 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("columnlines=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 244:
#line 1305 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("frame=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 245:
#line 1310 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("rowspacing=", (yyvsp[0]), " columnspacing=");
  (yyval) = itex2MML_copy2(s1, (yyvsp[0]));
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 246:
#line 1317 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 247:
#line 1321 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 248:
#line 1327 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtr>", (yyvsp[0]), "</mtr>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 249:
#line 1331 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 250:
#line 1336 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 251:
#line 1340 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-2]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 252:
#line 1346 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtr ", (yyvsp[-2]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mtr>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 253:
#line 1354 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 254:
#line 1358 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-1]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 255:
#line 1364 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 256:
#line 1368 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 257:
#line 1373 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string("<mtd></mtd>");
}
    break;

  case 258:
#line 1376 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3("<mtd>", (yyvsp[0]), "</mtd>");
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 259:
#line 1380 "itex2MML.y"
    {
  char * s1 = itex2MML_copy3("<mtd ", (yyvsp[-2]), ">");
  (yyval) = itex2MML_copy3(s1, (yyvsp[0]), "</mtd>");
  itex2MML_free_string(s1);
  itex2MML_free_string((yyvsp[-2]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 260:
#line 1388 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 261:
#line 1392 "itex2MML.y"
    {
  (yyval) = itex2MML_copy3((yyvsp[-1]), " ", (yyvsp[0]));
  itex2MML_free_string((yyvsp[-1]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 262:
#line 1398 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 263:
#line 1402 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 264:
#line 1406 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 265:
#line 1410 "itex2MML.y"
    {
  (yyval) = itex2MML_copy_string((yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 266:
#line 1415 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("rowspan=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;

  case 267:
#line 1420 "itex2MML.y"
    {
  (yyval) = itex2MML_copy2("colspan=", (yyvsp[0]));
  itex2MML_free_string((yyvsp[0]));
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 4324 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1425 "itex2MML.y"


char * itex2MML_parse (const char * buffer, unsigned long length)
{
  char * mathml = 0;

  int result;

  itex2MML_setup (buffer, length);
  itex2MML_restart ();

  result = itex2MML_yyparse (&mathml);

  if (result && mathml) /* shouldn't happen? */
    {
      itex2MML_free_string (mathml);
      mathml = 0;
    }
  return mathml;
}

int itex2MML_filter (const char * buffer, unsigned long length)
{
  itex2MML_setup (buffer, length);
  itex2MML_restart ();

  return itex2MML_yyparse (0);
}

#define ITEX_DELIMITER_DOLLAR 0
#define ITEX_DELIMITER_DOUBLE 1
#define ITEX_DELIMITER_SQUARE 2

static char * itex2MML_last_error = 0;

static void itex2MML_keep_error (const char * msg)
{
  if (itex2MML_last_error)
    {
      itex2MML_free_string (itex2MML_last_error);
      itex2MML_last_error = 0;
    }
  itex2MML_last_error = itex2MML_copy_escaped (msg);
}

int itex2MML_html_filter (const char * buffer, unsigned long length)
{
  int result = 0;

  int type = 0;
  int skip = 0;
  int match = 0;

  const char * ptr1 = buffer;
  const char * ptr2 = 0;

  const char * end = buffer + length;

  char * mathml = 0;

  void (*save_error_fn) (const char * msg) = itex2MML_error;

  itex2MML_error = itex2MML_keep_error;

 _until_math:
  ptr2 = ptr1;

  while (ptr2 < end)
    {
      if (*ptr2 == '$') break;
      if ((*ptr2 == '\\') && (ptr2 + 1 < end))
	{
	  if (*(ptr2+1) == '[') break;
	}
      ++ptr2;
    }
  if (itex2MML_write)
    (*itex2MML_write) (ptr1, ptr2 - ptr1);

  if (ptr2 == end) goto _finish;

 _until_html:
  ptr1 = ptr2;

  if (ptr2 + 1 < end)
    {
      if ((*ptr2 == '\\') && (*(ptr2+1) == '['))
	{
	  type = ITEX_DELIMITER_SQUARE;
	  ptr2 += 2;
	}
      else if ((*ptr2 == '$') && (*(ptr2+1) == '$'))
	{
	  type = ITEX_DELIMITER_DOUBLE;
	  ptr2 += 2;
	}
      else
	{
	  type = ITEX_DELIMITER_DOLLAR;
	  ptr2 += 2;
	}
    }
  else goto _finish;

  skip = 0;
  match = 0;

  while (ptr2 < end)
    {
      switch (*ptr2)
	{
	case '<':
	case '>':
	  skip = 1;
	  break;

	case '\\':
	  if (ptr2 + 1 < end)
	    {
	      if (*(ptr2 + 1) == '[')
		{
		  skip = 1;
		}
	      else if (*(ptr2 + 1) == ']')
		{
		  if (type == ITEX_DELIMITER_SQUARE)
		    {
		      ptr2 += 2;
		      match = 1;
		    }
		  else
		    {
		      skip = 1;
		    }
		}
	    }
	  break;

	case '$':
	  if (type == ITEX_DELIMITER_SQUARE)
	    {
	      skip = 1;
	    }
	  else if (ptr2 + 1 < end)
	    {
	      if (*(ptr2 + 1) == '$')
		{
		  if (type == ITEX_DELIMITER_DOLLAR)
		    {
		      ptr2++;
		      match = 1;
		    }
		  else
		    {
		      ptr2 += 2;
		      match = 1;
		    }
		}
	      else
		{
		  if (type == ITEX_DELIMITER_DOLLAR)
		    {
		      ptr2++;
		      match = 1;
		    }
		  else
		    {
		      skip = 1;
		    }
		}
	    }
	  else
	    {
	      if (type == ITEX_DELIMITER_DOLLAR)
		{
		  ptr2++;
		  match = 1;
		}
	      else
		{
		  skip = 1;
		}
	    }
	  break;

	default:
	  break;
	}
      if (skip || match) break;

      ++ptr2;
    }
  if (skip)
    {
      if (type == ITEX_DELIMITER_DOLLAR)
	{
	  if (itex2MML_write)
	    (*itex2MML_write) (ptr1, 1);
	  ptr1++;
	}
      else
	{
	  if (itex2MML_write)
	    (*itex2MML_write) (ptr1, 2);
	  ptr1 += 2;
	}
      goto _until_math;
    }
  if (match)
    {
      mathml = itex2MML_parse (ptr1, ptr2 - ptr1);

      if (mathml)
	{
	  if (itex2MML_write_mathml)
	    (*itex2MML_write_mathml) (mathml);
	  itex2MML_free_string (mathml);
	  mathml = 0;
	}
      else
	{
	  ++result;
	  if (itex2MML_write)
	    {
	      if (type == ITEX_DELIMITER_DOLLAR)
		(*itex2MML_write) ("<math xmlns='http://www.w3.org/1998/Math/MathML' display='inline'><merror><mtext>", 0);
	      else
		(*itex2MML_write) ("<math xmlns='http://www.w3.org/1998/Math/MathML' display='block'><merror><mtext>", 0);

	      (*itex2MML_write) (itex2MML_last_error, 0);
	      (*itex2MML_write) ("</mtext></merror></math>", 0);
	    }
	}
      ptr1 = ptr2;

      goto _until_math;
    }
  if (itex2MML_write)
    (*itex2MML_write) (ptr1, ptr2 - ptr1);

 _finish:
  if (itex2MML_last_error)
    {
      itex2MML_free_string (itex2MML_last_error);
      itex2MML_last_error = 0;
    }
  itex2MML_error = save_error_fn;

  return result;
}

