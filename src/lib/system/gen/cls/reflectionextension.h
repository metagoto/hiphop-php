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

#ifndef __GENERATED_CLS_REFLECTIONEXTENSION_H__
#define __GENERATED_CLS_REFLECTIONEXTENSION_H__

#include <cls/reflector.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* SRC: classes/reflection.php line 676 */
class c_reflectionextension : virtual public c_reflector {
  BEGIN_CLASS_MAP(reflectionextension)
    PARENT_CLASS(reflector)
  END_CLASS_MAP(reflectionextension)
  DECLARE_CLASS(reflectionextension, ReflectionExtension, ObjectData)
  DECLARE_INVOKES_FROM_EVAL
  void init();
  public: Variant m_name;
  public: Array m_info;
  public: void t___construct(Variant v_name);
  public: ObjectData *create(Variant v_name);
  public: ObjectData *dynCreate(CArrRef params, bool init = true);
  public: void dynConstruct(CArrRef params);
  public: String t___tostring();
  public: static Variant ti_export(const char* cls, CVarRef v_name, CVarRef v_ret);
  public: Variant t_getname();
  public: Variant t_getversion();
  public: Variant t_getfunctions();
  public: Variant t_getconstants();
  public: Variant t_getinientries();
  public: Variant t_getclasses();
  public: Array t_getclassnames();
  public: Variant t_info();
  public: static Variant t_export(CVarRef v_name, CVarRef v_ret) { return ti_export("reflectionextension", v_name, v_ret); }
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __GENERATED_CLS_REFLECTIONEXTENSION_H__