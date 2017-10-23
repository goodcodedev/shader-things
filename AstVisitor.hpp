#pragma once
#include "AstNode.hpp"

class AstVisitor {
public:
    virtual void visitSource(Source *source) = 0;
    virtual void visitExpression(AstNode *expr) = 0;
    virtual void visitStatement(AstNode *expr) = 0;
    virtual void visitAttribute(Attribute *attribute) = 0;
    virtual void visitOut(Out *out) = 0;
    virtual void visitIn(In *in) = 0;
    virtual void visitUniform(Uniform *uniform) = 0;
    virtual void visitBlock(Block *block) = 0;
    virtual void visitArgDecl(ArgDecl *argDecl) = 0;
    virtual void visitFunction(Function *function) = 0;
    virtual void visitReturn(Return *returnNode) = 0;
    virtual void visitPrePostFix(PrePostFix *prePostFix) = 0;
    virtual void visitPrePostFixStm(PrePostFixStm *prePostFix) = 0;
    virtual void visitIf(If *ifNode) = 0;
    virtual void visitForLoop(ForLoop *forLoop) = 0;
    virtual void visitIntConst(IntConst *intConst) = 0;
    virtual void visitFloatConst(FloatConst *floatConst) = 0;
    virtual void visitReference(Reference *reference) = 0;
    virtual void visitFieldReference(FieldReference *ref) = 0;
    virtual void visitBracedExpr(BracedExpr *bracedExpr) = 0;
    virtual void visitComparison(Comparison *comparison) = 0;
    virtual void visitMultiplyExpr(MultiplyExpr *expr) = 0;
    virtual void visitDivideExpr(DivideExpr *expr) = 0;
    virtual void visitPlusExpr(PlusExpr *expr) = 0;
    virtual void visitMinusExpr(MinusExpr *expr) = 0;
    virtual void visitFunctionCall(FunctionCall *call) = 0;
    virtual void visitFunctionCallStm(FunctionCallStm *call) = 0;
    virtual void visitTypeConstructor(TypeConstructor *constructor) = 0;
    virtual void visitAssignment(Assignment *assignment) = 0;
    virtual void visitOpAssignment(OpAssignment *assignment) = 0;
    virtual void visitTypedAssignment(TypedAssignment *assignment) = 0;
    virtual void visitStructMember(StructMember *member) = 0;
    virtual void visitStructDecl(StructDecl *decl) = 0;
    virtual void visitVersion(Version *version) = 0;
    virtual void visitPrecision(Precision *precision) = 0;
    virtual void visitUnaryMinus(UnaryMinus *expr) = 0;
};

