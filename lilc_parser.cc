// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "lilc_parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "grammar.hh"

// User implementation prologue.

#line 51 "lilc_parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 33 "lilc.yy" // lalr1.cc:408

   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "lilc_compiler.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "lilc_parser.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "lilc.yy" // lalr1.cc:474
namespace LILC {
#line 132 "lilc_parser.cc" // lalr1.cc:474

  /// Build a parser object.
  LilC_Parser::LilC_Parser (LilC_Scanner  &scanner_yyarg, LilC_Compiler &compiler_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      compiler (compiler_yyarg)
  {}

  LilC_Parser::~LilC_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  LilC_Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  LilC_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  LilC_Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  LilC_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  LilC_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  LilC_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  LilC_Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  LilC_Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  LilC_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  LilC_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  LilC_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  LilC_Parser::symbol_number_type
  LilC_Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  LilC_Parser::stack_symbol_type&
  LilC_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  LilC_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  LilC_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  LilC_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  LilC_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  LilC_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  LilC_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  LilC_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  LilC_Parser::debug_level_type
  LilC_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  LilC_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline LilC_Parser::state_type
  LilC_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  LilC_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  LilC_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  LilC_Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 166 "lilc.yy" // lalr1.cc:847
    {
		   //$$ = new ProgramNode(new DeclListNode($1));
		   (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declList)));
		   compiler.setASTRoot((yylhs.value.programNode));
		   }
#line 533 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 173 "lilc.yy" // lalr1.cc:847
    {
			 (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
			 (yylhs.value.declList) = (yystack_[1].value.declList);
			 }
#line 542 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 177 "lilc.yy" // lalr1.cc:847
    {
			(yylhs.value.declList) = new std::list<DeclNode *>();
			}
#line 550 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 182 "lilc.yy" // lalr1.cc:847
    {
		(yylhs.value.declNode) = (yystack_[0].value.varDeclNode);
		}
#line 558 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 185 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.declNode) = (yystack_[0].value.fnDeclNode);
    }
#line 566 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 188 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.declNode) = (yystack_[0].value.structDeclNode);
    }
#line 574 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 192 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.varDeclList)->push_back((yystack_[0].value.varDeclNode));
    (yylhs.value.varDeclList) = (yystack_[1].value.varDeclList);
    }
#line 583 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 196 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.varDeclList) = new std::list<DeclNode *>();
    }
#line 591 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 200 "lilc.yy" // lalr1.cc:847
    {
		(yylhs.value.varDeclNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode), VarDeclNode::NOT_STRUCT);
		}
#line 599 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 203 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.varDeclNode) = new VarDeclNode(new StructNode((yystack_[2].value.idNode)), (yystack_[1].value.idNode), 0);
    }
#line 607 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 207 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.fnDeclNode) = new FnDeclNode((yystack_[3].value.typeNode), (yystack_[2].value.idNode), (yystack_[1].value.formalsListNode), (yystack_[0].value.fnBody));
    }
#line 615 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 210 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.structDeclNode) = new StructDeclNode((yystack_[4].value.idNode), new DeclListNode((yystack_[2].value.declList)));
    }
#line 623 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 214 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.declList)->push_back((yystack_[0].value.varDeclNode));
    (yylhs.value.declList) = (yystack_[1].value.declList);
    }
#line 632 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 218 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.declList) = new std::list<DeclNode *>();
    (yylhs.value.declList)->push_back((yystack_[0].value.varDeclNode));
    }
#line 641 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 223 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.formalsListNode) = new FormalsListNode(new std::list<FormalDeclNode *>());
    }
#line 649 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 226 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.formalsListNode) = new FormalsListNode((yystack_[1].value.formalsList));
    }
#line 657 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 230 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.formalsList) = new std::list<FormalDeclNode *>();
    (yylhs.value.formalsList)->push_back((yystack_[0].value.formalsDecl));
    }
#line 666 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 234 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[0].value.formalsList)->push_back((yystack_[2].value.formalsDecl));
    (yylhs.value.formalsList) = (yystack_[0].value.formalsList);
    }
