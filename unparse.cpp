#include "ast.hpp"

namespace LILC{

void ProgramNode::unparse(std::ostream& out, int indent){
	myDeclList->unparse(out, indent);
}

void DeclListNode::unparse(std::ostream& out, int indent){
	for (std::list<DeclNode *>::iterator it=myDecls.begin();
		it != myDecls.end(); ++it){
	    DeclNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myType->unparse(out, 0);
	out << " ";
	myId->unparse(out, 0);
	out << ";\n";
}

void IdNode::unparse(std::ostream& out, int indent){
	out << myStrVal;
}

void IntNode::unparse(std::ostream& out, int indent){
	out << "int";
}

void BoolNode::unparse(std::ostream& out, int indent) {
	out << "bool";
}

void VoidNode::unparse(std::ostream& out, int indent) {
	out << "void";
}

void StructDeclNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "struct ";
	myId->unparse(out, 0);
	out << " {\n";
	myDeclList->unparse(out, indent + 1);
	out << "};\n";
}

void StructNode::unparse(std::ostream& out, int indent) {
	out << "struct ";
	myId->unparse(out, indent);
}

void FnDeclNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	myType->unparse(out, 0);
	out << " ";
	myId->unparse(out, 0);
	myFormalsList->unparse(out, 0);
	out << " {\n";
	myFnBody->unparse(out, 0);
	out << "}\n";
}

void FormalDeclNode::unparse(std::ostream& out, int indent) {
	myType->unparse(out, 0);
	out << " ";
	myId->unparse(out, 0);
}

void FormalsListNode::unparse(std::ostream& out, int indent) {
	out << "(";
	for (std::list<FormalDeclNode *>::iterator it=myFormalDeclList.begin();
		it != myFormalDeclList.end(); ++it){
	    FormalDeclNode * elt = *it;
			if (it != myFormalDeclList.begin()) {
				out << ", ";
			}
	    elt->unparse(out, indent);
	}
	out << ")";
}

void FnBodyNode::unparse(std::ostream& out, int indent) {
	myDeclList->unparse(out, indent + 1);
	myStmtList->unparse(out, indent + 1);
}

void StmtListNode::unparse(std::ostream& out, int indent) {
	for (std::list<StmtNode *>::iterator it=myStmtList.begin();
		it != myStmtList.end(); ++it){
	    StmtNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void AssignStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	myAssignNode->unparse(out, 0);
}

void AssignNode::unparse(std::ostream& out, int indent) {
	myExpNode1->unparse(out, indent);
	out << " = ";
	myExpNode2->unparse(out, indent);
	out << ";\n";
}

void ExpListNode::unparse(std::ostream& out, int indent) {
	for (std::list<ExpNode *>::iterator it=myExpList.begin();
		it != myExpList.end(); ++it){
	    ExpNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void DotAccessNode::unparse(std::ostream& out, int indent) {
	myExp->unparse(out, indent);
	out << ".";
	myId->unparse(out, indent);
}

void IntLitNode::unparse(std::ostream& out, int indent) {
	out << myIntLit->value();
}

void StrLitNode::unparse(std::ostream& out, int indent) {
	out << myStringLit->value();
}

void TrueNode::unparse(std::ostream& out, int indent) {
	out << "true";
}

void FalseNode::unparse(std::ostream& out, int indent) {
	out << "false";
}

void PostIncStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	myExp->unparse(out, 0);
	out << "++;\n";
}

void PostDecStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	myExp->unparse(out, 0);
	out << "--;\n";
}

void ReadStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "input >> ";
	myExp->unparse(out, 0);
	out << ";\n";
}

void WriteStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "output >> ";
	myExp->unparse(out, 0);
	out << ";\n";
}

void IfStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "if (";
	myExp->unparse(out, 0);
	out << ") {\n";
	myDeclList->unparse(out, indent + 1);
	myStmtList->unparse(out, indent + 1);
	doIndent(out, indent);
	out << "}\n";
}

void IfElseStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "if (";
	myExp->unparse(out, 0);
	out << ") {\n";
	myDeclList1->unparse(out, indent + 1);
	myStmtList1->unparse(out, indent + 1);
	doIndent(out, indent);
	out << "} else {\n";
	myDeclList2->unparse(out, indent + 1);
	myStmtList2->unparse(out, indent + 1);
	doIndent(out, indent);
	out << "}\n";
}

void WhileStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "while (";
	myExp->unparse(out, 0);
	out << ") {\n";
	myDeclList->unparse(out, indent + 1);
	myStmtList->unparse(out, indent + 1);
	doIndent(out, indent);
	out << "}\n";
}

void ReturnStmtNode::unparse(std::ostream& out, int indent) {
	doIndent(out, indent);
	out << "return";
	if (myExp != nullptr) {
		out << " ";
		myExp->unparse(out, 0);
	}
	out << ";\n";
}

void PlusNode::unparse(std::ostream& out, int indent) {
	out << "(";
	myExp1->unparse(out, 0);
	out << " + ";
	myExp2->unparse(out, 0);
	out << ")";
}

} // End namespace LIL' C
