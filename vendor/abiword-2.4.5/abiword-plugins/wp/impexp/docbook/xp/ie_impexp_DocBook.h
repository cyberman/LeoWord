/* AbiWord
 * Copyright (C) 1998 AbiSource, Inc.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
 * 02111-1307, USA.
 */

#ifndef IE_IMPEXP_DOCBOOK_H
#define IE_IMPEXP_DOCBOOK_H

#define TT_OTHER			0	// anything else
#define TT_DOCUMENT			1	// a document <book>
#define TT_SECTION			2	// section <section>
#define TT_BLOCK			3	// a paragraph <para>
#define TT_PHRASE			4	// formatted text
#define TT_EMPHASIS			5	// emphasized (italic) text
#define TT_SUPERSCRIPT		6	// superscript
#define TT_SUBSCRIPT		7	// subscript
#define TT_BLOCKQUOTE		8	// block quote
#define TT_BRIDGEHEAD		9	// heading  <bridgehead ...>
#define TT_CHAPTER			10	// legacy abiword documents
#define TT_TITLE			11	// title
#define	TT_PAGEBREAK		12
#define	TT_PLAINTEXT		13
#define	TT_LINK				14
#define	TT_ULINK			15
#define	TT_BOOKMARK			16
#define	TT_FIGURE			17
#define	TT_MEDIAOBJECT		18
#define	TT_IMAGEOBJECT		19
#define	TT_IMAGEDATA		20
#define TT_TABLE			21	// table without a title <informaltable>
#define TT_COLSPEC			22	// <colspec>
#define TT_TBODY			23	// <tbody>
#define TT_TGROUP			24	// <tgroup>
#define TT_ROW				25	// table row <row>
#define TT_ENTRY			26	// table cell <entry>
#define TT_FOOTNOTE			27	// footnote <footnote>
#define TT_BOOKINFO			28	// <bookinfo>
#define TT_AUTHOR			29	// <author>
#define TT_HONORIFIC		30	// <honorific>
#define TT_PERSONNAME		31	// <personname>
#define TT_FIRSTNAME		32	// <firstname>
#define TT_SURNAME			33	// <surname>
#define TT_OTHERNAME		34	// <othername>
#define TT_KEYWORDSET		35	// <keywordset>
#define TT_KEYWORD			36	// <keyword>
#define TT_PUBLISHER		37	// <publisher>
#define TT_PUBLISHERNAME	38	// <publishername>
#define TT_ABSTRACT			39	// <abstract>
#define TT_DATE				40	// <date>
#define TT_LEGALNOTICE		41	// <legalnotice>
#define TT_SUBJECTSET		42	// <subjectset>
#define TT_SUBJECT			43	// <subject>
#define TT_SUBJECTTERM		44	// <subjectterm>
#define TT_COLLAB			45	// a collaborator <collab>
#define TT_COLLABNAME		46	// <collabname>
#define TT_REVHISTORY		47	// <revhistory>
#define TT_REVISION			48	// <revision>
#define TT_REVNUMBER		49	// <revnumber>
#define TT_REVREMARK		50	// <revremark>
#define TT_BIBLIOMISC		51	// <bibliomisc>
#define TT_APPLICATION		52	// <application>
#define TT_ENTRYTBL			53	// nested table <entrytbl>
#define TT_TEXTOBJECT		54	// <textobject>
#define TT_INLINEEQUATION	55	// <inlineequation>
#define TT_MATHPHRASE		56	// <mathphrase>
#define TT_INFORMALFIGURE	57	// a figure without a title <informalfigure>
#define TT_FOOTNOTEREF		58	// <footnoteref>
#define TT_ITEMIZEDLIST		59	// <itemizedlist>
#define TT_LISTITEM			60	// <listitem>
#define TT_TOC				61	// table of contents <toc>
#define TT_TOCBACK			62	// <tocback>
#define TT_TOCCHAP			63	// <tocchap>
#define TT_TOCFRONT			64	// <tocfront>
#define TT_TOCPART			65	// <tocpart>
#define TT_TOCLEVEL1		66	// <toclevel1>
#define TT_TOCLEVEL2		67	// <toclevel2>
#define TT_TOCLEVEL3		68	// <toclevel3>
#define TT_TOCLEVEL4		69	// <toclevel4>
#define TT_TOCLEVEL5		70	// <toclevel5>
#define TT_COL				71	// <col>
#define TT_THEAD			72	// table header <thead>
#define TT_TFOOT			73	// table footer <tfoot>
#define TT_QUOTE			74	// <quote>
#define TT_EMAIL			75	// <email>
#define TT_BIBLIOCOVERAGE	76	// <bibliocoverage>
#define TT_BIBLIORELATION	77	// <bibliorelation>
#define TT_BIBLIOSOURCE		78	// <bibliosource>
#define TT_REVDESCRIPTION	79	// <revdescription>

#endif
