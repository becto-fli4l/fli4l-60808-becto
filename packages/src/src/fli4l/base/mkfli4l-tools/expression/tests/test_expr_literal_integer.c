/*****************************************************************************
 *  @file test_expr_literal_integer.c
 *  Functions for testing literal integer expressions.
 *
 *  Copyright (c) 2012-2016 The fli4l team
 *
 *  This file is part of fli4l.
 *
 *  fli4l is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  fli4l is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with fli4l.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Last Update: $Id$
 *****************************************************************************
 */

#include <testing/tests.h>
#include <expression.h>
#include <libmkfli4l/str.h>
#include <stdlib.h>
#include <string.h>

#define MU_TESTSUITE "expression.expr_literal"

/**
 * Tests expr_get_type().
 */
mu_test_begin(test_expr_literal_integer_gettype)
    struct expr_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    mu_assert_eq_int(EXPR_TYPE_INTEGER, expr_get_type(expr));
    expr_destroy(expr);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_kind().
 */
mu_test_begin(test_expr_literal_integer_getkind)
    struct expr_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    mu_assert_eq_int(EXPR_KIND_LITERAL, expr_get_kind(expr));
    expr_destroy(expr);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_scope().
 */
mu_test_begin(test_expr_literal_integer_getscope)
    struct expr_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    mu_assert(expr_get_scope(expr) == var_get_global_scope());
    expr_destroy(expr);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_integer_value().
 */
mu_test_begin(test_expr_literal_integer_getvalue)
    int value;
    char *error_msg;
    struct expr_literal_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_create_integer(var_get_global_scope(), 42);
    mu_assert_eq_int(TRUE, expr_get_integer_value(expr, &value, &error_msg));
    mu_assert_eq_int(42, value);
    expr_destroy(expr_literal_to_expr(expr));

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_integer_value() on a string literal.
 */
mu_test_begin(test_expr_literal_integer_getvalue2)
    int value;
    char *error_msg;
    struct expr_literal_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_create_string(var_get_global_scope(), "42");
    mu_assert_eq_int(FALSE, expr_get_integer_value(expr, &value, &error_msg));
    free(error_msg);
    expr_destroy(expr_literal_to_expr(expr));

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_integer_value() on a boolean literal.
 */
mu_test_begin(test_expr_literal_integer_getvalue3)
    int value;
    char *error_msg;
    struct expr_literal_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_create_boolean(var_get_global_scope(), TRUE);
    mu_assert_eq_int(FALSE, expr_get_integer_value(expr, &value, &error_msg));
    free(error_msg);
    expr_destroy(expr_literal_to_expr(expr));

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests expr_get_integer_value() on an error literal.
 */
mu_test_begin(test_expr_literal_integer_getvalue4)
    int value;
    char *error_msg;
    char const *message = "division by zero";
    struct expr_literal_t *expr;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_create_error(var_get_global_scope(), message);
    mu_assert_eq_int(FALSE, expr_get_integer_value(expr, &value, &error_msg));
    mu_assert_eq_str(message, error_msg);
    free(error_msg);
    expr_destroy(expr_literal_to_expr(expr));

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests the evaluation of a literal integer expression.
 */
mu_test_begin(test_expr_literal_integer_eval)
    int value;
    char *error_msg;
    struct expr_t *expr;
    struct expr_t *error_expr;
    struct expr_literal_t *e;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    mu_assert(expr_typecheck_expression(expr, &error_expr));

    e = expr_evaluate(expr, NULL);
    mu_assert_eq_int(expr_get_type(expr), expr_get_type(expr_literal_to_expr(e)));
    mu_assert_eq_int(expr_get_kind(expr), expr_get_kind(expr_literal_to_expr(e)));
    mu_assert_eq_int(TRUE, expr_get_integer_value(e, &value, &error_msg));
    mu_assert_eq_int(42, value);

    expr_destroy(expr_literal_to_expr(e));
    expr_destroy(expr);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests toString() on a literal integer expression.
 */
mu_test_begin(test_expr_literal_integer_tostring)
    struct expr_t *expr;
    char *value;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    value = expr_to_string(expr);
    mu_assert_eq_str("42", value);
    free(value);
    expr_destroy(expr);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests equal() on two equal integer expressions.
 */
mu_test_begin(test_expr_literal_integer_equal1)
    struct expr_t *expr1;
    struct expr_t *expr2;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr1 = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    expr2 = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 42));
    mu_assert_eq_int(TRUE, expr_equal(expr1, expr2));
    expr_destroy(expr1);
    expr_destroy(expr2);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests equal() on two unequal integer expressions.
 */
mu_test_begin(test_expr_literal_integer_equal2)
    struct expr_t *expr1;
    struct expr_t *expr2;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr1 = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 23));
    expr2 = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 5));
    mu_assert_eq_int(FALSE, expr_equal(expr1, expr2));
    expr_destroy(expr1);
    expr_destroy(expr2);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

/**
 * Tests clone() on an integer expression.
 */
mu_test_begin(test_expr_literal_integer_clone)
    struct expr_t *expr1;
    struct expr_t *expr2;

    package_init_module();
    vartype_init_module();
    var_init_module();
    vartype_finalize_type_system();

    expr1 = expr_literal_to_expr(expr_literal_create_integer(var_get_global_scope(), 31337));
    expr2 = expr_clone(expr1);
    mu_assert_eq_int(TRUE, expr_equal(expr1, expr2));
    expr_destroy(expr1);
    expr_destroy(expr2);

    var_fini_module();
    vartype_fini_module();
    package_fini_module();
mu_test_end()

void
test_expr_literal_integer(void)
{
    mu_run_test(test_expr_literal_integer_gettype);
    mu_run_test(test_expr_literal_integer_getkind);
    mu_run_test(test_expr_literal_integer_getscope);
    mu_run_test(test_expr_literal_integer_getvalue);
    mu_run_test(test_expr_literal_integer_getvalue2);
    mu_run_test(test_expr_literal_integer_getvalue3);
    mu_run_test(test_expr_literal_integer_getvalue4);
    mu_run_test(test_expr_literal_integer_eval);
    mu_run_test(test_expr_literal_integer_tostring);
    mu_run_test(test_expr_literal_integer_equal1);
    mu_run_test(test_expr_literal_integer_equal2);
    mu_run_test(test_expr_literal_integer_clone);
}
