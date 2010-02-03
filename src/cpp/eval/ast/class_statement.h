/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __EVAL_CLASS_STATEMENT_H__
#define __EVAL_CLASS_STATEMENT_H__

#include <cpp/eval/ast/statement.h>
#include <cpp/base/class_info.h>
#include <util/case_insensitive.h>

namespace HPHP {
namespace Eval {
///////////////////////////////////////////////////////////////////////////////

DECLARE_AST_PTR(Expression);
DECLARE_AST_PTR(ClassVariable);
DECLARE_AST_PTR(ClassStatement);
DECLARE_AST_PTR(MethodStatement);
DECLARE_AST_PTR(ScalarExpression);
class EvalObjectData;
class ClassInfoEvaled;
class ClassEvalState;

class ClassVariable : public Construct {
public:
  ClassVariable(CONSTRUCT_ARGS, const std::string &name, int modifiers,
                ExpressionPtr value, const std::string &doc);
  void set(VariableEnvironment &env, EvalObjectData *self) const;
  void setStatic(VariableEnvironment &env, LVariableTable &statics) const;
  virtual void dump() const;
  const std::string &name() const { return m_name; }
  void getInfo(ClassInfo::PropertyInfo &info) const;
  int getModifiers() const { return m_modifiers; }
private:
  std::string m_name;
  int64 m_hash;
  int m_modifiers;
  ExpressionPtr m_value;
  std::string m_docComment;
};

class ClassStatement : public Statement {
public:
  enum Modifier {
    Public = 1,
    Protected = 2,
    Private = 4,
    Static = 8,
    Abstract = 16,
    Final = 32,
    Interface = 64
  };

  ClassStatement(STATEMENT_ARGS, const std::string &name,
                 const std::string &parent, const std::string &doc);
  void finish();
  const std::string &name() const { return m_name; }
  const std::string &lname() const { return m_lname; }
  const std::string &parent() const { return m_parent; }
  const ClassStatement *parentStatement() const;
  void setModifiers(int m) { m_modifiers = m; }
  int getModifiers() const { return m_modifiers; }
  void addBases(const std::vector<String> &bases);
  void addVariable(ClassVariablePtr v) {
    m_variables[v->name().c_str()] = v;
    m_variablesVec.push_back(v);
  }
  void addMethod(MethodStatementPtr m);
  void addConstant(const std::string &name, ExpressionPtr v);

  bool instanceOf(const char *c) const;
  bool subclassOf(const char *c) const;

  // Eval is called at declaration, not invocation
  virtual void eval(VariableEnvironment &env) const;
  // Called by create_class
  Object create(ClassEvalState &ce, CArrRef params, bool init,
                ObjectData* root = NULL) const;
  void initializeObject(EvalObjectData *obj) const;
  void initializeStatics(LVariableTable &statics) const;

  const MethodStatement* findMethod(const char* name) const;
  bool getConstant(Variant &res, const char *c) const;

  virtual void dump() const;
  static void printModifiers(int m);

  void getPropertyInfo(ClassInfoEvaled &owner) const;
  void getInfo(ClassInfoEvaled &info) const;

  bool hasAccess(CStrRef context, Modifier level) const;
  bool attemptPropertyAccess(CStrRef prop) const;

  void loadMethodTable(hphp_const_char_imap<const MethodStatement*> &mtable)
    const;

protected:
  std::string m_name;
  std::string m_lname;
  int m_modifiers;

  std::string m_parent;
  hphp_const_char_imap<bool> m_bases;
  std::vector<std::string> m_basesVec;

  hphp_const_char_imap<ClassVariablePtr> m_variables;
  std::vector<ClassVariablePtr> m_variablesVec;
  hphp_const_char_imap<MethodStatementPtr> m_methods;
  std::vector<MethodStatementPtr> m_methodsVec;
  std::map<std::string, ExpressionPtr> m_constants;

  std::string m_docComment;

  void loadProperties(ClassInfoEvaled &info) const;
};

///////////////////////////////////////////////////////////////////////////////
}
}

#endif /* __EVAL_CLASS_STATEMENT_H__ */