%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {LILC}
%define parser_class_name {LilC_Parser}
%output "lilc_parser.cc"
%token-table

%code requires{
   #include <list>
   #include "symbols.hpp"
   #include "ast.hpp"
   namespace LILC {
      class LilC_Compiler;
      class LilC_Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { LilC_Scanner  &scanner  }
%parse-param { LilC_Compiler &compiler }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for interoperation between scanner/parser */
   #include "lilc_compiler.hpp"

#undef yylex
#define yylex scanner.yylex
}

/*%define api.value.type variant*/
%union {
	/*
	int intVal;
	std::string * strVal;
	*/
	LILC::SynSymbol * symbolValue;
	LILC::IDToken * idTokenValue;
	LILC::ASTNode * astNode;
	LILC::ProgramNode * programNode;
	std::list<DeclNode *> * declList;
	LILC::DeclNode * declNode;
	LILC::VarDeclNode * varDeclNode;
	LILC::TypeNode * typeNode;
	LILC::IdNode * idNode;
  LILC::StructDeclNode * structDeclNode;
  LILC::FnDeclNode * fnDeclNode;
  LILC::FormalsListNode * formalsListNode;
  std::list<FormalDeclNode *> * formalsList;
  LILC::FormalDeclNode * formalsDecl;
  LILC::FnBodyNode * fnBody;
  std::list<DeclNode *> * varDeclList;
  std::list<StmtNode *> * stmtList;
  LILC::StmtNode * stmtNode;
  LILC::AssignNode * assignNode;
  LILC::ExpNode * expNode;
  LILC::ExpNode * loc;
  LILC::ExpNode * term;
  LILC::IntLitToken * intLitTokenValue;
  LILC::StringLitToken * stringLitTokenValue;
  std::list<ExpNode*>* expListNode;
  LILC::CallExpNode * callExpNode;
	/*LILC::Token * token;*/
}

%define parse.assert

%token               END    0     "end of file"
%token               NEWLINE "newline"
%token               CHAR
%token               BOOL
%token               INT
%token               VOID
%token               TRUE
%token               FALSE
%token               STRUCT
%token               INPUT
%token               OUTPUT
%token               IF
%token               ELSE
%token               WHILE
%token               RETURN
%token <idTokenValue> ID
%token <intLitTokenValue> INTLITERAL
%token <stringLitTokenValue> STRINGLITERAL
%token               LCURLY
%token               RCURLY
%token               LPAREN
%token               RPAREN
%token               SEMICOLON
%token               COMMA
%token               DOT
%token               WRITE
%token               READ
%token               PLUSPLUS
%token               MINUSMINUS
%token               PLUS
%token               MINUS
%token               TIMES
%token               DIVIDE
%token               NOT
%token               AND
%token               OR
%token               EQUALS
%token               NOTEQUALS
%token               LESS
%token               GREATER
%token               LESSEQ
%token               GREATEREQ
%token               ASSIGNDeclNode

/* Nonterminals
*  NOTE: You will need to add more nonterminals
*  to this list as you add productions to the grammar
*  below.
*/
%type <programNode> program
%type <declList> declList
%type <declNode> decl
%type <varDeclNode> varDecl
%type <typeNode> type
%type <idNode> id
%type <structDeclNode> structDecl
%type <declList> structBody
%type <fnDeclNode> fnDecl
%type <formalsListNode> formals
%type <formalsList> formalsList
%type <formalsDecl> formalDecl
%type <fnBody> fnBody
%type <varDeclList> varDeclList
%type <stmtList> stmtList
%type <stmtNode> stmt
%type <assignNode> assignExp
%type <expNode> exp
%type <loc> loc
%type <term> term
%type <expListNode> actualList
%type <callExpNode> fncall

/* NOTE: Make sure to add precedence and associativity
 * declarations
*/
%right            ASSIGN
%left             OR
%left             AND
%nonassoc         EQUALS NOTEQUALS GREATER GREATEREQ LESS LESSEQ
%left             PLUS
%left             DIVIDE TIMES
%precedence       MINUS NOT
%%

program : declList {
		   //$$ = new ProgramNode(new DeclListNode($1));
		   $$ = new ProgramNode(new DeclListNode($1));
		   compiler.setASTRoot($$);
		   }
  	;

declList : declList decl {
			 $1->push_back($2);
			 $$ = $1;
			 }
	| /* epsilon */ {
			$$ = new std::list<DeclNode *>();
			}
	;

decl : varDecl {
		$$ = $1;
		}
  | fnDecl {
    $$ = $1;
    }
  | structDecl {
    $$ = $1;
    }
  ;
varDeclList : varDeclList varDecl {
    $1->push_back($2);
    $$ = $1;
    }
  | /*epsilon*/ {
    $$ = new std::list<DeclNode *>();
    }
  ;
varDecl : type id SEMICOLON {
		$$ = new VarDeclNode($1, $2, VarDeclNode::NOT_STRUCT);
		}
  | STRUCT id id SEMICOLON {
    $$ = new VarDeclNode(new StructNode($2), $3, 0);
    }
  ;
fnDecl : type id formals fnBody {
    $$ = new FnDeclNode($1, $2, $3, $4);
    }
structDecl : STRUCT id LCURLY structBody RCURLY SEMICOLON {
    $$ = new StructDeclNode($2, new DeclListNode($4));
    }
  ;
structBody : structBody varDecl {
    $1->push_back($2);
    $$ = $1;
    }
  | varDecl {
    $$ = new std::list<DeclNode *>();
    $$->push_back($1);
    }
  ;
formals : LPAREN RPAREN {
    $$ = new FormalsListNode(new std::list<FormalDeclNode *>());
    }
  | LPAREN formalsList RPAREN {
    $$ = new FormalsListNode($2);
    }
  ;
formalsList : formalDecl {
    $$ = new std::list<FormalDeclNode *>();
    $$->push_back($1);
    }
  | formalDecl COMMA formalsList {
    $3->push_back($1);
    $$ = $3;
    }
  ;
formalDecl : type id {
    $$ = new FormalDeclNode($1, $2);
    }
fnBody : LCURLY varDeclList stmtList RCURLY {
    $$ = new FnBodyNode(new DeclListNode($2), new StmtListNode($3));
    }
stmtList : stmtList stmt {
    $1->push_back($2);
    $$ = $1;
    }
  | /*epsilon*/ {
    $$ = new std::list<StmtNode *>();
    }
  ;
stmt : assignExp SEMICOLON {
    $$ = new AssignStmtNode($1);
    }
  | loc PLUSPLUS SEMICOLON {
    $$ = new PostIncStmtNode($1);
    }
  | loc MINUSMINUS SEMICOLON {
    $$ = new PostDecStmtNode($1);
    }
  | INPUT READ loc SEMICOLON {
    $$ = new ReadStmtNode($3);
    }
  | OUTPUT WRITE exp SEMICOLON {
    $$ = new WriteStmtNode($3);
    }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
    $$ = new IfStmtNode($3, new DeclListNode($6), new StmtListNode($7));
    }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY ELSE LCURLY varDeclList stmtList RCURLY {
    $$ = new IfElseStmtNode($3, new DeclListNode($6), new StmtListNode($7),
                            new DeclListNode($11), new StmtListNode($12));
    }
  | WHILE LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
    $$ = new WhileStmtNode($3, new DeclListNode($6), new StmtListNode($7));
    }
  | RETURN exp SEMICOLON {
    $$ = new ReturnStmtNode($2);
    }
  | RETURN SEMICOLON {
    $$ = new ReturnStmtNode(nullptr);
    }
  | fncall SEMICOLON{
      $$ = new CallStmtNode($1);
    }
  ;
