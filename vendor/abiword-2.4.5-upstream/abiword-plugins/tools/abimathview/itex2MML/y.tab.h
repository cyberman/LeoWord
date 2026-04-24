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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE itex2MML_yylval;



