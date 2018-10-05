#ifndef LILC_AST_HPP
#define LILC_AST_HPP

#include <ostream>
#include <list>
#include "symbols.hpp"

//Here is a suggestion for all the different kinds of AST nodes
// and what kinds
// of children they have. All of these kinds of AST nodes are
// subclasses of ASTNode.
// Indentation indicates further subclassing:
//
//     Subclass		Children
//     --------		------
//     ProgramNode	DeclListNode
//     DeclListNode	linked list of DeclNode
//     DeclNode
//       VarDeclNode	TypeNode, IdNode, int
//       FnDeclNode	TypeNode, IdNode, FormalsListNode, FnBodyNode
//       FormalDeclNode    TypeNode, IdNode
//       StructDeclNode    IdNode, DeclListNode
//
//     FormalsListNode     linked list of FormalDeclNode
//     FnBodyNode          DeclListNode, StmtListNode
//     StmtListNode        linked list of StmtNode
//     ExpListNode         linked list of ExpNode
//
//     TypeNode:
//       IntNode           -- none --
//       BoolNode          -- none --
//       VoidNode          -- none --
//       StructNode        IdNode
//
//     StmtNode:
//       AssignStmtNode      AssignNode
//       PostIncStmtNode     ExpNode
//       PostDecStmtNode     ExpNode
//       ReadStmtNode        ExpNode
//       WriteStmtNode       ExpNode
//       IfStmtNode          ExpNode, DeclListNode, StmtListNode
//       IfElseStmtNode      ExpNode, DeclListNode, StmtListNode,
//                                    DeclListNode, StmtListNode
//       WhileStmtNode       ExpNode, DeclListNode, StmtListNode
//       CallStmtNode        CallExpNode
//       ReturnStmtNode      ExpNode
//
//     ExpNode:
//       IntLitNode          -- none --
//       StrLitNode          -- none --
//       TrueNode            -- none --
//       FalseNode           -- none --
//       IdNode              -- none --
//       DotAccessNode       ExpNode, IdNode
//       AssignNode          ExpNode, ExpNode
//       CallExpNode         IdNode, ExpListNode
//       UnaryExpNode        ExpNode
//         UnaryMinusNode
//         NotNode
//       BinaryExpNode       ExpNode ExpNode
//         PlusNode
//         MinusNode
//         TimesNode
//         DivideNode
//         AndNode
//         OrNode
//         EqualsNode
//         NotEqualsNode
//         LessNode
//         GreaterNode
//         LessEqNode
//         GreaterEqNode
//
//
// Here are the different kinds of AST nodes again, organized according to
// whether they are leaves, internal nodes with linked lists of kids, or
// internal nodes with a fixed number of kids:
//
// (1) Leaf nodes:
//        IntNode,   BoolNode,  VoidNode,  IntLitNode,  StrLitNode,
//        TrueNode,  FalseNode, IdNode
//
// (2) Internal nodes with (possibly empty) linked lists of children:
//        DeclListNode, FormalsListNode, StmtListNode, ExpListNode
//
// (3) Internal nodes with fixed numbers of kids:
//        ProgramNode,     VarDeclNode,     FnDeclNode,     FormalDeclNode,
//        StructDeclNode,  FnBodyNode,      StructNode,     AssignStmtNode,
//        PostIncStmtNode, PostDecStmtNode, ReadStmtNode,   WriteStmtNode
//        IfStmtNode,      IfElseStmtNode,  WhileStmtNode,  CallStmtNode
//        ReturnStmtNode,  DotAccessNode,   CallExpNode,
//        UnaryExpNode,    BinaryExpNode,   UnaryMinusNode, NotNode,
//        PlusNode,        MinusNode,       TimesNode,      DivideNode,
//        AndNode,         OrNode,          EqualsNode,     NotEqualsNode,
//        LessNode,        GreaterNode,     LessEqNode,     GreaterEqNode
//
// **********************************************************************

// **********************************************************************
// ASTnode class (base class for all other kinds of nodes)
// **********************************************************************

