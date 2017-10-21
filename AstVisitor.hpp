#pragma once

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

class AstVisitorPreOrder : public AstVisitor {
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
    virtual void visitStructDecl(StructDecl *decl) {}
    virtual void visitVersion(Version *version) {}
};