#line 675 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 239 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.formalsDecl) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
    }
#line 683 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 242 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.fnBody) = new FnBodyNode(new DeclListNode((yystack_[2].value.varDeclList)), new StmtListNode((yystack_[1].value.stmtList)));
    }
#line 691 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 245 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.stmtList)->push_back((yystack_[0].value.stmtNode));
    (yylhs.value.stmtList) = (yystack_[1].value.stmtList);
    }
#line 700 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 249 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtList) = new std::list<StmtNode *>();
    }
#line 708 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 253 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode));
    }
#line 716 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 256 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.loc));
    }
#line 724 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 259 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.loc));
    }
#line 732 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 262 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.loc));
    }
#line 740 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 265 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.expNode));
    }
#line 748 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 268 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new IfStmtNode((yystack_[5].value.expNode), new DeclListNode((yystack_[2].value.varDeclList)), new StmtListNode((yystack_[1].value.stmtList)));
    }
#line 756 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 271 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new IfElseStmtNode((yystack_[10].value.expNode), new DeclListNode((yystack_[7].value.varDeclList)), new StmtListNode((yystack_[6].value.stmtList)),
                            new DeclListNode((yystack_[2].value.varDeclList)), new StmtListNode((yystack_[1].value.stmtList)));
    }
#line 765 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 275 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[5].value.expNode), new DeclListNode((yystack_[2].value.varDeclList)), new StmtListNode((yystack_[1].value.stmtList)));
    }
#line 773 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 278 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.expNode));
    }
#line 781 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 281 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.stmtNode) = new ReturnStmtNode(nullptr);
    }
#line 789 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 284 "lilc.yy" // lalr1.cc:847
    {
      (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callExpNode));
    }
#line 797 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 288 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.assignNode) = new AssignNode((yystack_[2].value.loc), (yystack_[0].value.expNode));
    }
#line 805 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 36:
#line 291 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.expNode) = new PlusNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));
    }
#line 813 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 37:
#line 294 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.expNode) = (yystack_[0].value.term);
    }
#line 821 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 38:
#line 297 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.term) = (yystack_[0].value.loc);
    }
#line 829 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 39:
#line 300 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.term) = new IntLitNode((yystack_[0].value.intLitTokenValue));
    }
#line 837 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 40:
#line 303 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.term) = new StrLitNode((yystack_[0].value.stringLitTokenValue));
    }
#line 845 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 41:
#line 306 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.term) = new TrueNode();
    }
#line 853 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 42:
#line 309 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.term) = new FalseNode();
    }
#line 861 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 43:
#line 313 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.callExpNode) = new CallExpNode((yystack_[2].value.idNode), new ExpListNode(new std::list<ExpNode*>()));
    }
#line 869 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 44:
#line 316 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.callExpNode) = new CallExpNode((yystack_[3].value.idNode), new ExpListNode((yystack_[1].value.expListNode)));
    }
#line 877 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 45:
#line 319 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.expListNode) = new std::list<ExpNode*>();
    (yylhs.value.expListNode)->push_back((yystack_[0].value.expNode));
    }
#line 886 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 46:
#line 323 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[2].value.expListNode)->push_back((yystack_[0].value.expNode));
    (yylhs.value.expListNode) = (yystack_[2].value.expListNode);
    }
#line 895 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 47:
#line 327 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new IntNode();}
#line 901 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 48:
#line 328 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new BoolNode();}
#line 907 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 49:
#line 329 "lilc.yy" // lalr1.cc:847
    {(yylhs.value.typeNode) = new VoidNode();}
#line 913 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 50:
#line 330 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.loc) = (yystack_[0].value.idNode);
    }
#line 921 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 51:
#line 333 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.loc) = new DotAccessNode((yystack_[2].value.loc), (yystack_[0].value.idNode));
    }
#line 929 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 52:
#line 337 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue));}
#line 935 "lilc_parser.cc" // lalr1.cc:847
    break;