class AstVisitorBase : public AstVisitor {
public:
    virtual void visitSource(Source *source) {
        for (AstNode *node : *source->nodes) {
            switch (node->nodeType) {
                case FunctionNode: visitFunction(static_cast<Function*>(node)); break;
                case AttributeNode: visitAttribute(static_cast<Attribute*>(node)); break;
                case InNode: visitIn(static_cast<In*>(node)); break;
                case OutNode: visitOut(static_cast<Out*>(node)); break;
                case UniformNode: visitUniform(static_cast<Uniform*>(node)); break;
                case TypedAssignmentNode: visitTypedAssignment(static_cast<TypedAssignment*>(node)); break;
                case StructDeclNode: visitStructDecl(static_cast<StructDecl*>(node)); break;
                case VersionNode: visitVersion(static_cast<Version*>(node)); break;
                case PrecisionNode: visitPrecision(static_cast<Precision*>(node)); break;
                default: {}
            }
        }
    }
    virtual void visitStatement(AstNode *node) {
        switch (node->nodeType) {
            case TypedAssignmentNode: visitTypedAssignment(static_cast<TypedAssignment*>(node)); break;
            case AssignmentNode: visitAssignment(static_cast<Assignment*>(node)); break;
            case OpAssignmentNode: visitOpAssignment(static_cast<OpAssignment*>(node)); break;
            case FunctionCallStmNode: visitFunctionCallStm(static_cast<FunctionCallStm*>(node)); break;
            case PrePostFixStmNode: visitPrePostFixStm(static_cast<PrePostFixStm*>(node)); break;
            case ReturnNode: visitReturn(static_cast<Return*>(node)); break;
            default: {}
        }
    }
    virtual void visitExpression(AstNode *node) {
        switch (node->nodeType) {
            case FloatConstNode: visitFloatConst(static_cast<FloatConst*>(node)); break;
            case IntConstNode: visitIntConst(static_cast<IntConst*>(node)); break;
            case TypeConstructorNode: visitTypeConstructor(static_cast<TypeConstructor*>(node)); break;
            case FunctionCallNode: visitFunctionCall(static_cast<FunctionCall*>(node)); break;
            case ReferenceNode: visitReference(static_cast<Reference*>(node)); break;
            case FieldReferenceNode: visitFieldReference(static_cast<FieldReference*>(node)); break;
            case MultiplyExprNode: visitMultiplyExpr(static_cast<MultiplyExpr*>(node)); break;
            case DivideExprNode: visitDivideExpr(static_cast<DivideExpr*>(node)); break;
            case PlusExprNode: visitPlusExpr(static_cast<PlusExpr*>(node)); break;
            case MinusExprNode: visitMinusExpr(static_cast<MinusExpr*>(node)); break;
            case BracedExprNode: visitBracedExpr(static_cast<BracedExpr*>(node)); break;
            case ComparisonNode: visitComparison(static_cast<Comparison*>(node)); break;
            case UnaryMinusNode: visitUnaryMinus(static_cast<UnaryMinus*>(node)); break;
            default: {}
        }
    }
    virtual void visitAttribute(Attribute *attribute) {}
    virtual void visitOut(Out *out) {}
    virtual void visitIn(In *in) {}
    virtual void visitUniform(Uniform *uniform) {}
    virtual void visitBlock(Block *block) {
        for (Statement *node : *block->statements) {
            visitStatement(node);
        }
    }
    virtual void visitArgDecl(ArgDecl *argDecl) {}
    virtual void visitFunction(Function *function) {
        for (ArgDecl *arg : *function->args) {
            visitArgDecl(arg);
        }
        visitBlock(function->block);
    }
    virtual void visitReturn(Return *returnNode) {
        visitExpression(returnNode->expr);
    }
    virtual void visitPrePostFix(PrePostFix *prePostFix) {}
    virtual void visitPrePostFixStm(PrePostFixStm *prePostFix) {}
    virtual void visitIf(If *ifNode) {
        visitExpression(ifNode->expr);
        visitBlock(ifNode->ifBlock);
        if (ifNode->elseBlock != NULL) {
            visitBlock(ifNode->elseBlock);
        }
    }
    virtual void visitForLoop(ForLoop *forLoop) {
        visitStatement(forLoop->init);
        visitExpression(forLoop->test);
        visitStatement(forLoop->iter);
        visitBlock(forLoop->block);
    }
    virtual void visitIntConst(IntConst *intConst) {}
    virtual void visitFloatConst(FloatConst *floatConst) {}
    virtual void visitReference(Reference *reference) {}
    virtual void visitFieldReference(FieldReference *ref) {}
    virtual void visitBracedExpr(BracedExpr *bracedExpr) {
        visitExpression(bracedExpr->expr);
    }
    virtual void visitComparison(Comparison *comparison) {
        visitExpression(comparison->expr1);
        visitExpression(comparison->expr2);
    }
    virtual void visitMultiplyExpr(MultiplyExpr *expr) {
        visitExpression(expr->op1);
        visitExpression(expr->op2);
    }
    virtual void visitDivideExpr(DivideExpr *expr) {
        visitExpression(expr->op1);
        visitExpression(expr->op2);
    }
    virtual void visitPlusExpr(PlusExpr *expr) {
        visitExpression(expr->op1);
        visitExpression(expr->op2);
    }
    virtual void visitMinusExpr(MinusExpr *expr) {
        visitExpression(expr->op1);
        visitExpression(expr->op2);
    }
    virtual void visitFunctionCall(FunctionCall *call) {
        for (Expression *arg : *call->args) {
            visitExpression(arg);
        }
    }
    virtual void visitFunctionCallStm(FunctionCallStm *call) {
        for (Expression *arg : *call->args) {
            visitExpression(arg);
        }
    }
    virtual void visitTypeConstructor(TypeConstructor *constructor) {
        for (Expression *arg : *constructor->args) {
            visitExpression(arg);
        }
    }
    virtual void visitAssignment(Assignment *assignment) {
        visitExpression(assignment->expr);
    }
    virtual void visitOpAssignment(OpAssignment *assignment) {
        visitExpression(assignment->expr);
    }
    virtual void visitTypedAssignment(TypedAssignment *assignment) {
        visitExpression(assignment->expr);
    }
    virtual void visitStructMember(StructMember *member) {}
    virtual void visitStructDecl(StructDecl *decl) {
        for (StructMember *member : *decl->members) {
            visitStructMember(member);
        }
    }
    virtual void visitVersion(Version *version) {}
    virtual void visitPrecision(Precision *precision) {}
    virtual void visitUnaryMinus(UnaryMinus *expr) {}
};

