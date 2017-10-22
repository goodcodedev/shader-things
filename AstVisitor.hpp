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
    virtual void visitIf(If *ifNode) = 0;
    virtual void visitForLoop(ForLoop *forLoop) = 0;
    virtual void visitIntConst(IntConst *intConst) = 0;
    virtual void visitFloatConst(FloatConst *floatConst) = 0;
    virtual void visitReference(Reference *reference) = 0;
    virtual void visitFieldReference(FieldReference *fieldReference) = 0;
    virtual void visitBracedExpr(BracedExpr *bracedExpr) = 0;
    virtual void visitComparison(Comparison *comparison) = 0;
    virtual void visitMultiplyExpr(MultiplyExpr *expr) = 0;
    virtual void visitDivideExpr(DivideExpr *expr) = 0;
    virtual void visitPlusExpr(PlusExpr *expr) = 0;
    virtual void visitMinusExpr(MinusExpr *expr) = 0;
    virtual void visitFunctionCall(FunctionCall *call) = 0;
    virtual void visitTypeConstructor(TypeConstructor *constructor) = 0;
    virtual void visitAssignment(Assignment *assignment) = 0;
    virtual void visitOpAssignment(OpAssignment *assignment) = 0;
    virtual void visitTypedAssignment(TypedAssignment *assignment) = 0;
    virtual void visitStructMember(StructMember *member) = 0;
    virtual void visitStructDecl(StructDecl *decl) = 0;
    virtual void visitVersion(Version *version) = 0;
};

