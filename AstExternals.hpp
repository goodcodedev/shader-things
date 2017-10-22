#include "AstVisitor.hpp"
#include <map>

class AstExternals : public AstVisitorTransform {
public:
    std::map<std::string, Expression*> *externals;
    AstExternals(std::map<std::string, Expression*> *externals) : externals(externals) {}

    StructDecl* visitStructDecl(StructDecl *decl) {
        // Remove external struct
        if (decl->name.compare("external") == 0) {
            return NULL;
        } else {
            return AstVisitorTransform::visitStructDecl(decl);
        }
    }

    Expression* visitFieldReference(FieldReference *ref) {
        if (ref->expr->nodeType == ReferenceNode) {
            Reference *ref2 = static_cast<Reference*>(ref->expr);
            if (ref2->name.compare("external") == 0) {
                // Check map for expression
                if (externals->count(ref->field) > 0) {
                    delete ref;
                    return (*externals)[ref->field];
                }
            }
        }
        return ref;
    }
};