namespace LILC{

class SymSymbol;
class DeclListNode;
class DeclNode;
class TypeNode;
class IdNode;
class FormalsListNode;
class FnBodyNode;
class StmtNode;
class StmtListNode;
class AssignNode;
class ExpNode;
class CallExpNode;

class ASTNode{
public:
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
};

class ProgramNode : public ASTNode{
public:
	ProgramNode(DeclListNode * L) : ASTNode(){
		myDeclList = L;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode * myDeclList;

};

class ExpNode : public ASTNode {
public:
	ExpNode() : ASTNode() {
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

class ExpListNode : public ASTNode {
public:
	ExpListNode(std::list<ExpNode *> * expList) : ASTNode() {
		myExpList = *expList;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<ExpNode *> myExpList;
};

class DeclListNode : public ASTNode{
public:
	DeclListNode(std::list<DeclNode *> * decls) : ASTNode(){
		myDecls = *decls;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<DeclNode *> myDecls;
};

class DeclNode : public ASTNode{
public:
	virtual void unparse(std::ostream& out, int indent) = 0;
};

class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id, int size) : DeclNode(){
		myType = type;
		myId = id;
		mySize = size;
	}
	void unparse(std::ostream& out, int indent);
	static const int NOT_STRUCT = -1; //Use this value for mySize
					  // if this is not a struct type
private:
	TypeNode * myType;
	IdNode * myId;
	int mySize;
};

class TypeNode : public ASTNode{
public:
	TypeNode() : ASTNode(){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

class IdNode : public ExpNode{
public:
	IdNode(IDToken * token) : ExpNode(){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	std::string myStrVal;
};

class IntNode : public TypeNode{
public:
	IntNode(): TypeNode(){
	}
	void unparse(std::ostream& out, int indent);
};

class BoolNode : public TypeNode {
public:
	BoolNode() : TypeNode() {
	}
	void unparse(std::ostream& out, int indent);
};

class VoidNode : public TypeNode {
public:
	VoidNode() : TypeNode() {
	}
	void unparse(std::ostream& out, int indent);
};

class StructDeclNode : public DeclNode {
public:
	StructDeclNode(IdNode * id, DeclListNode * declList) : DeclNode() {
		myId = id;
		myDeclList = declList;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode * myId;
	DeclListNode * myDeclList;
};

class StructNode : public TypeNode {
public:
	StructNode(IdNode * id) : TypeNode() {
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode * myId;
};

class FnDeclNode : public DeclNode {
public:
	FnDeclNode(TypeNode * type, IdNode * id, FormalsListNode * formalsList,
		FnBodyNode * fnBody) : DeclNode() {
			myType = type;
			myId = id;
			myFormalsList = formalsList;
			myFnBody = fnBody;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
	FormalsListNode * myFormalsList;
	FnBodyNode * myFnBody;
};

class FormalDeclNode : public DeclNode {
public:
	FormalDeclNode(TypeNode * type, IdNode * id) : DeclNode() {
		myType = type;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
};

class FormalsListNode : public ASTNode {
public:
	FormalsListNode(std::list<FormalDeclNode *> * formalDeclList) : ASTNode() {
		myFormalDeclList = *formalDeclList;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<FormalDeclNode *> myFormalDeclList;
};

class FnBodyNode : public ASTNode {
public:
	FnBodyNode(DeclListNode * declList, StmtListNode * stmtList) : ASTNode() {
		myDeclList = declList;
		myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

class StmtListNode : public ASTNode {
public:
	StmtListNode(std::list<StmtNode *> * stmtList) : ASTNode() {
		myStmtList = *stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<StmtNode *> myStmtList;
};

class StmtNode : public ASTNode {
public:
	StmtNode() : ASTNode() {
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

class AssignStmtNode : public StmtNode {
public:
	AssignStmtNode(AssignNode * assignNode) : StmtNode() {
		myAssignNode = assignNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	AssignNode * myAssignNode;
};

class AssignNode : public ExpNode {
public:
	AssignNode(ExpNode * expNode1, ExpNode * expNode2) : ExpNode() {
		myExpNode1 = expNode1;
		myExpNode2 = expNode2;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExpNode1;
	ExpNode * myExpNode2;
};

class DotAccessNode : public ExpNode {
public:
	DotAccessNode(ExpNode * expNode, IdNode * id) : ExpNode() {
		myExp = expNode;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	IdNode * myId;
};

class IntLitNode : public ExpNode {
public:
	IntLitNode(IntLitToken * intLit) : ExpNode() {
		myIntLit = intLit;
	}
	void unparse(std::ostream& out, int indent);
private:
	IntLitToken * myIntLit;
};

class StrLitNode : public ExpNode {
public:
	StrLitNode(StringLitToken * stringLit) : ExpNode() {
		myStringLit = stringLit;
	}
	void unparse(std::ostream& out, int indent);
private:
	StringLitToken * myStringLit;
};

class TrueNode : public ExpNode {
public:
	TrueNode() : ExpNode() {
	}
	void unparse(std::ostream& out, int indent);
};

class FalseNode : public ExpNode {
public:
	FalseNode() : ExpNode() {
	}
	void unparse(std::ostream& out, int indent);
};

class PostIncStmtNode : public StmtNode {
public:
	PostIncStmtNode(ExpNode * expNode) : StmtNode() {
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

class PostDecStmtNode : public StmtNode {
public:
	PostDecStmtNode(ExpNode * expNode) : StmtNode() {
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

class ReadStmtNode : public StmtNode {
public:
	ReadStmtNode(ExpNode * expNode) : StmtNode() {
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

class WriteStmtNode : public StmtNode {
public:
	WriteStmtNode(ExpNode * expNode) : StmtNode() {
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

class IfStmtNode : public StmtNode {
public:
	IfStmtNode(ExpNode * expNode, DeclListNode* declList,
		StmtListNode * stmtList) : StmtNode() {
			myExp = expNode;
			myDeclList = declList;
			myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

class IfElseStmtNode : public StmtNode {
public:
	IfElseStmtNode(ExpNode * expNode, DeclListNode* declList1,
		StmtListNode * stmtList1, DeclListNode* declList2,
			StmtListNode * stmtList2) : StmtNode() {
			myExp = expNode;
			myDeclList1 = declList1;
			myStmtList1 = stmtList1;
			myDeclList2 = declList2;
			myStmtList2 = stmtList2;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList1;
	StmtListNode * myStmtList1;
	DeclListNode * myDeclList2;
	StmtListNode * myStmtList2;
};

class WhileStmtNode : public StmtNode {
public:
	WhileStmtNode(ExpNode * expNode, DeclListNode* declList,
		StmtListNode * stmtList) : StmtNode() {
			myExp = expNode;
			myDeclList = declList;
			myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

class ReturnStmtNode : public StmtNode {
public:
	ReturnStmtNode(ExpNode * expNode) : StmtNode() {
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode * myExp;
};

class BinaryExpNode : public ExpNode {
public:
	BinaryExpNode(ExpNode * expNode1, ExpNode * expNode2) : ExpNode() {
		myExp1 = expNode1;
		myExp2 = expNode2;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
protected:
	ExpNode * myExp1;
	ExpNode * myExp2;
};

class PlusNode : public BinaryExpNode {
public:
	PlusNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class MinusNode : public BinaryExpNode {
public:
	MinusNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class TimesNode : public BinaryExpNode {
public:
	TimesNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class DivideNode : public BinaryExpNode {
public:
	DivideNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class AndNode : public BinaryExpNode {
public:
	AndNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class OrNode : public BinaryExpNode {
public:
	OrNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class EqualsNode : public BinaryExpNode {
public:
	EqualsNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class NotEqualsNode : public BinaryExpNode {
public:
	NotEqualsNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class LessNode : public BinaryExpNode {
public:
	LessNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class GreaterNode : public BinaryExpNode {
public:
	GreaterNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class LessEqNode : public BinaryExpNode {
public:
	LessEqNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class GreaterEqNode : public BinaryExpNode {
public:
	GreaterEqNode(ExpNode * expNode1, ExpNode * expNode2) : BinaryExpNode(expNode1, expNode2) {
	}
	void unparse(std::ostream& out, int indent);
};

class CallExpNode : public ExpNode{
public:
	CallExpNode(IdNode * id, ExpListNode * expListNode) : ExpNode(){
		myExpList = expListNode;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpListNode * myExpList;
	IdNode * myId;
};

class CallStmtNode : public StmtNode{
public:
	CallStmtNode(CallExpNode * callExpNode) : StmtNode(){
		myCallExpNode = callExpNode;
	}
	void unparse(std::ostream& out, int indent);
private:
	CallExpNode * myCallExpNode;
};

} //End namespace LIL' C

#endif
