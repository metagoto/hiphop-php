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

#include <php/globals/symbols.h>
#include <cpp/ext/ext.h>
#include <cpp/eval/eval.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
/* preface finishes */
Variant pm_php$globals$symbols_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */) {
  FUNCTION_INJECTION(run_init::globals/symbols.php);
  {
    DECLARE_SYSTEM_GLOBALS(g);
    bool &alreadyRun = g->run_pm_php$globals$symbols_php;
    if (alreadyRun) { if (incOnce) return true;}
    else alreadyRun = true;
    if (!variables) variables = g;
  }
  DECLARE_SYSTEM_GLOBALS(g);
  LVariableTable *gVariables __attribute__((__unused__)) = get_variable_table();
  Variant &v_argc __attribute__((__unused__)) = g->gv_argc;
  Variant &v_argv __attribute__((__unused__)) = g->gv_argv;
  Variant &v__SERVER __attribute__((__unused__)) = g->gv__SERVER;
  Variant &v__GET __attribute__((__unused__)) = g->gv__GET;
  Variant &v__POST __attribute__((__unused__)) = g->gv__POST;
  Variant &v__COOKIE __attribute__((__unused__)) = g->gv__COOKIE;
  Variant &v__FILES __attribute__((__unused__)) = g->gv__FILES;
  Variant &v__ENV __attribute__((__unused__)) = g->gv__ENV;
  Variant &v__REQUEST __attribute__((__unused__)) = g->gv__REQUEST;
  Variant &v__SESSION __attribute__((__unused__)) = g->gv__SESSION;
  Variant &v_HTTP_RAW_POST_DATA __attribute__((__unused__)) = g->gv_HTTP_RAW_POST_DATA;
  Variant &v_http_response_header __attribute__((__unused__)) = g->gv_http_response_header;

  setNull(v_argc);
  setNull(v_argv);
  setNull(v__SERVER);
  setNull(v__GET);
  setNull(v__POST);
  setNull(v__COOKIE);
  setNull(v__FILES);
  setNull(v__ENV);
  setNull(v__REQUEST);
  setNull(v__SESSION);
  v__SERVER = SystemScalarArrays::ssa_[0];
  v__GET = SystemScalarArrays::ssa_[0];
  v__POST = SystemScalarArrays::ssa_[0];
  v__COOKIE = SystemScalarArrays::ssa_[0];
  v__FILES = SystemScalarArrays::ssa_[0];
  v__ENV = SystemScalarArrays::ssa_[0];
  v__REQUEST = SystemScalarArrays::ssa_[0];
  v__SESSION = SystemScalarArrays::ssa_[0];
  setNull(v_HTTP_RAW_POST_DATA);
  setNull(v_http_response_header);
  return true;
} /* function */

///////////////////////////////////////////////////////////////////////////////
}