// If you transform a node, then clean up/delete the previous one
// the same place. This allows better control in reusing parts of the node.
class AstVisitorTransform {
private:
    // Allows passing in NULL to delete objects
    template<typename T>
    static void toVec(std::vector<T*>* nodes, T *node) {
        if (node != NULL) {
            nodes->push_back(node);
        }
    }
    template<typename T>
    static std::vector<T*>* checkNodes(std::vector<T*>* newNodes, std::vector<T*>* curNodes) {
        // Check if equal, in which case return the current
        if (newNodes->size() == curNodes->size()) {
            bool isEqual = true;
            for (size_t i = 0; i < curNodes->size(); ++i) {
                if ((*newNodes)[i] != (*curNodes)[i]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
                delete newNodes;
                return curNodes;
            }
        }
        // Not equal, check for each curNode in newNodes and delete those not present
        // Could be optimized to assume more similarity
        for (T* node : *curNodes) {
            bool isFound = false;
            for (T* newNode : *newNodes) {
                if (node == newNode) {
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                delete node;
            }
        }
        // Only delete the pointer addresses and vector
        delete curNodes;
        return newNodes; 
    }
public:
    virtual Source* visitSource(Source *source) {
        std::vector<AstNode*> *newNodes = new std::vector<AstNode*>();
        for (AstNode *node : *source->nodes) {
            switch (node->nodeType) {
                case FunctionNode: toVec<AstNode>(newNodes, visitFunction(static_cast<Function*>(node))); break;
                case AttributeNode: toVec<AstNode>(newNodes, visitAttribute(static_cast<Attribute*>(node))); break;
                case InNode: toVec<AstNode>(newNodes, visitIn(static_cast<In*>(node))); break;
                case OutNode: toVec<AstNode>(newNodes, visitOut(static_cast<Out*>(node))); break;
                case UniformNode: toVec<AstNode>(newNodes, visitUniform(static_cast<Uniform*>(node))); break;
                case TypedAssignmentNode: toVec<AstNode>(newNodes, visitTypedAssignment(static_cast<TypedAssignment*>(node))); break;
                case StructDeclNode: toVec<AstNode>(newNodes, visitStructDecl(static_cast<StructDecl*>(node))); break;
                case VersionNode: toVec<AstNode>(newNodes, visitVersion(static_cast<Version*>(node))); break;
                case PrecisionNode: toVec<AstNode>(newNodes, visitPrecision(static_cast<Precision*>(node))); break;
                default: { toVec<AstNode>(newNodes, node); }
            }
        }
        source->nodes = checkNodes<AstNode>(newNodes, source->nodes);
        return source;
    }
    virtual Statement* visitStatement(Statement *node) {
        switch (node->nodeType) {
            case TypedAssignmentNode:   return visitTypedAssignment(static_cast<TypedAssignment*>(node));
            case AssignmentNode:        return visitAssignment(static_cast<Assignment*>(node));
            case OpAssignmentNode:      return visitOpAssignment(static_cast<OpAssignment*>(node));
            case FunctionCallStmNode:   return visitFunctionCallStm(static_cast<FunctionCallStm*>(node));
            case PrePostFixStmNode:     return visitPrePostFixStm(static_cast<PrePostFixStm*>(node));
            case ReturnNode:            return visitReturn(static_cast<Return*>(node));
            case IfNode:                return visitIf(static_cast<If*>(node));
            case ForLoopNode:           return visitForLoop(static_cast<ForLoop*>(node));
            default: { return NULL; }
        }
    }
    virtual Expression* visitExpression(Expression *node) {
        switch (node->nodeType) {
            case FloatConstNode:        return visitFloatConst(static_cast<FloatConst*>(node));
            case IntConstNode:          return visitIntConst(static_cast<IntConst*>(node));
            case TypeConstructorNode:   return visitTypeConstructor(static_cast<TypeConstructor*>(node));
            case FunctionCallNode:      return visitFunctionCall(static_cast<FunctionCall*>(node));
            case ReferenceNode:         return visitReference(static_cast<Reference*>(node));
            case FieldReferenceNode:    return visitFieldReference(static_cast<FieldReference*>(node));
            case MultiplyExprNode:      return visitMultiplyExpr(static_cast<MultiplyExpr*>(node));
            case DivideExprNode:        return visitDivideExpr(static_cast<DivideExpr*>(node));
            case PlusExprNode:          return visitPlusExpr(static_cast<PlusExpr*>(node));
            case MinusExprNode:         return visitMinusExpr(static_cast<MinusExpr*>(node));
            case BracedExprNode:        return visitBracedExpr(static_cast<BracedExpr*>(node));
            case ComparisonNode:        return visitComparison(static_cast<Comparison*>(node));
            case UnaryMinusNode:        return visitUnaryMinus(static_cast<UnaryMinus*>(node));
            default: { return NULL; }
        }
    }
    virtual Attribute* visitAttribute(Attribute *attribute) {
        return attribute;
    }
    virtual Out* visitOut(Out *out) {
        return out;
    }
    virtual In* visitIn(In *in) {
        return in;
    }
    virtual Uniform* visitUniform(Uniform *uniform) {
        return uniform;
    }
    virtual Block* visitBlock(Block *block) {
        std::vector<Statement*> *newNodes = new std::vector<Statement*>();
        for (Statement *node : *block->statements) {
            toVec<Statement>(newNodes, visitStatement(node));
        }
        block->statements = checkNodes<Statement>(newNodes, block->statements);
        return block;
    }
    virtual ArgDecl* visitArgDecl(ArgDecl *argDecl) {
        return argDecl;
    }
    virtual Function* visitFunction(Function *function) {
        std::vector<ArgDecl*> *newNodes = new std::vector<ArgDecl*>();
        for (ArgDecl *arg : *function->args) {
            toVec<ArgDecl>(newNodes, visitArgDecl(arg));
        }
        function->args = checkNodes<ArgDecl>(newNodes, function->args);
        function->block = visitBlock(function->block);
        return function;
    }
    virtual Return* visitReturn(Return *returnNode) {
        returnNode->expr = visitExpression(returnNode->expr);
        return returnNode;
    }
    virtual Expression* visitPrePostFix(PrePostFix *prePostFix) {
        return prePostFix;
    }
    virtual Statement* visitPrePostFixStm(PrePostFixStm *prePostFix) {
        return prePostFix;
    }
    virtual If* visitIf(If *ifNode) {
        ifNode->expr = visitExpression(ifNode->expr);
        ifNode->ifBlock = visitBlock(ifNode->ifBlock);
        if (ifNode->elseBlock != NULL) {
            ifNode->elseBlock = visitBlock(ifNode->elseBlock);
        }
        return ifNode;
    }
    virtual ForLoop* visitForLoop(ForLoop *forLoop) {
        forLoop->init = visitStatement(forLoop->init);
        forLoop->test = visitExpression(forLoop->test);
        forLoop->iter = visitStatement(forLoop->iter);
        forLoop->block = visitBlock(forLoop->block);
        return forLoop;
    }
    virtual Expression* visitIntConst(IntConst *intConst) {
        return intConst;
    }
    virtual Expression* visitFloatConst(FloatConst *floatConst) {
        return floatConst;
    }
    virtual Expression* visitReference(Reference *reference) {
        return reference;
    }
    virtual Expression* visitFieldReference(FieldReference *ref) {
        return ref;
    }
    virtual Expression* visitBracedExpr(BracedExpr *bracedExpr) {
        bracedExpr->expr = visitExpression(bracedExpr->expr);
        return bracedExpr;
    }
    virtual Expression* visitComparison(Comparison *comparison) {
        comparison->expr1 = visitExpression(comparison->expr1);
        comparison->expr2 = visitExpression(comparison->expr2);
        return comparison;
    }
    virtual Expression* visitMultiplyExpr(MultiplyExpr *expr) {
        expr->op1 = visitExpression(expr->op1);
        expr->op2 = visitExpression(expr->op2);
        return expr;
    }
    virtual Expression* visitDivideExpr(DivideExpr *expr) {
        expr->op1 = visitExpression(expr->op1);
        expr->op2 = visitExpression(expr->op2);
        return expr;
    }
    virtual Expression* visitPlusExpr(PlusExpr *expr) {
        expr->op1 = visitExpression(expr->op1);
        expr->op2 = visitExpression(expr->op2);
        return expr;
    }
    virtual Expression* visitMinusExpr(MinusExpr *expr) {
        expr->op1 = visitExpression(expr->op1);
        expr->op2 = visitExpression(expr->op2);
        return expr;
    }
    virtual Expression* visitFunctionCall(FunctionCall *call) {
        std::vector<Expression*> *newNodes = new std::vector<Expression*>();
        for (Expression *arg : *call->args) {
            toVec<Expression>(newNodes, visitExpression(arg));
        }
        call->args = checkNodes<Expression>(newNodes, call->args);
        return call;
    }
    virtual Statement* visitFunctionCallStm(FunctionCallStm *call) {
        std::vector<Expression*> *newNodes = new std::vector<Expression*>();
        for (Expression *arg : *call->args) {
            toVec<Expression>(newNodes, visitExpression(arg));
        }
        call->args = checkNodes<Expression>(newNodes, call->args);
        return call;
    }
    virtual TypeConstructor* visitTypeConstructor(TypeConstructor *constructor) {
        std::vector<Expression*> *newNodes = new std::vector<Expression*>();
        for (Expression *arg : *constructor->args) {
            toVec<Expression>(newNodes, visitExpression(arg));
        }
        constructor->args = checkNodes<Expression>(newNodes, constructor->args);
        return constructor;
    }
    virtual Assignment* visitAssignment(Assignment *assignment) {
        assignment->expr = visitExpression(assignment->expr);
        return assignment;
    }
    virtual OpAssignment* visitOpAssignment(OpAssignment *assignment) {
        assignment->expr = visitExpression(assignment->expr);
        return assignment;
    }
    virtual TypedAssignment* visitTypedAssignment(TypedAssignment *assignment) {
        assignment->expr = visitExpression(assignment->expr);
        return assignment;
    }
    virtual StructMember* visitStructMember(StructMember *member) {
        return member;
    }
    virtual StructDecl* visitStructDecl(StructDecl *decl) {
        std::vector<StructMember*> *newNodes = new std::vector<StructMember*>();
        for (StructMember *member : *decl->members) {
            toVec<StructMember>(newNodes, visitStructMember(member));
        }
        decl->members = checkNodes<StructMember>(newNodes, decl->members);
        return decl;
    }
    virtual Version* visitVersion(Version *version) {
        return version;
    }
    virtual Precision* visitPrecision(Precision *precision) {
        return precision;
    }
    virtual UnaryMinus* visitUnaryMinus(UnaryMinus *expr) {
        return expr;
    }
};