assignExp : loc ASSIGN exp {
    $$ = new AssignNode($1, $3);
    }
exp : exp PLUS exp {
    $$ = new PlusNode($1, $3);
    }
  | exp MINUS exp{
    $$ = new MinusNode($1, $3);
    }
  | exp TIMES exp{
    $$ = new TimesNode($1, $3);
    }
  | exp DIVIDE exp{
    $$ = new DivideNode($1, $3);
    }
  /* | exp AND exp{
    $$ = new ANDNode($1, $3);
    }
  | exp OR exp{
    $$ = new ORNode($1, $3);
    }
  | exp EQUALS exp{
    $$ = new EqualsNode($1, $3);
    }
  | exp NOTEQUALS exp{
    $$ = new NotEqualsNode($1, $3);
    }
  | exp LESS exp{
    $$ = new LessNode($1, $3);
    }
  | exp GREATER exp{
    $$ = new GreaterNode($1, $3);
    }
  | exp LESSEQ exp{
    $$ = new LessEqNode($1, $3);
    }
  | exp GREATEREQ exp{
      $$ = new GreaterEqNode($1, $3);
    } */
  | term {
    $$ = $1;
    }
term : loc {
    $$ = $1;
    }
  | INTLITERAL {
    $$ = new IntLitNode($1);
    }
  | STRINGLITERAL {
    $$ = new StrLitNode($1);
    }
  | TRUE {
    $$ = new TrueNode();
    }
  | FALSE {
    $$ = new FalseNode();
    }
  ;
fncall : id LPAREN RPAREN {
    $$ = new CallExpNode($1, new ExpListNode(new std::list<ExpNode*>()));
    }
  | id LPAREN actualList RPAREN{
    $$ = new CallExpNode($1, new ExpListNode($3));
    }
actualList : exp{
    $$ = new std::list<ExpNode*>();
    $$->push_back($1);
    }
  | actualList COMMA exp{
    $1->push_back($3);
    $$ = $1;
    }
type : INT { $$ = new IntNode();}
type : BOOL { $$ = new BoolNode();}
type : VOID {$$ = new VoidNode();}
loc : id {
    $$ = $1;
    }
  | loc DOT id {
  $$ = new DotAccessNode($1, $3);
    }
  ;
id : ID { $$ = new IdNode($1);}

%%
void
LILC::LilC_Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