#line 939 "lilc_parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  LilC_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  LilC_Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char LilC_Parser::yypact_ninf_ = -89;

  const signed char LilC_Parser::yytable_ninf_ = -1;

  const short int
  LilC_Parser::yypact_[] =
  {
     -89,    21,   110,   -89,   -89,   -89,   -89,   -11,   -89,   -89,
     -89,   -89,   -11,   -89,   107,   106,   116,    10,    22,   -89,
      15,   -11,   -89,    45,   -11,   -89,   -89,    16,    19,   -11,
     -89,   -89,   -11,    32,   -89,    58,   -89,    67,   -89,   116,
     -89,   -89,   -89,    68,    84,    92,    73,    91,    29,   -89,
     -89,   101,   111,   -14,   114,   -11,    59,    59,    59,   -89,
     -89,   -89,   -89,   -89,    33,   -89,   112,   -89,   -89,   -89,
     -11,   113,   115,    59,    52,   105,    87,    18,    31,   -89,
      59,   -89,   -89,   -89,   102,   -89,   102,   109,   -89,   -89,
     120,   121,   -89,   -89,    59,   -89,   -89,   102,   116,   116,
      75,    86,   128,   -89,   123,   -89,   116,    93,   -89
  };

  const unsigned char
  LilC_Parser::yydefact_[] =
  {
       4,     0,     2,     1,    48,    47,    49,     0,     3,     5,
       6,     7,     0,    52,     0,     0,     0,     0,     0,    10,
       0,     0,    15,     0,     0,    11,    16,     0,    18,     0,
       9,    12,     0,     0,    14,     0,    17,     0,    20,    23,
      13,    19,     8,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,    50,     0,     0,     0,     0,    41,
      42,    39,    40,    33,     0,    37,    38,    50,    24,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    51,    25,    26,    35,    43,    45,     0,    27,    28,
       0,     0,    36,    44,     0,     9,     9,    46,    23,    23,
       0,     0,    29,    31,     0,     9,    23,     0,    30
  };

  const signed char
  LilC_Parser::yypgoto_[] =
  {
     -89,   -89,   -89,   -89,   -63,     7,   -89,   -89,   -89,   -89,
     108,   -89,   -89,   -88,   -89,   -89,   -54,   -89,   -89,   -89,
       6,   -42,    -7
  };

  const signed char
  LilC_Parser::yydefgoto_[] =
  {
      -1,     1,     2,     8,    39,    42,    10,    11,    23,    20,
      27,    28,    31,    43,    50,    51,    64,    65,    52,    87,
      24,    66,    67
  };

  const unsigned char
  LilC_Parser::yytable_[] =
  {
      14,    53,    76,    77,    78,    15,    13,    17,    12,     9,
     100,   101,    70,    75,    32,    71,    72,    35,   107,    84,
      86,     3,    38,    22,    29,    17,    92,     4,     5,     6,
      34,    73,    98,    99,    25,    30,    54,    59,    60,    36,
      97,    90,   106,    29,    37,    26,    13,    61,    62,    80,
       4,     5,     6,    63,    91,    21,    40,    79,    53,    53,
      59,    60,    80,    81,    80,    53,    33,    59,    60,    13,
      61,    62,     4,     5,     6,    85,    13,    61,    62,    44,
      45,    46,    19,    47,    48,    13,    44,    45,    46,    49,
      47,    48,    13,    54,    54,    57,   102,    44,    45,    46,
      54,    47,    48,    13,    44,    45,    46,   103,    47,    48,
      13,    89,    55,    58,   108,     4,     5,     6,    80,    56,
       7,     4,     5,     6,    13,    68,    21,    16,    18,    88,
      19,    70,    93,    80,    94,    69,    74,    82,    70,    83,
      95,    96,   104,   105,     0,    41
  };

  const signed char
  LilC_Parser::yycheck_[] =
  {
       7,    43,    56,    57,    58,    12,    17,    14,     2,     2,
      98,    99,    26,    55,    21,    29,    30,    24,   106,    73,
      74,     0,    29,    16,    18,    32,    80,     5,     6,     7,
      23,    45,    95,    96,    24,    20,    43,     8,     9,    23,
      94,    23,   105,    37,    25,    23,    17,    18,    19,    31,
       5,     6,     7,    24,    23,    10,    24,    24,   100,   101,
       8,     9,    31,    70,    31,   107,    21,     8,     9,    17,
      18,    19,     5,     6,     7,    23,    17,    18,    19,    11,
      12,    13,    24,    15,    16,    17,    11,    12,    13,    21,
      15,    16,    17,   100,   101,    22,    21,    11,    12,    13,
     107,    15,    16,    17,    11,    12,    13,    21,    15,    16,
      17,    24,    28,    22,    21,     5,     6,     7,    31,    27,
      10,     5,     6,     7,    17,    24,    10,    20,    22,    24,
      24,    26,    23,    31,    25,    24,    22,    24,    26,    24,
      20,    20,    14,    20,    -1,    37
  };

  const unsigned char
  LilC_Parser::yystos_[] =
  {
       0,    47,    48,     0,     5,     6,     7,    10,    49,    51,
      52,    53,    66,    17,    68,    68,    20,    68,    22,    24,
      55,    10,    51,    54,    66,    24,    23,    56,    57,    66,
      20,    58,    68,    21,    51,    68,    23,    25,    68,    50,
      24,    56,    51,    59,    11,    12,    13,    15,    16,    21,
      60,    61,    64,    67,    68,    28,    27,    22,    22,     8,
       9,    18,    19,    24,    62,    63,    67,    68,    24,    24,
      26,    29,    30,    45,    22,    67,    62,    62,    62,    24,
      31,    68,    24,    24,    62,    23,    62,    65,    24,    24,
      23,    23,    62,    23,    25,    20,    20,    62,    50,    50,
      59,    59,    21,    21,    14,    20,    50,    59,    21
  };

  const unsigned char
  LilC_Parser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    68
  };

  const unsigned char
  LilC_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     2,     0,
       3,     4,     4,     6,     2,     1,     2,     3,     1,     3,
       2,     4,     2,     0,     2,     3,     3,     4,     4,     8,
      13,     8,     3,     2,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const LilC_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"newline\"", "CHAR", "BOOL",
  "INT", "VOID", "TRUE", "FALSE", "STRUCT", "INPUT", "OUTPUT", "IF",
  "ELSE", "WHILE", "RETURN", "ID", "INTLITERAL", "STRINGLITERAL", "LCURLY",
  "RCURLY", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "DOT", "WRITE",
  "READ", "PLUSPLUS", "MINUSMINUS", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "NOT", "AND", "OR", "EQUALS", "NOTEQUALS", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "ASSIGNDeclNode", "ASSIGN", "$accept", "program",
  "declList", "decl", "varDeclList", "varDecl", "fnDecl", "structDecl",
  "structBody", "formals", "formalsList", "formalDecl", "fnBody",
  "stmtList", "stmt", "assignExp", "exp", "term", "fncall", "actualList",
  "type", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  LilC_Parser::yyrline_[] =
  {
       0,   166,   166,   173,   177,   182,   185,   188,   192,   196,
     200,   203,   207,   210,   214,   218,   223,   226,   230,   234,
     239,   242,   245,   249,   253,   256,   259,   262,   265,   268,
     271,   275,   278,   281,   284,   288,   291,   294,   297,   300,
     303,   306,   309,   313,   316,   319,   323,   327,   328,   329,
     330,   333,   337
  };

  // Print the state stack on the debug stream.
  void
  LilC_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  LilC_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  LilC_Parser::token_number_type
  LilC_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      45
    };
    const unsigned int user_token_number_max_ = 300;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "lilc.yy" // lalr1.cc:1155
} // LILC
#line 1346 "lilc_parser.cc" // lalr1.cc:1155
#line 339 "lilc.yy" // lalr1.cc:1156

void
LILC::LilC_Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