class AstVisitorBase : public AstVisitor {
public:
    virtual void visitSource(Source *source) {
        for (AstNode *node : *source->nodes) {
            switch (node->nodeType) {
                case FunctionNode: visitFunction(reinterpret_cast<Function*>(node)); break;
                case AttributeNode: visitAttribute(reinterpret_cast<Attribute*>(node)); break;
                case InNode: visitIn(reinterpret_cast<In*>(node)); break;
                case OutNode: visitOut(reinterpret_cast<Out*>(node)); break;
                case UniformNode: visitUniform(reinterpret_cast<Uniform*>(node)); break;
                case TypedAssignmentNode: visitTypedAssignment(reinterpret_cast<TypedAssignment*>(node)); break;
                case StructDeclNode: visitStructDecl(reinterpret_cast<StructDecl*>(node)); break;
                case VersionNode: visitVersion(reinterpret_cast<Version*>(node)); break;
                default: {}
            }
        }
    }
    virtual void visitStatement(AstNode *node) {
        switch (node->nodeType) {
            case TypedAssignmentNode: visitTypedAssignment(reinterpret_cast<TypedAssignment*>(node)); break;
            case AssignmentNode: visitAssignment(reinterpret_cast<Assignment*>(node)); break;
            case OpAssignmentNode: visitOpAssignment(reinterpret_cast<OpAssignment*>(node)); break;
            case FunctionCallNode: visitFunctionCall(reinterpret_cast<FunctionCall*>(node)); break;
            case PrePostFixNode: visitPrePostFix(reinterpret_cast<PrePostFix*>(node)); break;
            case ReturnNode: visitReturn(reinterpret_cast<Return*>(node)); break;
            default: {}
        }
    }
    virtual void visitExpression(AstNode *node) {
        switch (node->nodeType) {
            case FloatConstNode: visitFloatConst(reinterpret_cast<FloatConst>(node)); break;
            case IntConstNode: visitIntConst(reinterpret_cast<IntConst>(node)); break;
            case TypeConstructorNode: visitTypeConstructor(reinterpret_cast<TypeConstructor>(node)); break;
            case FunctionCallNode: visitFunctionCall(reinterpret_cast<FunctionCall>(node)); break;
            case ReferenceNode: visitReference(reinterpret_cast<Reference>(node)); break;
            case FieldReferenceNode: visitFieldReference(reinterpret_cast<FieldReference>(node)); break;
            case MultiplyExprNode: visitMultiplyExpr(reinterpret_cast<MultiplyExpr>(node)); break;
            case DivideExprNode: visitDivideExpr(reinterpret_cast<DivideExpr>(node)); break;
            case PlusExprNode: visitPlusExpr(reinterpret_cast<PlusExpr>(node)); break;
            case MinusExprNode: visitMinusExpr(reinterpret_cast<MinusExpr>(node)); break;
            case BracedExprNode: visitBracedExpr(reinterpret_cast<BracedExpr>(node)); break;
            case ComparisonNode: visitComparison(reinterpret_cast<Comparison>(node)); break;
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
        visitExpression(ReturnNode->expr);
    }
    virtual void visitPrePostFix(PrePostFix *prePostFix) {}
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
    virtual void visitFieldReference(FieldReference *fieldReference) {}
    virtual void visitBracedExpr(BracedExpr *bracedExpr) {
        visitExpression(BracedExpr->expr);
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
        for (Expression *arg : call->args) {
            visitExpression(arg);
        }
    }
    virtual void visitTypeConstructor(TypeConstructor *constructor) {
        for (Expression *arg : constructor->args) {
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
        for (StructMember *member : decl->members) {
            visitArgDecl(member);
        }
    }
    virtual void visitVersion(Version *version) {}
};

class AstVisitorTransform : public AstVisitor {
private:
    // Allows passing in NULL to delete objects
    template<typename T>
    static void toVec(std::vector<T*> nodes, T *node) {
        if (node != NULL) {
            nodes.push_back(node);
        }
    }
    template<typename T>
    static std::vector<T*>* checkNodes(std::vector<T*>* newNodes, std::vector<T*>* curNodes) {
        // Check if equal, in which case return the current
        if (newNodes.size() == curNodes.size()) {
            bool isEqual = true;
            for (int i = 0; i < curNodes.size(); i++) {
                if (newNodes[i] != curNodes[i]) {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) {
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
        std::vector<AstNode*> newNodes = new std::vector<AstNode*>();
        for (AstNode *node : *source->nodes) {
            switch (node->nodeType) {
                case FunctionNode: toVec<AstNode>(newNodes, visitFunction(reinterpret_cast<Function*>(node))); break;
                case AttributeNode: toVec<AstNode>(newNodes, visitAttribute(reinterpret_cast<Attribute*>(node))); break;
                case InNode: toVec<AstNode>(newNodes, visitIn(reinterpret_cast<In*>(node))); break;
                case OutNode: toVec<AstNode>(newNodes, visitOut(reinterpret_cast<Out*>(node))); break;
                case UniformNode: toVec<AstNode>(newNodes, visitUniform(reinterpret_cast<Uniform*>(node))); break;
                case TypedAssignmentNode: toVec<AstNode>(newNodes, visitTypedAssignment(reinterpret_cast<TypedAssignment*>(node))); break;
                case StructDeclNode: toVec<AstNode>(newNodes, visitStructDecl(reinterpret_cast<StructDecl*>(node))); break;
                case VersionNode: toVec<AstNode>(newNodes, visitVersion(reinterpret_cast<Version*>(node))); break;
                default: { toVec<AstNode>(newNodes, node); }
            }
        }
        source->nodes = checkNodes<AstNode>(newNodes, source->nodes);
        return source;
    }
    virtual Statement* visitStatement(Statement *node) {
        switch (node->nodeType) {
            case TypedAssignmentNode:   return visitTypedAssignment(reinterpret_cast<TypedAssignment*>(node));
            case AssignmentNode:        return visitAssignment(reinterpret_cast<Assignment*>(node));
            case OpAssignmentNode:      return visitOpAssignment(reinterpret_cast<OpAssignment*>(node));
            case FunctionCallNode:      return visitFunctionCall(reinterpret_cast<FunctionCall*>(node));
            case PrePostFixNode:        return visitPrePostFix(reinterpret_cast<PrePostFix*>(node));
            case ReturnNode:            return visitReturn(reinterpret_cast<Return*>(node));
            default: { return NULL; }
        }
    }
    virtual Expression* visitExpression(Expression *node) {
        switch (node->nodeType) {
            case FloatConstNode:        return visitFloatConst(reinterpret_cast<FloatConst>(node));
            case IntConstNode:          return visitIntConst(reinterpret_cast<IntConst>(node));
            case TypeConstructorNode:   return visitTypeConstructor(reinterpret_cast<TypeConstructor>(node));
            case FunctionCallNode:      return visitFunctionCall(reinterpret_cast<FunctionCall>(node));
            case ReferenceNode:         return visitReference(reinterpret_cast<Reference>(node));
            case FieldReferenceNode:    return visitFieldReference(reinterpret_cast<FieldReference>(node));
            case MultiplyExprNode:      return visitMultiplyExpr(reinterpret_cast<MultiplyExpr>(node));
            case DivideExprNode:        return visitDivideExpr(reinterpret_cast<DivideExpr>(node));
            case PlusExprNode:          return visitPlusExpr(reinterpret_cast<PlusExpr>(node));
            case MinusExprNode:         return visitMinusExpr(reinterpret_cast<MinusExpr>(node));
            case BracedExprNode:        return visitBracedExpr(reinterpret_cast<BracedExpr>(node));
            case ComparisonNode:        return visitComparison(reinterpret_cast<Comparison>(node));
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
        std::vector<Statement*> newNodes = new std::vector<Statement*>();
        for (Statement *node : *block->statements) {
            toVec<Statement>(newNodes, visitStatement(node));
        }
        block->statements = checkNodes<<Statement>AstNode>(newNodes, block->statements);
        return block;
    }
    virtual ArgDecl* visitArgDecl(ArgDecl *argDecl) {
        return argDecl;
    }
    virtual Function* visitFunction(Function *function) {
        std::vector<ArgDecl*> newNodes = new std::vector<ArgDecl*>();
        for (ArgDecl *arg : *function->args) {
            toVec<ArgDecl>(visitArgDecl(arg));
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
    virtual If visitIf(If *ifNode) {
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
    virtual Expression* visitFieldReference(FieldReference *fieldReference) {
        return FieldReference;
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
        std::vector<Expression*> newNodes = new std::vector<Expression*>();
        for (Expression *arg : call->args) {
            toVec<Expression>(newNodes, visitExpression(arg));
        }
        call->args = checkNodes<Expression>(newNodes, call->args);
        return call;
    }
    virtual TypeConstructor* visitTypeConstructor(TypeConstructor *constructor) {
        std::vector<Expression*> newNodes = new std::vector<Expression*>();
        for (Expression *arg : constructor->args) {
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
        std::vector<StructMember*> newNodes = new std::vector<StructMember*>();
        for (StructMember *member : decl->members) {
            toVec<StructMember>(newNodes, visitArgDecl(member));
        }
        decl->members = checkNodes<StructMember>(newNodes, decl->members);
        return decl;
    }
    virtual Version* visitVersion(Version *version) {
        return version;
    }
};
