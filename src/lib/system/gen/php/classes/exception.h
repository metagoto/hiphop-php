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

#ifndef __GENERATED_php_classes_exception_h__
#define __GENERATED_php_classes_exception_h__

#include <cpp/base/hphp_system.h>
#include <php/classes/exception.fw.h>

// Declarations
#include <cls/unexpectedvalueexception.h>
#include <cls/overflowexception.h>
#include <cls/outofboundsexception.h>
#include <cls/logicexception.h>
#include <cls/rangeexception.h>
#include <cls/invalidargumentexception.h>
#include <cls/underflowexception.h>
#include <cls/outofrangeexception.h>
#include <cls/badmethodcallexception.h>
#include <cls/runtimeexception.h>
#include <cls/exception.h>
#include <cls/badfunctioncallexception.h>
#include <cls/lengthexception.h>
#include <cls/domainexception.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Variant pm_php$classes$exception_php(bool incOnce = false, LVariableTable* variables = NULL);
Object co_unexpectedvalueexception(CArrRef params, bool init = true);
Object co_overflowexception(CArrRef params, bool init = true);
Object co_outofboundsexception(CArrRef params, bool init = true);
Object co_logicexception(CArrRef params, bool init = true);
Object co_rangeexception(CArrRef params, bool init = true);
Object co_invalidargumentexception(CArrRef params, bool init = true);
Object co_underflowexception(CArrRef params, bool init = true);
Object co_outofrangeexception(CArrRef params, bool init = true);
Object co_badmethodcallexception(CArrRef params, bool init = true);
Object co_runtimeexception(CArrRef params, bool init = true);
Object co_exception(CArrRef params, bool init = true);
Object co_badfunctioncallexception(CArrRef params, bool init = true);
Object co_lengthexception(CArrRef params, bool init = true);
Object co_domainexception(CArrRef params, bool init = true);

///////////////////////////////////////////////////////////////////////////////
}

#endif // __GENERATED_php_classes_exception_h__
